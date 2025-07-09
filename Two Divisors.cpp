#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;

long int t, a, b;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        long int y = gcd(a, b);
        a /= y, b /= y;
        if (a == 1)a = b;
        cout << a * b * y << endl;
    }

    return 0;
}
