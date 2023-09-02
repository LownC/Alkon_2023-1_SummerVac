#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
queue<int> q;
map<int, int> dist; //<퍼즐 상태 , 퍼즐 이동 횟수>
string s;
const int dx[] = { -1,0,1,0, }, dy[] = { 0,-1,0,1 };
void bfs() {
	while (!q.empty()) {
		int d = q.front();
		q.pop();
		if (d == 123456789) {
			cout << dist[d] << '\n';
			return;
		}
		string s = to_string(d);
		int k = s.find('9');
		int x = k / 3, y = k % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i]; //바꿀 숫자의 좌표 계산
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
				continue;
			int nk = nx * 3 + ny; // 바꿀 숫자의 string에서의 index
			string ns = s;
			swap(ns[k], ns[nk]); // 바꿀 숫자와 빈칸 swap
			int nd = stoi(ns);
			if (!dist[nd]) { // not visited before
				dist[nd] = dist[d] + 1;
				q.push(nd);
			}
		}
	}
	cout << "-1\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m = 0;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		if (!n)
			n = 9;
		m = m * 10 + n;
	} 
	q.push(m); //처음 상태를 큐에 push
	bfs();
	return 0;
}