#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool is_balanced(string p) {
    if (p == "")
        return false;
    int chk = 0;
    for (auto i : p) {
        if (i == '(')
            chk++;
        else if (i == ')')
            chk--;
    }
    if (chk == 0)
        return true;
    else
        return false;
}

bool is_correct(string p) {
    stack <char> s;
    if (p == "")
        return false;
    for (auto i : p) {
        if (i == '(')
            s.push(i);
        else if (i == ')') {
            if (s.empty())
                return false;
            s.pop();
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}


string solution(string p) {
    if (p == "" || is_correct(p))
        return p;
    string u = "";
    string v = "";
    string answer = "";
    int i = 0;
    
    while (!is_balanced(p.substr(0, i))) {
        i++;
    }
    u = p.substr(0, i);
    v = p.substr(i);
    if (is_correct(u))
        answer = u + solution(v);
    else {
        answer = '(' + solution(v) + ')';
        for (int j = 1; j < u.length()-1; j++) {
            answer += u[j] == '(' ? ')' : '(';
        }   
    }
    return answer;
}