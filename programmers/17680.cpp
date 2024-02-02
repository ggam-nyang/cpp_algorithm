#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    set<string> cache{};
    for (const auto &item: cities) {
        if (cache.find(item) != cache.end()) {
            ++answer;
            cache.erase(item);
            cache.insert(item);
            continue;
        }

        if (cache.size() >= cacheSize) {
            cache.erase(cache.begin());
        }
        cache.insert(item);
        answer += 5;
    }

    return answer;
}