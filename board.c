#include "board.h"
#include <stdio.h>
#include <string.h>

/*
  Prints the current chess board
*/
void board_print(Board *board){
  for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
    if(i%BOARD_SIZE==0){printf("\n");}
    int piece = PIECE(board->squares[i]);
    char c;
    switch (PIECE(piece)) {
      case EMPTY:
        c = '*';
        break;
      case PAWN:
        c = 'P';
        break;
      case KNIGHT:
        c = 'k';
        break;
      case BISHOP:
        c = 'B';
        break;
      case ROOK:
        c = 'R';
        break;
      case QUEEN:
        c = 'Q';
        break;
      case KING:
        c = 'K';
        break;
    }
    printf("%c ", c);
  }
  printf("\n");
}

/*
  Set a piece
*/
void board_set(Board *board, int pos, int piece){
  board->squares[pos] = piece;
}

/*
  Set all places to empty, should be run on first run to remove rubbish values
*/
void board_clear(Board *board){
  memset(board, EMPTY, sizeof(Board));
}

/*
  Set all pieces as a normal initial chess board
*/
void board_init(Board *board){
  // set black pieces
  board_set(board, POS(0,0), BLACK_ROOK);
  board_set(board, POS(0,1), BLACK_KNIGHT);
  board_set(board, POS(0,2), BLACK_BISHOP);
  board_set(board, POS(0,3), BLACK_QUEEN);
  board_set(board, POS(0,4), BLACK_KING);
  board_set(board, POS(0,5), BLACK_BISHOP);
  board_set(board, POS(0,6), BLACK_KNIGHT);
  board_set(board, POS(0,7), BLACK_ROOK);
  for (unsigned char i = 0; i < 8; i++) {
    board_set(board, POS(1,i), BLACK_PAWN);
  }

  // set white pieces
  board_set(board, POS(7,0), WHITE_ROOK);
  board_set(board, POS(7,1), WHITE_KNIGHT);
  board_set(board, POS(7,2), WHITE_BISHOP);
  board_set(board, POS(7,3), WHITE_QUEEN);
  board_set(board, POS(7,4), WHITE_KING);
  board_set(board, POS(7,5), WHITE_BISHOP);
  board_set(board, POS(7,6), WHITE_KNIGHT);
  board_set(board, POS(7,7), WHITE_ROOK);
  for (unsigned char i = 0; i < 8; i++) {
    board_set(board, POS(6,i), WHITE_PAWN);
  }

}
