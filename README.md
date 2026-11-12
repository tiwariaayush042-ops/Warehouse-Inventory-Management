Warehouse Inventory Management System Using C

1. Project Overview

This project implements a Warehouse Inventory Management System using three different data structures: Binary Search Tree (BST), AVL Tree, and Hashing with Linear Probing.

The main objective is to compare the performance of these data structures in storing, inserting, and searching warehouse product records.

2. Problem Statement

A warehouse needs an efficient system to store product information and search for products using unique Product IDs.

This project implements three data structures and compares their performance to identify a suitable approach for inventory management.

3. Technologies Used

* Programming Language: C
* Compiler: GCC
* IDE: Visual Studio Code / Code::Blocks
* Version Control: Git and GitHub

4. Dataset

The project uses 40 unique warehouse product records.

Each record contains:

* Product ID
* Product Name
* Category
* Price
* Quantity

Dataset file: data/products.csv

The same dataset and insertion order are used for all three data structures to ensure a fair comparison.

5. Data Structures Implemented

A. Binary Search Tree (BST)

* Insertion of product records.
* Searching using Product ID.
* Inorder traversal.
* Tree height calculation.

B. AVL Tree

* Insertion with automatic balancing.
* Searching using Product ID.
* Inorder traversal.
* LL, RR, LR and RL rotations.
* Tree height calculation.

C. Hashing with Linear Probing

* Hash function: ProductID % 53
* Insertion of product records.
* Searching using Product ID.
* Collision handling using Linear Probing.

6. Test Cases

The following test cases are used to evaluate the implementations:

Test Case	Input	Expected Result
Successful Search	175	Product found
Successful Search	105	Product found
Unsuccessful Search	999	Product not found
Additional Insertion	305	Product inserted

7. Compilation and Execution

Each data structure is implemented in a separate C file.

Compile using GCC:

gcc bst.c -o bst
gcc avl.c -o avl
gcc hashing.c -o hashing

Run the programs:

./bst
./avl
./hashing

On Windows, execute the corresponding .exe files.

8. Performance Analysis

The performance of the three data structures is compared using the following parameters:

* Number of search comparisons.
* BST and AVL tree heights.
* Number of hash collisions.
* Successful search performance.
* Unsuccessful search performance.
* Insertion performance.

Experimental outputs and comparison results are stored in the results/ folder.

9. Conclusion

This project compares Binary Search Tree, AVL Tree, and Hashing with Linear Probing for warehouse inventory management.

By using the same dataset for all three implementations, their performance can be evaluated fairly. The experimental results help identify the advantages and limitations of each data structure.

10. Project Information

* Project: Warehouse Inventory Management System
* Course: Data Structures and Algorithms
* Language: C
* Institution: SRM Institute of Science and Technology, Tiruchirappalli
* Assignment: Continuous Learning Assessment 2

11. Repository Structure

Warehouse-Inventory-Management/
│
├── data/
│   └── products.csv
│
├── results/
│
├── bst.c
├── avl.c
├── hashing.c
├── README.md
└── .gitignore
