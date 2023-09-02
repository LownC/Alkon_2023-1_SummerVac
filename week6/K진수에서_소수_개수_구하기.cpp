#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>

#define MAX 1001

using namespace std;

vector <int> edge[MAX];
int T, N, K, W;
int in_degree[MAX]; //진입차수
int build_time[MAX];
int dp[MAX];

void topology_sort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			dp[i] = build_time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int j = 0; j < edge[cur].size(); j++) {
			int next = edge[cur][j];
			dp[next] = max(dp[next], dp[cur] + build_time[next]);
			if (--in_degree[next] == 0)
				q.push(next);
		}
	}
	cout << dp[W] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int j = 1; j <= N; j++) {
			cin >> build_time[j];
		}
		for (int j = 0; j < K; j++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			in_degree[b]++; // 진입 차수 저장
		}
		cin >> W;
		topology_sort();

		//배열 초기화
		memset(edge, 0, sizeof(edge));
		memset(in_degree, 0, sizeof(in_degree));
		memset(build_time, 0, sizeof(build_time));
		memset(dp, 0, sizeof(dp));
	}

	return 0;
}