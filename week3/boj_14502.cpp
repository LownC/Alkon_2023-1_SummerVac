#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int board[8][8];
int board_copy[8][8];
vector<pair<int, int>> blank;
vector<pair<int, int>> virus;
bool visit[8][8];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void init(int sel1,int sel2,int sel3) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board_copy[i][j] = board[i][j];
			visit[i][j] = false;
		}
	}
	board_copy[blank[sel1].first][blank[sel1].second] = 1;
	board_copy[blank[sel2].first][blank[sel2].second] = 1;
	board_copy[blank[sel3].first][blank[sel3].second] = 1;
}
int bfs() {
	queue<pair<int, int>> q;
	for (auto it : virus) {
		q.push({ it.first,it.second });
	}
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (visit[nx][ny] || board_copy[nx][ny] != 0)
				continue;
			visit[nx][ny] = true;
			board_copy[nx][ny] = 2;
			q.push({ nx,ny });
		}
	}
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board_copy[i][j] == 0)
				safe++;
		}
	}
	return safe;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				blank.push_back({ i, j });
			else if (board[i][j] == 2)
				virus.push_back({ i,j });
		}
	}
	int blank_len = blank.size();
	int answer = 0;
	for (int i = 0; i < blank_len - 2; i++) {
		for (int j = i+1; j < blank_len - 1; j++) {
			for (int k = j+1; k < blank_len; k++) {
				init(i, j, k);
				int retval = bfs();
				answer = max(answer, retval);
			}
		}
	}
	cout << answer;
	return 0;
}