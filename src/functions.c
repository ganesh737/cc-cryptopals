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
#include <unistd.h>
#include <stdlib.h>

#include "functions.h"

// Dictionary for decoding base64 data
const char* base64Dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Dictionary for giving ratings based on dictionary
// help from http://scottbryce.com/cryptograms/stats.htm
const char* dict[] = {	" ",
						"what",
						"upon",
						"take",
						"our",
						"make",
						"like",
						"large",
						"interest",
						"him",
						"good",
						"debts",
						"country",
						"between",
						"before",
						"years",
						"while",
						"where",
						"well",
						"war",
						"up",
						"under",
						"through",
						"such",
						"still",
						"since",
						"said",
						"public",
						"people",
						"now",
						"new",
						"last",
						"here",
						"her",
						"general",
						"found",
						"every",
						"days",
						"can",
						"these",
						"must",
						"great",
						"first",
						"out",
						"made",
						"even",
						"day",
						"they",
						"than",
						"most",
						"into",
						"you",
						"very",
						"over",
						"only",
						"no",
						"its",
						"being",
						"them",
						"some",
						"other",
						"my",
						"if",
						"dollars",
						"after",
						"about",
						"we",
						"time",
						"would",
						"who",
						"today",
						"may",
						"had",
						"when",
						"so",
						"more",
						"many",
						"been",
						"there",
						"I",
						"an",
						"their",
						"all",
						"or",
						"were",
						"not",
						"have",
						"one",
						"will",
						"this",
						"has",
						"from",
						"but",
						"which",
						"at",
						"his",
						"on",
						"with",
						"he",
						"as",
						"was",
						"for",
						"are",
						"by",
						"it",
						"be",
						"that",
						"is",
						"a",
						"in",
						"to",
						"and",
						"of",
						"The"};


// All static functions

static char asciiToHex(const char src)
{
	char val = 0;
	val = src - '0';
	if(val > 9)
	{
		val -= 39;
	}
	return val;
}

static char hexToAscii(const char src)
{
	char tmp;
	tmp = src + '0';
	if(tmp > 57)
	{
		tmp += 39;
	}
	return tmp;
}


// Remaining functions

void hexArrayToBase64Array(char* dest, const char* src)
{
	char threeHex[3];

	char val = 0;
	char tmp;

	size_t srcLen = strlen(src);

	while(srcLen > 2) {
		threeHex[0] = *(src + srcLen - 1);
		threeHex[1] = *(src + srcLen - 2);
		threeHex[2] = *(src + srcLen - 3);

		threeHexTo2Base64(dest, threeHex);

		srcLen -= 3;
	}

	if(srcLen == 1)
	{
		val = (asciiToHex(*(src)) & 0x0f);
		tmp = binToBase64(val);
		strncat(dest, &tmp, 1);
	}
	else if (srcLen == 2)
	{
		threeHex[0] = *(src + srcLen - 1);
		threeHex[1] = *(src + srcLen - 2);
		threeHex[2] = '0';
		threeHexTo2Base64(dest, threeHex);
	}

	// need to reverse the string dest
	reverseString(dest);
}

void threeHexTo2Base64(char* dest, const char* src)
{
	char val = 0;
	char tmp;

	//value of first 6 bits
	val = (asciiToHex(*(src)) & 0x0f) | ((asciiToHex(*(src+1)) & 0x03) << 4);
	tmp = binToBase64(val);
	strncat(dest, &tmp, 1);

	//value of second 6 bits
	val = ((asciiToHex(*(src+2)) & 0x0f) << 2) | ((asciiToHex(*(src+1)) & 0x0c) >> 2);
	tmp = binToBase64(val);
	strncat(dest, &tmp, 1);
}

char binToBase64(int val)
{
	return base64Dictionary[val];
}

void reverseString(char* dest)
{
	int i = 0;
	int b = strlen(dest);
	char* end = dest + strlen(dest) - 1;
	for (i = 0; i <= (b/2) - 1; i++)
	{
		*dest ^= *end;
		*end  ^= *dest;
		*dest ^= *end;
		dest++;
		end--;
	}
}

void xorStrings(char* dest, const char* src1, const char* src2)
{
	char valSrc1 = 0;
	char valSrc2 = 0;
	char xorVal = 0;
	int len = strlen(src1);
	int i = 0;
	for(i = 0; i < len; i++)
	{
		valSrc1 = asciiToHex(*(src1 + i));
		valSrc2 = asciiToHex(*(src2 + i));
		xorVal = valSrc1 ^ valSrc2;
		xorVal = hexToAscii(xorVal);
		dest[i] = xorVal;
	}
}

void decryptedSingleByteXOR(char* dest, const char* src)
{
	int i = 0;
	int num = 0;
	int numMax = 0;
	int iWithBestMatch = 0;
	char val = '\0';
	char space = 0x20;
	int len = strlen(src);

	void *hexString = (char*) calloc(len + 1, sizeof(char));

	setHexString(hexString, src);

	printAs(hexString, "hex");

	// for(i = 87; i < 89; i++)
	for(i = 0; i < 255; i++)
	{
		val = i;
		xorStringWithChar(dest, hexString, val);
		num = numOfCharInString(dest, space);
		if(num > numMax)
		{
			numMax = num;
			iWithBestMatch = i;
		}
		memset(dest, 0, len + 1);
	}

	printf("iWithBestMatch=%d\n", iWithBestMatch);

	xorStringWithChar(dest, hexString, iWithBestMatch);
	// printAs(dest, "char");

	free((void*) hexString);
}

int hexValueScore(const char* hexString, const char hexValue)
{
	printf("%s %c\n", hexString, hexValue);
	return 0;
}

void setHexString(char* dest, const char* src)
{
	int len = strlen(src);
	int i = 0;
	char tmp = '\0';
	for(i = 0; i < len; i++)
	{
		tmp = asciiToHex(*(src+i));
		strncat(dest, &tmp, 1);
	}
}

void xorStringWithChar(char* dest, const char* src, const char xorVal)
{
	int len = strlen(src);
	int i = 0;
	char tmp = '\0';
	for(i = 0; i < (len/2); i++)
	{
		tmp = (((*(src + (i*2)) << 4) & 0xf0) | (*(src + (i*2) + 1) & 0x0f)) ^ xorVal;
		strncat(dest, &tmp, 1);
	}
}

char numOfCharInString(const char* str, const char searchChar)
{
	char num = 0;
	unsigned int i = 0;
	for(i = 0; i < strlen(str); i++)
	{
		if(*(str+i) == searchChar)
		{
			num++;
		}
	}
	return num;
}

void showbits(char n)
{
	int i, k, andmask ;
	for ( i = 7 ; i >= 0 ; i-- )
	{
		andmask = 1 << i ;
		k = n & andmask ;
		k == 0 ? printf ( "0" ) : printf ( "1" ) ;
	}
	printf("\n");
}

void usage()
{
	printInfo("Usage:\n");
	printInfo("      After build, call this file as below\n");
	printInfo("      ./cryptopals OPTIONS\n");
	printInfo("      OPTIONS available are -\n");
	printInfo("       -s1c1  --> Set 1 Challenge 1\n");
	printInfo("       -s1c2  --> Set 1 Challenge 2\n");
	printInfo("       -s1c3  --> Set 1 Challenge 3\n");
	printf("\n");
}

int printError(const char* message)
{
	int ret = 0;
	ret = printf("ERROR: %s", message);
	return ret;
}

int printDebug(const char* message)
{
	int ret = 0;
	ret = printf("DEBUG: %s", message);
	return ret;
}

int printInfo(const char* message)
{
	int ret = 0;
	ret = printf("INFO : %s", message);
	return ret;
}

void printAsHexString(const char* str)
{
	unsigned int i = 0;
	printf("hexString: ");
	for(i = 0; i < strlen(str); i++)
	{
		printf("%x", *(str + i));
	}
	printf("\n");
}

void printAsCharString(const char* str)
{
	int i = 0;
	int len = strlen(str);
	printf("charString: ");
	for(i = 0; i < len; i++)
	{
		printf("%c", *(str + i));
	}
	printf("\n");
}

void printAs(const char* str, const char* format)
{
	if(strncmp(format, "char", 4) == 0)
	{
		printAsCharString(str);
	}
	else if(strncmp(format, "hex", 3) == 0)
	{
		printAsHexString(str);
	}
}