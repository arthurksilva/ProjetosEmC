#include <stdio.h>
#include <stdlib.h>
main()
{
    int matriz[10][10];
    int i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }

    printf("Matriz..:\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("\n%d\n", matriz[i][j]);
        }
    }
}