_OPT = $(if $(OPT),-O3 -flto,)
CC = gcc
CFLAGS = -g -std=c99 -Wall $(_OPT) -I./include
LDFLAGS =

.PHONY: clean doc check-syntax compile launch-apps launch-tests

# rule to generate the doxygen documentation
doc:
	doxygen conf/doxygen.conf

# rule to remove all .o files and all executables
clean:
	- rm -f *.o
	- find . -maxdepth 1 -executable -type f \( ! -name "Makefile" \) -delete

# compile rules
%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

%.o: ./tests/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

# Linking executable for grid testing
grid-test: grid.o test-grid.o
	$(CC) $(CFLAGS) -o grid-test grid.o test-grid.o $(LDFLAGS)

# Link test-loader executable
loader-test: loader.o grid.o test-loader.o
	$(CC) $(CFLAGS) -o loader-test loader.o grid.o test-loader.o $(LDFLAGS)

# Link test-generate-image executable
generate-image-test: grid.o loader.o test-generate-image.o
	$(CC) $(CFLAGS) -o generate-image-test grid.o loader.o test-generate-image.o $(LDFLAGS)

# Link test executable
percolate-dfs-test: percolate_dfs.o grid.o loader.o test-percolate-dfs.o 
	$(CC) $(CFLAGS) -o percolate-dfs-test percolate_dfs.o grid.o loader.o test-percolate-dfs.o $(LDFLAGS)

# Link Monte Carlo simulation test
simulation-dfs-test: simulation_dfs.o percolate_dfs.o grid.o test-simulation-dfs.o
	$(CC) $(CFLAGS) -o simulation-dfs-test simulation_dfs.o percolate_dfs.o grid.o test-simulation-dfs.o $(LDFLAGS)

# Link threshold computation program
threshold-dfs: simulation_dfs.o percolate_dfs.o grid.o threshold-dfs.o
	$(CC) $(CFLAGS) -o threshold-dfs simulation_dfs.o percolate_dfs.o grid.o threshold-dfs.o $(LDFLAGS)

# Link test executables
test-union-find: union_find.o test-union-find-correctness.o
	$(CC) $(CFLAGS) -o test-union-find union_find.o test-union-find-correctness.o $(LDFLAGS)

test-union-complexity: union_find.o test-union-find-complexity.o
	$(CC) $(CFLAGS) -o test-union-complexity union_find.o test-union-find-complexity.o $(LDFLAGS)

# you should put all the .o files corresponding to your .c files as prerequisites of
# this rule (see examples)
check-syntax: example-main.o read-file-formatted.o read-file-text.o \
	write-fact.o test-dummy.o app-ex-loader.o

# put all the rules to build your applications and tests here (see examples)
example-main: example-main.o
	$(CC) $(CFLAGS) -o example-main example-main.o $(LDFLAGS)

example-string: example-string.o
	$(CC) $(CFLAGS) -o example-string example-string.o $(LDFLAGS)

read-file-formatted: read-file-formatted.o
	$(CC) $(CFLAGS) -o read-file-formatted read-file-formatted.o $(LDFLAGS)

read-file-text: read-file-text.o
	$(CC) $(CFLAGS) -o read-file-text read-file-text.o $(LDFLAGS)

write-fact: write-fact.o
	$(CC) $(CFLAGS) -o write-fact write-fact.o $(LDFLAGS)

test-dummy: test-dummy.o
	$(CC) $(CFLAGS) -o test-dummy test-dummy.o $(LDFLAGS)

# the app-ex-loader app
app-ex-loader: app-ex-loader.o
	$(CC) $(CFLAGS) -o app-ex-loader app-ex-loader.o $(LDFLAGS)

# put all your applications and tests executables as prerequisite of this rule
compile-all: example-main example-string read-file-formatted read-file-text \
	write-fact test-dummy app-ex-loader grid-test loader-test generate-image-test percolate-dfs-test simulation-dfs-test threshold-dfs test-union-find test-union-complexity 

# add all your test executables in the following variable. You should respect
# the order given in the project text
ALL_TESTS = test-dummy grid-test loader-test generate-image-test percolate-dfs-test simulation-dfs-test threshold-dfs test-union-find test-union-complexity 

launch-tests: $(ALL_TESTS)
	for x in $(ALL_TESTS); do ./$$x --all; done

# add all .c, .h and .txt files in repository
git-add-all-files:
	git add tests/*.c src/*.c include/*.h data/*.t

valgrind-all:
	for x in $(ALL_TESTS); do \
		echo "Running Valgrind on $$x..." | tee -a valgrind_log.txt; \
		valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$$x 2>&1 | tee -a valgrind_log.txt; \
		echo "" | tee -a valgrind_log.txt; \
	done
