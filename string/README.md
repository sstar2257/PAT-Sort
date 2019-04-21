## 1010
[1010 Radix](https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536)  
输入两个数以及其中一个数的进制(不止10进制)，判断是否对另一个数，存在一种进制使两个数相等。  
题目要看清楚，这个进制是有可能特别大的。   

## 1022
[1022 Digital Library](https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336)  
输入一些图书的信息，然后进行N次检索，输出每次检索的结果。  
主要是有一些string的处理，信息的存储可以用map简单处理。  

## 1023
[1023 Have Fun with Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805478658260992)  
输入一个很大的数，输出该数乘以2之后是否为原数的一个全排列。考虑字符串乘法。  

## 1024
[1024 Palindromic Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805476473028608)
输入一个数N和最大步数K，问经过至多K步之后，该数能否成为一个回文数（处理步骤：新数=原数+原数的翻转）。注意字符串加法的效率以及首位的0。  

## 1037
[1031 Hello World for U](https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416)  
输入一个字符串，要求按照U字形输出。  

## 1038
[1038 Recover the Smallest Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704)  
输入一组不超过8位的非负整数（首位可能有0），输出拼接后的最小数。  

# 1040
[1040 Longest Symmetric String](https://pintia.cn/problem-sets/994805342720868352/problems/994805446102073344)  
输入一个字符串，求其中最长回文序列的长度。  
当初是用穷举写的有点蠢，这题可以用动态规划的方法去做，实现O(n)的时间复杂度。  
给个链接，[大佬写的动态规划](https://www.liuchuo.net/archives/2104)  

## 1050
[1050 String Subtraction](https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152)  
简单的字符串减法,输入两个字符串S1、S2，去除S1中所有在S2中出现的字符。因为只要输出去除后的结果就行，所以不需要对原字符串进行操作。  

## 1061
[1061 Dating](https://pintia.cn/problem-sets/994805342720868352/problems/994805411985604608)  
输入一个字符串，按照题目给出的要求解密出其中的信息。  

## 1071
[1071 Speech Patterns](https://pintia.cn/problem-sets/994805342720868352/problems/994805398257647616)  
输入一串以'\n'结尾的字符，求其中出现最多的单词及其次数，不区分大小写。  

## 1073
[1073 Scientific Notation](https://pintia.cn/problem-sets/994805342720868352/problems/994805395707510784)  
输入一个科学进制表示的数，转换为正常表示。  

## 1077
[1077 Kuchiguse](https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096)  
输入几个字符串，输出最长相同后缀。  

# 1082
[1082 Read Number in Chinese](https://pintia.cn/problem-sets/994805342720868352/problems/994805385053978624)  
输入一个不超过9位的整数，输出中文的读法。  

## 1084
[1084 Broken Keyboard](https://pintia.cn/problem-sets/994805342720868352/problems/994805382902300672)  
输入两个字符串，分别为实际输入和显示字符，输出键盘上的坏键。  

## 1092
[1092 To Buy or Not to Buy](https://pintia.cn/problem-sets/994805342720868352/problems/994805374509498368)  
输入两个字符串，求第二个字符串中的字符能否全部在第一个字符串中找到。  

# 1093
[1093 Count PAT's](https://pintia.cn/problem-sets/994805342720868352/problems/994805373582557184)  
输入一个字符串，输出其中PAT出现的次数。字符之间不必相邻。  

## 1100
[1100 Mars Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805367156883456)  
输入十进制数和火星数，输出互相转换后的结果。  

## 1108
[1108 Finding Average](https://pintia.cn/problem-sets/994805342720868352/problems/994805360777347072)  
输入一组数据，首先判断数据的合法性，然后输出所有合法数据的平均数。  

## 1112
[1112 Stucked Keyboard](https://pintia.cn/problem-sets/994805342720868352/problems/994805357933608960)  
假设一个键盘上的某些键坏了，按下之后会重复K次。输入一个字符串，输出坏掉的键和正确的输入。  

## 1136
[1136 A Delayed Palindrome](https://pintia.cn/problem-sets/994805342720868352/problems/994805345732378624)  
输入一个大数，判断是否回文。若不是，则与自身的翻转相加，不断重复后判断是否回文。  

# 1140
[1140 Look-and-say Sequence](https://pintia.cn/problem-sets/994805342720868352/problems/994805344490864640)  
输入两个数，按照题目给定的规则进行输出。  
注意string的不同加法操作的时间复杂度。  

## 1152
[1152 Google Recruitment](https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672)  
输入一个字符串S和一个正整数K，在S中寻找K个连续的字符组成的质数，输出最先找到的结果。  
