#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct Record {
    string order;
    string id;
    string nickName;

    static Record fromVector(vector<string> v) {
        Record temp;
        temp.order = v[0];
        temp.id = v[1];
        if (v[0] == "Leave") return temp;

        temp.nickName = v[2];
        return temp;
    }
};


Record split(const string &str, char Delimiter) {
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return Record::fromVector(result);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<Record> tempAnswer;
    map<string, string> idMap;

    for (const auto &rec: record) {
        tempAnswer.push_back(split(rec, ' '));
    }

    for (const Record &rec: tempAnswer) {
        if (rec.order == "Leave") {
            continue;
        }
        idMap[rec.id] = rec.nickName;
    }
    for (const Record &rec: tempAnswer) {
        if (rec.order == "Enter") {
            answer.push_back(idMap[rec.id] + "님이 들어왔습니다.");
        } else if (rec.order == "Leave") {
            answer.push_back(idMap[rec.id] + "님이 나갔습니다.");
        }
    }

    return answer;
}