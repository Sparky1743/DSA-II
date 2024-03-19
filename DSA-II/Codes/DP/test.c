#include <stdio.h>
#include<limits.h>

int p[5] = {3, 2, 4, 2, 5};
#define n (sizeof(p) / sizeof(p[0]) - 1)

typedef int mat[n][n];

void print_array(int m, mat matrix){
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < m; j ++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    mat dp;
    for (int i = 0; i < n; i ++){
            dp[i][i] = 0;
    }

    print_array(n, dp);

    for (int gap = 1; gap < n; gap ++){
        for (int i = 0, j = gap; j < n; j ++, i ++){
            int bigno = INT_MAX;
            int count = 0;

            for (int k = i; k < j; k ++){
                dp[i][j] = dp[i][k] + dp[k + 1][j] + p[i]*p[j + 1]*p[k + 1];

                if (dp[i][j] < bigno){
                    bigno = dp[i][j];
                    count = k + 1;
                }
            }

            dp[i][j] = bigno;
        }
    }

    print_array(n, dp);

}

