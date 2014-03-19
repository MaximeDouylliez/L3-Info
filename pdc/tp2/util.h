#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define  MAX_LINE 81
void print_arg(int argc,char** argv);
int readl(char* line);
void tableau_1d(int n, char*tab);
void fatal (int assert, const char* message,int statuts);
void lister_tableau(char* tab);

