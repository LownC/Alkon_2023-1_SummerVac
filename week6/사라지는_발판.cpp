#include <vector>

using namespace std;

int N,M;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

bool in_range(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < M;
}

bool is_finished(vector<vector<int>> board, int y, int x){
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(in_range(ny,nx) && board[ny][nx])
            return false;
    }
    return true;
}


pair<bool,int> solve(vector<vector<int>> board, int y1, int x1, int y2, int x2){
    if(is_finished(board,y1,x1))
        return {false,0};
    pair<bool,int> ret={false,0};

    if(board[y1][x1]){
        int minT=1e9;
        int maxT=0;
        for(int d=0; d<4; d++){
            int ny=y1+dy[d];
            int nx=x1+dx[d]; 
            if(!in_range(ny,nx) || !board[ny][nx]) // 범위를 벗어나거나, 발판이 없으면 next
                continue;
            board[y1][x1]=0;
            auto [win,move]=solve(board,y2,x2,ny,nx); //재귀를 이용한 DFS, 상대방 차례
            board[y1][x1]=1;
            if(!win){ //상대가 질 경우 => 최소의 움직임으로 플레이
                ret.first=true;
                minT=min(minT,move);
            }
            else if(!ret.first){ //내가 질 경우 => 최대 움직임으로 플레이
                maxT=max(maxT,move);
            }
        }
        ret.second=ret.first ? minT+1 : maxT+1; //내가 이겼으면 minT+1, 상대가 이겼으면 maxT+1
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N=board.size(), M=board[0].size();
    return solve(board,aloc[0],aloc[1],bloc[0],bloc[1]).second;
}