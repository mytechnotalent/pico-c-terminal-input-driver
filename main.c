/**
 * MIT License
 * 
 * Copyright (c) 2023 My Techno Talent
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

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
    