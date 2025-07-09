// •	给定 n个数的序列 aa。mm 次操作，操作有两种：
// 1.	求 ∑i=lra。
// 2.	把 al∼ar异或上 x。
// •	1≤n≤10e5，1≤m≤5×10e4，0≤ai≤10e6，1≤x≤10e6。

#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int n, opt, x, y, z, m, a[N], l;
long long ans;

int read()
{
	int sum = 0; 
	char ch = getchar();
	while (ch < '0' || ch>'9') 
		ch = getchar();
	while (ch >= '0' && ch <= '9')
	{
		sum = sum * 10 + ch - '0';
		ch = getchar();
	}
	return sum;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	m = read();
	while (m--) {
		opt = read(); x = read(); y = read();
		if (opt == 1) {
			ans = 0;
			for (int i = x; i <= y; i += 7)
				ans += a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] + a[i + 5] + a[i + 6], l = i;
			for (int i = l; i <= l + 6; i++)
				if (i > y) 
					ans -= a[i];
			cout << ans<<endl;
		}
		else {
			z = read();
			for (int i = x; i <= y; i += 7)
			{
				a[i] ^= z;
				a[i + 1] ^= z;
				a[i + 2] ^= z;
				a[i + 3] ^= z;
				a[i + 4] ^= z;
				a[i + 5] ^= z;
				a[i + 6] ^= z;
				l = i;
			}
			for (int i = l; i <= l + 6; i++)
				if (i > y) 
					a[i] ^= z;

		}
	}


	return 0;
}
