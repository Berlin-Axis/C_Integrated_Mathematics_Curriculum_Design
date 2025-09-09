/*
网格搜索算法
- 将搜索区间通过横纵轴切割成一张网，通过遍历横纵坐标搜索网上的每一个点。
*/

// 求最大值
// 题目：r = sqrt(pow(x-5,2) + pow(y-5,2))  z = sin(r) / r  求z的近似最大值及此时(x,y)

# include <stdio.h>
# include <math.h>
# define m 1000

int main(){
  double x, y, r, z, max = -1e9, step;
  double x_min = -10.0, x_max = 10.0;
  double y_min = -10.0, y_max = 10.0;
  double best_x, best_y;
  step = 2.0 / m;
  
  for(x = x_min; x <= x_max; x += step){
    for(y = y_min; y <= y_max; y += step){
      r = sqrt(pow(x-5,2) + pow(y-5,2));
      z = sin(r) / r;
      if(r < 1e-6){
        z = 1.0;
      }
      if(z > max){
        max = z;
        best_x = x;
        best_y = y;
      }
    }
  }

  printf("当(x,y)为(%.5f,%.5f)时，z取到最大值%.5f。\n",best_x,best_y,max);
  
  return 0;
}
