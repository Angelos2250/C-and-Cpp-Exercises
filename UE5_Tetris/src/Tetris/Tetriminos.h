#pragma once
#include "types.h"
#include "current_block.h"
#include <stddef.h>
#include <assert.h>

extern bool tt_try_move(int dx, int dy);
extern Tetrimino tt_new_tetrimino(void);
extern Tetrimino tt_get_current(void);
extern void tt_render(void);
extern bool is_block(block bl);
 