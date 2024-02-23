#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string, int> yearningMap;
    vector<int> answer;
    for (int i = 0; i < name.size(); ++i) {
        yearningMap[name[i]] = yearning[i];
    }
    for (const auto &p: photo) {
        int temp = 0;
        for (const auto &person: p) {
            temp += yearningMap[person];
        }
        answer.push_back(temp);
    }

    return answer;
}