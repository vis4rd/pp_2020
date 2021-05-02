#include <stdio.h>

#define MAK_1(r) printf(#r " = %d\n", r)
#define MAK_2(k) ((k)%2==0 ? ((k)>0 ? 1 : -1) : 0)

int main(void)
{
	int x = 5;
	int y = 9;

	MAK_1(7*x+2-y/6);
	MAK_1(MAK_2(4));
	MAK_1(MAK_2(5));
	MAK_1(MAK_2(-1));
	MAK_1(MAK_2(-8));
}