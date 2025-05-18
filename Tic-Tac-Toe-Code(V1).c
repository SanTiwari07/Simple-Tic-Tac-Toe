#include <stdio.h>
char mat[3][3];
int player1(int *x, int *y)
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
    return 0;
}
int player2(int *x, int *y)
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
    char input[3][3];
    int z, z1, v, v1;
    for (int a = 0; a < 3; a++)
    {
        for (int s = 0; s < 3; s++)
        {
            input[a][s] = ' ';
        }
    }

    printf("Player is X and Player 2 is O\n");
    printf("Player should start with putting coordinates ie (1 1),(3 2)etc\n");
    for (int a3 = 0; a3 < 4; a3++)
    {
        printf("Player 1 Enter inputs:");
        scanf("%d %d", &z, &v);
        player1(&z, &v);
        if (winner('X'))
        {
            printf("Kudos Player 1 Won!");
            return 0;
        }
        printf("Player 2 Enter inputs:");
        scanf("%d %d", &z1, &v1);
        player2(&z1, &v1);
        if (winner('O'))
        {
            printf("Kudos Player 2 Won!");
            return 0;
        }
    }
    printf("Player 1 Enter inputs:");
    scanf("%d %d", &z, &v);
    player1(&z, &v);
    if (winner('X'))
    {
        printf("Kudos Player 1 Won!");
        return 0;
    }
    else if (winner('O'))
    {
        printf("Kudos Player 2 Won!");
        return 0;
    }
}
