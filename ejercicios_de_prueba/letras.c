#include <unistd.h>

void	letras(void)
{
	char	let;
	int	i;
	char	mayu;

	let = 'a';
	i = 1;
	while (let <= 'z')
	{
		if(i % 2 == 0)
		{
			mayu = let - 32;
			write (1, &mayu, 1);
		}
		else
			write (1, &let, 1);

		let++;
		i++;
	}
	write (1, "\n", 1);
}

int	main(void)
{
	letras();
	return (0);
}
