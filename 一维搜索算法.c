/*
一维搜索算法
- 沿着一定方向按照一定步长，搜索一个问题里解空间的部分，或者所有可能情况，从而求得问题的解。

回溯
- 搜索算法中一种控制策略，即当搜索方向不正确时退回调整方向。
*/

// 取最大值
// 题目：f(x) = -4x² + 3x + 2  x∈[-1,1]，问x取何值时f(x)取到最大值。

# include <stdio.h>
# include <math.h>
# define m 1000

int main()
{
  double x = -1, xf = -1, step, f, max = -10;
  step = 2.0 / m; // 步长设定

// 循环：遍历区间，当f值大于设定max值，用f值替代max
  int i;
  for(i = 0;i < m;i++){
    f = -4 * pow(x,2) + 3 * x + 2;
    if(f > max){
      max = f;
      xf = x;
    }
    x += step;
  }

  printf("x在%.5f时取到最大值。\n",xf);
  printf("此时f的值为%.5f\n",max);

  return 0;
}

// 求根
// 题目：1 - pow(1+x,-10) = 6.71x  x∈[-1,1]

# include <stdio.h>
# include <math.h>
# define m 10000

int main()
{
  double x = -0.999, step, f;
  step = 2.0 / m;

// 循环：遍历区间，寻找令f几乎等于0时的X取值，直接打印
  int i;
  for(i = 0;i < m;i++){
    f = 1 - pow(1+x,-10) - 6.71 * x;
    if(fabs(f) <= 1e-5){
      printf("此时x的值为：%.6f\n",x);
    }
    x += step;
  }

  printf("结果是：%.10f\n",x);

  return 0;
}
