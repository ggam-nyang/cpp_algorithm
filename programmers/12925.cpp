#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    if (s[0] == '-') return -stoi(s.substr(1));
    return stoi(s);
}