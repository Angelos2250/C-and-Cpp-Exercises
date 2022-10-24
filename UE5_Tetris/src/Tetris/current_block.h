#pragma once

#include "types.h"

extern bool cb_try_move_block(block bl, int dx, int dy);
extern void cb_move_block(block* bl, int dx, int dy);
extern block cb_new_block_color(color color);
