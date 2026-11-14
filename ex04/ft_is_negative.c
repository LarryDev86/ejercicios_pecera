#include <unistd.h>

void	ft_is_negative(int n)
{
	char resultado;

	if(n >= 0)
	{
		resultado = 'P';
	}
	else
	{
		resultado = 'N';
	}

	write(1, &resultado, 1);
	write(1, "\n", 1);
}

int	main()
{
	ft_is_negative(-5);
	return (0);
}
