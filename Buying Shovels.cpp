#include <iostream>
#include<math.h>
using namespace std;

long int t, n, k, i;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n <= k) {
            cout << 1 << endl;
        }
        else {
            long int ans = n;
            for (i = 1; i <=sqrt(n); i++) {
                if (n % i == 0) {
                    if (i <= k) {
                        ans = min(ans, n / i);
                    }
                    if (n / i <= k) {
                        ans = min(ans, i);
                    }

                }
            }
            cout << ans << endl;
        }


    }

    return 0;
}
