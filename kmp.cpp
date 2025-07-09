// 题目描述
// 给出两个字符串 s1s1​ 和 s2s2​，若 s1s1​ 的区间 [l,r][l,r] 子串与 s2s2​ 完全相同，则称 s2s2​ 在 s1s1​ 中出现了，其出现位置为 ll。
// 现在请你求出 s2s2​ 在 s1s1​ 中所有出现的位置。
// 定义一个字符串 ss 的 border 为 ss 的一个非 ss 本身的子串 tt，满足 tt 既是 ss 的前缀，又是 ss 的后缀。
// 对于 s2s2​，你还需要求出对于其每个前缀 s′′ 的最长 border t′t′ 的长度。
// 输入格式
// 第一行为一个字符串，即为 s1s1​。
// 第二行为一个字符串，即为 s2s2​。
// 输出格式
// 首先输出若干行，每行一个整数，按从小到大的顺序输出 s2s2​ 在 s1s1​ 中出现的位置。
// 最后一行输出 ∣s2∣∣s2​∣ 个整数，第 ii 个整数表示 s2s2​ 的长度为 ii 的前缀的最长 border 长度。



#include<iostream>
using namespace std;

int pi[2000050], n;
string str1, str2;

int main() {
	cin >> str1;
	cin >> str2;
	string c = str2 + '#' + str1;
	n = c.length();
	int x = str2.length();
	for (int i = 1; i < n; i++) {
		int len = pi[i - 1];
		while (len&&c[len] != c[i]) {
			len = pi[len - 1];
		}
		if (c[len] == c[i]) {
			pi[i] = len + 1;
		}
		if (pi[i] == x) {
			cout << i - 2 * x + 1 << endl;
		}			
	}
	for (int i = 0; i < x; i++) {
		cout << pi[i] << " ";
	}
	return 0;
}

