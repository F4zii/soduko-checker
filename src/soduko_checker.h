#ifndef SC_H_
#define SC_H_

/*=========================================================================
  Constants and definitions:
==========================================================================*/

#define MAX_SIZE 25

void printOpenMessageForSodokoSize();

void printOpenMessageForSodokoSolution();

void printValidSolution();

void printBadSolution();

int scan_n();

int root(int num);

void scan_sodoko(int sodoko[MAX_SIZE][MAX_SIZE],int n);

int calculate_sumof_nums_smaller_than_n(int n);

int check_square(int sodoko[MAX_SIZE][MAX_SIZE],int i,int j, int n);

int check_cols(int sodoko[MAX_SIZE][MAX_SIZE], int n);

int check_rows(int sodoko[MAX_SIZE][MAX_SIZE], int n);

int check_all_squares(int sodoko[MAX_SIZE][MAX_SIZE], int n);

#endif /*SC_H_ */
