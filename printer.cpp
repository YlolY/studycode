// SUA程序设计竞赛题目设置团队的评委正在为即将到来的2024年CCPC山东邀请赛和CCPC山东省大学生程序设计竞赛打印题目集。
// 打印店里有nn台打印机。第ii台打印机每titi秒可以生产一份题目集。然而，每当第ii台打印机生产了lili份后，它必须停止wiwi秒以避免过热。也就是说，第ii台打印机将重复以下工作安排：连续工作ti×liti×li秒，然后停止wiwi秒。
// 评委将同时使用所有打印机。计算生产至少kk份题目集所需的最少秒数。
// 输入
// 有多个测试用例。输入的第一行是一个整数TT（1≤T≤1001≤T≤100），表示测试用例的数量。对于每个测试用例：
// 第一行包含两个整数nn和kk（1≤n≤1001≤n≤100，1≤k≤1091≤k≤109），表示打印机的数量和所需的份数。
// 接下来的nn行中，第ii行包含三个整数titi、lili和wiwi（1≤ti,li,wi≤1091≤ti,li,wi≤109）。它们的含义如上所述。
// 输出
// 对于每个测试用例，输出一行包含一个整数，表示所需的最少秒数
#include<iostream>
#include<math.h>
using namespace std;
long long T, n, m;
long long worked;
long long l, r, mid;
long long times, num;
struct printer {
    long long t, l, w;
}per[105];

bool check(long long mid) {
    worked = 0;
    for (long long i = 1; i <= n; i++) {
        if (per[i].t * per[i].l >= mid) {
            worked += (mid / per[i].t);
        }
        else {
            times = per[i].t * per[i].l + per[i].w;
            num = (mid / times);
            worked += num * per[i].l + ((min((per[i].t * per[i].l), (mid % times))) / per[i].t);
        }
        if (worked >= m)
            return true;

    }
    return false;


}
int main() {
    cin >> T;
    for (long long j = 1; j <= T; j++) {
        cin >> n >> m;
        for (long long i = 1; i <= n; i++) {
            cin >> per[i].t >> per[i].l >> per[i].w;
        }
        l = 0;
        r =8e18 ;
        while (l  < r) {
            mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
    return 0;
}
