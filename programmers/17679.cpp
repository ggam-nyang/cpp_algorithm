#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

// 오른, 아래, 우하
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
set<pair<int, int>> boomSet;
int boomCnt = 0;

void boomBlocks(vector<string> &board, int m, int n) {
  for (int x = 0; x < m - 1; ++x) {
    for (int y = 0; y < n - 1; ++y) {
      if (board[x][y] != ' ') {
        bool isBoom = true;
        for (int i = 0; i < 3; ++i) {
          int newX = x + dx[i];
          int newY = y + dy[i];

          if ((0 <= newX && newX < m) && (0 <= newY && newY < n) && board[x][y] == board[newX][newY]) {
            continue;
          } else {
            isBoom = false;
            break;
          }
        }

        if (isBoom) {
          boomSet.insert(make_pair(x, y));
          for (int i = 0; i < 3; ++i) { boomSet.insert(make_pair(x + dx[i], y + dy[i])); }
        }
      }
    }
  }
}

int solution(int m, int n, vector<string> board) {
  boomBlocks(board, m, n);
  while (!boomSet.empty()) {
    for (const auto &item : boomSet) {
      int x = item.first;
      int y = item.second;
      board[x][y] = ' ';
      ++boomCnt;
    }
    boomSet.clear();

    for (int x = 1; x < m; ++x) {
      for (int y = 0; y < n; ++y) {
        if (board[x][y] == ' ') {
          for (int i = x; i > 0; --i) {
            board[i][y] = board[i - 1][y];
          }
          board[0][y] = ' ';
        }
      }
    }
    boomBlocks(board, m, n);
  }

  return boomCnt;
}