// 没做出来，好像是跟卡特兰数有关？

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include <math.h>
using namespace std;
const int maxn=1005;
const int mod=10;

// int m,n;
// long long d[maxn]={0};

// long long dfs(int x)
// {
//     cout << x << endl;
//     if(x<2) return 1;
//     if(d[x]) return d[x];
//     for(int i=0;i<x;i++) {
//         // d[x]=(d[x]+dfs(i)*dfs(x-i-2)%mod)%mod;
//         long long temp = d[x];
//         d[x]=(d[x]+dfs(i)*dfs(x-i-2));
//         cout<< x << " " << i << " " << temp << " " << d[x] << endl;
//     }
//     return d[x];
// }


int Catalan(int n)
{
	if(n <= 1)
		return 1;
 
	int *h = new int [n+1]; //保存临时结果
	h[0] = h[1] = 1;        //h(0)和h(1)
	for(int i = 2; i <= n; i++)    //依次计算h(2),h(3)...h(n)
	{
		h[i] = 0;
		for(int j = 0; j < i; j++) //根据递归式计算 h(i)= h(0)*h(i-1)+h(1)*h(i-2) + ... + h(i-1)h(0)
			h[i] += (h[j] * h[i-1-j]);
	}
	int result = h[n]; //保存结果
	delete [] h;       //注意释放空间
	return result;
}

// long long c[]
long factorial(long number)
{	if(number<=1)
		return 1;
	else 
		return number*factorial(number-1);
}

int combinator(int n,int m)
{	int temp;
	if(n<m)
	{	temp=n;
		n=m;
		m=temp;}
	return factorial(n)/(factorial(m)*factorial(n-m));
}

int main()
{
    // scanf("%d",&n);
    // cout<<dfs(n)<<endl;
    // return 0;
    long long n;
    cin >> n;
    // cout << Catalan(n)<<endl;
    long long ctl = Catalan(n);

    long long all = combinator(2, n) / 2;

    int orgina = ctl;
	int orginb = all;
 
    long long t;
	while(all != 0){
		t = ctl%all;
		ctl = all;
		all = t;
	}


    long long res = ctl % ((long long)pow(10, 9) + 7) / all;
    cout << res;


    return 0;
}