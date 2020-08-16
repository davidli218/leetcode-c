//
// Created by David on 2020/8/16.
//

#define SOLUTION 0

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#if SOLUTION == 0
/* 2020/8/16 DFS O(imageSize×imageColSize) O(imageSize×imageColSize) */
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int bx, by;

void dfs(int **image, int x, int y, int color, int newColor) {
    if (image[x][y] == color) {
        image[x][y] = newColor;
        for (int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if (mx >= 0 && mx < bx && my >= 0 && my < by) {
                dfs(image, mx, my, color, newColor);
            }
        }
    }
}

int **floodFill(int **image, int imageSize, const int *imageColSize, int sr, int sc, int newColor, int *returnSize,
                int **returnColumnSizes) {
    *returnSize = bx = imageSize;
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = *imageColSize;
    }
    by = *imageColSize;

    int dstColor = image[sr][sc];

    if (dstColor != newColor)
        dfs(image, sr, sc, dstColor, newColor);

    return image;
}

#endif