#include <stdio.h>
#include<limits.h>
#include<stdlib.h>

// int p[5] = {3, 2, 4, 2, 5};
// #define N (sizeof(p)/ sizeof(p[0]) - 1)

// typedef int matrix [N][N] ;

// void print_matrix(matrix mat){
//     for (int i = 0; i < N; i ++){
//         for (int j = 0; j < N; j ++){
//             printf("%d ", mat[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main(){

//     matrix dp;

//     for (int i = 0; i < N; i ++){
//             dp[i][i] = 0;
//     }

//     for (int gap = 1; gap < N; gap ++){
//         for (int i = 0, j = gap; j < N; j ++, i ++){
//             int bigno = INT_MAX;
//             int count = 0;
//             for (int k = i; k < j; k ++){
//                 dp[i][j] = dp[i][k] + dp[k + 1][j] + p[i]*p[j + 1]*p[k + 1];
//                 if (dp[i][j] < bigno){
//                     bigno = dp[i][j];
//                     count = k + 1;
//                 }

//             }
//             dp[i][j] = bigno;
//         }
//     }

//     print_matrix(dp);
// }

// struct node{
//     int data;
//     int liss;
//     struct node *left, *right;
    
// };

// max (int a, int b){
//     if (a > b){
//         return a;
//     }

//     else{
//         return b;
//     }
// }

// int liss (struct node * root){
//     if (root == NULL){
//         return 0;
//     }
//     if (root -> liss){
//         return root->liss;
//     }
//     if (root->left == NULL && root -> right == NULL){
//         return root->liss = 1;
//     }

//     int liss_excl = liss(root->left) + liss(root-> right);

//     int liss_incl = 1;
//     if (root -> left){
//         liss_incl = liss(root->left->left) + liss(root->left->right);
//     }
//     if (root -> right){
//         liss_incl = liss(root->right->left) + liss(root->right->right);
//     }

//     return max(liss_excl, liss_incl);
// }

// int main(){
//     for (int gap = 1; gap < n; gap++){
//         for (int i = 0, j = gap; j < n; j ++, i ++){
//             int smallno = -1;
//             int current = 0;
//             for (int k = i + 1; k < j; k ++){
//                 if (start[k] >= finish[i] && finish[k] <= start[j]){
//                     current = mat[i][k] + mat[k][j] + 1;
//                     if (current > smallno){
//                         smallno = current;
//                     }
//                 }

//             }
//             if (smallno == - 1){
//                 mat[i][j] = 0;
//             }
//             else{
//                 mat[i][j] = smallno;
//             }
//         }
//     }
// }

int comp(const void * a, const void* b){
    const int * a1 = a;
    const int * b1 = b;
    return (*a1 - *b1);
}

int main(){
    int values[] = { 88, 56, 100, 2, 25 };

    for (int i = 0; i < 5; i ++){
        printf("%d ", values[i]);
    }

    qsort(values, 5, sizeof(int), comp);
    printf("\n");

    for (int i = 0; i < 5; i ++){
        printf("%d ", values[i]);
    }
}