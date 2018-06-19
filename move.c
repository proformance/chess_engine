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

  int rad;

  switch (PIECE(piece)) {
    case PAWN:
      if(VALID_POS(curRow+dir,curCol)){
        moves[num_moves++] = POS(curRow+dir,curCol);
      }
      break;

    case KNIGHT:
      for (rad = -1; rad <= 1; rad+=2) {
        if(VALID_POS(curRow+rad*2,curCol+1)){
          moves[num_moves++] = POS(curRow+rad,curCol+1);
        }
        if(VALID_POS(curRow+rad*2,curCol-1)){
          moves[num_moves++] = POS(curRow+rad,curCol-1);
        }
        if(VALID_POS(curRow+1,curCol+rad*2)){
          moves[num_moves++] = POS(curRow+1,curCol+rad*2);
        }
        if(VALID_POS(curRow+rad-1,curCol+rad*2)){
          moves[num_moves++] = POS(curRow+rad-1,curCol+rad*2);
        }
      }
      break;

    case BISHOP:
      for (rad = 1; rad < BOARD_SIZE; rad++) {

        if(VALID_POS(curRow+rad,curCol+rad)){
          moves[num_moves++] = POS(curRow+rad,curCol+rad);
        }
        if(VALID_POS(curRow+rad,curCol-rad)){
          moves[num_moves++] = POS(curRow+rad,curCol-rad);
        }
        if(VALID_POS(curRow-rad,curCol+rad)){
          moves[num_moves++] = POS(curRow-rad,curCol+rad);
        }
        if(VALID_POS(curRow-rad,curCol-rad)){
          moves[num_moves++] = POS(curRow-rad,curCol-rad);
        }

      }
      break;

      case ROOK:
        for (rad = 1; rad < BOARD_SIZE; rad++) {

          if(VALID_POS(curRow+rad,curCol)){
            moves[num_moves++] = POS(curRow+rad,curCol);
          }
          if(VALID_POS(curRow-rad,curCol)){
            moves[num_moves++] = POS(curRow-rad,curCol);
          }
          if(VALID_POS(curRow,curCol+rad)){
            moves[num_moves++] = POS(curRow,curCol+rad);
          }
          if(VALID_POS(curRow,curCol-rad)){
            moves[num_moves++] = POS(curRow,curCol-rad);
          }

        }
        break;

        case QUEEN:
          for (rad = 1; rad < BOARD_SIZE; rad++) {

            // same as bishop
            if(VALID_POS(curRow+rad,curCol+rad)){
              moves[num_moves++] = POS(curRow+rad,curCol+rad);
            }
            if(VALID_POS(curRow+rad,curCol-rad)){
              moves[num_moves++] = POS(curRow+rad,curCol-rad);
            }
            if(VALID_POS(curRow-rad,curCol+rad)){
              moves[num_moves++] = POS(curRow-rad,curCol+rad);
            }
            if(VALID_POS(curRow-rad,curCol-rad)){
              moves[num_moves++] = POS(curRow-rad,curCol-rad);
            }

            // same as rook
            if(VALID_POS(curRow+rad,curCol)){
              moves[num_moves++] = POS(curRow+rad,curCol);
            }
            if(VALID_POS(curRow-rad,curCol)){
              moves[num_moves++] = POS(curRow-rad,curCol);
            }
            if(VALID_POS(curRow,curCol+rad)){
              moves[num_moves++] = POS(curRow,curCol+rad);
            }
            if(VALID_POS(curRow,curCol-rad)){
              moves[num_moves++] = POS(curRow,curCol-rad);
            }

          }
          break;

          case KING:
            // same as queen but only rad = 1
            rad = 1;

            // same as bishop
            if(VALID_POS(curRow+rad,curCol+rad)){
              moves[num_moves++] = POS(curRow+rad,curCol+rad);
            }
            if(VALID_POS(curRow+rad,curCol-rad)){
              moves[num_moves++] = POS(curRow+rad,curCol-rad);
            }
            if(VALID_POS(curRow-rad,curCol+rad)){
              moves[num_moves++] = POS(curRow-rad,curCol+rad);
            }
            if(VALID_POS(curRow-rad,curCol-rad)){
              moves[num_moves++] = POS(curRow-rad,curCol-rad);
            }

            // same as rook
            if(VALID_POS(curRow+rad,curCol)){
              moves[num_moves++] = POS(curRow+rad,curCol);
            }
            if(VALID_POS(curRow-rad,curCol)){
              moves[num_moves++] = POS(curRow-rad,curCol);
            }
            if(VALID_POS(curRow,curCol+rad)){
              moves[num_moves++] = POS(curRow,curCol+rad);
            }
            if(VALID_POS(curRow,curCol-rad)){
              moves[num_moves++] = POS(curRow,curCol-rad);
            }

            break;
  }
  return num_moves;//number of moves
}
