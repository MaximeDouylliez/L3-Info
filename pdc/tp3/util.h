#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define  MAX_LINE 81
#define MAX_NUMBER_PER_LINE 12
void print_arg(int argc,char** argv);
int readl(char* line);
void tableau_1d(int n, char*tab);
void fatal (int assert, const char* message,int statuts);
int alea(int bmin,int bmax);
void lister_tableau(char* tab);
void alea_tableau_int(int* tab,int lg);
void lister_tableau_int(int* tab,int lg);
void is_sorted_int(int* tab,int lg);

