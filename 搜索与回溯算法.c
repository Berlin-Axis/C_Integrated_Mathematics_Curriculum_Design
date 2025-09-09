// 点到平面的投影
// 题目：求P(x0,y0,z0)关于平面x1+x2+x3=0的距离和P关于该平面的投影点A的坐标，假设P(x0,y0,z0)=(3,-2,6)

# include <stdio.h>
# include <math.h>

double P[3] = {3,-2,6}; // P点坐标
double plane[4] = {1,1,1,0}; // 平面参数

double dis(double E[3]) // 计算空间上一点到平面的距离
{
    double nu,de;
    nu = fabs(plane[0] * P[0] + plane[1] * P[1] + plane[2] * P[2] + plane[3]);
    de = sqrt(pow(plane[0],2) + pow(plane[1],2) + pow(plane[2],2));
    return nu/de;
}

int main(){
    double t = 0; // 直线参数方程的参数，控制点在直线上的移动
    double dt = 0.1; // 沿直线搜索的方向和步长，初始方向为正
    double F0[3], F1[3]; // 直线上的点
    
    int i;
    do{
      // 隐含了一条直线：过点P且垂直于平面的直线
        for(i = 0;i < 3;i++){
            F0[i] = t * plane[i] + P[i]; // 这条直线上，参数为t时点的坐标
            F1[i] =(t+dt) * plane[i] + P[i]; // 这条直线上，参数为t+dt时点的坐标
        }
        if(dis(F1)>dis(F0)) dt = -dt/2; // 如果方向错误（距离变大）则回溯，步长缩小，方向改变
        t = t + dt;
    }while(fabs(dt)>1e-5); // 步长缩到足够小时，停止搜索，此时得到近似解

    printf("当前距离：%.5f.\n",dis(P));
    printf("现在N的坐标为：(%.2f,%.2f,%.2f).\n",F1[0],F1[1],F1[2]);
    printf("参数为：%.2f.\n",t);

    return 0;
}
