

# include <stdio.h>
# include <math.h>

void calculate_weight(int a,double A[a][a],double W[a])
{
    int i,j;
    double sqA[a];
    double sum1;
    double sum2 = 0;

    for(i = 0;i < a;i++)
    {
        sum1 = 1;
        for(j = 0;j < a;j++)
        {
            sum1 *= A[i][j];
        }
        sqA[i] = pow(sum1,1.0/a);
        sum2 += sqA[i];
    }

    for(i = 0;i < a;i++)
    {
        W[i] = sqA[i] / sum2; 
    }

    printf("指标重要性权数为：\n");

    for(i = 0;i < a;i++)
    {
        printf("%.2f\t",W[i]); 
    }

}

void examination(int a,double A[a][a],double W[a])
{
    int i,j;
    double AW[a];
    double lambda_max;

    for(i = 0;i < a;i++)
    {
        AW[i] = 0;
    }

    for(i = 0;i < a;i++)
    {
        for(j = 0;j < a;j++)
        {
            AW[i] += A[i][j] * W[j];
        }
    }

    double sum3 = 0;
    for(i = 0;i < a;i++)
    {
        sum3 += AW[i] / W[i];
    }

    lambda_max = (1.0 / a) * sum3;

    double CI,RI,CR;

    CI = (lambda_max - a) / (a - 1);

    switch (a)
    {
    case 3:
        RI = 0.52;
        break;
    case 4:
        RI = 0.89;
        break;
    case 5:
        RI = 1.12;
        break;
    
    default:
        printf("仅支持3-5是因为我不想写了。\n");
        return;
    }

    CR = CI / RI;

    printf("最大特征值lambda_max = %.4f\n", lambda_max);
    printf("一致性指标CI = %.4f\n", CI);
    printf("随机一致性指标RI = %.4f\n", RI);
    printf("一致性比例CR = %.4f\n", CR);

    if(CR <= 0.10)
    {
        printf("上述判断矩阵满足一致性要求。\n");
    }
    else
    {
        printf("上述判断矩阵不满足一致性要求。\n");
    }

}

int main()
{
    double A[3][3] = {{1,3,7},{1.0/3,1,3},{1.0/7,1.0/3,1}};
    double W[3];
    
    int i;
    for(i = 0;i < 3;i++)
    {
        W[i] = 0;
    }

    calculate_weight(3,A,W);

    examination(3,A,W);

    return 0;
}
