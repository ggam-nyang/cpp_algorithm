#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    int stageClearCount[N + 1];
    fill(stageClearCount, stageClearCount + N + 1, 0);
    vector<pair<int, double>> failVector(N);
    vector<int> answer(N);

    for (const auto &item: stages) {
        stageClearCount[item - 1]++;
    }
    for (int i = N; i >= 0; --i) {
        stageClearCount[i - 1] += stageClearCount[i];
    }
    for (int i = 1; i < N + 1; ++i) {
        double failureRate = static_cast<double>(stageClearCount[i - 1] - stageClearCount[i]) / stageClearCount[i - 1];
        if (stageClearCount[i - 1] == 0) failureRate = 0;
        failVector[i - 1] = make_pair(i, failureRate);
    }
    sort(failVector.begin(), failVector.end(), compare);

    for (int i = 0; i < N; ++i) {
        answer[i] = failVector[i].first;
    }

    return answer;
}