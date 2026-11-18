
int	ft_str_end(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && to_find[j] != '\0' && str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0' && str[i + j] == '\0')
				return (1);
		}
		i++;

	}
	return (0);
}

/* Este es parecido al ex04 pero la diferencia es que aqui miramos si ambos acaban igual 
 * ejemplo hola mundo -> mundo -> undo -> do.
 * */
