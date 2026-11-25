#include <stdio.h>

void buildScores(int change[], int score[], int i, int n, int current)
{
    if (i == n)
    {
        return;
    }
    current = current + change[i + 1];
    score[i] = current;
    buildScores(change, score, i + 1, n, current);
}

int countLow(int score[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (score[n - 1] < 50)
    {
        return 1 + countLow(score, n - 1);
    }
    return countLow(score, n - 1);
}

void reverse(int arr[], int left, int right)
{
    int temp;

    if (left >= right)
    {
        return;
    }
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    reverse(arr, left + 1, right - 1);
}

int main()
{
    int change[10] = {60, -5, -10, 8, -12, 20, -15, -9, 30, 5};
    int score[9];
    int i;

    buildScores(change, score, 0, 9, change[0]);

    printf("Daily scores: ");
    for (i = 0; i < 9; i++)
    {
        printf("%d ", score[i]);
    }
    printf("\n");

    printf("Days below 50: %d\n", countLow(score, 9));

    reverse(score, 0, 8);
    printf("Reversed scores: ");
    for (i = 0; i < 9; i++)
    {
        printf("%d ", score[i]);
    }
    printf("\n");

    return 0;
}