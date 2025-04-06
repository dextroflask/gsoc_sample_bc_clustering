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

## Outputs
![image](https://github.com/user-attachments/assets/bb81c2c3-8b19-4c90-9d1d-9612295d62f8)

![image](https://github.com/user-attachments/assets/f91f6c08-f713-4936-880b-10b5319ea2a4)

![image](https://github.com/user-attachments/assets/ad2f18bd-b2cd-4286-be8e-f101ee3116fb)

---

## Graph Visuals
Drawn on paper
![WhatsApp Image 2025-04-06 at 16 40 12 (1)](https://github.com/user-attachments/assets/e1c7b541-dfa2-41d3-acef-4f87e3c5d2c1)

![WhatsApp Image 2025-04-06 at 16 40 12](https://github.com/user-attachments/assets/ad6bbc66-f312-4201-a679-c72c5fd4a121)



---
