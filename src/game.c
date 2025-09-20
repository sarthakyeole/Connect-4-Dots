#include "game.h"
#include <string.h>
#include <stdio.h>

// logic main
Player calculate_winner(Game *game)
{
    if (game->current_move < bwidth)
        return player_none;

    int directions[4][2] = {
        {0, 1},
        {1, 0},
        {1, 1},
        {-1, 1}};

    for (int row = 0; row < bheight; row++)
    {
        for (int col = 0; col < bwidth; col++)
        {
            int cell = game->board[row][col];
            if (cell == 0)
                continue;

            for (int d = 0; d < 4; d++)
            {
                int dr = directions[d][0];
                int dc = directions[d][1];
                int count = 1;

                int r = row + dr;
                int c = col + dc;

                while (r >= 0 && r < bheight && c >= 0 && c < bwidth && game->board[r][c] == cell)
                {
                    count++;
                    if (count == 4)
                    {
                        game->is_finished = true;
                        return (Player)cell;
                    }
                    r += dr;
                    c += dc;
                }
            }
        }
    }

    if (game->current_move >= bwidth * bheight)
    {
        game->is_finished = true;
    }
    return player_none;
}

bool play_move(Game *game, int column)
{
    if (game->is_finished)
    {
        return false;
    }

    if (column < 0 || column >= bwidth)
    {
        return false;
    }

    int row_to_place = -1;
    for (int row = bheight - 1; row >= 0; row--)
    {
        if (game->board[row][column] == 0)
        {
            row_to_place = row;
            break;
        }
    }

    if (row_to_place == -1)
    {
        return false; // column_full
    }

    game->board[row_to_place][column] = game->current_player;
    game->current_move++;

    Player winner = calculate_winner(game);
    if (winner != player_none)
    {
        game->winner = winner;
    }
    else
    {
        game->current_player = (game->current_player == player_one) ? player_two : player_one;
    }

    return true;
}

Game new_game()
{
    Game g;
    g.current_move = 0;
    g.current_player = player_one;
    g.is_finished = false;
    g.winner = player_none;
    memset(g.board, 0, sizeof(g.board));
    return g;
}