/*
  牛顿迭代法
- 基本思想：在pow(x,k)邻域内用泰勒二阶展开函数g(x)来近似替代原目标函数f(x)，并将该函数的极小点作为对目标函数求优的下一个迭代点pow(x,k+1)。多次迭代后使之逼近目标函数f(x)的极小点。
- 公式：xk+1 = xk - g`(xk) / g``(xk)
*/

// 题目：给定函数 pow(x,4) - 4 * pow(x,3) - 6 * pow(x,2) - 16 * x + 4，初始值为3，控制误差0.001，使用牛顿迭代法求其极值点。

# include <stdio.h>
# include <math.h>
# define eps 0.001
# define N 100
# define r 0.001

double func(double x){
    return pow(x,4) - 4 * pow(x,3) - 6 * pow(x,2) - 16 * x + 4;
}

int main(){

    double x0 = 3, x1, f, f1, f2;
    int i = 0;
    do{
        f = func(x0);
        f1 = (func(x0+r) - f) / r;
        f2 = (func(x0+r) - 2 * f + func(x0-r)) / pow(r,2);
        if(fabs(f2) <= eps){
            printf("分母为0。\n");
            return 1;
        }
        x1 = x0 - f1 / f2;
        x0 = x1;
        i++;
        if(i >=  N){
            printf("超过迭代次数。\n");
            break;
        }
    }while(fabs(f1) > eps);

    printf("极值点为：%.5f",x1);

    return 0;
}
