# 1045
[1045 Favorite Color Stripe](https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456)  
题目意思：给定一个整数序列表示一根绳子，不同的数字代表不同的颜色。然后给出想要的颜色序列，使得前面的绳子经过截除、原地缝合之后，变成想要的颜色序列（可以缺少其中某种颜色，但是前后的相对顺序不能混乱）。输出符合要求的最长绳子长度。  
后续的最优解受到前面选择的影响，所以使用动态规划来做，维护一个二维的表格来做。横纵坐标分别代表喜欢的颜色和给定的绳子颜色。  
(动态规划一定要拿给出的示例去画画图，这样容易找到思路)  


