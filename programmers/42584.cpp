#include <string>
#include <vector>
#include <deque>
#include "iostream"

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<pair<int,int>> stack;

    for (int i = 0; i < prices.size(); ++i) {
        while (!stack.empty() && stack.back().second > prices[i]) {
            pair<int, int> top = stack.back();
            stack.pop_back();
            answer[top.first] = i - top.first;
        }
        stack.push_back(make_pair(i, prices[i]));
    }

    while (!stack.empty()) {
        pair<int, int> top = stack.back();
        stack.pop_back();
        answer[top.first] = prices.size() - 1 - top.first;
    }

    return answer;
}