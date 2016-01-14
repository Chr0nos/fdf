#include "draw.h"
#include "libft.h"

int		main(void)
{
	int		x;

	x = DRAW_V_FD((double)42.312f);
	ft_printf("%d -- %d --- %d\n", DRAW_V_REAL(x), DRAW_V_FD(x), x);
	return (0);
}
