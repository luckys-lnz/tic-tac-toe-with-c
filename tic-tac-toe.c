#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* A tic-tac-toe-game */

char board[3][3];
const char PLAYER = 'O';
const char COMPUTER = 'X';

void resetBoard();
void printBoard();
int checkFreeSpace();
void playerMove();
void computerMove();
char checkWinner();
void printWinner();

int main()
{
    char winner = 'X';

    resetBoard();
    while (winner == ' ' && checkFreeSpace() != 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner == ' ' || checkFreeSpace() == 0)
        {
            break;
        }

        computerMove();
        winner = checkWinner();
        if (winner == ' ' || checkFreeSpace() == 0)
        {
            break;
        }
    };
    return 0;
};

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        };
    };
};

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");
    printf("\n");
};

int checkFreeSpace()
{
    int freSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freSpaces--;
            }
        }
    }
    return freSpaces;
};

void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row #(1 - 3): ");
        scanf("%d", &x);
        x--;
        printf("Enter col #(1 - 3): ");
        scanf("%d", &y);
        y--;

        /* check if the coordinates are occupied or not */
        if (board[x][y] != ' ')
        {
            printf("Move invalid");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
};

void computerMove();

char checkWinner()
{
    /* iterate over rows and cols to find winner */
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    /* cols Check */
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[i][0];
        }
    }

    /* checking the diagonals */
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

void printWinner();
