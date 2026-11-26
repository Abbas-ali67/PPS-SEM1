#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *returnColumnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];
    int total = m * n;

    if (total != r * c) {
        *returnSize = m;
        *returnColumnSizes = (int*)malloc((size_t)m * sizeof(int));
        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = matColSize[i];
        }
        return mat;
    }

    *returnSize = r;
    *returnColumnSizes = (int*)malloc((size_t)r * sizeof(int));

    int** res = (int**)malloc((size_t)r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        res[i] = (int*)malloc((size_t)c * sizeof(int));
    }

    for (int idx = 0; idx < total; idx++) {
        res[idx / c][idx % c] = mat[idx / n][idx % n];
    }

    return res;
}