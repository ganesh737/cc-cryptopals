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

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


// converting hex to base64
void hexArrayToBase64Array(char* dest, const char* src);
void threeHexTo2Base64(char* dest, const char* src);
char binToBase64(int val);
void reverseString(char* dest);


// xor strings
void xorStrings(char* dest, const char* src1, const char* src2);
// static asciiToHex
// static hexToAscii


// Single-byte XOR cipher
void decryptedSingleByteXOR(char* dest, const char* src);
int hexValueScore(const char* hexString, const char hexValue);
void setHexString(char* dest, const char* src);
void xorStringWithChar(char* dest, const char* src, const char xorVal);
char numOfCharInString(const char* str, const char searchChar);


//  other functions
void showbit(char n);
void usage();


// common printing usage
int printError(const char* message);
int printDebug(const char* message);
int printInfo(const char* message);
void printAsHexString(const char* str);
void printAsCharString(const char* str);
void printAs(const char* str, const char* format);

#endif
