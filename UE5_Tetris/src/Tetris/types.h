#pragma once

#include <assert.h>
#include <stdbool.h>

#define GB_ROWS 22
#define GB_COLS 11

#define MAX_SIZE 4

#define UNUSED(var) ((void)var)

typedef enum {
	color_black = 0x000000U,
	color_red = 0x0000FFU,
	color_green = 0x00FF00U,
	color_blue = 0xFF0000U,
	color_yellow = color_red | color_green,
	color_magenta = color_red | color_blue,
	color_cyan = color_green | color_blue,
	color_white = color_red | color_green | color_blue,
	color_orange = color_red | color_green / 2
} color;

typedef enum { 
	I, 
	O, 
	T, 
	L, 
	J, 
	S, 
	Z 
} shapes;

typedef struct {
	int x, y;
} position;

typedef struct {
	position pos;
	color color;
} block;

typedef struct {
	block blocks[MAX_SIZE][MAX_SIZE];
	shapes shape;
} Tetrimino;

extern void render_quad(const position pos, const color color);
extern void render_block(const block block);
extern void render_Tetrimino(const Tetrimino tetr);
 