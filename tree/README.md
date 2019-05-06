# 1004
[1004 Counting Leaves](https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184)  
题目抽象出来就是给定一棵树，从根节点开始输出每一层没有子节点的节点的数量。  
看之前自己写的代码真的是稚嫩啊\_(:ｪ 」∠)\_  

# 1020
[1020 Tree Traversals](https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072)  
给定一棵树的中序和后序遍历序列，输出树的层序遍历。  

# 1043
[1043 Is It a Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856)  
给定一个序列，问是否为一棵二叉搜索树或其镜像的前序遍历。递归。  

# 1053
[1053 Path of Equal Weight](https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512)  
给定一棵树的结构和每个节点的权重，给定一个数字N，求所有根节点到叶节点的路径中权重之和等于N的路径并打印。深度优先搜索的应用。  

# 1064
[1064 Complete Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568)  
给定一组数字，可以构造唯一的完全二叉搜索树，按照层顺序输出。每次分为左右两部分递归，可以用vector来保存每层的数字。  

# 1065
[1066 Root of AVL Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805404939173888)  
[AVL树](https://zh.wikipedia.org/zh-hans/AVL树)是自平衡的二叉搜索树。即任意节点的左右子树高度差不超过1。  
输入N个数，依次插入AVL树中，求最后AVL树的根节点值为多少。  

# 1079
[1079 Total Sales of Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560)  
供应链问题，给定一个类似树的结构，起售价以及利润率，求最后所有零售商的收入总和。用BFS和DFS都可以做。  

# 1086
[1086 Tree Traversals Again](https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024)  
给定一个有关push和pop的输入，根据这些输入能够构造出一棵二叉树的前序和中序遍历顺序，求该二叉树的后序遍历顺序。  

# 1090
[1090 Highest Price in Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944)  
供应链问题，求零售商的最高价格以及个数，其实就是求树的深度。  

# 1094
[1094 The Largest Generation](https://pintia.cn/problem-sets/994805342720868352/problems/994805372601090048)  
输入一个家族的族谱，求最多的一代人的数量以及是哪一代。  
需要判断lvl的广度优先搜索。  

## 1099
[1099 Build A Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805367987355648)  
给定一棵空树和一个序列，要求以二叉搜索树的形式填充之后，输出层序遍历。  

## 1102
[1102 Invert a Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805365537882112)  
输入一棵二叉树，输出其层序遍历和中序遍历。  

# 1106
[1106 Lowest Price in Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805362341822464)  
供应链问题，求零售商的最低价格以及个数。  

## 1110
[1110 Complete Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805359372255232)  
输入一棵二叉树，判断是否是一棵完全二叉树。  

# 1115
[1115 Counting Nodes in a BST](https://pintia.cn/problem-sets/994805342720868352/problems/994805355987451904)  
给定一个数组输入，依次插入一棵空的二叉搜索树中，输出最低两层的节点数之和。  

# 1119
[1119 Pre- and Post-order Traversals](https://pintia.cn/problem-sets/994805342720868352/problems/994805353470869504)  
好题，考察树的几个遍历顺序。  
已知树的前序和中序、后序和中序遍历顺序，能够唯一确定一棵树（因为中序可以区分左右子树）。  
输入一棵树的前序和后序顺序，问是否能确定唯一的一棵树。若能，输出其中序；否则输出其中一种中序遍历结果。  
不能唯一确定的情况在于，当某一个节点的后序前一个节点与先序后一个节点相同时，无法判断其是左子树还是右子树。  

## 1123
[1123 Is It a Complete AVL Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805351302414336)  
输入一个序列，构造一棵AVL树，输出其层序遍历，并判断是否是一棵完全二叉树。  

## 1127
[1127 ZigZagging on a Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805349394006016)  
给定一棵树的中序和后序遍历顺序，输出其“之”字形遍历的顺序。  

# 1130
[1130 Infix Expression](https://pintia.cn/problem-sets/994805342720868352/problems/994805347921805312)  
给定一棵表示运算表达式的二叉树，输出其中序表示，难点在于需要判断是否要加括号。  

## 1135
[1135 Is It A Red-Black Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640)  
给定一棵树，判断其是否为红黑树。  

## 1138
[1138 Postorder Traversal](https://pintia.cn/problem-sets/994805342720868352/problems/994805345078067200)  
输入一棵树的前序和中序遍历，输出其后序遍历的第一个节点值。  

# 1143
[1143 Lowest Common Ancestor](https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312)  
给定一个二叉搜索树的先序序列，进行k次询问，每次给出两个节点，求最低公共先祖。  
*递归构造二叉树、递归查找公共先祖*  
1143.cpp为后来ac的代码，1143_2.cpp为原来的思路。  

## 1147
输入一些完全二叉树的层序遍历序列，问是否为最大堆、最小堆，然后输出后序遍历序列。  

# 1151
[1151 LCA in a Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856)  
给定一颗二叉树的中序和先序序列，输入任意两个值，首先判断这两个值是否在这棵树中，若在，求出最低公共先祖。  
这题很不错，自己用的方法是先建树，然后用类似两个链表求交点的方法做的，比较繁琐。  
后面注释区放了两个网上找的代码，非常简洁，效率也很高，值得借鉴。  

## 1155
[1155 Heap Paths](https://pintia.cn/problem-sets/994805342720868352/problems/1071785408849047552)  
给定一棵完全二叉树的层序遍历，输出从根节点到叶节点的所有路径，并判断是否为大小堆。  
