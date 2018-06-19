
#ifndef BOARD_H
#define BOARD_H

enum type{
  EMPTY = 0x00,
  PAWN = 0x01,
  KNIGHT = 0x02,
  BISHOP = 0x03,
  ROOK = 0x04,
  QUEEN = 0x05,
  KING = 0x06
};

enum color{
  WHITE = 0x00,
  BLACK = 0x10
};


#define WHITE_PAWN (PAWN | WHITE)
#define WHITE_KNIGHT (KNIGHT | WHITE)
#define WHITE_BISHOP (BISHOP | WHITE)
#define WHITE_ROOK (ROOK | WHITE)
#define WHITE_QUEEN (QUEEN | WHITE)
#define WHITE_KING (KING | WHITE)

#define BLACK_PAWN (PAWN | BLACK)
#define BLACK_KNIGHT (KNIGHT | BLACK)
#define BLACK_BISHOP (BISHOP | BLACK)
#define BLACK_ROOK (ROOK | BLACK)
#define BLACK_QUEEN (QUEEN | BLACK)
#define BLACK_KING (KING | BLACK)

#define BOARD_SIZE 8

#define PIECE(x) ((x) & 0x0F)
#define COLOR(x) ((x) & 0x10)

#define POS(row,col) (row*BOARD_SIZE+col)
#define VALID_POS(row,col) ((row >= 0 && row < BOARD_SIZE) && \
                           (col >= 0 && col < BOARD_SIZE))

#define VACANT_POS(board,row,col) (board->squares[POS(row,col)] == EMPTY)

#define GET_PIECE(board,row,col) (board->squares[POS(row,col)])

#define DIRECTION(x) (PIECE(x)==BLACK ? -1 : 1)

#define ROW(x) x/BOARD_SIZE
#define COL(x) x%BOARD_SIZE

typedef struct{
  int squares[BOARD_SIZE*BOARD_SIZE];
  int current_color;
} Board;

typedef struct{
  unsigned char row;
  unsigned char col;
} Position;

void board_print(Board *board);
void board_set(Board *board, int pos, int piece);
void board_clear(Board *board);
void board_init(Board *board);

#endif
