# Mouse Input Reader

## Introduction
This software is a simple C program designed to read and display relative mouse movements in the terminal. It allows you to track the mouse's X and Y coordinates in real-time.

## Usage
To use this software, follow these steps:

1. Compile the program:
   gcc main.c -o mouse_reader

2. Run the program:
   ./mouse_reader

3. Move your mouse, and you will see the X and Y coordinates displayed on the terminal.
4. To exit the program, press Ctrl+C.

## Safety Concernes
When using this software, there are a few safety concerns to be aware of:

Permission: The program requires access to the mouse device file, typically located at "/dev/input/mouse0." Make sure you have the necessary permissions to read this file. You may need to run the program with elevated privileges (e.g., using sudo) or add your user to the appropriate group (e.g., input group).

Compatibility: This software is designed for Linux systems. It relies on the "/dev/input/mouse0" device file, which may not exist on all Linux distributions or may have a different name. Ensure that you're using a system with the appropriate mouse device configuration.



