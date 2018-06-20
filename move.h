#ifndef MOVE_H
#define MOVE_H

#include "board.h"
#include "headers.h"

int possibleMoves(Board* board, int piece, int pos, int* moves);

bool tryMoveOnce(Board* board, int row, int col, int* moves, int* numMoves);
void tryMoveRecursive(Board* board, int piece, int row, int col, int* moves, int* num_moves, int directionRow, int directionCol);

#define TRY_MOVE_UP(board, row, col, moves, num_moves) tryMoveRecursive(board, GET_PIECE(board,row,col), row+1, col, moves, num_moves, 1, 0)
#define TRY_MOVE_DOWN(board, row, col, moves, num_moves) tryMoveRecursive(board, GET_PIECE(board,row,col), row-1, col, moves, num_moves, -1, 0)
#define TRY_MOVE_LEFT(board, row, col, moves, num_moves) tryMoveRecursive(board, GET_PIECE(board,row,col), row, col-1, moves, num_moves, 0, -1)
#define TRY_MOVE_RIGHT(board, row, col, moves, num_moves) tryMoveRecursive(board, GET_PIECE(board,row,col), row, col+1, moves, num_moves, 0, 1)
#define TRY_MOVE_DIAG_NE(board, row, col, moves, num_moves) tryMoveRecursive(board, GET_PIECE(board,row,col), row+1, col+1, moves, num_moves, 1, 1)
#define TRY_MOVE_DIAG_NW(board, row, col, moves, num_moves) tryMoveRecursive(board, GET_PIECE(board,row,col), row+1, col-1, moves, num_moves, 1, -1)
#define TRY_MOVE_DIAG_SE(board, row, col, moves, num_moves) tryMoveRecursive(board, GET_PIECE(board,row,col), row-1, col+1, moves, num_moves, -1, 1)
#define TRY_MOVE_DIAG_SW(board, row, col, moves, num_moves) tryMoveRecursive(board, GET_PIECE(board,row,col), row-1, col-1, moves, num_moves, -1, -1)

#endif
