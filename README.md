# Genome Assembly using De Bruijn Graphs

## Overview
This project demonstrates genome assembly from short DNA reads using De Bruijn graphs. The algorithm constructs a graph from k-mers of the reads and reconstructs the original genome by finding an Eulerian path.

## Concepts Used
- k-mer generation
- De Bruijn Graph
- Eulerian Path
- Hierholzer’s Algorithm

## How It Works
1. Break DNA reads into k-mers
2. Construct graph using (k-1)-mers as nodes
3. Add directed edges for overlaps
4. Find Eulerian path
5. Reconstruct genome from path

## Input Format
- First line: integer k
- Next lines: DNA reads

Example:
3
AGCT
GCTA
CTAG
TAGC

## Output
Assembled genome sequence.

## How to Run
g++ main.cpp -o genome
./genome < input.txt

## Applications
- Genome assembly
- DNA sequencing
- Bioinformatics research
