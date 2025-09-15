#include <stdio.h>
#include <math.h>

// 定义结果结构体，存储产品名称和对应的权重
struct Result
{
    char name[20];
    double weight;
};

// 计算权重向量
void calculate_weight(int a, double A[a][a], double W[a])
{
    double sum_A_column[a];
    double B[a][a];
    double tem_W[a];
    double tem_W_sum = 0;

    int i, j;
    for (i = 0; i < a; i++)
    {
        sum_A_column[i] = 0;
        for (j = 0; j < a; j++)
        {
            sum_A_column[i] += A[j][i];
        }
    }

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            B[i][j] = A[i][j] / sum_A_column[j];
        }
    }

    for (i = 0; i < a; i++)
    {
        tem_W[i] = 0;
        for (j = 0; j < a; j++)
        {
            tem_W[i] += B[i][j]; 
        }
        tem_W_sum += tem_W[i];
    }

    for (i = 0; i < a; i++)
    {
        W[i] = tem_W[i] / tem_W_sum;
    }

    for (i = 0; i < a; i++)
    {
        printf("%.4f\t", W[i]);  // 统一为4位小数，提高一致性
    }
    
    printf("\n");
}

// 一致性检验
void examination(int a, double A[a][a], double W[a])
{
    int i, j;
    double AW[a];
    double lambda_max;

    for (i = 0; i < a; i++)
    {
        AW[i] = 0;
    }

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            AW[i] += A[i][j] * W[j];
        }
    }

    double sum3 = 0;
    for (i = 0; i < a; i++)
    {
        sum3 += AW[i] / W[i];
    }

    lambda_max = (1.0 / a) * sum3;

    double CI, RI, CR;

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
        printf("仅支持3-5阶矩阵的一致性检验。\n");
        return;
    }

    CR = CI / RI;

    printf("最大特征值lambda_max = %.4f\n", lambda_max);
    printf("一致性指标CI = %.4f\n", CI);
    printf("随机一致性指标RI = %.4f\n", RI);
    printf("一致性比例CR = %.4f\n", CR);

    if (CR <= 0.10)
    {
        printf("上述判断矩阵满足一致性要求。\n");
    }
    else
    {
        printf("上述判断矩阵不满足一致性要求。\n");
    }
}

// 冒泡排序：按权重从大到小排序产品
void BubbleSort(int n, struct Result arr[])
{
    int i, j;
    struct Result temp;  // 用于交换的临时结构体变量
    
    // 外层循环控制排序轮数
    for (i = 0; i < n - 1; i++)
    {
        // 内层循环控制每轮比较次数
        for (j = 0; j < n - i - 1; j++)
        {
            // 如果前一个元素的权重小于后一个，交换它们（从大到小排序）
            if (arr[j].weight < arr[j + 1].weight)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // 准则层判断矩阵 (3×3)
    double A[3][3] = {{1, 2, 3}, {1.0/2, 1, 1}, {1.0/3, 1, 1}};
    // 方案层判断矩阵 (4×4)
    double B1[4][4] = {{1, 1.0/2, 1.0/7, 1.0/5}, {2, 1, 1.0/4, 1.0/3}, {7, 4, 1, 1}, {5, 3, 1, 1}};
    double B2[4][4] = {{1, 1.0/2, 1.0/5, 1.0/7}, {2, 1, 1.0/3, 1.0/5}, {5, 3, 1, 1.0/2}, {7, 5, 2, 1}};
    double B3[4][4] = {{1, 2, 1.0/5, 1.0/4}, {1.0/2, 1, 1.0/7, 1.0/3}, {5, 7, 1, 2}, {4, 3, 1.0/2, 1}};
    
    // 权重向量
    double WA[3] = {0};    // 准则层权重
    double W1[4] = {0};    // B1下方案权重
    double W2[4] = {0};    // B2下方案权重
    double W3[4] = {0};    // B3下方案权重
    double total_weights[4] = {0};  // 综合权重，对应4个产品
    
    int i;

    printf("A权重向量为：\n");
    calculate_weight(3, A, WA);
    printf("A一致性检验结果为：\n");
    examination(3, A, WA);
    printf("\n");

    printf("B1权重向量为：\n");
    calculate_weight(4, B1, W1);
    printf("B1一致性检验结果为：\n");
    examination(4, B1, W1);
    printf("\n");

    printf("B2权重向量为：\n");
    calculate_weight(4, B2, W2);
    printf("B2一致性检验结果为：\n");
    examination(4, B2, W2);
    printf("\n");

    printf("B3权重向量为：\n");
    calculate_weight(4, B3, W3);
    printf("B3一致性检验结果为：\n");
    examination(4, B3, W3);
    printf("\n");

    // 计算综合权重
    for (i = 0; i < 4; i++) {
        total_weights[i] = WA[0] * W1[i] + WA[1] * W2[i] + WA[2] * W3[i];
    }

    // 输出综合权重
    printf("各产品的综合权重：\n");
    printf("产品1（C1）的综合权重：%.4f\n", total_weights[0]);
    printf("产品2（C2）的综合权重：%.4f\n", total_weights[1]);
    printf("产品3（C3）的综合权重：%.4f\n", total_weights[2]);
    printf("产品4（C4）的综合权重：%.4f\n", total_weights[3]);
    printf("\n");

    // 创建结果结构体数组
    struct Result data[] = {
        {"产品1", total_weights[0]},
        {"产品2", total_weights[1]},
        {"产品3", total_weights[2]},
        {"产品4", total_weights[3]}
    };

    // 进行冒泡排序
    BubbleSort(4, data);

    // 输出排序结果
    printf("按综合权重从高到低排序：\n");
    for (i = 0; i < 4; i++) {
        printf("%s: %.4f\n", data[i].name, data[i].weight);
    }

    // 最优产品是排序后的第一个
    printf("\n最优产品为%s，其综合权重为%.4f\n", data[0].name, data[0].weight);

    return 0;
}
