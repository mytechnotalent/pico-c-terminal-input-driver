#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "input.h"

int main() 
{
    stdio_init_all();

    const int USB_STRING_SIZE = 1;
    char usb_char = '\0';
    char choice[USB_STRING_SIZE];

    // Wait until the enter key is pressed.
    while (1)
    {
        input('s', &usb_char, choice, &USB_STRING_SIZE);
        if(usb_char == 0xd)
        {
            flush_input(choice);
            break;
        }
    }

    // Obtain only a single character from STDIN and echo it.
    while (1)
    {
        printf("choice: ");
        while (1)
        {
            input('s', &usb_char, choice, &USB_STRING_SIZE);

            if(usb_char == 0xd)
            {
                printf("\n%s\n", choice);
                flush_input(choice);
                break;
            }
        }
    }
}
    