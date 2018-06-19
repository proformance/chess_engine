#include <criterion/criterion.h>
#include "move.h"
#include "board.h"

#define TEST_MOVE(var,eq,piece) cr_assert_eq(var, eq, "%s : number of moves %d == %d", piece, var, eq);

Test(simple, test){
  int moves[BOARD_SIZE*BOARD_SIZE];

  /* EMPTY BOARD */

  // pawn
  int numMoves = possibleMoves(BLACK_PAWN, POS(0,0),moves);
  TEST_MOVE(numMoves,1,"pawn")
  // ------

  // knight
  numMoves = possibleMoves(BLACK_KNIGHT, POS(0,6),moves);
  TEST_MOVE(numMoves,3,"knight")

  numMoves = possibleMoves(BLACK_KNIGHT, POS(0,7),moves);
  TEST_MOVE(numMoves,2,"knight")
  // ------

  // bishop
  numMoves = possibleMoves(BLACK_BISHOP, POS(0,5),moves);
  TEST_MOVE(numMoves,7,"bishop")
  // ------

  // rook
  numMoves = possibleMoves(BLACK_ROOK, POS(0,7),moves);
  TEST_MOVE(numMoves,14,"rook")
  // ------

  // queen
  numMoves = possibleMoves(BLACK_QUEEN, POS(0,3),moves);
  TEST_MOVE(numMoves,21,"rook")
  // ------
  /* ############ */
}
