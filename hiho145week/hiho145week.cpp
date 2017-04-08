#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int const NUM = 1005;
int const INF = 0x7f7f7f7f;
int dp[NUM][NUM];
int a[NUM];

int main() {
	// Q 输入测试数据组数 N 关卡数 M 答题机会数 S 答对一题分数 T 答错一题分数
	int q, n, m, s, t;
	cin >> q;

	while (q--) {
		memset(dp, INF, sizeof(dp));
		cin >> n >> m >> s >> t;
		//输入每关卡所需点数
		for (int i = 1; i <= n; i++) cin >> a[i];
		//方便计算，第0行置0
		for (int i = 0; i <= m; i++) dp[0][i] = 0;
		for (int i = 1; i <= n; i++) {
			//all 无错答通关时所需答对的题数
			int all = (a [i] % s == 0) ? a[i] / s : a[i] / s + 1;
			for (int j = 0; j <= all; j++) {
				//x 答对题数j不同时的答错题数
				int x = a[i] - j * s;
				if (x > 0) x = (x % t == 0) ? x / t : x / t + 1;
				//注意x为负数时需置为0
				else x = 0;
				//DP的意思是：前i关的答对题数 = min{前i-1关答错了k道题的情况下的答对题数 + 第i关的答对题数}
				for (int k = 0; j + x + k <= m; k++) {
					dp[i][j + k + x] = min(dp[i][j + k + x], dp[i - 1][k] + j);
				}
			}
		}
		int ans = INF;
		//得到最后一关的最少答对题数
		for (int i = 0; i <= m; i++) {
			ans = min(ans, dp[n][i]);
		}
		if (ans <= m) cout << ans << endl;
		else cout << "No" << endl;
	}
	return 0;
}