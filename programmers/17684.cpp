#include <string>
#include <vector>
#include <map>
#include "iostream"
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string, int> dictionary{};
    for (int i = 0; i < alphabet.length(); ++i) {
        dictionary.insert(make_pair(alphabet.substr(i, 1), i + 1));
    }

    vector<int> answer;
    string curr;
    int currIndex;
    for (int i = 0; i < msg.size(); ++i) {
        curr += msg[i];
        if (dictionary.find(curr) != dictionary.end())
        {
            currIndex = dictionary[curr];
            continue;
        }
        else
        {
            dictionary.insert(make_pair(curr, dictionary.size() + 1));
//            dictionary[curr] = dictionary.size();
            curr = msg[i];
            answer.push_back(currIndex);
            currIndex = dictionary[curr];
        }
    }
    answer.push_back(currIndex);
    return answer;
}