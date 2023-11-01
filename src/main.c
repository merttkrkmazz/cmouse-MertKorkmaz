#include "main.h"

int main() {
    const char *mouse_device = "/dev/input/mouse0";

    // Open the mouse device file
    int mouse_fd = open_mouse_device(mouse_device);
    if (mouse_fd == -1) {
        fprintf(stderr, "Failed to open the mouse device\n");
        return 1;
    }

    printf("You can move your mouse!!\n\n");
    // Read and process mouse input
    read_mouse_input(mouse_fd);

    // Close the mouse device file when done
    close(mouse_fd);
    return 0;
}

// Function to open the mouse device
int open_mouse_device(const char *device) {
    int fd = open(device, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }
    return fd;
}

// Function to read and process mouse input
void read_mouse_input(int fd) {
    char event[3];
    int rel_x = 0;
    int rel_y = 0;

    while (read(fd, event, sizeof(event)) == sizeof(event)) {
        // Decode the movement data from the buffer and update the x and y variables
        rel_x += (signed char)event[1];
        rel_y += (signed char)event[2];

        // Display the updated relative mouse position to the user
        printf("\rX: %5d, Y: %5d", rel_x, rel_y);
        
        // Force the terminal to display the updated position immediately
        fflush(stdout);
    }
}
