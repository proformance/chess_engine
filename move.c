#include "move.h"
#include "board.h"
#include <stdio.h>

/*!
\brief Get possible moves from the current position
\param Pointer to the board used
\param What piece to move
\param The current position of the piece on the board
\return Array of possible moves
*/
int possibleMoves(Board* board, int piece, int pos, int* moves){
  int curRow = ROW(pos);
  int curCol = COL(pos);
  int num_moves = 0;
  int dir = DIRECTION(piece);

  switch (PIECE(piece)) {
    case PAWN:
    tryMoveOnce_noAttack(board, curRow+dir, curCol, moves, &num_moves);
    tryMoveOnce_onlyAttack(board, piece, curRow+dir, curCol+1, moves, &num_moves);
    tryMoveOnce_onlyAttack(board, piece, curRow+dir, curCol-1, moves, &num_moves);
    break;

    case KNIGHT:
    for (int i = -1; i <= 1; i+=2) {
      tryMoveOnce_withAttack(board, piece, curRow+i*2, curCol+1, moves, &num_moves);
      tryMoveOnce_withAttack(board, piece, curRow+i*2, curCol-1, moves, &num_moves);
      tryMoveOnce_withAttack(board, piece, curRow+1, curCol+i*2, moves, &num_moves);
      tryMoveOnce_withAttack(board, piece, curRow-1, curCol+i*2, moves, &num_moves);
    }
    break;

    case BISHOP:
    TRY_MOVE_DIAG_NE(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_DIAG_NW(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_DIAG_SE(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_DIAG_SW(board, curRow, curCol, moves, &num_moves);
    break;

    case ROOK:

    TRY_MOVE_UP(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_DOWN(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_LEFT(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_RIGHT(board, curRow, curCol, moves, &num_moves);

    break;

    case QUEEN:

    // same as bishop
    TRY_MOVE_DIAG_NE(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_DIAG_NW(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_DIAG_SE(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_DIAG_SW(board, curRow, curCol, moves, &num_moves);

    // same as rook
    TRY_MOVE_UP(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_DOWN(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_LEFT(board, curRow, curCol, moves, &num_moves);
    TRY_MOVE_RIGHT(board, curRow, curCol, moves, &num_moves);

    break;

    case KING:
    // same as bishop
    tryMoveOnce_withAttack(board, piece, curRow+1, curCol+1, moves, &num_moves);
    tryMoveOnce_withAttack(board, piece, curRow+1, curCol-1, moves, &num_moves);
    tryMoveOnce_withAttack(board, piece, curRow-1, curCol+1, moves, &num_moves);
    tryMoveOnce_withAttack(board, piece, curRow-1, curCol-1, moves, &num_moves);

    // same as rook
    tryMoveOnce_withAttack(board, piece, curRow+1, curCol, moves, &num_moves);
    tryMoveOnce_withAttack(board, piece, curRow-1, curCol, moves, &num_moves);
    tryMoveOnce_withAttack(board, piece, curRow, curCol+1, moves, &num_moves);
    tryMoveOnce_withAttack(board, piece, curRow, curCol-1, moves, &num_moves);

    break;
  }
  return num_moves;//number of moves
}

void tryMoveOnce_noAttack(Board* board, int row, int col, int* moves, int* num_moves){
  if(VALID_POS(row,col) && VACANT_POS(board,row,col)){
    moves[(*num_moves)++] = POS(row,col);
  }
}

void tryMoveOnce_onlyAttack(Board* board, int piece, int row, int col, int* moves, int* num_moves){
  if(VALID_POS(row,col) && CAN_ATTACK(board, piece, row, col)){
    moves[(*num_moves)++] = POS(row,col);
  }
}

void tryMoveOnce_withAttack(Board* board, int piece, int row, int col, int* moves, int* num_moves){
  if(VALID_POS(row,col) && (VACANT_POS(board,row,col) || CAN_ATTACK(board, piece, row, col))){
    moves[(*num_moves)++] = POS(row,col);
  }
}

void tryMoveRecursive(Board* board, int piece, int row, int col, int* moves, int* num_moves, int directionRow, int directionCol){
  if(VALID_POS(row,col) && VACANT_POS(board,row,col)){
    moves[(*num_moves)++] = POS(row,col);
    tryMoveRecursive(board, piece, row+directionRow, col+directionCol, moves, num_moves, directionRow, directionCol);
  }else if(VALID_POS(row,col) && CAN_ATTACK(board, piece, row, col)){
    moves[(*num_moves)++] = POS(row,col);
  }
}

void print_moves(int* moves, int num_moves){
  if (num_moves == 0) {
    printf("no moves are possible\n");
  }

  for (size_t i = 0; i < num_moves; i++) {
    printf("%d,%d\n", ROW(moves[i]), COL(moves[i]));
  }
}
