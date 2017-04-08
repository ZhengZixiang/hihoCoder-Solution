#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int const NUM = 1005;
int const INF = 0x7f7f7f7f;
int dp[NUM][NUM];
int a[NUM];

int main() {
	// Q ��������������� N �ؿ��� M ��������� S ���һ����� T ���һ�����
	int q, n, m, s, t;
	cin >> q;

	while (q--) {
		memset(dp, INF, sizeof(dp));
		cin >> n >> m >> s >> t;
		//����ÿ�ؿ��������
		for (int i = 1; i <= n; i++) cin >> a[i];
		//������㣬��0����0
		for (int i = 0; i <= m; i++) dp[0][i] = 0;
		for (int i = 1; i <= n; i++) {
			//all �޴��ͨ��ʱ�����Ե�����
			int all = (a [i] % s == 0) ? a[i] / s : a[i] / s + 1;
			for (int j = 0; j <= all; j++) {
				//x �������j��ͬʱ�Ĵ������
				int x = a[i] - j * s;
				if (x > 0) x = (x % t == 0) ? x / t : x / t + 1;
				//ע��xΪ����ʱ����Ϊ0
				else x = 0;
				//DP����˼�ǣ�ǰi�صĴ������ = min{ǰi-1�ش����k���������µĴ������ + ��i�صĴ������}
				for (int k = 0; j + x + k <= m; k++) {
					dp[i][j + k + x] = min(dp[i][j + k + x], dp[i - 1][k] + j);
				}
			}
		}
		int ans = INF;
		//�õ����һ�ص����ٴ������
		for (int i = 0; i <= m; i++) {
			ans = min(ans, dp[n][i]);
		}
		if (ans <= m) cout << ans << endl;
		else cout << "No" << endl;
	}
	return 0;
}