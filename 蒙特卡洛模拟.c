# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# define M 100000

int main()
{
    int i;
    int count = 0;
    srand((unsigned int)time(NULL));
    
    for(i = 0;i < M;i++)
    {
        double U = (double)rand() / RAND_MAX;
        int train_depart;
        if(U < 0.7)
        {
            train_depart = 0;
        }
        else if(U < 0.9)
        {
            train_depart = 5;
        }
        else
        {
            train_depart = 10;
        }
    
        double v1 = (double)rand() / RAND_MAX;
        double v2 = (double)rand() / RAND_MAX;
        double V = sqrt(-2.0*log(v1)) * cos(2*M_PI*v2);
        V = 30 + V * 2;
        train_depart += V;

;        double W = (double)rand() / RAND_MAX;
        int person_depart = 0;
        if(W < 0.3)
        {
            person_depart += 28;
        }
        else if(W < 0.7)
        {
            person_depart += 30;
        }
        else if(W < 0.9)
        {
            person_depart += 32;
        }
        else
        {
            person_depart += 34;
        }
        
        
        if(train_depart >= person_depart)
        {
            count++;
        }
    }
    
    double possibility = (double)count / M;
    
    printf("能赶上火车的概率为：%.4f\n",possibility);
    
    return 0;
 }
