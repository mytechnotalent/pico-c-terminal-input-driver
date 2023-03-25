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

/** @file terminal_input.h
 *  @brief Function prototypes for the input driver.
 * 
 *  This contains the prototypes for the input
 *  driver to have complete control over what will 
 *  be accepted within the input buffer and length
 *  as you can control input to be either strings 
 *  with a length or decimals with a length, floats 
 *  with a length or alphanumerics with a length.
 * 
 *  @author Kevin Thomas (MyTechnoTalent)
 *  @date 03/25/2023
*/

#ifndef _TERMINAL_INPUT_H
#define _TERMINAL_INPUT_H

/** @brief Defines ASCII values for commonly used terminal input characters.
 * 
 *  These defines can be used to compare with user input to perform specific 
 *  actions or to restrict input.
*/
#define ZERO            0x30
#define NINE            0x39
#define PERIOD          0x2e
#define CAPITAL_A       0x41
#define LOWER_CASE_Z    0x7a
#define SPACE           0x20
#define BACKSPACE       0x08
#define DEL             0x7f
#define RETURN          0xd

/** @brief Function to obtain controlled input from the STDIN.
 * 
 *  If the type parameter 'f' is provided it will handle float 
 *  inputs at a given length.  If the type parameter 'd' is 
 *  provided it will handle decimal inputs at a given length.  
 *  If the type parameter 's' is given it will handle string
 *  inputs at a given length.  If the type parameter 'a' is
 *  given it will handle alphanumeric characters at a given
 *  length.
 * 
 *  @param type              The type of data looking to capture.
 *  @param usb_char          The individual char to process.
 *  @param usb_string        The built string from proper input.
 *  @param USB_STRING_SIZE   The max size of chars to accept from STDIN.
 */
void terminal_input(char type, char *usb_char, char *usb_string, const int *USB_STRING_SIZE);

/** @brief Function to flush the STDIN buffer.
 * 
 *  This will flush the input buffer string that was
 *  obtained from STDIN. 
 * 
 *  @param usb_string The string from STDIN.
 */
void terminal_flush_input(char *usb_string);

#endif /* _TERMINAL_INPUT_H */
