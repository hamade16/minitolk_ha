
#include "minitalk.h"



void	send_char(int sig)
{
	static int				n_bits;
	static unsigned char	c = 0;
	static unsigned char	tmp_bit = 1;

	if (sig == SIGUSR2)
		c = c | tmp_bit;
	tmp_bit = tmp_bit << 1;
	n_bits++;
	if (n_bits == 8)
	{
		ft_putchar(c);
		n_bits = 0;
		tmp_bit = 1;
		c = 0;
	}
}


int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("server pid: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR2, send_char);
	signal(SIGUSR1, send_char);
	while (1)
		pause();
	return (0);
}
