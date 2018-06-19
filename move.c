#include "move.h"
#include "board.h"
#include <stdio.h>

bool allowedMove(Board *board, int from, int to){
  return true;
}

int possibleMoves(int piece, int pos, int* moves){
  int curRow = ROW(pos);
  int curCol = COL(pos);
  int num_moves = 0;
  int dir = DIRECTION(piece);

  switch (PIECE(piece)) {
    case PAWN:
      if(VALID_POS(curRow+dir,curCol)){
        moves[num_moves++] = POS(curRow+dir,curCol);
      }
      break;
    case BISHOP:
      for (int i = -BOARD_SIZE; i < BOARD_SIZE; i++) {

        if(!(i == ROW(pos) && i == COL(pos))){
          if(VALID_POS(curRow+i,curCol+i)){
            moves[num_moves++] = POS(curRow+i,curCol+i);
            printf("%d,%d\n", curRow+i,curCol+i);
          }
          if(VALID_POS(curRow+i,curCol-i)){
            moves[num_moves++] = POS(curRow+i,curCol+i);
            printf("%d,%d\n", curRow+i,curCol-i);
          }
        }
      }
      printf("row:%d\n", ROW(pos));
      printf("col:%d\n", COL(pos));
      break;
  }
  return num_moves;//number of moves
}
