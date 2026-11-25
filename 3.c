#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    int i, city;
    char name[11], hotName[11];
    float temp, newTemp, hot;

    fp = fopen("temperature.txt", "wb");
    for (i = 1; i <= 5; i++)
    {
        printf("City name: ");
        scanf("%s", name);
        printf("Temperature: ");
        scanf("%f", &temp);
        fprintf(fp, "%-10s %5.1f\n", name, temp);
    }
    fclose(fp);

    fp = fopen("temperature.txt", "rb+");

    printf("City number: ");
    scanf("%d", &city);

    fseek(fp, (city - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f", name, &temp);
    printf("%s %.1f\n", name, temp);

    printf("City number to correct: ");
    scanf("%d", &city);
    printf("New temperature: ");
    scanf("%f", &newTemp);

    fseek(fp, (city - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f", name, &temp);

    fseek(fp, (city - 1) * 17, SEEK_SET);
    fprintf(fp, "%-10s %5.1f\n", name, newTemp);
    printf("%s updated to %.1f\n", name, newTemp);

    rewind(fp);
    hot = -100;
    for (i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %f", name, &temp);
        if (temp > hot)
        {
            hot = temp;
            strcpy(hotName, name);
        }
    }
    printf("Hottest city: %s (%.1f)\n", hotName, hot);

    fclose(fp);
    return 0;
}