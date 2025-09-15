#include "game.h"
#include <stdio.h>

// ANSI escape codes for color
#define RESET "\x1b[0m"
#define ORANGE "\x1b[93m"
#define RED "\x1b[0;31m"

void clear_screen()
{
    printf("%c[2J", 27);
}

void display_board(Game *game)
{
    clear_screen();
    printf("%s--------------------%s\n", ORANGE, RESET);
    printf("%sCONNECT 4 (Move %d)%s\n", ORANGE, game->current_move, RESET);
    printf("%s--------------------%s\n", ORANGE, RESET);

    for (int row = 0; row < BOARD_HEIGHT; row++)
    {
        for (int col = 0; col < BOARD_WIDTH; col++)
        {
            switch (game->board[row][col])
            {
            case PLAYER_ONE:
                printf("🔴 ");
                break;
            case PLAYER_TWO:
                printf("🟡 ");
                break;
            default:
                printf("⚫ ");
                break;
            }
        }
        printf("\n");
    }

    printf("%s--------------------%s\n", ORANGE, RESET);

    if (game->is_finished)
    {
        if (game->winner == PLAYER_ONE)
        {
            printf("%s🔴 Player 1 has won!%s\n", ORANGE, RESET);
        }
        else if (game->winner == PLAYER_TWO)
        {
            printf("%s🟡 Player 2 has won!%s\n", ORANGE, RESET);
        }
        else
        {
            printf("%sIt's a draw!%s\n", ORANGE, RESET);
        }
        printf("%s--------------------%s\n", ORANGE, RESET);
    }
}

void display_error(Game *game, const char *error)
{
    display_board(game);
    printf("%sError: %s%s\n", RED, error, RESET);
}
