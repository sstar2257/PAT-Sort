## 1021
[1021 Deepest Root](https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856)  
给定一个图的邻接矩阵，任取其中一个点作为树的根节点，输出树的深度最大时的节点id。  
1. 用vector来存储边的关系，用邻接矩阵内存会超限
2. 第一次出发开始搜索（不管起始点是哪个节点）所找到的「当前」最长路径的终点（们），一定是「整个图」最长路径的的起始点，所以再以此为起始点去深搜，找到的「当前」最长路径的终点，也一定是要找的「整个图」最长路径的起始点（因为这是无向图嘛，起点亦是终点，终点亦是起点）。把这些点保存下来，就是要求的节点。  

# 1034
[1034 Head of a Gang](https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624)  
给定一组输入,每个输入表示A、B之间的通话时间。一个Gang表示两两之间存在通话关系的连通簇，同时总的通话时间需要大于给定阈值K。Gang中通话时间最长的为HEAD。输出HEAD的id和该HEAD所在Gang的成员数量。  
用set表示Gang，注意每次输入之后需要做一个合并set的操作，因为可能出现两个Gang之间的某两人通话的情况，这样的话就需要把这两个Gang合并。  

# 1087
[1087 All Roads Lead to Rome](https://pintia.cn/problem-sets/994805342720868352/problems/994805379664297984)  
给定一些城市的相连距离，以及每个城市的权重，给出起点和终点，求最短路径。若路径不唯一，输出权重最大的一条。dijksra可以做，深度优先搜索应该也可以。  
//刷完过后回来的看法，应该用递归搜索代码方便些。  

# 1107
[1107 Social Clusters](https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744)  
给定一些人和每个人的爱好，假定相同爱好的人可以互相认识并结成一个簇，输出簇的数量以及非升序输出每个簇的大小。抽象出来可以理解为求连通图的数量。可以用广度搜索来处理。   

## 1114
[1114 Family Property](https://pintia.cn/problem-sets/994805342720868352/problems/994805356599820288)  
输入一些人的家庭情况和财富情况，统计后输出每个家庭的财富情况。一个抽象成图的情况，因为存在一对多的映射关系，所以不能简单的用数组来处理。   

## 1122
[1122 Hamiltonian Cycle](https://pintia.cn/problem-sets/994805342720868352/problems/994805351814119424)  
考察哈密顿回路  
题目刚开始看了好几遍没理解意思。。。其实就是下面4个判断  
满足了以下条件即输出YES，只要有不满足的就输出NO：  
1. 路径节点个数等于n + 1
2. 相邻点之间存在连通的边
3. 前n点各只出现过1次
4. 第一个节点等于最后一个节点，构成回路

# 1126
[1126 Eulerian Path](https://pintia.cn/problem-sets/994805342720868352/problems/994805349851185152)  
输入一些点和它们的连通关系，判断欧拉路径、半欧拉路径或者不是欧拉。输出每个点的边的数量。除了题目里给出的判断要求，还需要额外判断连通性，不然有一个5分的测试点过不去。  

## 1128
[1128 N Queens Puzzle](https://pintia.cn/problem-sets/994805342720868352/problems/994805348915855360)  
N皇后问题，判断给定的序列是否为N皇后问题的一组解。  

# 1131
[1131 Subway Map](https://pintia.cn/problem-sets/994805342720868352/problems/994805347523346432)  
很实用的一个问题。给定一组数据模拟地铁的线路情况。  
![测试样例](../img/subway.jpg)  
给出任意两个车站，打印出最短路径。  

## 1134
[1134 Vertex Cover](https://pintia.cn/problem-sets/994805342720868352/problems/994805346428633088)  
一幅图的顶点的集合是这样的一个集合：图中的每一条边都能关联到集合内的一个点。  
给定一幅图，然后给出一些点集，问是否符合上面的规则。  

# 1139
[1139 First Contact](https://pintia.cn/problem-sets/994805342720868352/problems/994805344776077312)  
给定一个朋友关系网，每次询问给定任意两人，通过类似boy-boy-girl-gril的中转关系使两人取得联系，求这样的关系对。（具体规则见题目）  
题目有几个需要注意的地方，详见注释。  
1139.cpp是网上找的某个大佬的代码，1139_2.cpp是按照我开始的思路改写的。  

## 1142
[1142 Maximal Clique](https://pintia.cn/problem-sets/994805342720868352/problems/994805343979159552)  
给定一个无向图，假设一个clique是这样一个点集：clique内的任意两点都互相连接。若在图中找不到任何一点p，使得p加入clique后仍然为一个clique，则原来的clique为maximal clique。  
输入几组点集，判断是否为clique以及最大clique。  

## 1146
[1146 Topological Order](https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760)  
给定一个有向图，输入一些序列，输出哪些不是[有向图的拓扑序列](https://zh.wikipedia.org/wiki/拓撲排序)。  
![topological order](../img/topological_order)

## 1154
[1154 Vertex Coloring](https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552)  
proper vertex coloring：图中任意两个相邻的点不使用同样的颜色，这样的染色序列叫做合适的染色。  
给定一个无向图，输入一些序列，判断是否为proper vertex coloring。  

	

