#include <stdio.h>

int finalBalance(int transaction[], int n, int balance)
{
    if (n == 0)
        return balance;
    return finalBalance(transaction, n - 1, balance + transaction[n - 1]);
}

int totalDeposits(int transaction[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (transaction[n - 1] > 0)
    {
        return transaction[n - 1] + totalDeposits(transaction, n - 1);
    }
    return totalDeposits(transaction, n - 1);
}

int copyLarge(int transaction[], int i, int n, int large[], int k)
{
    if (i == n)
    {
        return k;
    }
    if (transaction[i] <= -10000)
    {
        large[k] = transaction[i];
        k++;
    }
    return copyLarge(transaction, i + 1, n, large, k);
}

int main()
{
    int transaction[7] = {20000, -5000, -12000, 8000, -25000, -2500, 15000};
    int large[7];
    int i, count;

    printf("Final balance: %d\n", finalBalance(transaction, 7, 20000));
    printf("Total deposits: %d\n", totalDeposits(transaction, 7));

    count = copyLarge(transaction, 0, 7, large, 0);
    printf("Large withdrawals (%d): ", count);
    for (i = 0; i < count; i++)
    {
        printf("%d ", large[i]);
    }
    printf("\n");

    return 0;
}