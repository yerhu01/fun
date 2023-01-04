#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int dp[5][5];
    memset(dp, 0x80, sizeof(dp)); // -inf 11000000, 0xc0c0c0c0=-1061109568
    //memset(dp, 0x7f, sizeof(dp)); // +inf 00111111, 0x3f3f3f3f=1061109568
    dp[0][0] = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
