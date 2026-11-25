#include <stdio.h>

int markZone(char map[][5], int r, int c, char label)
{
    map[r][c] = label;
    if (r < 0 || r > 4 || c < 0 || c > 4)
    {
        return 0;
    }
    if (map[r][c] != '*')
    {
        return 0;
    }
    
    return 1 + markZone(map, r - 1, c, label)
             + markZone(map, r + 1, c, label)
             + markZone(map, r, c - 1, label)
             + markZone(map, r, c + 1, label);
}

int main(void)
{
    float temp[5][5] = {
        { 2.1, -1.5, -2.0,  3.0,  4.2},
        { 1.8, -0.5,  2.5,  3.1, -1.0},
        { 3.3,  2.0,  1.5, -0.8, -2.0},
        {-1.2,  3.4,  4.0,  3.8, -0.6},
        {-2.5, -3.1,  5.1,  6.0,  4.7}
    };
    char map[5][5];
    int i, j, zones = 0;
    char label = 'A';

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (temp[i][j] < 0)
            {
                map[i][j] = '*';
            }
            else
            {
                map[i][j] = '.';
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (map[i][j] == '*')
            {
                printf("Zone %c: %d stations\n", label, markZone(map, i, j, label));
                label++;
                zones++;
            }
        }
    }

    /* Task 4: print zones and map */
    printf("Total zones: %d\n\n", zones);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%c ", map[i][j]);
        printf("\n");
    }

    return 0;
}