#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* wallpaper[], size_t wallpaper_len)
{

    int minX = -1;
    int minY = -1;
    int maxX = -1;
    int maxY = -1;

    //어찌됐든, 좌측상단부터 우측하단까지가 드래그의 범위이므로 각각의 최소좌표만 구하면 된다.

    for (int y = 0; y < wallpaper_len; y++)
    {

        for (int x = 0; wallpaper[y][x] != '\0'; x++)
        {

            if (wallpaper[y][x] == '#')
            {

                if (minX == -1 || minX >= x)
                {
                    minX = x;
                }

                if (minY == -1 || minY >= y)
                {
                    minY = y;
                }

                if (maxX == -1 || maxX <= x)
                {
                    maxX = x;
                }

                if (maxY == -1 || maxY <= y)
                {
                    maxY = y;
                }
            }
        }
    }

    int* answer = (int*)malloc(sizeof(int) * 4);
    answer[0] = minY;
    answer[1] = minX;
    answer[2] = maxY + 1;
    answer[3] = maxX + 1;

    return answer;
}