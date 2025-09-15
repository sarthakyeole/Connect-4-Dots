#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

// ---------- Constants ----------
#define BOARD_WIDTH 7
#define BOARD_HEIGHT 6

// ---------- Enums & Structs ----------
typedef enum {
    PLAYER_NONE = 0,
    PLAYER_ONE = 1,
    PLAYER_TWO = 2
} Player;

typedef struct {
    int current_move;
    Player current_player;
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    bool is_finished;
    Player winner;
} Game;

// ---------- Function Declarations ----------
// game.c
Game new_game();
bool play_move(Game *game, int column);
Player calculate_winner(Game *game);

// ui.c
void clear_screen();
void display_board(Game *game);
void display_error(Game *game, const char *error);

#endif
