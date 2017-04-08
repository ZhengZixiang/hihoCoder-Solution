#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
//��ȡ�������
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    //n��m��ȡ���֣�nCount, mCount�ֱ�ͳ��n��m������������sameͳ��n��m����������
    LL n, m, nCount = 0, mCount = 0, same = 0;
    cin >> n >> m;
    //map���n������
    map<LL, bool> factorMap;
    //�ҳ�n����
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
    //�ҳ�m������ͬʱ�ҳ�������
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
    //�����������
    LL gcdMax = gcd(base, same);
    cout << base / gcdMax << " " << same / gcdMax;
    return 0;
}