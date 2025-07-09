题目描述
如题，已知一个数列，你需要进行下面两种操作：
1.	将某区间每一个数加上 kk。
2.	求出某区间每一个数的和。
输入格式
第一行包含两个整数 n,m分别表示该数列数字的个数和操作的总个数。
第二行包含 n个用空格分隔的整数，其中第 i个数字表示数列第 i项的初始值。
接下来 m行每行包含 3 或 4 个整数，表示一个操作，具体如下：
1.	1 x y k：将区间 [x,y] 内每个数加上 k。
2.	2 x y：输出区间 [x,y] 内每个数的和。
输出格式
输出包含若干行整数，即为所有操作 2 的结果。
#include<iostream>
using namespace std;

const int Maxn = 100000 + 50;
int n, m;

int a[Maxn + 2];

struct tree {
	int l, r;
	long long pre, add;
}t[4*Maxn+50];

void build(int p, int l, int r) {
	t[p].l = l;
	t[p].r = r;
	if (l == r) {
		t[p].pre = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	t[p].pre = t[p * 2].pre + t[p * 2 + 1].pre;
}

void spread(int p) {
	if (t[p].add) {
		t[p * 2].pre += t[p].add * (t[p * 2].r - t[p * 2].l + 1);
		t[p * 2 + 1].pre += t[p].add * (t[p * 2 + 1].r - t[p * 2 + 1].l + 1);
		t[p * 2].add += t[p].add;
		t[p * 2 + 1].add += t[p].add;
		t[p].add = 0;
	}
}

void change(int p, int x, int y, int z) {
	if (x <= t[p].l && y >= t[p].r) {
		t[p].pre += (long long)z * (t[p].r - t[p].l + 1);
		t[p].add += z;
		return;
	}
	spread(p);
	int mid = t[p].l + t[p].r >> 1;
	if (x <= mid) 
		change(p * 2, x, y, z);
	if (y > mid)
		change(p * 2 + 1, x, y, z);
	t[p].pre = t[p * 2].pre + t[p * 2 + 1].pre;
}

long long ask(int p, int x, int y) {
	if (x <= t[p].l && y >= t[p].r)
		return t[p].pre;
	spread(p);
	int mid = t[p].l + t[p].r >> 1;
	long long ans = 0;
	if (x <= mid)
		ans += ask(p * 2, x, y);
	if (y > mid)
		ans += ask(p * 2 + 1, x, y);
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);

	for (int i = 1; i <= m; i++) {
		int q, x, y, z;
		cin >> q;
		if (q == 1) {
			cin >> x >> y >> z;
			change(1, x, y, z);
		}
		else {
			cin >> x >> y;
			cout << ask(1, x, y) << endl;
		}
	}
	return 0;
}
