Warehouse Inventory Management System using C

Project Overview

This project implements a Warehouse Inventory Management System using three data structures: Binary Search Tree (BST), AVL Tree, and Hashing with Linear Probing.

The objective is to compare their performance in storing, inserting, and searching warehouse product records.

Problem Statement

A warehouse needs an efficient way to store product information and search for products using unique Product IDs. This project evaluates three data structures to identify a suitable approach for inventory management.

Technologies Used

* Programming Language: C
* Compiler: GCC
* IDE: Visual Studio Code / Code::Blocks
* Version Control: Git and GitHub

Dataset

The project uses 40 unique warehouse product records.

Each record contains:

* Product ID
* Product Name
* Category
* Price
* Quantity

Dataset file: data/products.csv

The same records and insertion order are used for all three data structures.

Data Structures Implemented

1. Binary Search Tree (BST)

* Insertion of product records
* Searching using Product ID
* Inorder traversal
* Tree height calculation

2. AVL Tree

* Insertion with automatic balancing
* Searching using Product ID
* Inorder traversal
* Rotations: LL, RR, LR and RL
* Tree height calculation

3. Hashing with Linear Probing

* Hash function: ProductID % 53
* Insertion of product records
* Searching using Product ID
* Collision handling using Linear Probing

Test Cases

* Successful search: 175 and 105
* Unsuccessful search: 999
* Additional insertion: 305

Compilation and Execution

Compile each program using GCC:

gcc src/bst.c -o bst
gcc src/avl.c -o avl
gcc src/hashing.c -o hashing

Run the programs:

./bst
./avl
./hashing

On Windows, run the corresponding .exe files.

Performance Analysis

The following parameters are evaluated:

* Number of search comparisons
* BST and AVL tree heights
* Number of hash collisions
* Successful search performance
* Unsuccessful search performance
* Insertion observations

Actual experimental outputs will be recorded in the results/ folder.

Conclusion

The three data structures are compared using the same warehouse inventory dataset. The final recommendation will be based on the measured experimental results.

Project Information

* Project: Warehouse Inventory Management System
* Course: Data Structures and Algorithms
* Language: C
* Institution: SRM Institute of Science and Technology, Tiruchirappalli
* Assignment: Continuous Learning Assessment 2
