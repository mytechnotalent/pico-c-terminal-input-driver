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

/** @file input.c
 *  @brief Functions for the input driver.
 * 
 *  This contains the functions for the input
 *  driver to have complete control over what will 
 *  be accepted within the input buffer and length
 *  as you can control input to be either strings 
 *  with a length or decimals with a length, floats 
 *  with a length or alphanumerics with a length.
 * 
 *  @author Kevin Thomas (MyTechnoTalent)
 *  @date 03/25/2023
*/

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#include "terminal_input.h"

void terminal_input(char type, char *usb_char, char *usb_string, const int *USB_STRING_SIZE)
{
  *usb_char = '\0';
  *usb_char = getchar_timeout_us(0);
  if(*usb_char == BACKSPACE || *usb_char == DEL)
  {
    if(usb_string[0] != '\0')
    {
      printf("\b");
      printf(" ");
      printf("\b");
      usb_string[strlen(usb_string)-1] = '\0';
    }
  }
  if(type == 'f')
  { 
    char* period;
    while((*usb_char >= ZERO && *usb_char <= NINE) || *usb_char == PERIOD)
    {
      if(*usb_char == PERIOD)
        period = strchr(usb_string, '.');
      if(period == NULL) 
      {
        if(strlen(usb_string) < *USB_STRING_SIZE)
        {
          putchar(*usb_char);
          strncat(usb_string, usb_char, 1);
        }
        *usb_char = '\0';
      }
      else
        break;
    }
  }
  else if(type == 'd')
  { 
    while(*usb_char >= ZERO && *usb_char <= NINE)
    {
      if(strlen(usb_string) < *USB_STRING_SIZE)
      {
        putchar(*usb_char);
        strncat(usb_string, usb_char, 1);
      }
      *usb_char = '\0';
    }
  }
  else if(type == 's')
  { 
    while((*usb_char >= CAPITAL_A && *usb_char <= LOWER_CASE_Z) || (*usb_char == SPACE))
    {
      if(strlen(usb_string) < *USB_STRING_SIZE)
      {
        putchar(*usb_char);
        strncat(usb_string, usb_char, 1);
      }
      *usb_char = '\0';
    }
  }
  else if(type == 'a')
  { 
    while((*usb_char >= CAPITAL_A && *usb_char <= LOWER_CASE_Z) || (*usb_char == SPACE) || (*usb_char >= ZERO && *usb_char <= NINE))
    {
      if(strlen(usb_string) < *USB_STRING_SIZE)
      {
        putchar(*usb_char);
        strncat(usb_string, usb_char, 1);
      }
      *usb_char = '\0';
    }
  }
}

void terminal_flush_input(char *usb_string)
{
  usb_string[0] = '\0';
}
