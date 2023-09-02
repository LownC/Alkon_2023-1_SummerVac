#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
unordered_map<string, int> combination[11]; //<음식이름, 횟수>. 인덱스는 음식의 갯수
int mxCount[11];

void comb(string order, int cnt, string result) {
    if (cnt == order.length()) { //문자 포함시킬지 말지 모두 끝났을 경우
        int num = result.length(); //결과 문자, 즉 코스요리가 몇개의 요리로 구성되어있는지
        combination[num][result]++;
        mxCount[num] = max(mxCount[num], combination[num][result]);
        return;
    }
    // 주어진 문자열의 앞부터 시작해서 포함시키거나 포함시키지 않거나 모든 경우 구하기.
    comb(order, cnt + 1, result + order[cnt]); // 포함시키는 경우
    comb(order, cnt + 1, result); // 포함시키지 않는 경우
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (auto order : orders) {
        sort(order.begin(), order.end());
        comb(order,0,"");
    }

    for (int num : course) {
        for (auto comb : combination[num]) {
            if (comb.second == mxCount[num] && comb.second >= 2) {
                answer.push_back(comb.first);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}