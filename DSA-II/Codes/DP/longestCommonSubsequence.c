#include <stdio.h>

// reference
// 1) LCS(video) : https://www.youtube.com/watch?v=sSno9rV8Rhg
// 2) LCS(printing_lcs) : https://www.javatpoint.com/longest-common-subsequence

// char A[] = {'a', 'b', 'c', 'd', '\0'};
// char B[] = {'b', 'd', '\0'};
// char A[] = {'a', 'b', 'd', 'a', 'c', 'e', '\0'};
// char B[] = {'b', 'a', 'b', 'c', 'e', '\0'};
char A[] = {'l', 'o', 'n', 'g', 'e', 's', 't', '\0'};
char B[] = {'s', 't', 'o', 'n', 'e', '\0'};
int n = sizeof(A) / sizeof(A[0]);
int m = sizeof(B) / sizeof(B[0]);

int max(int a, int b);
void print_lcs(int LCS[n][m], int i, int j);
int print_array(int arr[n][m]){
    for (int j = 0; j < m; j ++){
        for (int i = 0; i < n; i ++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int LCS[n][m];
    for (int i =0, j = 0; i < n; i ++){
        LCS[i][j] = 0;
    }

    for (int i =0, j = 0; j < m; j ++){
        LCS[i][j] = 0;
    }

    for (int i = 0; i < n - 1; i ++){
        for (int j = 0; j < m - 1; j ++){
                // printf("%d, %d", i, j);
                // printf("%d", i);
                if (A[i] == B[j]){
                    // printf("%c ", A[i]);
                    // printf("%c ", B[j]);
                    // printf("%d", j);
                    LCS[i + 1][j + 1] = 1 + LCS[i][j];

                }
                else{
                    LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
                }
        }
    }
    printf("\n");
    print_array(LCS);

    printf("LCS: ");
    print_lcs(LCS, n - 1, m - 1);
    printf("\n");
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void print_lcs(int LCS[n][m], int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }

    if (A[i - 1] == B[j - 1]) {
        print_lcs(LCS, i - 1, j - 1);
        printf("%c ", A[i - 1]);
    } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
        print_lcs(LCS, i - 1, j);
    } else {
        print_lcs(LCS, i, j - 1);
    }
}

// Recursion: (exponential time) - top down approach
// int LCS(int i, int j);

// int main(){
//     printf("%d", LCS(0, 0));
// }

// int LCS(int i, int j){
//     if (A[i] == '\0' || B[j] == '\0'){
//         return 0;
//     }

//     else if(A[i] == B[j]){
//         return 1 + LCS(i + 1, j + 1);
//     }

//     else {
//         return max(LCS(i + 1, j), LCS(i, j + 1));
//     }
// }