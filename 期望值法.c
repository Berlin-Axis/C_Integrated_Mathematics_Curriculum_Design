/*
  期望值法
- 根据每一可行方案能获得的收益的概率，计算每一可行方案所能获得收益的数学期望值。
*/

# include <stdio.h>

int main(){
    double hope[4] = {0.2, 0.5, 0.2, 0.1}; // 期望
    double P[4][4] = {{40, 70, 30, 35},
                    {95, 75, 65, 40},
                    {80, 45, 90, 35},
                    {60, 50, 65, 45}}; // 每一方案和四种天气状态结合所对应的收益
    double result[4];

    int i,j;
    for(i = 0; i < 4;i++){
        result[i] = 0; // 初始化避免干扰
        for(j = 0; j < 4;j++){
            result[i] += hope[j] * P[i][j];
        }
    }

    double max = 0;
    int k = 0;
    for(i = 0; i < 4; i++){
        if(result[i] > max){
            max = result[i];
            k = i;
        }
    }

    printf("最优方案为%d,收益期望值为%.2f.\n",k+1,max);

    return 0;
}
