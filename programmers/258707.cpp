#include <string>
#include <vector>
#include <deque>
#include <list>
using namespace std;


void startGame(const vector<int> &cards, list<int> &hands, int &currentIdx);
void draw(const vector<int> &cards, list<int> &hands, int &currentIdx, int drawCount);

int solution(int coin, vector<int> cards) {
    list<int> hands;
    int currentIdx = 0;
    startGame(cards, hands, currentIdx);

    for (int i = 0; i < 3; ++i) {
        draw(cards, hands, currentIdx, i);
    }






    int answer = 0;
    return answer;
}

void startGame(const vector<int> &cards, list<int> &hands, int &currentIdx) {
    draw(cards, hands, currentIdx, cards.size() / 3);
}

void draw(const vector<int> &cards, list<int> &hands, int &currentIdx, int drawCount = 2) {
    if (currentIdx + drawCount > cards.size()) {
        drawCount = cards.size() - currentIdx;
    }

    for (; currentIdx < drawCount; ++currentIdx) {
        hands.push_back(cards[currentIdx]);
    }
}
