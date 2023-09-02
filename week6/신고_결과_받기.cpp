#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string,set<string>> report_cnt;
    unordered_map<string,int> id_num;

    for(int i=0; i<id_list.size(); i++){
        id_num.insert({id_list[i],i});
        answer.push_back(0);
    }

    for(auto i : report){
        string s1=i.substr(0,i.find(" ")); 
        string s2=i.substr(i.find(" ")+1);
        report_cnt[s2].insert(s1);
    }
    for(auto it : report_cnt){
        if(it.second.size()>=k){
            for(auto set_it : it.second){
                int idx=id_num[set_it];
                answer[idx]++;
            }
        }
    }

    return answer;
}