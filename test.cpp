#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <list>

using namespace std;

int main() {

    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(4);

    cout << *std::min_element(temp.begin(), temp.end());
}