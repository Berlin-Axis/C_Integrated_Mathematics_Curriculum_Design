// 题目：计算B*CT。

# include <stdio.h>
# include <math.h>

void Transition(int C[3][2],int CT[2][3]){
    int i,j;
    for(i = 0; i < 3;i++){
        for(j = 0;j < 2;j++){
            CT[j][i] = C[i][j];
        }
    }
}

void Multiple(int B[2][2],int CT[2][3],int result[2][3]){
    int i,j,k;
    for(i = 0;i < 2;i++){
        for(j = 0;j < 3;j++){
            result[i][j] = 0;
            for(k = 0;k < 2;k++)
            {result[i][j] += B[i][k] * CT[k][j];}
        }
        
    }
}

int main(){
    int CT[2][3];
    int result[2][3];
    int C[3][2] = {{3,2},{-1,-2},{0,2}};
    int B[2][2] = {{-2,2},{-1,5}};

    Transition(C,CT);
    Multiple(B,CT,result);
    
    int i,j;
    for(i = 0;i < 2;i++){
        for(j = 0;j < 3;j++){
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
