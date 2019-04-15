## 1001
[1001 A+B Format](https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400)  
格式化输出两个输入数字之和。  

## 1002
[1002 A+B for Polynomials](https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000)  
输入两个多项式A、B，相加后输出。

## 1005
[1005 Spell It Right](https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336)  
输入一个超大数，对各位求和之后，读出这个和。  

## 1006
[1006 Sign In and Sign Out](https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928)  
给定一串输入，对每次输入做比较取最大最小值  

## 1008
[1008 Elevator](https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016)  
给定一个电梯上一层楼、下一层楼以及停靠花费的时间，输入楼层的序列，输出花费的总时间。  

## 1009
[1009 Product of Polynomials](https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344)  
多项式相乘  

## 1011
[1011 World Cup Betting](https://pintia.cn/problem-sets/994805342720868352/problems/994805504927186944)  
一道简单的练手题，取每次输入最大值，注意下输入输出就行。  

## 1015
[1015 Reversible Primes](https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000)  
给定一个十进制数A和一个进制r，输出A在r进制下的表示翻转以后的十进制数是否为质数。  

## 1019
[1019 General Palindromic Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984)  
进制转换，判断回文  

## 1027
[1027 Colors in Mars](https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768)  
送分题，13进制转16进制后按格式输出。  

# 1029
[1029 Median](https://pintia.cn/problem-sets/994805342720868352/problems/994805466364755968)  
好题，给定两个排完序的升序序列，输出他们的中位数。注意每个序列都很大，合并会导致内存超限。  
很经典的分治法的例子，可以网上搜些教程看看。  

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

## 1063
[1063 Set Similarity](https://pintia.cn/problem-sets/994805342720868352/problems/994805409175420928)  
给定一些数集，求两个数集中相同数字的数量的比例。可以利用set自动排序的功能进行检索。  

# 1105
[1105 Spiral Matrix](https://pintia.cn/problem-sets/994805342720868352/problems/994805363117768704)  
输入N个正整数，按照顺时针降序排列后，按行打印输出。因为输入都是正整数，所以可以把初始值设为0方便判断边界。如果输入数据不限制的话，得增加额外的变量判断边界。    

## 1113
[1113 Integer Set Partition](https://pintia.cn/problem-sets/994805342720868352/problems/994805357258326016)  
输入一些整数，分为两个数集，要求两个数集中数的个数之差最小，和之差最大。注意输入的数据很大。  

## 1120
[1120 Friend Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805352925609984)  
输入一些数字，计算每个数字的各位之和sum，输出所有不同的sum。可以利用set的不重性质直接进行插入操作。  

# 1145
[1145 Hashing - Average Search Time](https://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744)  
给定一个数组，使用二次再散列法构造一个符合要求的hash table。然后输入一些数字，求平均搜索时间。  
考察hash table的一些概念，可以找资料看一看。注意hash table和stl中的map不是一个东西。  

