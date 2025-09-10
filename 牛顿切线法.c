/*
  牛顿切线法
- 用于求方程f(x) = 0的根
- 要求f`(x) ≠ 0
- 迭代公式 xk+1 = xk - f(xk) / f`(xk)
*/

// 题目：求方程 pow(x0,3) - 4 * pow(x0,2) + 2 在[0,1]内的实根近似值。

# include <stdio.h>
# include <math.h>
# define eps 5e-6
# define N 100
# define r 0.001

int main(){
    double x0 = 1, x1, f, f1; // 初始值x0需使f(x0)与二阶导同号
    int i;
    do{ 
        f = pow(x0,3) - 4 * pow(x0,2) + 2;
        f1 = ((pow(x0+r,3) - 4 * pow(x0+r,2) + 2) - (pow(x0,3) - 4 * pow(x0,2) + 2)) / r;
        if(fabs(f1) <= eps){
            printf("分母为零。\n");
            break;
        }
        x1 = x0 - f / f1;
        x0 = x1;
        i++;
        if(i == N) break;
        if(x0 >= 1) return 1; // 直接反馈错误
    }while(fabs(f) >= eps);

    printf("等式的根为：%.5f\n",x1);

    return 0;
}
