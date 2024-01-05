#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char **ans, char *digits, int *returnSize, char *cur, int index) {
    if (index == strlen(digits)) {
        ans[(*returnSize)] = (char *)malloc(sizeof(char) * (strlen(cur) + 1));
        strcpy(ans[(*returnSize)++], cur);
        return;
    }
    int digit = digits[index] - '0';
    for (int i = 0; i < strlen(letters[digit]); i++) {
        cur[index] = letters[digit][i];
        backtrack(ans, digits, returnSize, cur, index + 1);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    int size = 1;
    for (int i = 0; i < strlen(digits); i++) {
        size *= strlen(letters[digits[i] - '0']);
    }
    char **ans = (char **)malloc(sizeof(char *) * size);
    char *cur = (char *)malloc(sizeof(char) * (strlen(digits) + 1));
    cur[strlen(digits)] = '\0';
    *returnSize = 0;
    backtrack(ans, digits, returnSize, cur, 0);
    free(cur);
    return ans;
}
