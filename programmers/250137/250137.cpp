#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct BandageInfo {
    int totalTime;
    int recoveryPerSec;
    int additionalRecovery;
};

bool getDamage(int &currHp, int damage) {
    currHp -= damage;

    return currHp <= 0;
}

void getRecovery(int &currHp, int recovery, int maxHp) {
    currHp += recovery;

    currHp = currHp > maxHp ? maxHp : currHp;
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    BandageInfo bi;
    bi.totalTime = bandage[0];
    bi.recoveryPerSec = bandage[1];
    bi.additionalRecovery = bandage[2];

    int currHp = health;
    int currTime = 1;
    int recoveryCount = 0;
    for (const auto &attack: attacks) {
        if (attack[0] != currTime) {
            while (currTime != attack[0]) {
                recoveryCount += 1;
                if (recoveryCount == bi.totalTime) {
                    getRecovery(currHp, bi.recoveryPerSec + bi.additionalRecovery, health);
                    recoveryCount = 0;
                }
                else {
                    getRecovery(currHp, bi.recoveryPerSec, health);
                }
                ++currTime;
            }
        }
        if (getDamage(currHp, attack[1])) return -1;
        recoveryCount = 0;
        ++currTime;
    }

    return currHp <= 0 ? -1 : currHp;
}