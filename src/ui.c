#include "game.h"
#include <stdio.h>

// ansi codes
#define reset "\x1b[0m"
#define orange "\x1b[93m"
#define red "\x1b[0;31m"

void clear_screen()
{
    printf("%c[2J", 27);
}

void display_board(Game *game)
{
    clear_screen();
    printf("%s--------------------%s\n", orange, reset);
    printf("%sCONNECT 4 (Move %d)%s\n", orange, game->current_move, reset);
    printf("%s--------------------%s\n", orange, reset);

    for (int row = 0; row < bheight; row++)
    {
        for (int col = 0; col < bwidth; col++)
        {
            if (game->board[row][col] == 1)
            {
                printf("🔴 ");
            }
            else if (game->board[row][col] == 2)
            {
                printf("🟡 ");
            }
            else
            {
                printf("⚫ ");
            }
        }
        printf("\n");
    }

    printf("%s--------------------%s\n", orange, reset);

    if (game->is_finished)
    {
        if (game->winner == player_one)
        {
            printf("%s🔴 Player 1 has won!%s\n", orange, reset);
        }
        else if (game->winner == player_two)
        {
            printf("%s🟡 Player 2 has won!%s\n", orange, reset);
        }
        else
        {
            printf("%sIt's a draw!%s\n", orange, reset);
        }
        printf("%s--------------------%s\n", orange, reset);
    }
}

void display_error(Game *game, const char *error)
{
    display_board(game);
    printf("%sError: %s%s\n", red, error, reset);
}
