#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Game game = new_game();
    display_board(&game);

    while (1)
    {
        while (!game.is_finished)
        {
            printf("\n");
            if (game.current_player == PLAYER_ONE)
                printf("PLAYER 1\n");
            else
                printf("PLAYER 2\n");

            printf("Enter a column between 1 and 7: ");
            char input[16];
            if (!fgets(input, sizeof(input), stdin))
                continue;

            int col = atoi(input);
            if (col < 1 || col > 7)
            {
                display_error(&game, "column must be between 1 and 7");
                continue;
            }

            if (play_move(&game, col - 1))
            {
                display_board(&game);
            }
            else
            {
                display_error(&game, "invalid move (column full or finished)");
            }
        }

        printf("Press 'R' to restart or 'Q' to quit the game: ");
        char choice[16];
        if (!fgets(choice, sizeof(choice), stdin))
            continue;

        if (choice[0] == 'R' || choice[0] == 'r')
        {
            game = new_game();
            display_board(&game);
        }
        else if (choice[0] == 'Q' || choice[0] == 'q')
        {
            printf("Quitting...\n");
            break;
        }
        else
        {
            display_error(&game, "invalid input");
        }
    }

    return 0;
}
