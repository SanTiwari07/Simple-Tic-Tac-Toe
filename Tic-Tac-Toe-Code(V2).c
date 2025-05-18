#include <stdio.h>
int a3;
char mat[3][3];
int player1(int *x, int *y)
{
    if (mat[*x - 1][*y - 1] == ' ')
    {
        mat[*x - 1][*y - 1] = 'X';
        printf("\n----------------\n");
        for (int a1 = 0; a1 < 3; a1++)
        {
            printf(" | ");
            for (int s1 = 0; s1 < 3; s1++)
            {
                printf("%c", mat[a1][s1]);
                printf(" | ");
            }
            printf("\n----------------\n");
        }
    }
    else if (mat[*x - 1][*y - 1] == 'X' || mat[*x - 1][*y - 1] == 'O')
    {
        printf("Enter Other coordinate>\n");
        a3--;
    }
    return 0;
}
int player2(int *x, int *y)
{
    if (mat[*x - 1][*y - 1] == ' ')
    {
        mat[*x - 1][*y - 1] = 'O';
        printf("\n----------------\n");
        for (int a1 = 0; a1 < 3; a1++)
        {
            printf(" | ");
            for (int s1 = 0; s1 < 3; s1++)
            {
                printf("%c", mat[a1][s1]);
                printf(" | ");
            }
            printf("\n----------------\n");
        }
    }
    else if (mat[*x - 1][*y - 1] == 'X' || mat[*x - 1][*y - 1] == 'O')
    {
        printf("Enter Other coordinate>\n");
        a3--;
    }
    return 0;
}
int winner(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((mat[i][0] == player && mat[i][1] == player && mat[i][2] == player) || (mat[0][i] == player && mat[1][i] == player && mat[2][i] == player))
        {
            return 1;
        }
    }
    if ((mat[0][0] == player && mat[1][1] == player && mat[2][2] == player) || (mat[0][2] == player && mat[1][1] == player && mat[2][0] == player))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int z, z1, v, v1;
    a3 = 0;
    for (int a = 0; a < 3; a++)
    {
        for (int s = 0; s < 3; s++)
        {
            mat[a][s] = ' ';
        }
    }

    printf("Player is X and Player 2 is O\n");
    printf("Player should start with putting coordinates ie (1 1),(3 2)etc\n");
    int a3 = 0;

    while (a3 < 9)
    {
        do
        {
            printf("Player 1 Enter inputs: ");
            scanf("%d %d", &z, &v);
        } while (z < 1 || z > 3 || v < 1 || v > 3 || mat[z - 1][v - 1] != ' ');
        player1(&z, &v);
        if (winner('X'))
        {
            printf("Kudos Player 1 Won!\n");
            return 0;
        }
        a3++;
        if (a3 == 9)
            break;
        do
        {
            printf("Player 2 Enter inputs: ");
            scanf("%d %d", &z1, &v1);
        } while (z1 < 1 || z1 > 3 || v1 < 1 || v1 > 3 || mat[z1 - 1][v1 - 1] != ' ');
        player2(&z1, &v1);
        if (winner('O'))
        {
            printf("Kudos Player 2 Won!\n");
            return 0;
        }
        a3++;
    }
    printf("No one Won!\n");
    return 0;
}
