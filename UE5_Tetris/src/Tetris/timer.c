#include <assert.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>
#include "timer.h"

static timer_func callback;
static double interval = 1;
static void reset_time();
bool is_timer_running = false;

void timer_start(double itvl, timer_func on_tick)
{
	assert(on_tick);
	interval = itvl;
	callback = on_tick;
	is_timer_running = true;
	reset_time();
}

void timer_fire()
{
	if (!is_timer_running)
		return;
	if (glfwGetTime() >= interval) {
		callback();
		reset_time();
	}
}

void timer_stop()
{

}

void reset_time()
{
	glfwSetTime(0);
}
