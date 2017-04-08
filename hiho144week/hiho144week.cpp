#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
//求取最大公因数
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    //n，m读取数字，nCount, mCount分别统计n和m的因数个数，same统计n和m公因数个数
    LL n, m, nCount = 0, mCount = 0, same = 0;
    cin >> n >> m;
    //map存放n的因数
    map<LL, bool> factorMap;
    //找出n因数
    for (LL i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factorMap[i] = true;
            nCount++;
            if (n / i != i) {
                factorMap[n / i] = true;
                nCount++;
            }
        }
    }
    //找出m因数，同时找出公因数
    for (LL i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            if (factorMap[i]) same++;
            mCount++;
            if (m / i != i) {
                if (factorMap[m / i]) same++;
                mCount++;
            }
        }
    }
    LL base = nCount*mCount;
    //计算最大公因数
    LL gcdMax = gcd(base, same);
    cout << base / gcdMax << " " << same / gcdMax;
    return 0;
}