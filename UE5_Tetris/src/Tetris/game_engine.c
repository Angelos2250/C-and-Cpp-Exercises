#include "game_engine.h"
#include "current_block.h"
#include "game_board.h"
#include "Tetriminos.h"

static bool end = false; //end of round

bool ge_handle_move(int dx, int dy, int turn) {
	if (end)
		return false;

	if (!tt_try_move(dx, dy) && dy == -1) {
		Tetrimino current = tt_get_current();
		for (int r = 0; r < MAX_SIZE; r++) {
			for (int c = 0; c < MAX_SIZE; c++) {
				if (is_block(current.blocks[r][c]))
					gb_add_block(current.blocks[r][c]);
			}
		}

		tt_new_tetrimino();

		if (!tt_try_move(0, 0))
			end = true;
	}

	return !end;
}

bool ge_is_game_over(void) {
	return end;
}

void ge_restart(void) {
	end = false;
}