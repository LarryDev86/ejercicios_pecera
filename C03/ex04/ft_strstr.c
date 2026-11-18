
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	//si to_find esta vacio retorn el valor de str como muestra de que no ha habido coincidencia.
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{	
		j = 0; 
		//aqui averiguamos si str no esta al final y to_find tampoco, ademas comprovamos que haya coincidencia para que entre y incremente j.
		while (str[i + j] != '\0' && to_find[j] != '\0'
				&& str[i + j] == to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "hola mundo";
	char	to_find[] = "un";
	char	*respuesta;

	respuesta = ft_strstr(str, to_find);
	printf("%s\n", respuesta);
	return (0);
}
