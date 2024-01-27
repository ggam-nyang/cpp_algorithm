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
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//struct fileName {
//    int index;
//    string head;
//    int number;
//};
//
//vector<fileName> v;
//
//bool cmp(const fileName& f1, const fileName& f2){
//    if(f1.head == f2.head){
//        if(f1.number == f2.number){
//            return f1.index < f2.index;
//        }
//        else return f1.number < f2.number;
//    }
//    else return f1.head < f2.head;
//}
//
//vector<string> solution1(vector<string> files) {
//    cout << stoi("123ad2") << endl;
//    vector<string> answer;
//
//    for(int i = 0; i < files.size(); i++){
//        vector<int> idx;
//        for(int j = 0; j < files[i].size(); j++){
//            if('0' <= files[i][j] && files[i][j] <= '9'){
//                idx.push_back(j);
//            }
//        }
//        string head = "";
//        for(int j = 0; j < idx[0]; j++){
//            head += tolower(files[i][j]);
//        }
//        string number = files[i].substr(idx[0], idx.size());
//
//        fileName f;
//        f.index = i;
//        f.head = head;
//        f.number = stoi(number);
//
//        v.push_back(f);
//    }
//    sort(v.begin(), v.end(), cmp);
//    for(int i = 0; i < v.size(); i++){
//        answer.push_back(files[v[i].index]);
//    }
//    return answer;
//}