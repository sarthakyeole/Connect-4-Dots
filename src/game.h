#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

// borad size
#define bwidth 7
#define bheight 6

// structs and enums
typedef enum
{
    player_none = 0,
    player_one = 1,
    player_two = 2
} Player;

typedef struct
{
    int current_move;
    Player current_player;
    int board[bheight][bwidth];
    bool is_finished;
    Player winner;
} Game;

// functions
// game.c
Game new_game();
bool play_move(Game *game, int column);
Player calculate_winner(Game *game);

// ui.c
void clear_screen();
void display_board(Game *game);
void display_error(Game *game, const char *error);

#endif
