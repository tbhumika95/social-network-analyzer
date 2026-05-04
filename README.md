# Social Network Analyzer (DSA Project)

##  Overview

This project simulates a social network using **Graph Data Structure** where:

* Users are represented as nodes
* Friendships are represented as edges

The system provides intelligent features like friend recommendation and connection analysis using graph algorithms.

---

##  Features

* Add users to the network
* Add friendships (undirected graph)
* Display complete network
* Friend recommendation (Friends of Friends)
* Smart recommendation based on **mutual friends**
* Show connection level and path between users (using BFS)

---

##  Data Structures & Algorithms Used

* Graph (Adjacency List using `unordered_map`)
* BFS (Breadth First Search)
* HashMap (`unordered_map`)
* HashSet (`unordered_set`)
* Sorting (for ranking suggestions)

---

##  Key Functionalities

### 1. Friend Recommendation

Suggests users who are not directly connected but share mutual connections.

### 2. Smart Recommendation

Ranks suggested users based on the number of mutual friends.

### 3. Connection Analysis

Finds the shortest path between two users using BFS and displays:

* Connection level (degree of separation)
* Actual connection path

---

##  Example

User A is connected to B and C
B is connected to D
C is connected to D and E

Suggestions for A:

* D (2 mutual friends)
* E (1 mutual friend)

Connection Path:
A → B → D

---

##  How to Run

1. Compile:
   g++ main.cpp -o main
2. Run:
   ./main

---

##  Future Improvements

* Implement friend request system (mutual acceptance)
* Convert to backend using Java Spring Boot
* Add database integration (MySQL/MongoDB)
* Build frontend UI (React)

---

##  Learnings

* Practical implementation of graph data structures
* BFS traversal for shortest path problems
* Designing real-world systems using DSA concepts

---

##  Author

Bhumika Tiwari
