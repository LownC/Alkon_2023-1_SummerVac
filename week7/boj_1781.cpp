#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;

priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> problems(N); // deadline,ramen
    for(int i=0; i<N; i++){
        cin >>problems[i].first >> problems[i].second;
    }
    sort(problems.begin(),problems.end());
    for(int i=0; i<N; i++){
        if(pq.size() < problems[i].first){ //데드라인이 모든 문제를 푸는 시간보다도 큰 문제는 무조건 풀 수 있음
            pq.push(problems[i].second);
        }
        else{
            if(pq.top() < problems[i].second){
                pq.pop();
                pq.push(problems[i].second);
            }
        }
    }
    int sum=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}