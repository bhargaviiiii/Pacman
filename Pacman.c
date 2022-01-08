#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char user_input()
{
    char choice = getch();
    return choice;
}

void Playfield_func()
{
    int i, j, z;
    int scores;
    char Playfield[10][10];

label:
    for (int i = 0; i < 10; i += 9)
    {
        for (int j = 0; j < 10; j++)
        {
            Playfield[i][j] = '#';
        }
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < 10; j += 9)
        {
            Playfield[i][j] = '#';
        }
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < 10; j += 9)
        {
            Playfield[i][j] = '#';
        }
    }
    printf("Welcome to pacman :)\n ");
    printf("Follow the instructions to play the game \n ");
    printf("A: To move left. \n D: To move right. \n W: To move upwards. \n S: To move downwards. \n");
    for (int i = 0; i < 10; i += 9)
    {
        for (int j = 0; j < 10; j++)
        {
            Playfield[i][j] = '#';
        }
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < 10; j += 9)
        {
            Playfield[i][j] = '#';
        }
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < 10; j += 9)
        {
            Playfield[i][j] = '#';
        }
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j = 0; j++)
        {
            Playfield[i][j] = ' ';
        }
    }
    for (int i = 3; i < 7; i++)
    {
        for (int j = 3; j < 7; j += 3)
        {
            Playfield[i][j] = '#';
        }
    }
    Playfield[6][7] = '#';
    Playfield[8][3] = '#';
    Playfield[7][3] = '#';
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (Playfield[i][j] != '#')
                Playfield[i][j] = '.';
        }
    }
    int startx = 1, starty = 1;
    Playfield[startx][starty] = 'P';
    Playfield[4][4] = '@';
    Playfield[8][8] = '@';
    int x, y;
    int a = 4, b = 4, c = 8, d = 8, e = 5, f = 5, g = 4, h = 2, p = 7, q = 5, r = 8, s = 1;

    int ghost[12] = {a, b, c, d, e, f, g, h, p, q, r, s};
    for (int t = 0; t < 70; t++)
    {
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (Playfield[i][j] == '@')
                        Playfield[i][j] = '.';
                }
            }
            for (int i = 0; i < 11; i += 2)
            {
                if (Playfield[ghost[i]][ghost[i + 1] - 1] == '.' || Playfield[ghost[i]][ghost[i + 1] - 1] == ' ')
                {
                    ghost[i + 1] = ghost[i + 1] - 1;
                    Playfield[ghost[i]][ghost[i + 1]] = '@';
                }
                else
                {
                    if (Playfield[ghost[i] - 1][ghost[i + 1]] == '.' || Playfield[ghost[i] - 1][ghost[i + 1]] == ' ')
                    {
                        ghost[i] = ghost[i] - 1;
                        Playfield[ghost[i]][ghost[i + 1]] = '@';
                    }
                    else
                    {
                        if (Playfield[ghost[i]][ghost[i + 1] + 1] == '.' || Playfield[ghost[i]][ghost[i + 1] + 1] == ' ')
                        {
                            ghost[i + 1] = ghost[i + 1] + 1;
                            Playfield[ghost[i]][ghost[i + 1]] = '@';
                        }
                        else
                        {
                            if (Playfield[ghost[i] - 1][ghost[i + 1]] == '.' || Playfield[ghost[i] - 1][ghost[i + 1]] == ' ')
                            {
                                ghost[i] = ghost[i] - 1;
                                Playfield[ghost[i]][ghost[i + 1]] = '@';
                            }
                            else
                                Playfield[ghost[i]][ghost[i + 1]] = '@';
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                printf("%c ", Playfield[i][j]);
            }
            printf("\n");
        }
        char var1 = user_input();
        Playfield[startx][starty] = ' ';
        system("cls");
        if (var1 == 'w' && Playfield[startx - 1][starty] != '#')
        {
            startx--;
            if (Playfield[startx][starty] == '@')
            {
                printf("GAME OVER!! :( \n");
                printf("Score: %d \n", scores);
                printf(" \nEnter 1 to restart the game. ");
                scanf("%d", &z);
                if (z == 1)
                {
                    system("cls");
                    goto label;
                }
                exit(0);
            }
            if (Playfield[startx][starty] == '.')
            {
                scores++;
            }
            Playfield[startx][starty] = 'P';
        }

        if (var1 == 's' && Playfield[startx + 1][starty] != '#')
        {
            startx++;
            if (Playfield[startx][starty] == '@')
            {
                printf("GAME OVER!! :( \n");
                printf("Score: %d \n", scores);
                printf("\nEnter 1 to restart the game. ");
                scanf("%d", &z);
                if (z == 1)
                {
                    system("cls");
                    goto label;
                }
                exit(0);
            }
            if (Playfield[startx][starty] == '.')
            {
                scores++;
            }

            Playfield[startx][starty] = 'P';
        }
        if (var1 == 'a' && Playfield[startx][starty - 1] != '#')
        {
            starty--;
            if (Playfield[startx][starty] == '@')
            {
                printf("GAME OVER!! :( \n");
                printf("\nScore: %d", scores);
                printf("\nEnter 1 to restart the game. ");
                scanf("%d", &z);
                if (z == 1)
                {
                    system("cls");
                    goto label;
                }
                exit(0);
            }
            if (Playfield[startx][starty] == '.')
            {
                scores++;
            }
            Playfield[startx][starty] = 'P';
        }
        if (var1 == 'd' && Playfield[startx][starty + 1] != '#')
        {
            starty++;
            if (Playfield[startx][starty] == '@')
            {
                printf("GAME OVER :(!! \n");
                printf("\nScore: %d", scores);
                printf("\nEnter 1 to restart the game. ");
                scanf("%d", &z);
                if (z == 1)
                {
                    system("cls");
                    goto label;
                }
                exit(0);
            }
            if (Playfield[startx][starty] == '.')
            {
                scores++;
            }
            Playfield[startx][starty] = 'P';
        }

        else
        {
            Playfield[startx][starty] = 'P';
        }
        if (scores == 55)
        {
            printf("\nCongratulations!!! You've Won!! \n");
            /* code */
            printf("Enter 1 to restart the game. \n");
            scanf("%d", &z);
            if (z == 1)

            {
                system("cls");
                goto label;
            }
            exit(0);
        }
    }
}

int main()
{
    Playfield_func();
    return 0;
}

