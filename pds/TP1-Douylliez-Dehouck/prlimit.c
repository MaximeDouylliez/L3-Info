#include <limits.h>
#include <unistd.h>
#include <stdio.h>

#define XOPEN_SOURCE 500

int main() {

	printf("NAME_MAX = %d\n", NAME_MAX );
	printf("PATH_MAX = %d\n", PATH_MAX );

	return 0;

}
