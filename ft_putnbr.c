

#include "minitalk.h"

void	ft_putnbr(int n)
{
	unsigned int	b;

	if (n < 0)
	{
		ft_putchar('-');
		b = n * -1;
	}
	else
		b = n;
	if (b >= 10)
		ft_putnbr(b / 10);
	ft_putchar(b % 10 + '0');
}
