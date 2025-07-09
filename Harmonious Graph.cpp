#include<iostream>
#include<math.h>
using namespace std;
int n, m, num,  ans;
int fa[200010], mx[200010], mn[200010];
bool v[200010];

int Find(int k) {
	if (fa[k] == k) 
		return k;
	return fa[k] = Find(fa[k]);
}

void H(int k1, int k2) {
	int x = Find(k1), y = Find(k2);
	fa[x] = y;
	mn[y] = min(mn[x], mn[y]);
	mx[y] = max(mx[x], mx[y]);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fa[i] = mx[i] = mn[i] = i;
	for (int i = 1; i <= m; i++) {
		int x1, x2;
		cin >> x1 >> x2;
		H(x1, x2);
	}
	for (int i = 1; i <= n; i++) {
		int f = Find(i);
		if (v[f]) 
			continue;
		v[f] = 1;

		for (int j = mn[f] + 1; j < mx[f]; j++) {
			int fj = Find(j);
			if (fj != f) 
				H(fj, f), ans++;
		}
	}

	cout << ans;
	return 0;
}
