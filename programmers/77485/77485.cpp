#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int matrix[rows][columns];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = i * columns + j + 1;
        }
    }

    for (const auto query : queries) {
        int x1, y1, x2, y2;
        x1 = query[0] - 1;
        y1 = query[1] - 1;
        x2 = query[2] - 1;
        y2 = query[3] - 1;

        int count = (x2 - x1 + 1) * 2 + (y2 - y1 + 1) * 2 - 4;
        int direction = 0;
        int r = x1;
        int c = y1;
        int prev = matrix[r][c];
        int next = 0;
        vector<int> tempV{};

        while (count > 0) {

            int newR = r + dx[direction];
            int newC = c + dy[direction];

            if (newR < x1 || newR > x2 || newC < y1 || newC > y2) {
                ++direction;
                continue;
            }

            next = matrix[newR][newC];
            matrix[newR][newC] = prev;
            tempV.push_back(prev);
            prev = next;

            r = newR;
            c = newC;
            --count;
        }

        answer.push_back(*min_element(tempV.begin(), tempV.end()));
    }

    return answer;
}