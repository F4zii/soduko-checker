/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "soduko_checker.h"

/*-------------------------------------------------------------------------
  The main program.
 -------------------------------------------------------------------------*/

int main()
{
    printOpenMessageForSodokoSize();
    int n = scan_n(), bool_count = 0;
    printOpenMessageForSodokoSolution();
    int sodoko[MAX_SIZE][MAX_SIZE] = { { 0 } };
    scan_sodoko(sodoko, n);
    bool_count += check_cols(sodoko, n);
    bool_count += check_rows(sodoko, n);
    bool_count += check_all_squares(sodoko,n);
    if (bool_count == 3)
    {
        printValidSolution();
        return 0;
    }
    printBadSolution();
    return 0;
}

int scan_n()
{
    int n = 0;
    int is_true = (n > 0 && (root(n) != -1));
    do
    {
        scanf("%d", &n);
        is_true = (n > 0 && (root(n) != -1));
        if (is_true) return n;
    } while (!is_true);
    return n;
}

int calculate_sumof_nums_smaller_than_n(int n)
{
  return (n - 1) * n >> 1;
}

int check_cols(int sodoko[MAX_SIZE][MAX_SIZE], int n)
{
    int nums_sum = calculate_sumof_nums_smaller_than_n(n);
    int sum = 0;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += sodoko[i][j];
        }
        if (sum == nums_sum)
        {
            counter++;
        }
    }
    return (counter == n);
}

int check_rows(int sodoko[MAX_SIZE][MAX_SIZE], int n)
{
    int nums_sum = calculate_sumof_nums_smaller_than_n(n);
    int sum = 0;
    int counter = 0;
    for (int j = 0; j < n; j++)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += sodoko[i][j];
        }
        if (sum == nums_sum)
        {
            counter++;
        }
    }
    return (counter == n);
}

int check_all_squares(int sodoko[MAX_SIZE][MAX_SIZE], int n)
{
    int i = 0, j = 0, bool_counter = 0, sqrt = root(n);
    for(int counter = 0; (j < n) && (counter < n); counter++)
    {
        bool_counter += check_square(sodoko, i, j, n);
        i += sqrt;
        if (i >= n)
        {
            i = 0;
            j += sqrt;
        }

    }
    return (bool_counter == n);
}

int check_square(int sodoko[MAX_SIZE][MAX_SIZE],int i,int j, int n)
{
    int nums_sum = calculate_sumof_nums_smaller_than_n(n);
    int sqrt = root(n);
    int sum = 0;
    int Itmp = i, Jtmp = j;
    for (; i < sqrt + Itmp; i++)
    {
        j = Jtmp;
        for (; j < sqrt + Jtmp; j++)
        {
            int curr = sodoko[i][j];
            sum += curr;
        }
    }
    return (sum == nums_sum);
}

void scan_sodoko(int sodoko[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &sodoko[i][j]);
        }
    }
}

int root(int num)
{
    if (num == 1) return 1;
    if (num < 0) return -1;
    for (int i = 2; i < num; i++)
    {
        if (i * i == num) return i;
    }
    return -1; // if no int root for number, returns -1 , used for checks
}

void printOpenMessageForSodokoSize()
{
    printf("Please enter the size of your soduko:\n");
}
void printOpenMessageForSodokoSolution()
{
    printf("Please enter your solution:\n");
}
void printValidSolution()
{
    printf("Valid solution!\n");
}
void printBadSolution()
{
    printf("Bad solution!\n");
}
