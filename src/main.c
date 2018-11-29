/*
 * MIT License
 *
 * Copyright (c) 2017 Ganesh Halthota
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the 'Software'), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * Revision History:
 *     Initial: 2017/11/20      Ganesh Halthota
 */

#include <stdio.h>
#include <string.h>

#include "functions.h"
#include "s1.h"

static int myHash(const char* str)
{
	int val = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		val += *(str+i);
		i++;
	}
	return val;
}

int main(int argc, char** argv)
{
	int i = 0;

	if (argc < 2)
	{
		printError("No arguments\n");
		usage();
	}
	else
	{
		for(i = 1; i < argc; i++)
		{
			printInfo("myHash for %s:%d\n", *(argv + i), myHash(*(argv + i)));
			switch(myHash(*(argv + i)))
			{
				case 357:
					printInfo("-s1c1\n");
					s1c1();
					break;

				case 358:
					printInfo("-s1c2\n");
					s1c2();
					break;

				case 359:
					printInfo("-s1c3\n");
					s1c3();
					break;

				default:
					printInfo("argv:%s\n", *(argv + i));
					break;
			}
		}
	}
	printInfo("the end ...\n");
	return 0;
}
