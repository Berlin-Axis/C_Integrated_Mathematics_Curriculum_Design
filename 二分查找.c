/*
  二分查找算法
- 单调函数中，x1, x2对应的函数值若符号不同，则[x1,x2]区间内存在实根。
- 因此，判断条件是x1 * x2 < 0，才能继续查找。
- 求x1和x2的中点，x0 = (x1 + x2) / 2;
- 求出f(x0).若f(x0)与f(x1)同号，则[x1,x2]替换为[x0,x2];
- 反之，[x1,x2]替换为[x1,x0]。
- 判断f(x0)的绝对值是否小于1e-5,如果不小于，则重复执行求中间点的动作。
- 如果小于，输出x0即可。
  */

// 题目：向量a=(5,-7),b=(-6,-4),求a·b及a、b间的夹角（不用acos函数）

# include <stdio.h>
# include <math.h>
# define PI 3.1415926535

double a[2] = {5,-7};
double b[2] = {-6,-4};

int main(){
    double dot_product = a[0] * b[0] + a[1] * b[1];
    double mod_a = sqrt(pow(a[0],2) + pow(a[1],2));
    double mod_b = sqrt(pow(b[0],2) + pow(b[1],2));
// 计算余弦值公式
    double target_cos = dot_product / (mod_a * mod_b);
    printf("目标余弦值为：%.5f.\n",target_cos);

    double left = 0.0, right = PI;
    double eps = 1e-6;
    double mid, current_cos;
    double f;

    do{
        mid = (left + right) / 2;
        current_cos = cos(mid); // 计算中点cos值
        f = current_cos - target_cos;
        if(f > 0){ // 二分查找
            left = mid;
        }
        else{
            right = mid;
    }
    }while(fabs(f) >= eps); // 判断条件，不要使用fabs(right - left) >= 1e-5, 有可能mid即为根

    double theta_rad = (left + right) / 2;
    double theta_deg = theta_rad * 180.0 /PI;

    printf("向量夹角（弧度）：%.6lf\n",theta_rad);
    printf("向量夹角（角度）：%.6lf\n",theta_deg);

    return 0;
}
