
#include <stdio.h>
/*Crear una funcion que añada la cadena src al final del dest,
 * respetando el limite establecido por size.
*/
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;
	int	k;
	
	i = 0;
	while (i < size && dest[i] != '\0')
		i++;
	
	j = 0;
	while (src[j] != '\0')
		j++;

	if (i == size)
		return (size + j);

	k = 0;
	while (src[k] != '\0' && k < size - i - 1)
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (i + j);

}
/*
int	main(void)
{
	char	dest[12] = "hola";
	char	src[] = " mundo";
	int	size = 10;
	unsigned int	resultado;

	resultado = ft_strlcat(dest, src, size);
	printf("%u\n", resultado);
	printf("%s\n", dest);
	return (0);
}*/
