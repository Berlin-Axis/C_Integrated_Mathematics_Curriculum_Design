/*
积分
- 利用微元法思想
*/

// 题目：根据供求曲线计算均衡点和消费者剩余

# include <stdio.h>
# include <math.h>
# define m 10000

double demand(double q){ // 需求函数
    return -2 * pow(q,2) + 3 * q + 8;
}

double supply(double q){ // 供给函数
    return pow(q,2) + q;
}

double balance(){ // 计算均衡点：需求=供给
    double q;
    double a = 3, b = -2, c = -8;
    double discriminant = pow(b,2) - 4 * a * c; // 判别式
    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);
    q = (root1 > 0)?root1:root2;
    return q;
}

int main(){
    double q_star,p_star,f1, upper, lower = 0, step, s = 0;
  // 使用函数得到均衡点
    q_star = balance(); 
    p_star = supply(q_star);

    upper = q_star;
    step = (upper - lower) * 1.0 / m; // 设定步长（积分区间）

  // 循环：累加积分区间，并使用current_q记录当前积分变量位置
    int i;
    for(i = 0; i < m; i++){ 
        double current_q = lower + i * step;
        s += demand(current_q) * step;
    }

    s = s - p_star * q_star;

    printf("均衡点为：(%.5f,%.5f).\n",q_star,p_star);
    printf("消费者剩余为：%.5f.\n",s);

    return 0;
}
