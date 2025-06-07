#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
import sys

data = np.genfromtxt('union_find_complexity.csv' if len(sys.argv) == 1 else sys.argv[1],
                     delimiter=',',
                     names=['nb', 'merge', 'find'])

fig, axes = plt.subplots(1,1)

axes.set_title("Time to merge/find all nodes in union_find")
axes.set_xlabel('dimension')
axes.set_ylabel('time')

# time to merge
axes.plot(data['nb'], data['merge'], c='r', label='merge')

# time to find
axes.plot(data['nb'], data['find'], c='b', label='find')

# legend
axes.legend()

plt.show()
