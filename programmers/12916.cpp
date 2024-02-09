#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int pcnt = count(s.begin(), s.end(), 'p');
    int ycnt = count(s.begin(), s.end(), 'y');

    return pcnt == ycnt;
}