#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL)); // 初始化随机数种子
    int trials = 100000;         // 试验次数（越多越接近理论值）
    double total_games = 0;      // 所有试验的总局数之和

    for (int t = 0; t < trials; t++) {
        int games = 5; // 先玩5局

        // 模拟第5局是否赢：生成[0,1)随机数，<2/3则为“赢”
        double rand_num = (double)rand() / RAND_MAX;
        int fifth_game_win = (rand_num < 2.0 / 3);

        if (fifth_game_win) {
            // 第5局赢了，继续玩直到输一局（模拟几何分布）
            int continue_games = 0;
            while (1) {
                rand_num = (double)rand() / RAND_MAX;
                if (rand_num < 1.0 / 3) { // 输了，停止后续游戏
                    break;
                } else { // 赢了，继续玩，后续局数+1
                    continue_games++;
                }
            }
            games += continue_games; // 总局数 = 前5局 + 后续局数
        }

        total_games += games; // 累加本次试验的总局数
    }

    // 计算并输出期望（总局长 / 试验次数）
    double expected = total_games / trials;
    printf("总局数的期望值近似为：%.6f（理论值为7）\n", expected);

    return 0;
}
