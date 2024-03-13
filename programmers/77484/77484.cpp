#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int zero_count = 0;
    int match_count = 0;

    for (const auto &lotto_num: lottos) {
        if (lotto_num == 0) {
            ++zero_count;
            continue;
        }

        for (const auto &win_num: win_nums) {
            if (win_num == lotto_num) ++match_count;
        }
    }

    int max_rank = 7 - (zero_count + match_count) > 6 ? 6 : 7 - (zero_count + match_count);
    int min_rank = 7 - match_count > 6 ? 6 : 7 - match_count;

    return vector<int> { max_rank, min_rank };
}