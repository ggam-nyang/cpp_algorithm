#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getSplitIndex(string u) {
    if (u.empty()) return 0;
    int curr = 0;

    for (int i = 0; i < u.length(); ++i) {
        if (u[i] == '(') ++curr;
        else --curr;

        if (curr == 0) return i;
    }

    return -1;
}

bool isBalance(string u) {
    if (getSplitIndex(u) == -1) return false;
    return true;
}

bool isCorrect(string u) {
    vector<char> temp{};

    for (const auto &item: u) {
        if (temp.empty() || item == '(') temp.push_back(item);
        else temp.pop_back();
    }

    return temp.empty();
}

pair<string, string> splitInTwoString(string u) {
    int splitIdx = getSplitIndex(u);
    if (splitIdx == 0 || splitIdx == -1 || splitIdx == u.length() - 1) return make_pair(u, "");

    return make_pair(u.substr(0, splitIdx + 1), u.substr(splitIdx + 1));
}

string changeUString(string u) {
    string temp = u.substr(1, u.length() - 2);
    cout << temp << endl;
    for (auto &item: temp) {
        if (item == '(') item = ')';
        else item = '(';
    }

    return temp;
}

string toCorrectString(string u) {
    if (u.empty() || isCorrect(u)) return u;
    auto temp = splitInTwoString(u);

    cout << "first: " << temp.first << "  second: " << temp.second << endl;
    if (isCorrect(temp.first)) return temp.first + toCorrectString(temp.second);
    return '(' + toCorrectString(temp.second) + ')' + changeUString(temp.first);
}

string solution(string p) {

    return toCorrectString(p);
}