#include<iostream>
using namespace std;
const int N = 500000;

struct tree {
	int lsum, rsum, mx, sum;
}t[N << 2 + 5];

int n, m;
int a[N + 5];

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}


tree operator +(const tree& a, const tree& b) {
	tree c;
	c.lsum = max(a.lsum, a.sum + b.lsum);
	c.rsum = max(b.rsum, b.sum + a.rsum);
	c.sum = a.sum + b.sum;
	c.mx = max(a.mx, max(b.mx, a.rsum + b.lsum));
	return c;
}

void spread(int k) {
	t[k] = t[k << 1] + t[(k << 1) | 1];
}

void change(int k, int l, int r, int pos, int val) {
	if (l == r) {
		t[k].lsum = t[k].rsum = t[k].mx = t[k].sum = val;
		return;
	}
	if (pos <= ((l + r) >> 1))
		change(k << 1, l, ((l + r) >> 1), pos, val);
	else
		change((k << 1) | 1, ((l + r) >> 1) + 1, r, pos, val);
	spread(k);
}

tree ask(int k, int l, int r, int x, int y) {
	if (l == x && r == y)
		return t[k];
	if (y <= ((l + r) >> 1))
		return ask(k << 1, l, ((l + r) >> 1), x, y);
	else if (x > ((l + r) >> 1))
		return ask((k << 1) | 1, ((l + r) >> 1) + 1, r, x, y);
	else {
		tree temp1 = ask(k << 1, l, ((l + r) >> 1), x, ((l + r) >> 1));
		tree temp2 = ask((k << 1) | 1, ((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, y);
		return temp1 + temp2;
	}
}

void build(int p, int l, int r) {
	if (l == r) {
		t[p].sum = t[p].lsum = t[p].rsum = t[p].mx = a[l];
		return;
	}
	build(p << 1, l, ((l + r) >> 1)); build((p << 1)|1,  ((l + r) >> 1)+1,r);
	spread(p);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	m = read();
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int op, x, y;
		op = read(), x = read(), y = read();
		if (op == 1) {
			if (x > y)
				swap(x, y);
			cout<<ask(1, 1, n, x, y).mx<<endl;
		}
		if (op == 0)
			change(1, 1, n, x, y);
	}
	return 0;
}
