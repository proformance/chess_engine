#ifndef MOVE_H
#define MOVE_H

#include "board.h"
#include "headers.h"

bool allowedMove(Board *board, int from, int to);
int possibleMoves(int piece, int pos, int* moves);

#endif
