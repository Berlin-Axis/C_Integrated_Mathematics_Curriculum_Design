/*
  决策问题
- 对于效益型目标，采用标准化公式 zij = (yij - yj(min)) / (yj(max) - yj(min))
- 对于成本型目标，采用标准化公式 zij = (yj(max) - yij) / (yj(max) - yj(min))
*/

# include <stdio.h>

void standardize(double data[4][5], double result[4][5],int type[5]){
    int i,j;
    double y_max[5], y_min[5];

    for(i = 0;i < 5;i++)
    {
        y_max[i] = data[0][i]; // 初始化
        y_min[i] = data[0][i];
        for(j = 0;j < 4;j++)
        {
            
            if(data[j][i] > y_max[i])
            {
                y_max[i] = data[j][i];
            }
            if(data[j][i] < y_min[i])
            {
                y_min[i] = data[j][i];
            }

        }
    }

    for(i = 0;i < 5;i++)
    { 
        if(y_max[i]-y_min[i] <= 1e-9)
        {
            for(j = 0; j < 4; j++)
            {
                result[j][i] = 0.0;
            }
            // 跳过当前列的后续计算
            continue;
        }
        if(type[i] == 0)
        {
            for(j = 0;j < 4;j++)
            {
                result[j][i] = (y_max[i] - data[j][i]) / (y_max[i] - y_min[i]); // 成本型
            }
        }
        else
        {
            for(j = 0;j < 4;j++)
            {
                result[j][i] = (data[j][i] - y_min[i]) / (y_max[i] - y_min[i]); // 效益型
            }            
        }

    }

}

int main()
{
    double data[4][5] = {{150,100,10,7,7},{125,80,8,3,5},{90,50,20,5,11},{110,70,12,5,9}};
    double result[4][5];
    int type[5] = {0,1,0,1,1};
    
    int i,j;
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 5;j++)
        {
            result[i][j] = 0;
        }
    }

    standardize(data,result,type);

    printf("数据标准化的结果为：\n");

    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 5;j++)
        {
            printf("%.2f\t",result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
