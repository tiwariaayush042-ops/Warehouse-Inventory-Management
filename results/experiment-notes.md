Experimental Analysis

Objective

To compare Binary Search Tree (BST), AVL Tree and Hashing with Linear Probing for a Warehouse Inventory Management System.

Dataset

* Total records: 40
* Search key: Product ID
* Successful search keys: 175 and 105
* Unsuccessful search key: 999
* Additional product inserted: 305

Observations

Binary Search Tree

BST stores products according to their Product IDs. Its performance depends on the order of insertion. Inorder traversal displays the product IDs in sorted order.

AVL Tree

AVL automatically maintains balance through LL, RR, LR and RL rotations. It provides logarithmic worst-case search and insertion performance.

Hashing with Linear Probing

Hashing uses the hash function Product ID % 53. When a collision occurs, linear probing checks the next available slot. It provides expected constant-time searching when the table is not heavily loaded.

Comparison and Recommendation

Hashing with Linear Probing is suitable when fast product-ID lookup is the main requirement. AVL Tree is suitable when predictable search performance and sorted traversal are both important. BST is simpler but can become inefficient if it becomes unbalanced.

Result Limitation

The theoretical comparison above is based on the properties of the three data structures. Actual search comparisons, tree heights and collision counts must be obtained by executing the programs. They are not claimed as measured experimental results in this report.
