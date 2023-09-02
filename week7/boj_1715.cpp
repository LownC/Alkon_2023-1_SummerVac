#include <iostream>
#include <queue>

using namespace std;
int N;
int ans;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        int input;
        cin >>input;
        pq.push(input);
    }
    while(pq.size()!=1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        int sum=first+second;
        pq.push(sum);
        ans+=sum;
    }
    cout<<ans;
    return 0;
}