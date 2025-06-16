#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

void print_arrow(int leftCol, int size)
{
  int tHeight = (size + 1) / 2;   /*top half of size for triangle*/
  int sHeight = size - tHeight;  /*bottom half for square (shaft)*/
  int center = leftCol + tHeight; /*shaft center*/
  
  for (int row = 0; row < tHeight; row++){ /*triangle logic*/
    int minCol = center - row;
    int maxCol = center + row;
    for (int col = 0; col < minCol; col++) putchar(' ');
    for (int col = minCol; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
  for (int row = 0; row < sHeight; row++){ /*square logic*/
    for (int col = 0; col < center; col++) putchar(' ');
    putchar('*');
    putchar('\n');
  }
}
