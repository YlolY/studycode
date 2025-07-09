#include<iostream>
#include<string.h>
using namespace std;


int flag;
void func(int x, int y) {
	if (x == y) {
		flag = 1;
		return;
	}

	if (x % 3 != 0) {
		return;
	}
	
	func(x / 3, y), func(x / 3 * 2, y);

}



int main() {
	int t ;
	cin >> t;
	while (t--) {
		
		int x, y;
		cin >> x >> y;
		if (y > x) {
			cout << "NO" << endl;
		}
		else if (x == y) {
			cout << "YES" << endl;
		}
		else if (x % 3 != 0){
			cout << "NO" << endl;
		}
		else {
			flag = 0;
			func(x, y);
			if (flag) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}
