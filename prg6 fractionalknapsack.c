#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int n, M;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int W[n+1], P[n+1];
    printf("Enter weights:\n");
    for(int i = 1; i <= n; i++) {
        scanf("%d", &W[i]);
    }
    printf("Enter profits:\n");
    for(int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);
    int Table[n+1][M+1];
    for(int i = 0; i <= n; i++) {
        Table[i][0] = 0;
    }
    for(int j = 0; j <= M; j++) {
        Table[0][j] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= M; j++) {
            if(j < W[i]) {
                Table[i][j] = Table[i-1][j];
            }
            else {
                Table[i][j] = max(
                    Table[i-1][j],
                    P[i] + Table[i-1][j - W[i]]
                );
            }
        }
    }
    printf("Maximum Profit = %d\n", Table[n][M]);
    return 0;
}
