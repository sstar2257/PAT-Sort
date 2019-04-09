# 1004
[1004 Counting Leaves](https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184)  
题目抽象出来就是给定一棵树，从根节点开始输出每一层没有子节点的节点的数量。  
看之前自己写的代码真的是稚嫩啊\_(:ｪ 」∠)\_  

# 1053
[1053 Path of Equal Weight](https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512)  
给定一棵树的结构和每个节点的权重，给定一个数字N，求所有根节点到叶节点的路径中权重之和等于N的路径并打印。深度优先搜索的应用。  

# 1064
[1064 Complete Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568)  
给定一组数字，可以构造唯一的完全二叉搜索树，按照层顺序输出。每次分为左右两部分递归，可以用vector来保存每层的数字。  

# 1079
[1079 Total Sales of Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560)  
供应链问题，给定一个类似树的结构，起售价以及利润率，求最后所有零售商的收入总和。用BFS和DFS都可以做。  

# 1090
[1090 Highest Price in Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944)  
供应链问题，求零售商的最高价格以及个数，其实就是求树的深度。  

# 1106
[1106 Lowest Price in Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805362341822464)  
供应链问题，求零售商的最低价格以及个数。  

# 1143
[1143 Lowest Common Ancestor](https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312)  
给定一个二叉搜索树的先序序列，进行k次询问，每次给出两个节点，求最低公共先祖。  
*递归构造二叉树、递归查找公共先祖*  
1143.cpp为后来ac的代码，1143_2.cpp为原来的思路。  

# 1151
[1151 LCA in a Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856)  
给定一颗二叉树的中序和先序序列，输入任意两个值，首先判断这两个值是否在这棵树中，若在，求出最低公共先祖。  
这题很不错，自己用的方法是先建树，然后用类似两个链表求交点的方法做的，比较繁琐。  
后面注释区放了两个网上找的代码，非常简洁，效率也很高，值得借鉴。  

