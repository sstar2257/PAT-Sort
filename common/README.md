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

## 1036
[1036 Boys vs Girls](https://pintia.cn/problem-sets/994805342720868352/problems/994805453203030016)  
输入一组男女生的成绩，输出最好女生与最差男生的分数之差。  

## 1039
[1039 Course List for Student](https://pintia.cn/problem-sets/994805342720868352/problems/994805447855292416)  
简单的map和set的应用,输入为每个学生所选的课程，输出每个课程中的所有学生。  

## 1041
[1041 Be Unique](https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184)  
输入一组数，输出第一个没有重复的数。  

## 1042
[1042 Shuffling Machine](https://pintia.cn/problem-sets/994805342720868352/problems/994805442671132672)  
对于一副扑克牌，给定一个排序顺序，输出重复k次之后的牌序。  

# 1044
[1044 Shopping in Mars](https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264)  
输入一个序列，以及一个目标值M，求所有连续的子序列和恰好满足a1+...+an == M，输出对应的下标[1, n]。若找不到恰好满足，则输出大于M的最小和。  
因为输入的值都不为负，所以可以用简单的滑动窗口实现。  

# 1046
[1046 Shortest Distance](https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424)  
给定N个点标号1-N，依次连接起来组成一个环，给定相邻两点之间的距离，求任意给出两点之间的最短距离。  
因为环的存在，所以最短距离可能是正向或负向的。一个处理方法是，将所有的距离加起来，即求出环的长度，若两点之间的距离大于环的一般，则最短距离为负向。  
核心思路是用一个表来存储各个点到第一个点的距离之和，求各个点的距离相减即可。  

## 1047
[1047 Student List for Course](https://pintia.cn/problem-sets/994805342720868352/problems/994805433955368960)  
1039的相反题，输入为每个课程中的所有学生，输出每个学生所选的课。  

## 1048
[1048 Find Coins](https://pintia.cn/problem-sets/994805342720868352/problems/994805432256675840)  
简单的找硬币问题，给定一个序列表示币值，以及要求的和SUM。输出是否能找到两枚V1 < V2 并且V1 + V2 = SUM，若结果不唯一，输出币值V1最小的那个解。  

# 1049
[1049 Counting Ones](https://pintia.cn/problem-sets/994805342720868352/problems/994805430595731456)  
输入一个数字N，求1-N的所有数字中1出现过次数。  
代码里是一种数学的解法，剑指offer里讲过另一种排列的方法。都可以借鉴学习下。  

# 1051
[1051 Pop Sequence](https://pintia.cn/problem-sets/994805342720868352/problems/994805427332562944)  
好题。给定一个栈的最大容积，栈的规则为按顺序压入1-N，随机弹出。给定一串序列，问该序列是否有可能是栈的弹出顺序。  
针对序列中的每个数，把每种情况考虑清楚即可。每次判断还需要确认栈是否溢出。  

## 1054
[1054 The Dominant Color](https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768)  
输入一个二维矩阵，求其中出现次数最多的元素并输出。  

## 1056
[1056 Mice and Rice](https://pintia.cn/problem-sets/994805342720868352/problems/994805419468242944)  
给定一个长度N的序列代表老鼠体积的大小，按照给定的顺序每次G只进行比赛，体重最大的胜利进入下一轮。输出每只老鼠的名次。  

# 1057
[1057 Stack](https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592)  
实现取栈的中位数操作。针对输入的指令，输出对应的值。  
我是用了两个multiset做辅助，分别储存小于中位数和大于等于中位数的集合，容易理解但是效率应该不高。注意set的erase操作会删除迭代器。  

## 1058
[1058 A+B in Hogwarts](https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232)  
多项式给定进制的加法。  

# 1059
[1059 Prime Factors](https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488)  
因数分解。对于输出格式有要求。测试用例没有很严格，很容易ac。  

## 1060
[1060 Are They Equal](https://pintia.cn/problem-sets/994805342720868352/problems/994805413520719872)  
假设一个机器只能存储N位精度，输入两个浮点数A、B，问A、B两个数在该机器是否相同。  
要考虑各种奇怪的输入。  

## 1063
[1063 Set Similarity](https://pintia.cn/problem-sets/994805342720868352/problems/994805409175420928)  
给定一些数集，求两个数集中相同数字的数量的比例。可以利用set自动排序的功能进行检索。  

## 1065
[1065 A+B and C (64bit)](https://pintia.cn/problem-sets/994805342720868352/problems/994805406352654336)  
输出三个数，问A+B是否大于C。可以用大数算，也可以直接用long long。  

## 1069
[1069 The Black Hole of Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088)  
输入一个数，将其按各位从大到小排序后减去从小到大排序，依次执行知道0000或者6147。  

## 1070
[1070 Mooncake](https://pintia.cn/problem-sets/994805342720868352/problems/994805399578853376)  
简单的贪心应用。给定一些月饼的数量和利润，求最大获利。优先取单位利润最高的即可。    

## 1078
[1078 Hashing](https://pintia.cn/problem-sets/994805342720868352/problems/994805389634158592)  
按照给定的规则创造一个hash表，输出每个数据插入的位置。  

## 1080
[1085 Perfect Sequence](https://pintia.cn/problem-sets/994805342720868352/problems/994805381845336064)  
输入一个数组，以及P，问最多能从数组中选取多少数据，使得这些数据的最小值\*P>=最大值。  

# 1081
[1081 Rational Sum](https://pintia.cn/problem-sets/994805342720868352/problems/994805386161274880)  
输入N个分数，输出它们的和。 

# 1088
[1088 Rational Arithmetic](https://pintia.cn/problem-sets/994805342720868352/problems/994805378443755520)  
输入两个分数，输出它们的四则运算结果。  

# 1091
[1091 Acute Stroke](https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072)  
输入一个由0-1组成三维空间，输出最大的相连的1的数量。  

## 1096
[1096 Consecutive Factors](https://pintia.cn/problem-sets/994805342720868352/problems/994805370650738688)  
输入一个数，输出其最大的连续因数。即630包含5*6*7。  

## 1104
[1104 Sum of Number Segments](https://pintia.cn/problem-sets/994805342720868352/problems/994805363914686464)  
输入一个序列，输出其所有连续子序列的和。不需要先去求子序列，找规律能快很多。  

# 1105
[1105 Spiral Matrix](https://pintia.cn/problem-sets/994805342720868352/problems/994805363117768704)  
输入N个正整数，按照顺时针降序排列后，按行打印输出。因为输入都是正整数，所以可以把初始值设为0方便判断边界。如果输入数据不限制的话，得增加额外的变量判断边界。   

## 1113
[1113 Integer Set Partition](https://pintia.cn/problem-sets/994805342720868352/problems/994805357258326016)  
输入一些整数，分为两个数集，要求两个数集中数的个数之差最小，和之差最大。注意输入的数据很大。  

## 1116
[1116 Come on! Let's C](https://pintia.cn/problem-sets/994805342720868352/problems/994805355358306304)  
根据输入的顺序，按格式输出不同的值。  

## 1117
[1117 Eddington Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805354762715136)  
给定一个序列，求最大的爱丁堡数。

## 1120
[1120 Friend Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805352925609984)  
输入一些数字，计算每个数字的各位之和sum，输出所有不同的sum。可以利用set的不重性质直接进行插入操作。  

# 1121
[1121 Damn Single](https://pintia.cn/problem-sets/994805342720868352/problems/994805352359378944)  
首先输入一些数据对，每个数据对表示这两个为夫妻。然后输入一个序列，问这些序列中的单身狗id并输出。注意夫妻双方只来了一个的也算做单身狗。  

## 1124
[1124 Raffle for Weibo Followers](https://pintia.cn/problem-sets/994805342720868352/problems/994805350803292160)  
转发抽奖，遇到重复的就跳过选取下一个。  

## 1125
[1125 Chain the Ropes](https://pintia.cn/problem-sets/994805342720868352/problems/994805350316752896)  
给定一组数据代表每根绳子的长度，要求将所有绳子对折后相连，问能取得的最大长度是多少。  

## 1132
[1132 Cut Integer](https://pintia.cn/problem-sets/994805342720868352/problems/994805347145859072)  
切分一个整数Z为A和B，判断A*B是否为Z的因数。  

## 1144
[1144 The Missing Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160)  
输入一个序列，输出其中未出现的最小正整数。  

# 1145
[1145 Hashing - Average Search Time](https://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744)  
给定一个数组，使用二次再散列法构造一个符合要求的hash table。然后输入一些数字，求平均搜索时间。  
考察hash table的一些概念，可以找资料看一看。注意hash table和stl中的map不是一个东西。  

# 1148
[1148 Werewolf - Simple Version](https://pintia.cn/problem-sets/994805342720868352/problems/1038429808099098624)  
狼人杀的简化版本，在N个人中，假定有两个狼人，有且只有一个狼人说谎，总共有两个人说谎，输出狼人的id。  
这题在B级里也有，目前只想到了暴力穷举。  
