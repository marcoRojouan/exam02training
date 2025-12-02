int white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int ft_word_len(char *str)
{
	int i = 0;

	while (str[i] && !white_space(str[i]))
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *dup;
	int i = 0;
	int word_len = ft_word_len(str);

	if (!str)
		return (0);
	dup = malloc(sizeof(char) * (word_len + 1));
	if (!dup)
		return (0);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}	
	dup[i] = '\0';
	return (dup);
}

int count_words(char *str)
{
	int i = 1;
	int count = 0;

	if (!white_space(str[0]))
		count++;
	while (str[i])
	{
		if (!white_space(str[i]) && white_space(str[i - 1]))
			count++;
		i++;
	}
	return (count);
}

char **ft_split(char *str)
{
	char **tab;
	int i = 0;
	int j = 0;
	int words = count_words(str);

	if (!str)
		return (0);
	tab = malloc(sizeof(char *) * (words + 1));

	while (str[i])
	{
		if ((!white_space(str[i]) && white_space(str[i - 1])) || (!white_space(str[i]) && !str[i - 1]))
		{
			tab[j] = ft_strdup(str + i);
			if (!tab[j])
			{
				free_all(tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
