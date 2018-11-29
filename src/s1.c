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
#include <stdlib.h>

#include "functions.h"
#include "s1.h"

// Input for Set 1 Challenge 1
const char* s1c1hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

// Input for Set 1 Challenge 2
const char* s1c2str1 = "1c0111001f010100061a024b53535009181c";
const char* s1c2str2 = "686974207468652062756c6c277320657965";

// Input for Set 1 Challenge 3
const char* s1c3str="1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

// Input for Set 1 Challenge 4
const char* s1c4InputFile = "inputs/s1c4.txt";

void s1c1()
{
	printInfo("s1c1\n");
	char* base64Val = (char*) calloc(strlen(s1c1hexString), sizeof(char));
	hexArrayToBase64Array(base64Val, s1c1hexString);
	printAs(s1c1hexString, "char");
	printAs(base64Val, "char");
	free(base64Val);
}

void s1c2()
{
	printInfo("s1c2\n");
	char* xorStr = (char*) calloc(strlen(s1c2str1) + 1, sizeof(char));
	xorStrings(xorStr, s1c2str1, s1c2str2);
	printAs(s1c2str1, "char");
	printAs(s1c2str2, "char");
	printAs(xorStr, "char");
	free(xorStr);
}
void s1c3()
{
	printInfo("s1c3\n");

	char* hexResultString = NULL;
	int len = strlen(s1c3str);

	hexResultString = (char*) calloc(len + 1, sizeof(char));

	decryptedSingleByteXOR(hexResultString, s1c3str);

	printAs(hexResultString, "char");

	free((void*) hexResultString);
}