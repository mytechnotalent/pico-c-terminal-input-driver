![image](https://github.com/mytechnotalent/pico-c-terminal-input-driver/blob/main/Pico%20C%20Terminal%20Input%20Driver.png?raw=true)

## FREE Reverse Engineering Self-Study Course [HERE](https://github.com/mytechnotalent/Reverse-Engineering-Tutorial)

<br>

# Pico C Terminal Input Driver
A Raspberry Pi Pico terminal input driver written in C.

# Usage
#### If the type parameter 'f' is provided it will handle float inputs at a given length.  If the type parameter 'd' is provided it will handle decimal inputs at a given length.  If the type parameter 's' is given it will handle string inputs at a given length.  If the type parameter 'a' is given it will handle alphanumeric characters at a given length.

# `main.c`
```c
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#include "terminal_input.h"

int main() 
{
    stdio_init_all();

    const int USB_STRING_SIZE = 1;
    char usb_char = '\0';
    char choice[USB_STRING_SIZE];

    // Wait until the enter key is pressed.
    while (1)
    {
        terminal_input('s', &usb_char, choice, &USB_STRING_SIZE);
        if(usb_char == 0xd)
        {
            terminal_flush_input(choice);
            break;
        }
    }

    // Obtain only a single character from STDIN and echo it.
    while (1)
    {
        printf("choice: ");
        while (1)
        {
            terminal_input('s', &usb_char, choice, &USB_STRING_SIZE);

            if(usb_char == 0xd)
            {
                printf("\n%s\n", choice);
                terminal_flush_input(choice);
                break;
            }
        }
    }
}
```

## License
[MIT](https://raw.githubusercontent.com/mytechnotalent/pico-c-terminal-input-driver/main/LICENSE)
