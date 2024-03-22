#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string, map<string, int>> giveMap;
    map<string, int> giftIdxMap;
    map<string, int> giftMap;

    for (const auto gift : gifts) {
        int splitIdx = gift.find(' ');
        string giver = gift.substr(0, splitIdx);
        string receiver = gift.substr(splitIdx + 1);

        giveMap[giver][receiver] += 1;
        ++giftIdxMap[giver];
        --giftIdxMap[receiver];
    }

    for (const auto &giver : friends) {
        for (const auto &receiver : friends) {
            if (giver == receiver) continue;

            if (giveMap[giver][receiver] > giveMap[receiver][giver]) ++giftMap[giver];
            else if (giveMap[giver][receiver] < giveMap[receiver][giver]) ++giftMap[receiver];
            else {
                if (giftIdxMap[giver] > giftIdxMap[receiver]) ++giftMap[giver];
                else if (giftIdxMap[giver] < giftIdxMap[receiver]) ++giftMap[receiver];
            }
        }
    }

    int answer = 0;
    for (const auto &it : giftMap) {
        if (answer < it.second / 2) answer = it.second / 2;
    }
    return answer;
}