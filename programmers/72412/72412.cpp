#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Info {
    unsigned int bit;
    int score;
};

ostream &operator<<(ostream &os, const vector<Info> &infos) {
    for (const auto &info: infos) {
        os << bitset<5>(info.bit) << " " << info.score << endl;
    }
    return os;
}

vector<string> split(const string &str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
    return result;
}

unsigned int getBit(bool isCpp, bool isJava, bool isBack, bool isJunior, bool isChicken) {
    unsigned int bit = 0b00000;
    if (isCpp) bit |= 0b10000;
    else if (isJava) bit |= 0b01000;

    if (isBack) bit |= 0b00100;
    if (isJunior) bit |= 0b00010;
    if (isChicken) bit |= 0b00001;

    return bit;
}

pair<unsigned char, int> getInfo(const string &in) {
    vector<string> temp = split(in, ' ');
    bool isCpp = temp[0] == "cpp";
    bool isJava = temp[0] == "java";
    bool isBack = temp[1] == "backend";
    bool isJunior = temp[2] == "junior";
    bool isChicken = temp[3] == "chicken";

    unsigned int bit = getBit(isCpp, isJava, isBack, isJunior, isChicken);
    return make_pair(bit, stoi(temp[4]));
}

pair<unsigned char, int> getInfoFromQuery(const string &query) {
    vector<string> temp = split(query, ' ');
    bool isCpp = temp[0] == "cpp";
    bool isJava = temp[0] == "java";
    bool isBack = temp[2] == "backend";
    bool isJunior = temp[4] == "junior";
    bool isChicken = temp[6] == "chicken";

    unsigned int bit = getBit(isCpp, isJava, isBack, isJunior, isChicken);
    return make_pair(bit, stoi(temp[7]));
}

int countApplicant(const vector<Info> &infos, Info &qInfo) {
    return std::count_if(infos.begin(), infos.end(),
                         [qInfo](Info info) {
                             return (info.bit & qInfo.bit) == qInfo.bit && info.score >= qInfo.score;
                         });
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<Info> infos;
    multimap<unsigned char, int> mm{};

    for (const auto &in: info) {
        mm.insert(getInfo(in));
    }

    for (const auto &q: query) {
        int count = 0;

        auto qString = getInfoFromQuery(q);
        auto range = mm.equal_range(qString.first);
        for (auto iter = range.first; iter != range.second; ++iter) {
            if (iter->second >= qString.second) ++count;
        }

        answer.push_back(count);
    }


    return answer;
}