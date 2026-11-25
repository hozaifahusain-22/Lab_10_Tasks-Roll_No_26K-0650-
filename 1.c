#include <stdio.h>

int main()
{
    FILE *fp;
    int itemNo, qty, id, stock;
    char name[21];
    float price, bill, total = 0;


    fp = fopen("items.txt", "wb");
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 1, "Rice", 250.00, 40);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 2, "Sugar", 160.00, 25);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 3, "Milk", 220.00, 30);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 4, "CookingOil", 560.00, 12);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 5, "Tea", 450.00, 18);
    fclose(fp);

    fp = fopen("items.txt", "rb+");

    while (1)
    {
        printf("Item no: ");
        scanf("%d", &itemNo);

        if (itemNo == 0)
            break;

        printf("Quantity: ");
        scanf("%d", &qty);

       
        fseek(fp, (itemNo - 1) * 42, SEEK_SET);
        fscanf(fp, "%d %s %f %d", &id, name, &price, &stock);

        
        if (stock >= qty)
        {
            bill = qty * price;
            total = total + bill;
            printf("%s\n", name);
            printf("%d x %.2f = %.2f\n", qty, price, bill);

            stock = stock - qty;

            fseek(fp, (itemNo - 1) * 42, SEEK_SET);
            fprintf(fp, "%-4d %-20s %9.2f %5d\n", id, name, price, stock);
        }
        else
        {
            printf("Only %d %s in stock\n", stock, name);
        }
    }

    
    printf("Total bill: %.2f\n", total);
    fclose(fp);

    return 0;
}