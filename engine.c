#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "board.h"
#include "move.h"
#include "headers.h"

int main(int argc, char const* argv[])
{
  Board b;

  board_clear(&b);
  board_init(&b);
  board_print(&b);

  int* moves = (int*)malloc(sizeof(int)*64);
  printf("number of moves: %d\n", possibleMoves(BLACK_PAWN, 4, moves));
  return 0;

}
