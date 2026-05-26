#include <stdio.h>
struct Item
{
    int weight;
    int profit;
    float ratio;
};
void sort(struct Item item[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(item[j].ratio < item[j + 1].ratio)
            {
                struct Item temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    float capacity, totalProfit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item item[n];
    printf("Enter profit and weight:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);
    sort(item, n);
    for(int i = 0; i < n; i++)
    {
        if(item[i].weight <= capacity)
        {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }
    printf("Maximum Profit = %.2f\n", totalProfit);
    return 0;
}
