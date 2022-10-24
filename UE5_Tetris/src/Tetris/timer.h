#pragma once

typedef void (*timer_func)(void);

extern void timer_start(double itvl, timer_func on_tick);
extern void timer_fire();
extern void timer_stop();
 
