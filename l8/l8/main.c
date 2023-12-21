//
//  main.c
//  l8
//
//  Created by Тимур on 21.12.2023.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>


void find(int x, int** k, int m, int* D)
{
    printf("%d\n", x + 1);
    D[x] = 1;    //Посетили вершину

    for (int i = 0; i < m; i++)
    {
        if (k[x][i] == 1 && D[i] == 0)
        {
            find(i, k, m, D);
        }
    }
}

int main ()
{
    setlocale(LC_ALL, "rus");
    int m;
    srand(time(NULL));

    printf("Введите размер матрицы\n");
    scanf("%d", &m);

    int** k = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        k[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            k[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t = rand() % 2;
            k[i][j] = t;
            k[j][i] = t;
            k[i][i] = 0;
        }

    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", k[i][j]);
        }
        printf("\n");
    }
    //_____________________________________________

    int* D = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        D[i] = 0;    //Массив вершин
    }

    find(0, k, m, D);

    //_____________________________________________

    
    getchar();getchar();
    return 0;
}

