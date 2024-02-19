#ifndef __TEST_H__
#define __TEST_H__
#include "RTE_Device.h"
#include "shell.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "driver.h"
#include "autoconf.h"
#include "board.h"


extern void led_thread(void *param);
extern void led_thread_init(void);
#endif