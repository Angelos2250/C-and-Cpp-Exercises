#include <stdlib.h>
#include "current_block.h"
#include "game_board.h"

bool cb_try_move_block(block bl, int dx, int dy) {
	position pos = bl.pos;
	pos.x += dx;
	pos.y += dy;
	if (!gb_is_valid_position(pos))
		return false;

	return true;
}

void cb_move_block(block* bl, int dx, int dy) {
	bl->pos.x += dx;
	bl->pos.y += dy;
}

void cb_render(block block) {
	render_block(block);
}

block cb_new_block_color(color color) {
	block b;
	b.pos.x = GB_COLS / 2;
	b.pos.y = GB_ROWS - 1;
	b.color = color;

	return b;
}