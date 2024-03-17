#include <stdio.h>
#include <stdlib.h>

// problem link : https://canvas.instructure.com/courses/8452576/discussion_topics/21018784
// alternate link : https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0063.Unique%20Paths%20II/README_EN.md
// Inputs:
// 8 5
// 0 0 0 0 1 0 1 0
// 0 1 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 1 0 1 1 0 0 0 0
// 0 0 0 0 0 0 0 0

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize, FILE* output) {
    int n = obstacleGridSize;
    int m = *obstacleGridColSize;

    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }



    //write your logic here, Fill the dp table correctly, dp[i][j] should contain the number of unique paths to reach the cell (i, j)
    for (int i = 0; i < n; i++) {
        if (obstacleGrid[i][0] == 1) {
            break;
        }
        dp[i][0] = 1;
    }

    for (int j = 0; j < m; j++) {
        if (obstacleGrid[0][j] == 1) {
            break;
        }
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }


    // Print dp table to output file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(output, "%d ", dp[i][j]);
        }
        fprintf(output, "\n");
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    int result = dp[n - 1][m - 1];
    return result;
}

int main() {
    FILE *input, *output, *expectedOutput;
    input = fopen("obs_input.txt", "r");
    output = fopen("obs_output.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int m, n;
    fscanf(input, "%d %d", &m, &n);

    int** obstacleGrid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        obstacleGrid[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &obstacleGrid[i][j]);
        }
    }

    int obstacleGridColSize = m;
    int result = uniquePathsWithObstacles(obstacleGrid, n, &obstacleGridColSize, output);

    return 0;
}

