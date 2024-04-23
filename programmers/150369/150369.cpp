#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    while (!deliveries.empty() && deliveries.back() == 0) {
        if (deliveries.back() == 0) deliveries.pop_back();
    }

    while (!pickups.empty() && pickups.back() == 0) {
        if (pickups.back() == 0) pickups.pop_back();
    }

    while (!deliveries.empty() || !pickups.empty()) {
        int remainDeliver = cap;
        int remainPickup = cap;

        answer += max(deliveries.size(), pickups.size()) * 2;
        while (remainDeliver > 0 && !deliveries.empty()) {
            if (remainDeliver - deliveries.back() >= 0) {
                remainDeliver -= deliveries.back();
                deliveries.pop_back();
            } else {
                deliveries.back() -= remainDeliver;
                remainDeliver = 0;
            }

            while (!deliveries.empty() && deliveries.back() == 0) {
                if (deliveries.back() == 0) deliveries.pop_back();
            }
        }

        while (remainPickup > 0 && !pickups.empty()) {
            if (remainPickup - pickups.back() >= 0) {
                remainPickup -= pickups.back();
                pickups.pop_back();
            } else {
                pickups.back() -= remainPickup;
                remainPickup = 0;
            }

            while (!pickups.empty() && pickups.back() == 0) {
                if (pickups.back() == 0) pickups.pop_back();
            }
        }
    }

    return answer;
}