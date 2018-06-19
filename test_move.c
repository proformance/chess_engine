#include <criterion/criterion.h>
#include "move.h"
#include "board.h"

Test(simple, test){
  int moves[BOARD_SIZE*BOARD_SIZE];

  int numMoves = possibleMoves(BLACK_PAWN, POS(0,0),moves);
  cr_assert_eq(numMoves, 1, "number of moves %d == %d", numMoves, 1);

  numMoves = possibleMoves(BLACK_BISHOP, POS(3,3),moves);
  /** cr_assert_eq(numMoves, 2, "number of moves %d == %d", numMoves, 2); */



  /** for(int i = 0; i < numMoves; i++){ */
  /**   printf("%d,%d\n", ROW(moves[i]),COL(moves[i])); */
  /** } */
}
