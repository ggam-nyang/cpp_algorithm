#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    multimap<string, string> prefixMap;
    multimap<string, string> suffixMap;

    for (const auto &word: words) {
        prefixMap.insert(make_pair(word.substr(0, 1), word));
        suffixMap.insert(make_pair(word.substr(word.length() - 1, 1), word));
    }

    for (const auto &query: queries) {
        if (query[0] != '?') {
            int wildCardIdx = query.find('?');
            string pf = query.substr(0, wildCardIdx);
            auto range = prefixMap.equal_range(pf.substr(0, 1));

            int temp = 0;
            for (auto i = range.first; i != range.second ; ++i) {
                if (i->second.length() != query.length()) continue;
                if (i->second.substr(0, pf.length())== pf) ++temp;
            }

            answer.push_back(temp);
        } else {
            int wildCardIdx = query.rfind('?');
            string sf = query.substr(wildCardIdx + 1, query.length() - (wildCardIdx + 1));
            auto range = suffixMap.equal_range(sf.substr(sf.length() - 1, 1));

            int temp = 0;
            for (auto i = range.first; i != range.second ; ++i) {
                if (i->second.length() < query.length()) continue;
                if (i->second.compare(i->second.length() - sf.length(), sf.length(), sf) == 0) ++temp;
            }

            answer.push_back(temp);
        }
    }

    return answer;
}