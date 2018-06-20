#include <criterion/criterion.h>
#include "move.h"
#include "board.h"

#define TEST_MOVE(var,eq,piece) cr_assert_eq(var, eq, "%s : number of moves %d == %d", piece, var, eq);

int moves[BOARD_SIZE*BOARD_SIZE];
Board b;

void setup(void) {
    board_clear(&b);
}

Test(moves, test_empty_board){

  /* EMPTY BOARD */

  // pawn
  int numMoves = possibleMoves(&b, BLACK_PAWN, POS(0,0),moves);
  TEST_MOVE(numMoves,1,"pawn")
  // ------

  // knight
  numMoves = possibleMoves(&b, BLACK_KNIGHT, POS(0,6),moves);
  TEST_MOVE(numMoves,3,"knight")

  numMoves = possibleMoves(&b, BLACK_KNIGHT, POS(0,7),moves);
  TEST_MOVE(numMoves,2,"knight")
  // ------

  // bishop
  numMoves = possibleMoves(&b, BLACK_BISHOP, POS(0,5),moves);
  TEST_MOVE(numMoves,7,"bishop")
  // ------

  // rook
  numMoves = possibleMoves(&b, BLACK_ROOK, POS(0,7),moves);
  TEST_MOVE(numMoves,14,"rook")
  // ------

  // queen
  numMoves = possibleMoves(&b, BLACK_QUEEN, POS(0,3),moves);
  TEST_MOVE(numMoves,21,"rook")
  // ------
  /* ############ */
}

Test(moves, test_initial_board){
  board_init(&b);

  /* EMPTY BOARD */

  // pawn
  int numMoves = possibleMoves(&b, BLACK_PAWN, POS(1,0),moves);
  TEST_MOVE(numMoves,1,"pawn")
  // ------

  // knight
  numMoves = possibleMoves(&b, BLACK_KNIGHT, POS(0,6),moves);
  TEST_MOVE(numMoves,2,"knight")

  numMoves = possibleMoves(&b, BLACK_KNIGHT, POS(0,7),moves);
  TEST_MOVE(numMoves,1,"knight")
  // ------

  // bishop
  numMoves = possibleMoves(&b, BLACK_BISHOP, POS(0,5),moves);
  TEST_MOVE(numMoves,0,"bishop")
  // ------

  // rook
  numMoves = possibleMoves(&b, BLACK_ROOK, POS(0,7),moves);
  TEST_MOVE(numMoves,0,"rook")
  // ------

  // queen
  numMoves = possibleMoves(&b, BLACK_QUEEN, POS(0,3),moves);
  TEST_MOVE(numMoves,0,"queen")
  // ------
  /* ############ */
}
