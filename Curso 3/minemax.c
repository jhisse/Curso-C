#include <stdio.h>

#define min(m,n) (m >= n) ? m : n;

int main()
{
	int x = min(9, 10);
	printf("%d\n", x);
	return 0;
}