// include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

// macros
#define size(arr) ((&arr)[1]-arr)
#define MAX_WORD_NUM 6		// max # of words per line (5+1 ICOI)
#define MAX_WORD_SIZE 20	// max # of chars for a label or a filename
#define TABSIZE 4

// types
struct Symbol {
	char label[MAX_WORD_SIZE+2];
	int addr;
};

struct Alert {
	int warn;
	int err;
	int exception;
};

// function declarations
int isKeyword(char c[]);

int isPseuodoOp(char c[]);

int isRegister(char c[]);

int isLabel(char c[]);

int isValidOffset(char c[]);

int isTrap(char c[]);

int isBranch(char c[]);

int isQuote(char c);

int fillRegister(int r, int bin[], int n);

int offset (int type, char c[], int bits);

int fillDecOffset(int off, int bits, int ln, int put_bin[]);

int addrToDec(char hex[]);

char* decToAddr(char hex[], int dec_num);

void putSymbol(FILE *fp, char symbol[], char addr[]);

void fprintIntArr(FILE *fp, int num[], int size);

void fprintCharArr(FILE *fp, char hex[], int size);

void decToTwoComp(int n, int bin[], int size);

void binToHex(int bin[], int bin_size, char hex[], int hex_size);

void op_reg_imm(char *keyword, char *op, int *bin, int loc, int offset_bits, int ln, struct Alert alert);

void op_register(char *keyword, char *op, int loc, int *bin, int ln, struct Alert alert);

void op_offset(char *keyword, char *op, int offset_bits, int ln, int *bin, int s_cnt, struct Symbol *symbols, int addr, struct Alert alert);