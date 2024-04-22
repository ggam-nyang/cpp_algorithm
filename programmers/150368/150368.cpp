#include <string>
#include <vector>
#include <iostream>

using namespace std;

int discout[] = {10, 20, 30, 40};
vector<int> answer = {0, 0};

void calculate(vector<int> sale, vector<vector<int>>& users, vector<int>& emoticons) {
    int plus = 0;
    int totalPrice = 0;
    for (const auto &user: users) {
        int userSale = user[0];
        int userPrice = user[1];
        int price = 0;

        for (int i = 0; i < emoticons.size(); ++i) {
            if (userSale > sale[i]) continue;
            price += emoticons[i] / 100 * (100 - sale[i]);
        }

        if (price >= userPrice) ++plus;
        else totalPrice += price;
    }

    if (answer[0] < plus) {
        answer[0] = plus;
        answer[1] = totalPrice;
    } else if (answer[0] == plus) {
        if (answer[1] < totalPrice) answer[1] = totalPrice;
    }
}

void dfs(vector<int> sale, vector<vector<int>>& users, vector<int>& emoticons) {
    if (sale.size() == emoticons.size()) {
        calculate(sale, users, emoticons);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        sale.push_back(discout[i]);
        dfs(sale, users, emoticons);
        sale.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> sale;
    dfs(sale, users, emoticons);

    return answer;
}