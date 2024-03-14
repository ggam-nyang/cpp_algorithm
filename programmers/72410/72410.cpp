#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

ostream& operator<<(ostream &os, const list<char> &l) {
    for (const auto &c: l) {
        os << c << " ";
    }
    return os;
}

string solution(string new_id) {
    list<char> answerV;

    bool isDot = false;
    std::transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    for (const auto &c: new_id) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.') {
            if (c == '.') {
                if (isDot) {
                    continue;
                }
                isDot = true;
            } else {
                isDot = false;
            }
            answerV.push_back(c);
        }
    }

    if (*answerV.begin() == '.') answerV.pop_front();
    if (answerV.empty()) answerV.push_back('a');
    if (*answerV.rbegin() == '.') answerV.pop_back();

    if (answerV.size() >= 16) {
        answerV.resize(15);
        if (*answerV.rbegin() == '.') answerV.pop_back();
    }

    while (answerV.size() < 3) {
        answerV.push_back(answerV.back());
    }

    return string(answerV.begin(), answerV.end());
}