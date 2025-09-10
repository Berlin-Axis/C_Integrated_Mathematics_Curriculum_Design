/*
  公式迭代法
- 最关键的是构造迭代公式，利用公式反复迭代计算。
*/

// 题目：试用迭代公式 xk+1 = 20 / (pow(x0,2) + 2 * x0 + 10)  x0 = 1 求方程 pow(x,3) + 2 * pow(x,2) + 10 * x -20 = 0 的根，要求准确到1e-5

# include <stdio.h>
# include <math.h>
# define eps 1e-5
# define N 500

int main(){
    int i = 1;
    float x0 = 1, x1;

    do{
        x1 = 20 / (pow(x0,2) + 2 * x0 + 10);
        x0 = x1;  // 更新变量
        i++;
        if(i==N){ // 控制循环次数
            printf("收敛已达最大次数。\n");
            return 1;
        }
    }while(fabs(x0-x1) >= eps);

    printf("解得根为：%.5f.\n",x1);

    return 0;
}
