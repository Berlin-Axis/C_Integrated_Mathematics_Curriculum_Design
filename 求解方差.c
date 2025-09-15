# include <stdio.h>
# include <time.h>
# include <math.h>
# include <stdlib.h>
# define M 10000

int main()
{
    int i;
    srand(time(NULL));
    double u,sum1 = 0,sum2 = 0,w1,w2,f1,f2,u1,u2;
    for(i = 0;i < M;i++)
    {
        double u1 = (double)rand()/RAND_MAX;
        double u2 = (double)rand()/RAND_MAX;
        u = sqrt(-2.0*log(u1)) * cos(2.0*M_PI*u2);
        u = 20 + u * 10;
        f1 = 9 * pow(u,4);
        f2 = 3 * pow(u,2);
        sum1 += f1;
        sum2 += f2;
    }
    w1 = sum1/M;
    w2 = sum2/M;
    
    double D;
    D = w1 - pow(w2,2);
    
    printf("方差为：%.2f.\n",D);
    
    return 0;
}
