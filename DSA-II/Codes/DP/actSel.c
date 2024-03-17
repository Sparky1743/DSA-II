#include <stdio.h>
#include <limits.h>

// references
// 1) DP Soln: https://www.youtube.com/watch?v=I9D1zdKm8Nk
// 2) CLRS: https://walkccc.me/CLRS/Chap16/16.1/
// 3) Greedy Soln: https://www.youtube.com/watch?v=Qz6D7mrxaJM

int start[] = {0, 1, 3, 2, 0, 5, 8, 11, INT_MAX};
int finish[] = {0, 3, 4, 5, 7, 9, 10, 12, INT_MAX};

// int start[] = {0, 10, 12, 20, INT_MAX};
// int finish[] = {0, 20, 25, 30, INT_MAX};

// int start[] = {0, 1, 3, 0, 5, 8, 5, INT_MAX};
// int finish[] = {0, 2, 4, 6, 7, 9, 9, INT_MAX};

int n = sizeof(finish) / sizeof(finish[0]);

void print_mat(int arr[n][n]){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

 int main(){
    int mat[n][n];

    for(int i = 0; i < n; i++){
        mat[i][i] = 0;
    }
    // print_mat(mat);

    for (int gap = 1; gap < n; gap++){
        for (int i = 0, j = gap; j < n; i++, j++){
            int smallno = -1;
            for (int k = i + 1; k < j; k++){
                if (start[k] >= finish[i] && finish[k] <= start[j]){
                    int current = mat[i][k] + mat[k][j] + 1;
                    if (current > smallno){
                        smallno = current;
                    }
                }
            }
            if (smallno == -1){
                mat[i][j] = 0; // No compatible activities found
            } else {
                mat[i][j] = smallno;
            }
        }
    }
    
    // print_mat(mat);
    printf("max number of activities = %d", mat[0][n - 1]);
 }