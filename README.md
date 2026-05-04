# Social Network Analyzer (DSA Project)

## Overview

This project simulates a social network using **Graph Data Structure**, where:

* Users are represented as nodes
* Friendships are represented as edges

It demonstrates how real-world social platforms can be modeled using graph algorithms to perform **recommendation, connection analysis, and community detection**.

---

## Features

* Add users and friendships (Graph-based representation)
* Display network structure
* Friend recommendation using **Friends-of-Friends logic**
* Smart recommendation using **mutual connections + BFS**
* Connection analysis using **Shortest Path (BFS)**
* Community detection using **DFS (Connected Components)**
* Influence score calculation (weighted: direct + indirect connections)
* Top influencer detection within each community
* Global influencer detection across the entire network

---

## Data Structures & Algorithms Used

* **Graph (Adjacency List)** using `unordered_map`
* **Breadth First Search (BFS)**

  * Shortest path
  * Recommendation logic
* **Depth First Search (DFS)**

  * Community detection
* **Hashing** (`unordered_map`, `unordered_set`)
* **Sorting** (ranking recommendations)

---

## Key Functionalities

### 🔹 Friend Recommendation

Suggests users who are not directly connected but share mutual connections.

### 🔹 Smart Recommendation

Ranks suggested users based on the number of mutual friends and displays connection details.

### 🔹 Connection Analysis

Uses BFS to:

* Find shortest path between users
* Show degree of connection
* Display actual connection path

### 🔹 Community Detection

Uses DFS to identify clusters (connected components) in the network.

### 🔹 Influence Score

Calculates influence using:

* Direct connections (higher weight)
* Indirect connections (friends of friends)

### 🔹 Top Influencer (Local)

Finds the most influential user within each community.

### 🔹 Global Influencer

Identifies the most influential user across the entire network.

---

## Example

```
A → B, C  
B → D  
C → D, E
```

### Suggestions for A:

* D (2 mutual friends)
* E (1 mutual friend)

### Connection Path:

```
A → B → D
```

---

## How to Run

1. Compile:

   ```bash
   g++ main.cpp -o main
   ```

2. Run:

   ```bash
   ./main
   ```

---

## Future Improvements

* Implement friend request system (mutual acceptance model)
* Introduce weighted graph based on interaction frequency
* Convert to backend using **Java Spring Boot**
* Add database integration (MySQL / MongoDB)
* Build frontend UI (React)

---

## Learnings

* Practical implementation of graph-based systems
* BFS for shortest path and recommendation problems
* DFS for connected component detection
* Designing scalable, real-world systems using DSA concepts
* Combining multiple algorithms for system-level features

---

## Author

**Bhumika Tiwari**
