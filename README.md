# PercOWLation

This project addresses the classical percolation problem through simulations and algorithmic implementations in C.

## Overview

The objective is to:

- Determine whether a 2D grid percolates, using both a naive recursive algorithm and an optimized Union-Find structure.
- Experimentally estimate the percolation threshold using Monte Carlo simulations.
- Generate image representations of the grids in PPM format.

## Features

- Grid representation and loader from textual input files.
- Naive percolation detection using depth-first search.
- Optimized percolation detection using Union-Find with path compression and union by rank.
- Monte Carlo simulations to approximate the percolation threshold.
- Image generation to visualize grid states.
