#include <stdio.h>

#define FIXED_SCALE 20
#define FIXED_REAL(x) ((x) >> FIXED_SCALE)
#define FIXED_DEC(x) ((x) & ~(1 << FIXED_SCALE) >> 1)
#define FIXED_DOUBLE(x) ((double)(x)) / ((double)(1 << FIXED_SCALE))
#define FIXED_FD(x) (int)((x) * (double)(1 << FIXED_SCALE))

//0000 0000 0000.0000 0000 0000 0000 0000
//0000 0000 0001.0000 0000 0000 0000 0000
//1111 1111 1111.0000 0000 0000 0000 0000
//0000 0000 0000.1111 1111 1111 1111 1111

int		main(void)
{
	int	x;

	x = FIXED_FD((double)42.312f);
	printf("%d -- %d --- %d\n", FIXED_REAL(x), FIXED_DEC(x), x);
	printf("%lf\n", FIXED_DOUBLE(x));
	return (0);
}
