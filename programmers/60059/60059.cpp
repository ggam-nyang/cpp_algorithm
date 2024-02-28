#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool canOpen(vector<vector<int>> &key, const int N, const int M, vector<pair<int, int>> &lockPoints, vector<vector<int>> &lock);

void printVector(vector<vector<int>> &key) {
    for (const auto &row: key) {
        for (const auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    const int N = key.size();
    const int M = lock.size();
    vector<pair<int, int>> lockPoints;

    // search lockPoints
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < M; ++c) {
            if (lock[r][c] == 0) lockPoints.emplace_back(r, c);
        }
    }
    if (lockPoints.empty()) return true;

    // 열쇠 회전
    vector<vector<int>> temp = key;
    if (canOpen(key, N, M, lockPoints, lock)) return true;

    for (int i = 0; i < 3; ++i) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                temp[c][N - 1 - r] = key[r][c];
            }
        }
//        printVector(temp);

        if (canOpen(temp, N, M, lockPoints, lock)) return true;
        key = temp;
    }

    return false;
}

bool canOpen(vector<vector<int>> &key, const int N, const int M, vector<pair<int, int>> &lockPoints, vector<vector<int>> &lock) {
    bool answer = false;
    for (int r = 1; r < N + M; ++r) {
        for (int c = 1; c < N + M; ++c) {
            pair<int, int> rowRange = make_pair(r - N, r - 1);
            pair<int, int> colRange = make_pair(c - N, c - 1);

            for (const auto &lp: lockPoints) {
//                cout << "row: " << rowRange.first << " " << rowRange.second << endl;
//                cout << "col: " << colRange.first << " " << colRange.second << endl;

                if ((rowRange.first <= lp.first && lp.first <= rowRange.second) && (colRange.first <= lp.second && lp.second <= colRange.second)) {
                    if (key[lp.first - rowRange.first][lp.second - colRange.first] == 1) {
                        answer = true;
                        continue;
                    }
                }
//                cout << lp.first << "  " << lp.second << endl;
                answer = false;
                break;
            }

            // 돌기끼리 부딪히는지 확인하는 로직
            for (int i = rowRange.first; i <= rowRange.second; ++i) {
                for (int j = colRange.first; j <= colRange.second ; ++j) {
                    if (i - rowRange.first < 0 || i - rowRange.first >= N || j - colRange.first < 0 || j - colRange.first >= N) continue;
                    if (i < 0 || i >= M || j < 0 || j >= M) continue;
                    if (key[i - rowRange.first][j - colRange.first] == lock[i][j]) {
                        answer = false;
                    }
                }
            }

            if (answer) return answer;
        }
    }

    return false;
}