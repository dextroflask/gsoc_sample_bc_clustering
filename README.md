# Betweenness Centrality Clustering – Sample Program

This repository contains a simple demonstration of the `betweenness_centrality_clustering` function from the [Boost Graph Library (BGL)](https://www.boost.org/doc/libs/1_84_0/libs/graph/doc/betweenness_centrality_clustering.html). It is meant to showcase how edge betweenness centrality can be used to perform graph clustering.

> This sample is part of my GSoC project for [pgRouting](https://pgrouting.org/) and is hosted separately for better visibility and testing.

---

## What It Does

The program runs the `bc_clustering` algorithm on 3 different types of graphs:

1. **Complete Graph (K₅)**  
   All nodes are interconnected. Clustering gradually disconnects the graph.

2. **Clustered Graph with Bridges**  
   Three fully connected subgraphs (clusters) connected by bridge edges. The algorithm quickly identifies and removes the bridges, forming clear clusters.

3. **Single Cluster Grid Graph**  
   A weakly connected graph (3×3 grid) that stays as a single cluster unless extensively pruned.

---

##  Highlights

- Shows **edge betweenness centrality** in action.
- Visualizes clustering by printing:
  - Initial edge list
  - Initial connected components (clusters)
  - Edges removed
  - Final clusters

---

## Dependencies

- Boost Graph Library (BGL)  
  Make sure to have Boost installed and properly linked.

---
