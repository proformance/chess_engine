#include <criterion/criterion.h>
#include "move.h"
#include "board.h"

#define TEST_MOVE(var,eq,piece) cr_assert_eq(var, eq, "%s : number of moves == %d, should be %d", piece, var, eq);

int moves[BOARD_SIZE*BOARD_SIZE];
Board b;

void setup(void) {
    printf("clearing board\n");
    board_clear(&b);
}

Test(moves, test_initial_board){

  // set it like a normal initial chess board
  board_init(&b);

  /* INITIAL BOARD */

  // pawn
  int numMoves = possibleMoves(&b, POS(1,0),moves);
  TEST_MOVE(numMoves,1,"pawn")
  // ------

  // knight
  numMoves = possibleMoves(&b, POS(0,6),moves);
  TEST_MOVE(numMoves,2,"knight")
  // ------

  // bishop
  numMoves = possibleMoves(&b, POS(0,5),moves);
  TEST_MOVE(numMoves,0,"bishop")
  // ------

  // rook
  numMoves = possibleMoves(&b, POS(0,7),moves);
  TEST_MOVE(numMoves,0,"rook")
  // ------

  // queen
  numMoves = possibleMoves(&b, POS(0,3),moves);
  TEST_MOVE(numMoves,0,"queen")
  // ------
  /* ############ */
}

Test(moves, test_bishop_corner_board_same_color){

  board_set(&b, POS(0,0), WHITE_BISHOP);
  board_set(&b, POS(6,6), WHITE_BISHOP);
  board_set(&b, POS(7,7), WHITE_BISHOP);

  int numMoves = possibleMoves(&b, POS(0,0),moves);
  TEST_MOVE(numMoves,5,"bishop no attack")
}

Test(moves, test_bishop_corner_board_different_color){

  board_set(&b, POS(0,0), WHITE_BISHOP);
  board_set(&b, POS(6,6), BLACK_BISHOP);
  board_set(&b, POS(7,7), BLACK_BISHOP);

  int numMoves = possibleMoves(&b, POS(0,0),moves);
  TEST_MOVE(numMoves,6,"bishop can attack")
}

Test(moves, test_queen_middle){

  board_set(&b, POS(3,3), WHITE_QUEEN);
  board_set(&b, POS(1,3), WHITE_KING);
  board_set(&b, POS(3,1), WHITE_KING);
  board_set(&b, POS(6,3), WHITE_KING);
  board_set(&b, POS(3,6), WHITE_KING);
  board_set(&b, POS(0,0), BLACK_ROOK);
  board_set(&b, POS(0,6), BLACK_ROOK);
  board_set(&b, POS(6,0), BLACK_ROOK);
  board_set(&b, POS(7,7), BLACK_ROOK);

  int numMoves = possibleMoves(&b, POS(3,3),moves);
  TEST_MOVE(numMoves,19,"queen partly attacking")
}
