#include "game.h"
#include <string.h>
#include <stdio.h>

// ---------- Game Logic ----------
Player calculate_winner(Game *game) {
    if (game->current_move < BOARD_WIDTH) return PLAYER_NONE;

    int directions[4][2] = {
        {0, 1},   // horizontal
        {1, 0},   // vertical
        {1, 1},   // diagonal ↘
        {-1, 1}   // diagonal ↗
    };

    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            int cell = game->board[row][col];
            if (cell == 0) continue;

            for (int d = 0; d < 4; d++) {
                int dr = directions[d][0];
                int dc = directions[d][1];
                int count = 1;

                int r = row + dr;
                int c = col + dc;

                while (r >= 0 && r < BOARD_HEIGHT &&
                       c >= 0 && c < BOARD_WIDTH &&
                       game->board[r][c] == cell) {
                    count++;
                    if (count == 4) {
                        game->is_finished = true;
                        return (Player)cell;
                    }
                    r += dr;
                    c += dc;
                }
            }
        }
    }

    if (game->current_move >= BOARD_WIDTH * BOARD_HEIGHT) {
        game->is_finished = true;
    }
    return PLAYER_NONE;
}

bool play_move(Game *game, int column) {
    if (game->is_finished) {
        return false;
    }

    if (column < 0 || column >= BOARD_WIDTH) {
        return false;
    }

    int row_to_place = -1;
    for (int row = BOARD_HEIGHT - 1; row >= 0; row--) {
        if (game->board[row][column] == 0) {
            row_to_place = row;
            break;
        }
    }

    if (row_to_place == -1) {
        return false; // column is full
    }

    game->board[row_to_place][column] = game->current_player;
    game->current_move++;

    Player winner = calculate_winner(game);
    if (winner != PLAYER_NONE) {
        game->winner = winner;
    } else {
        game->current_player =
            (game->current_player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
    }

    return true;
}

Game new_game() {
    Game g;
    g.current_move = 0;
    g.current_player = PLAYER_ONE;
    g.is_finished = false;
    g.winner = PLAYER_NONE;
    memset(g.board, 0, sizeof(g.board));
    return g;
}
