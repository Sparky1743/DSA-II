#include <stdio.h>
#include <limits.h>
// references :
// 1) MCM: https://www.youtube.com/watch?v=prx1psByp7U
// 2) Diagonal Traversal: https://www.youtube.com/watch?v=lvRdFCMD_Ew

typedef int arr[4][4];

void print_array(int n, arr matrix){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_utm(int n, arr matrix){
    for (int gap = 1; gap < n; gap ++){
        for (int i =0, j =gap; j < n; j ++, i ++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int p[5] = {3, 2, 4, 2, 5};
    int m[4][4];
    int pos[4][4];
    int n = 4;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if (i == j){
                m[i][j] = 0;
                pos[4][4] = 0;
            }
        }
    }

    for (int gap = 1; gap < n; gap ++){
        for (int i = 0, j = gap ; j < n; i++, j ++){
            int count = 0;
            int bigno = INT_MAX;
            for (int k = i; k < j; k ++){
                if (j > i){
                    m[i][j] = m[i][k] + m[k + 1][j] + p[i]*p[k+1]*p[j+1];
                    if (m[i][j] < bigno){   
                        bigno = m[i][j];
                        count = k + 1;
                    }
                }
            }
            if (i != j){
                m[i][j] = bigno;
                pos[i][j] = count;
            }

        }
    }

    print_utm(4, m);
    print_utm(4, pos);
    return 0;


    // Wrong (not diagonal wise traversal)
    // for (int i = 0; i < n; i ++){
    //     for (int j = 0; j < n; j ++){
    //         if (i == j){
    //             m[i][j] = 0;
    //             pos[4][4] = 0;
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i ++){
    //     for (int j = 0; j < n; j ++){
    //         int count = 0;
    //         int bigno = 1000000;
    //         for (int k = i; k < j; k ++){
    //             if (j > i){
    //                 m[i][j] = m[i][k] + m[k + 1][j] + p[i]*p[k+1]*p[j+1];
    //                 if (m[i][j] < bigno){   
    //                     bigno = m[i][j];
    //                     count ++;
    //                 }
    //             }
    //         }
    //         if (i != j){
    //             m[i][j] = bigno;
    //             pos[i][j] = count;
    //         }

    //     }
    // }

    // print_array(4, m);
    // print_array(4, pos);
    // return 0;
}
