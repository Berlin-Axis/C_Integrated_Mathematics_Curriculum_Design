# include <stdio.h>
# include <time.h>
# include <stdlib.h>

int main()
{
    srand((unsigned int)time(NULL));

    const int total_trials = 100000;
    int success_count = 0;

    int i;
    for(i = 0;i < total_trials;i++)
    {
        int x = rand() % 6 + 1;
        int y = rand() % 6 + 1;

        if(5 * x - 6 * y > 0)
        {
            success_count++;
        }
    }

    double probability = (double)success_count / total_trials;
    printf("模拟次数：%d\n",total_trials);
    printf("满足条件的次数：%d\n",success_count);
    printf("估计概率：%.6f\n",probability);

    return 0;
}
