#include <string>
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;

vector<string> split(string str, char delimeter) {
    istringstream iss(str);
    string buffer;
    vector<string> result;

    while (getline(iss, buffer, delimeter)) {
        result.push_back(buffer);
    }
    return result;
}

struct Info {
    int language = 0;
    int isFE = 0;
    int isSenior = 0;
    int isPizza = 0;

    static Info fromStr(vector<string> info) {
        Info temp;
        if (info[0] == "cpp") temp.language = 0;
        else if (info[0] == "java") temp.language = 1;
        else temp.language = 2;

        if (info[1] == "frontend") temp.isFE = 1;
        if (info[2] == "senior") temp.isSenior = 1;
        if (info[3] == "pizza") temp.isPizza = 1;

        return temp;
    }
};

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> scores[3][2][2][2];
    for (const auto &in : info) {
        vector<string> splitInfo = split(in, ' ');
        Info temp = Info::fromStr(splitInfo);
        scores[temp.language][temp.isFE][temp.isSenior][temp.isPizza].push_back(stoi(splitInfo[4]);
    }





    return answer;
}