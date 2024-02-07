#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> wordSet;
    vector<int> answer;
    int currNum = 1;
    char currChar = words[0][0];

    for (int i = 0; i < words.size(); ++i) {
        if (wordSet.find(words[i]) == wordSet.end() && currChar == words[i][0]) {
            wordSet.insert(words[i]);
            currChar = *(words[i].end() - 1);
        } else {
//            answer.push_back(currNum);
//            answer.push_back(i / n + 1);
//            return answer;
            return {currNum, (i / n + 1)};
        }
        ++currNum;
        if (currNum > n) currNum = 1;
    }

    return {0, 0};
}