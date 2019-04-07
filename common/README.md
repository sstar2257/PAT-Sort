## 1006
[1006 Sign In and Sign Out](https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928)  
给定一串输入，对每次输入做比较取最大最小值  

## 1016
[1016 Phone Bills](https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488)  
自定义排序，然后依次检索有效的账单整理输出  

## 1019
[1019 General Palindromic Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984)  
进制转换，判断回文  

## 1028
[1028 List Sorting](https://pintia.cn/problem-sets/994805342720868352/problems/994805468327690240)  
按照给定要求排序，自定义sort规则  

## 1035
[1035 Password](https://pintia.cn/problem-sets/994805342720868352/problems/994805454989803520)  
简单的字符串字符匹配和替换操作  

## 1039
[1039 Course List for Student](https://pintia.cn/problem-sets/994805342720868352/problems/994805447855292416)  
简单的map和set的应用,输入为每个学生所选的课程，输出每个课程中的所有学生。  

# 1046
[1046 Shortest Distance](https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424)  
给定N个点标号1-N，依次连接起来组成一个环，给定相邻两点之间的距离，求任意给出两点之间的最短距离。  
因为环的存在，所以最短距离可能是正向或负向的。一个处理方法是，将所有的距离加起来，即求出环的长度，若两点之间的距离大于环的一般，则最短距离为负向。  
核心思路是用一个表来存储各个点到第一个点的距离之和，求各个点的距离相减即可。  

## 1047
[1047 Student List for Course](https://pintia.cn/problem-sets/994805342720868352/problems/994805433955368960)  
1039的相反题，输入为每个课程中的所有学生，输出每个学生所选的课。  

## 1054
[1054 The Dominant Color](https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768)  
输入一个二维矩阵，求其中出现次数最多的元素并输出。  

## 1055
[1055 The World's Richest](https://pintia.cn/problem-sets/994805342720868352/problems/994805421066272768)  
给定一些富豪的id、age和wealth，进行K次询问,每次给出一个年龄范围，按照财富从大到小输出符合该年龄段的富豪id。需要仔细读题目，这题还需要剪枝，因为最多输出100，所以同一年龄超过100的可以先行去除。  

## 1063
[1063 Set Similarity](https://pintia.cn/problem-sets/994805342720868352/problems/994805409175420928)  
给定一些数集，求两个数集中相同数字的数量的比例。可以利用set自动排序的功能进行检索。  






