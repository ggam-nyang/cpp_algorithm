#include <string>
#include <vector>
#include "iostream"

using namespace std;

int solution(vector<int> order) {
    vector<int> main{};
    vector<int> sub{};
    int i = 0;
    for (int num = 1; num <= order.size(); ++num) {
        if (order[i] == num) {
            main.push_back(num);
            i++;
            continue;
        }

        while (!sub.empty() && sub.back() == order[i]) {
            main.push_back(order[i]);
            i++;
            sub.pop_back();
        }
        sub.push_back(num);
    }
    while (!sub.empty() && sub.back() == order[i]) {
        main.push_back(sub.back());
        i++;
        sub.pop_back();
    }

    return main.size();
}