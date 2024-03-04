#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 1000;
    int len = s.length();
    string top;
    int topCount = 1;

    if (len == 1) return 1;
    for (int n = 0; n < len / 2; ++n) {
        string ans;
        top = s.substr(0, n + 1);
        for (int i = n + 1; i < len - n; i += n + 1) {
            string temp = s.substr(i, n + 1);
            if (top == temp) {
                ++topCount;
                continue;
            }

            topCount == 1 ? ans.append(top) : ans.append(to_string(topCount) + top);
            top = temp;
            topCount = 1;
        }
        topCount == 1 ? ans.append(top) : ans.append(to_string(topCount) + top);
        ans.append(s.substr(len - len % (n + 1)));
        answer = answer < ans.length() ? answer : ans.length();

        top.clear();
        topCount = 1;
    }

    return answer;
}