#include <stdio.h>
#define INF 9999
int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if(i != j && a[i][j] == 0)
            {
                a[i][j] = INF;
            }
        }
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    printf("Shortest Path Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
