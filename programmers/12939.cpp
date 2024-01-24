#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    istringstream iss(s);
    string strBuffer;
    vector<int> vec;

    while (getline(iss, strBuffer, ' '))
    {
        vec.push_back(stoi(strBuffer));
    }

    sort(vec.begin(), vec.end());

    string min = to_string(vec[0]);
    string max = to_string(vec.back());

    return min + " " + max;
}