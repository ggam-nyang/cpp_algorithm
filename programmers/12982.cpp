#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    std::sort(d.begin(), d.end());
    for (const auto &item: d) {
        budget -= item;
        if (budget < 0) break;
        ++answer;
    }

    return answer;
}