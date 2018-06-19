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

  int rad;

  switch (PIECE(piece)) {
    case PAWN:
      tryMove(board, curRow+dir, curCol, moves, &num_moves);
      break;

    case KNIGHT:
      for (rad = -1; rad <= 1; rad+=2) {

        tryMove(board, curRow+rad*2, curCol+1, moves, &num_moves);
        tryMove(board, curRow+rad*2, curCol-1, moves, &num_moves);
        tryMove(board, curRow+1, curCol+rad*2, moves, &num_moves);
        tryMove(board, curRow-1, curCol+rad*2, moves, &num_moves);

      }
      break;

    case BISHOP:
      for (rad = 1; rad < BOARD_SIZE; rad++) {

        tryMove(board, curRow+rad, curCol+rad, moves, &num_moves);
        tryMove(board, curRow+rad, curCol-rad, moves, &num_moves);
        tryMove(board, curRow-rad, curCol+rad, moves, &num_moves);
        tryMove(board, curRow-rad, curCol-rad, moves, &num_moves);

      }
      break;

      case ROOK:
        for (rad = 1; rad < BOARD_SIZE; rad++) {

          tryMove(board, curRow+rad, curCol, moves, &num_moves);
          tryMove(board, curRow-rad, curCol, moves, &num_moves);
          tryMove(board, curRow, curCol+rad, moves, &num_moves);
          tryMove(board, curRow, curCol-rad, moves, &num_moves);

        }
        break;

        case QUEEN:
          for (rad = 1; rad < BOARD_SIZE; rad++) {

            // same as bishop
            tryMove(board, curRow+rad, curCol+rad, moves, &num_moves);
            tryMove(board, curRow+rad, curCol-rad, moves, &num_moves);
            tryMove(board, curRow-rad, curCol+rad, moves, &num_moves);
            tryMove(board, curRow-rad, curCol-rad, moves, &num_moves);

            // same as rook
            tryMove(board, curRow+rad, curCol, moves, &num_moves);
            tryMove(board, curRow-rad, curCol, moves, &num_moves);
            tryMove(board, curRow, curCol+rad, moves, &num_moves);
            tryMove(board, curRow, curCol-rad, moves, &num_moves);

          }
          break;

          case KING:
            // same as queen but only rad = 1
            rad = 1;

            // same as bishop
            tryMove(board, curRow+rad, curCol+rad, moves, &num_moves);
            tryMove(board, curRow+rad, curCol-rad, moves, &num_moves);
            tryMove(board, curRow-rad, curCol+rad, moves, &num_moves);
            tryMove(board, curRow-rad, curCol-rad, moves, &num_moves);

            // same as rook
            tryMove(board, curRow+rad, curCol, moves, &num_moves);
            tryMove(board, curRow-rad, curCol, moves, &num_moves);
            tryMove(board, curRow, curCol+rad, moves, &num_moves);
            tryMove(board, curRow, curCol-rad, moves, &num_moves);

            break;
  }
  return num_moves;//number of moves
}

bool tryMove(Board* board, int row, int col, int* moves, int* num_moves){
  if(VALID_POS(row,col) && VACANT_POS(board,row,col)){
    moves[(*num_moves)++] = POS(row,col);
    return true;
  }
  return false;
}

void tryMoveRecursive(Board* board, int row, int col, int* moves, int* num_moves, int directionRow, int directionCol){
  if(VALID_POS(row,col) && VACANT_POS(board,row,col)){
    moves[(*num_moves)++] = POS(row,col);
    tryMoveRecursive(board, row+1, col, moves, num_moves, directionRow, directionCol);
  }
}
