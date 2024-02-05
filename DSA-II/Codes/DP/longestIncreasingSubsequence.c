#include <stdio.h>
#include <limits.h>

// reference:
// 1) LIS(length) : https://www.youtube.com/watch?v=CE2b_-XfVDk
// 2) LIS(print_lis) : https://www.youtube.com/watch?v=E6us4nmXTHs

int arr[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
// int arr[] = {3, 4, -1, 0, 6, 2, 3};
#define n (sizeof(arr) / sizeof(arr[0]))

typedef int array[n];

void print_array(array arrs){
    for (int i = 0; i < n; i ++){
        printf("%d ", arrs[i]);
    }
    printf("\n");
}

void print_lis(int inds[], int index) {
    if (index == 0) {
        return;
    }

    print_lis(inds, inds[index]);
    printf("%d ", arr[index]);
}

int main(){
    // Time taken using DP is O(n^2)
    int lens[n];
    int inds[n];

    for (int i = 0; i < n; i ++){
        lens[i]  = 1;
        inds[i] = 0;
    }

    // print_array(lens);
    
    for (int i = 1; i < n; i ++){
        int smallno = 1;
        int pos = 0;
        for (int j = 0; j < i; j ++){
            if (arr[j] < arr[i]){
                // printf("lensj: %d", lens[i]);
                lens[i] = lens[j] + 1;
                if(lens[i] > smallno){
                    smallno = lens[i];
                    pos = j;
                }
            }
        }

        lens[i] = smallno;
        inds[i] = pos;
    }

    print_array(lens);
    print_array(inds);    

    int maxLenIndex = 0;
    for (int i = 1; i < n; i++) {
        if (lens[i] > lens[maxLenIndex]) {
            maxLenIndex = i;
        }
    }

    printf("Longest Increasing Subsequence (LIS): ");
    print_lis(inds, maxLenIndex);
    printf("\n");

}