
#include <stdio.h>

#define ROW 2UL
#define COL 5UL

void fun(size_t row, size_t col, int ary[row][col]);
void fuz(size_t row, size_t col, int * ary);

int main() {
  int ary[][COL] = {
    { 10, 11, 12, 13, 14, },
    { 21, 22, 22, 23, 24, },
    { 31, 32, 33, 33, 34, },
  };
  printf("bytes     %3zu\n", sizeof(ary));
  printf("bytes/row %3zu\n", sizeof(ary[0]));
  printf("each cell %3zu\n", sizeof(ary[0][0]));
  size_t ary_b = sizeof(ary);
  size_t ary_r = sizeof(ary) / sizeof(ary[0]);
  size_t ary_e = sizeof(ary) / sizeof((ary[0][0]));
  printf("bytes %3zu, "
         "rows  %3zu, "
         "cells %3zu\n\n", ary_b, ary_r, ary_e);

  fun(ary_r, COL, ary);
  fuz(ary_r, COL, (int *) ary);

  return 0;
}

void fun(size_t row, size_t col, int ary[row][col]) {
  printf("In: %s\n", __func__);
  for (size_t r_ = 0; r_ < row; ++r_) {
    for (size_t c_ = 0; c_ < col; ++c_) {
      printf("%3d", ary[r_][c_]);
    }
    putchar('\n');
  }
  putchar('\n');
}

void fuz(size_t row, size_t col, int * ary) {
  printf("In: %s\n", __func__);
  for (size_t r_ = 0; r_ < row; ++r_) {
    for (size_t c_ = 0; c_ < col; ++c_) {
      printf(" [%zu][%zu] %3d", r_, c_, *(ary + r_ * col + c_));
    }
    putchar('\n');
  }
  putchar('\n');

  for (size_t e_ = 0, cc = 0; e_ < row * col; ++e_) {
    printf("%3d%s", ary[e_], (++cc % col == 0 ? "\n" : ", "));
  }
}
