#include "Tetriminos.h"

static Tetrimino current;

static shapes random_shape(void);
static void init_shape(void);

static color random_color() {
	static color colors[] = { color_red, color_blue, color_green,color_yellow,color_magenta,color_cyan };
	int n_color = sizeof(colors) / sizeof(colors[0]);
	return colors[rand() % n_color];
}

bool tt_try_move(int dx, int dy) {
	for (int r = 0; r < MAX_SIZE; r++) {
		for (int c = 0; c < MAX_SIZE; c++) {
			if (is_block(current.blocks[r][c])) {
				if (!cb_try_move_block(current.blocks[r][c], dx, dy))
					return false;
			}
		}
	}

	for (int r = 0; r < MAX_SIZE; r++) {
		for (int c = 0; c < MAX_SIZE; c++) {
			if (is_block(current.blocks[r][c]))
				cb_move_block(&(current.blocks[r][c]), dx, dy);
		}
	}
	return true;
}




void tt_render(void) {
	render_Tetrimino(current);
}

Tetrimino tt_new_tetrimino(void) {
	current.shape = random_shape();
	init_shape();
}

void init_i(void) {
	color randcol = random_color();
	current.blocks[0][1] = cb_new_block_color(randcol);
	current.blocks[1][1] = cb_new_block_color(randcol);
	current.blocks[1][1].pos.y -= 1;
	current.blocks[2][1] = cb_new_block_color(randcol);
	current.blocks[2][1].pos.y -= 2;
	current.blocks[3][1] = cb_new_block_color(randcol);
	current.blocks[3][1].pos.y -= 3;
}

void init_o(void) {
	color randcol = random_color();
	current.blocks[2][1] = cb_new_block_color(randcol);
	current.blocks[2][2] = cb_new_block_color(randcol);
	current.blocks[2][2].pos.x += 1;
	current.blocks[3][1] = cb_new_block_color(randcol);
	current.blocks[3][1].pos.y -= 1;
	current.blocks[3][2] = cb_new_block_color(randcol);
	current.blocks[3][2].pos.x += 1;
	current.blocks[3][2].pos.y -= 1;
}

void init_t(void) {
	color randcol = random_color();
	current.blocks[0][1] = cb_new_block_color(randcol);
	current.blocks[1][0] = cb_new_block_color(randcol);
	current.blocks[1][0].pos.x -= 1;
	current.blocks[1][0].pos.y -= 1;
	current.blocks[1][1] = cb_new_block_color(randcol);
	current.blocks[1][1].pos.y -= 1;
	current.blocks[1][2] = cb_new_block_color(randcol);
	current.blocks[1][2].pos.x += 1;
	current.blocks[1][2].pos.y -= 1;
}

void init_j(void) {
	color randcol = random_color();
	current.blocks[0][1] = cb_new_block_color(randcol);
	current.blocks[1][1] = cb_new_block_color(randcol);
	current.blocks[1][1].pos.y -= 1;
	current.blocks[2][1] = cb_new_block_color(randcol);
	current.blocks[2][1].pos.y -= 2;
	current.blocks[2][0] = cb_new_block_color(randcol);
	current.blocks[2][0].pos.x -= 1;
	current.blocks[2][0].pos.y -= 2;
}

void init_l(void) {
	color randcol = random_color();
	current.blocks[0][1] = cb_new_block_color(randcol);
	current.blocks[1][1] = cb_new_block_color(randcol);
	current.blocks[1][1].pos.y -= 1;
	current.blocks[2][1] = cb_new_block_color(randcol);
	current.blocks[2][1].pos.y -= 2;
	current.blocks[2][2] = cb_new_block_color(randcol);
	current.blocks[2][2].pos.x += 1;
	current.blocks[2][2].pos.y -= 2;
}

void init_s(void) {
	color randcol = random_color();
	current.blocks[0][1] = cb_new_block_color(randcol);
	current.blocks[0][2] = cb_new_block_color(randcol);
	current.blocks[0][2].pos.x += 1;
	current.blocks[1][1] = cb_new_block_color(randcol);
	current.blocks[1][1].pos.y -= 1;
	current.blocks[1][0] = cb_new_block_color(randcol);
	current.blocks[1][0].pos.x -= 1;
	current.blocks[1][0].pos.y -= 1;
}

void init_z(void) {
	color randcol = random_color();
	current.blocks[0][0] = cb_new_block_color(randcol);
	current.blocks[0][0].pos.x -= 1;
	current.blocks[0][1] = cb_new_block_color(randcol);
	current.blocks[1][1] = cb_new_block_color(randcol);
	current.blocks[1][1].pos.y -= 1;
	current.blocks[1][2] = cb_new_block_color(randcol);
	current.blocks[1][2].pos.x += 1;
	current.blocks[1][2].pos.y -= 1;

}

void reset_blocks(void) {
	for (int r = 0; r < MAX_SIZE; r++) {
		for (int c = 0; c < MAX_SIZE; c++) {
			current.blocks[r][c].pos.x = -1;
			current.blocks[r][c].pos.y = -1;
		}
	}
}

void init_shape(void) {

	reset_blocks();

	switch (current.shape) {
	case I:
		init_i();
		break;
	case O:
		init_o();
		break;
	case T:
		init_t();
		break;
	case J:
		init_j();
		break;
	case L:
		init_l();
		break;
	case S:
		init_s();
		break;
	case Z:
		init_z();
		break;
	}
}

bool is_block(block bl) {
	return (bl.pos.x >= 0) || (bl.pos.y >= 0);
}

Tetrimino tt_get_current(void) {
	return current;
}

static shapes random_shape(void) {
	static shapes shapes[] = {I, O, T, J, L, S, Z};
	int n_shapes = sizeof(shapes) / sizeof(shapes[0]);
	return shapes[rand() % n_shapes];
}