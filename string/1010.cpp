#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

//将r进制的str转换成10进制输出
// long long trans(string str, long long r)
// {
// 	int len = str.size();
// 	long long res = 0;
// 	for(int i=0;i<len;i++){
// 		res *= r;
// 		if(str[i]<='9' && str[i]>='0')
// 			res = res + str[i] - '0';
// 		else if(str[i]<='z' && str[i]>='a'){
// 			res = res + str[i] - 'a' + 10;
// 		}
// 	}
// 	return res;
// }
long long trans(string str,int r){
    long long sum = 0;
    int index = 0;
    int per_digit = 0;
    for(auto t = str.rbegin();t!=str.rend();t++){
        per_digit = isdigit(*t)? *t - '0':*t - 'a' + 10;
        sum+=per_digit*pow(r,index++);
    }
    return sum;
}

int find_min_r(string str){
	int len = str.size();
	int res = 0;
	int tmp = 0;
	for(int i=0;i<len;i++){
		if(str[i]<='9' && str[i]>='0'){
			tmp = str[i] - '0';
		}
		else if(str[i]<='z' && str[i]>='a'){
			tmp = str[i] - 'a' + 10;
		}
		if(tmp > res){
			res = tmp;
		}
	}
	// if(res < 1)
	// 	res = 1;
	return res+1;
}

int main()
{
	// string a = "zy";
	// cout << trans(a, 100) << endl;
	// cout << trans(a, 200) << endl;
	// cout << trans(a, 1000) << endl;
	string N1, N2;
	int tag;
	long long radix;
	cin >> N1 >> N2 >> tag >> radix;
	long long res1, res2;
	string tmp;
	//!!!!!!!!!!!!!!!!!!!!
	//卧槽题目没看清，自以为tag是1和0，原来tag值是1和2！！！
	if(tag==1){
		res1 = trans(N1, radix);
		tmp = N2;
	}
	else{
		res1 = trans(N2, radix);
		tmp = N1;
	}
	//循环遍历太蠢了，可以用二分法
	char it = *max_element(tmp.begin(),tmp.end());
	long long r_min = (isdigit(it)?it - '0':it - 'a' + 10) + 1;
	//long long r_min = (long long)find_min_r(tmp);
	//cout << r_min << endl;
	long long r_max = res1;
	//cout << r_max << endl;
	//防止例2这种情况
	if(r_max < r_min){
		r_max = r_min;
	}
	long long r;
	long long out = -1;

	//最大边界问题
	// res2 = trans(tmp, r_max);
	// if(res2 == res1)
	// 	out = r_max;

	//cout << r_min << "," << r << "," << r_max << endl;
	//这里二分法使用有问题
	// do{
	// 	r = (r_min + r_max)/2;
	// 	res2 = trans(tmp, r);
	// 	if(res2 == res1){
	// 		out = r;
	// 		//r_max = r - 1;
	// 		break;
	// 	}
	// 	else if(res2 > res1 || res2<0){
	// 		r_max = r-1;
	// 	}
	// 	else{
	// 		r_min = r+1;
	// 	}
	// 	// else if(res2 < res1 && res2>=0){
	// 	// 	r_min = r + 1;
	// 	// }
	// 	// else{
	// 	// 	r_max = r - 1;
	// 	// }
	// 	//cout << r_min << "," << r << "," << r_max << endl;
	// }while(r_min <= r_max);
	while(r_min <= r_max)
	{
		r = (r_min + r_max)/2;
		res2 = trans(tmp, r);
		// if(res2 == res1){
		// 	out = r;
		// 	//r_max = r - 1;
		// 	break;
		// }
		// else if(res2 > res1 || res2<0){
		// 	r_max = r-1;
		// }
		// else{
		// 	r_min = r+1;
		// }
		if(res2 > res1 || res2 <0){
			r_max = r -1;
		}
		else if(res2 < res1){
			r_min = r + 1;
		}
		else{
			out = r;
			break;
		}
	}


	if(out!=-1){
		cout << out << endl;
	}
	else{
		cout << "Impossible" << endl;
	}
	return 0;
}