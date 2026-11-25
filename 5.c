#include <stdio.h>

int main()
{
    FILE *fp;
    int i, entry;
    char name[13], name2[13];
    float amount, amount2, newAmount, total = 0;

    fp = fopen("expenses.txt", "wb");
    fprintf(fp, "%-12s %9.2f\n", "Food", 1200.00);
    fprintf(fp, "%-12s %9.2f\n", "Transport", 500.00);
    fprintf(fp, "%-12s %9.2f\n", "Books", 850.00);
    fprintf(fp, "%-12s %9.2f\n", "Mobile", 300.00);
    fclose(fp);


    printf("Category: ");
    scanf("%s", name);
    printf("Amount: ");
    scanf("%f", &amount);

    fp = fopen("expenses.txt", "ab");
    fprintf(fp, "%-12s %9.2f\n", name, amount);
    fclose(fp);


    fp = fopen("expenses.txt", "rb+");

    fseek(fp, -2 * 23, SEEK_END);
    fscanf(fp, "%s %f", name, &amount);
    fscanf(fp, "%s %f", name2, &amount2);
    printf("Latest two: %s %.2f, %s %.2f\n", name, amount, name2, amount2);


    printf("Entry to fix: ");
    scanf("%d", &entry);
    printf("Correct amount: ");
    scanf("%f", &newAmount);

    fseek(fp, (entry - 1) * 23, SEEK_SET);
    fscanf(fp, "%s %f", name, &amount);

    fseek(fp, (entry - 1) * 23, SEEK_SET);
    fprintf(fp, "%-12s %9.2f\n", name, newAmount);


    rewind(fp);
    for (i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %f", name, &amount);
        printf("%s %.2f\n", name, amount);
        total = total + amount;
    }
    printf("Total: %.2f\n", total);

    fclose(fp);
    return 0;
}