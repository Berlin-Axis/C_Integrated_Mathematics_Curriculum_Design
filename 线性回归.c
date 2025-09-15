# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <math.h>
double normal(double mu,double sigma)
{
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    double z = sqrt(-2.0*log(u1)) * cos(2.0*M_PI*u2);
    return z = mu + sigma * z;
}
int main(){
    int seed = 100;
    int n = 1000;
    srand(seed);
    
    double x[1000],y[1000];
    double sum_x = 0,sum_y = 0,sum_xy = 0,sum_x2 = 0;
    int i;
    
    for(i = 0;i < n;i++)
    {
        x[i] = 28 + (55 - 28) *(double)rand() / RAND_MAX;
        double e = normal(0,3);
        y[i] = 5 + 10 * x[i] + e;
        
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }
    double b_hat = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double a_hat = (sum_y - b_hat * sum_x) / n;
    
    printf("估计参数：a_hat = %.4f,b_hat = %.4f\n",a_hat,b_hat);
    
    return 0;
}
