#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <linux/input.h>

// Function to open the mouse device
int open_mouse_device(const char *device);

// Function to read and process mouse input
void read_mouse_input(int fd);

#endif
