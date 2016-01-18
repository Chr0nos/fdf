#include <stdio.h>
#include "libft.h"

#define FIXED_SCALE 20
#define FIXED_FMASK ((int)2147483647 >> (32 - FIXED_SCALE))
#define FIXED_REAL(x) ((x) >> FIXED_SCALE)
#define FIXED_DEC(x) (int)((x) & FIXED_FMASK)
#define FIXED_DOUBLE(x) (((double)(x)) / ((double)(1 << FIXED_SCALE)))
#define FIXED_FD(x) (int)((x) * (double)(1 << FIXED_SCALE))

//SRRR RRRR RRRR.DDDD DDDD DDDD DDDD DDDD
//0000 0000 0000.0000 0000 0000 0000 0000
//0000 0000 0001.0000 0000 0000 0000 0000
//1111 1111 1111.0000 0000 0000 0000 0000
//0000 0000 0000.1111 1111 1111 1111 1111

int		main(void)
{
	int	x;
	int	mask;

	x = FIXED_FD((double)42.312f);
	printf("partie entiere: %d\n", FIXED_REAL(x));
	printf("double: %lf\n", FIXED_DOUBLE(x));
	printf("apres la virgule: %lf\n", FIXED_DOUBLE(FIXED_DEC(x)));
	printf("masque decimal: %d\n", FIXED_FMASK);
	mask = FIXED_FMASK;
	ft_putmem(&mask, sizeof(int));
	return (0);
}
