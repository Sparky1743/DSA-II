#include <stdio.h>
#include <limits.h>

// references:
// 1) refer MCM 
// 2) OBST(video) : https://www.youtube.com/watch?v=vLS-zRCHo-Y

// Time taken to search is O(logn)
int keys[] = {0, 10, 20, 30, 40};
int freqs[] = {0, 4, 2, 6, 3};

#define n (sizeof(keys) / sizeof(keys[0]))

typedef int arr[n][n];

void print_array(arr matrix){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_utm(arr matrix){
    for (int gap = 1; gap < n; gap ++){
        for (int i =0, j =gap; j < n; j ++, i ++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int w(int p, int q){
    int sum = 0;
    for (int i = p + 1; i <= q; i ++ ){
        sum += freqs[i];
    }
    return sum;
}

int main(){
    arr m;
    arr pos;
    // printf("%d", w(2, 2));

    // Initialization to build the table upon
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if (i == j){
                m[i][j] = 0;
                pos[i][j] = 0;
            }
        }
    }

    // Diagonal traversing 
    for (int gap = 1; gap < n; gap++){
        for (int i = 0, j = gap; j < n; i ++, j ++){
            int bigno = INT_MAX;
            int count = 0;
            for (int k = i; k < j; k ++){
                    m[i][j] = m[i][k] + m[k + 1][j] + w(i, j);

                    // Getting minimum and the corresponded root of all possible trees
                    if (m[i][j] < bigno){
                        bigno = m[i][j];
                        count = k + 1;
                    }
            }
        
            m[i][j] = bigno;
            pos[i][j] = count;
        }
    }

    print_utm(m);
    print_utm(pos);
}