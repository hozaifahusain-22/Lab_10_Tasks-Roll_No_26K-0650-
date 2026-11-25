#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    int i, room, nights, id, found;
    char status, name[21];
    char guests[10][21];
    int rooms[10];
    float rate;

    fp = fopen("hotel.txt", "wb");
    for (i = 101; i <= 110; i++)
    {
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n", i, 'F', "-", 0, 8000.00);
    }
    fclose(fp);

    fp = fopen("hotel.txt", "rb+");

    printf("Check-in room: ");
    scanf("%d", &room);
    printf("Name: ");
    scanf("%s", name);
    printf("Nights: ");
    scanf("%d", &nights);

    fseek(fp, (room - 101) * 39, SEEK_SET);
    fscanf(fp, "%d %c", &id, &status);

    if (status == 'F')
    {
        fseek(fp, (room - 101) * 39, SEEK_SET);
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n", room, 'B', name, nights, 8000.00);
        printf("Room %d booked\n", room);
    }
    else
    {
        printf("Room already booked\n");
    }
    
    rewind(fp);
    for (i = 0; i < 10; i++)
    {
        fscanf(fp, "%d %c %s %d %f", &rooms[i], &status, guests[i], &nights, &rate);
    }

    printf("Search name: ");
    scanf("%s", name);

    found = 0;
    for (i = 0; i < 10; i++)
    {
        if (strcmp(name, guests[i]) == 0)
        {
            printf("%s is in room %d\n", name, rooms[i]);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Guest not found\n");
    }
    
    printf("Check-out room: ");
    scanf("%d", &room);

    fseek(fp, (room - 101) * 39, SEEK_SET);
    fscanf(fp, "%d %c %s %d %f", &id, &status, name, &nights, &rate);

    printf("Bill: %d x %.2f = %.2f\n", nights, rate, nights * rate);

    fseek(fp, (room - 101) * 39, SEEK_SET);
    fprintf(fp, "%3d %c %-20s %2d %8.2f\n", room, 'F', "-", 0, rate);

    fclose(fp);
    return 0;
}