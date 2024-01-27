#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct FileName {
    string head;
    int number;
    int idx;
};

void split(FileName& f, string a, int index) {
    bool check = false;
    int checkIdx;
    for (int i = 0; i < a.size(); ++i) {
        if (('0' <= a[i] && a[i] <= '9') && !check) {
            f.head = a.substr(0, i);
            check = true;
            checkIdx = i;
        }
        else if (!('0' <= a[i] && a[i] <= '9') && check){
            f.number = stoi(a.substr(checkIdx, i));
            break;
        }
    }
    f.idx = index;
}

bool compare(FileName a, FileName b) {
    std::for_each(a.head.begin(), a.head.end(), [](auto& c){c = tolower(c);});
    std::for_each(b.head.begin(), b.head.end(), [](auto& c){c = tolower(c);});

    if (a.head != b.head)
        return a.head < b.head;
    else if (a.number != b.number)
        return a.number < b.number;
    else return a.idx < b.idx;
}

vector<string> solution(vector<string> files) {
    vector<FileName> fs(files.size());
    for (int i = 0; i < fs.size(); ++i) {
        split(fs[i], files[i],i);
    }
    sort(fs.begin(), fs.end(), compare);

    vector<string> answer;
    for (int j = 0; j < files.size(); ++j) {
        answer.push_back(files[fs[j].idx]);
    }

    return answer;
}