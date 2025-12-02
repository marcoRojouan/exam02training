#include <stdlib.h>

int white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void freelestrucs(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
int count_words(char *str)
{
	int i = 0;
	int count = 0;

	if (!white_space(str[0]))
	{
		count += 1;
	}
	i++;
	while (str[i])
	{
		if (!white_space(str[i]) && white_space(str[i - 1]))
			count++;
		i++;
	}
	return (count);
}

int get_word_len(char *str)
{
	int i = 0;

	while (!white_space(str[i]) && str[i])
		i++;
	return (i);
}

char *duplicate_wrd(char *str)
{
	char *dup;
	int word_len = get_word_len(str);
	int i = 0;

	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * (word_len + 1));
	if (!dup)
		return (NULL);
	while (i < word_len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}
char **ft_supulitu(char *str)
{
	char **tab;
	int word_count;
	int i = 0;
	int j = 0;

	word_count = count_words(str);
	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if ((!white_space(str[i]) && white_space(str[i - 1])) || (!white_space(str[i]) && !str[i - 1]))
		{
			tab[j] = duplicate_wrd(str + i);
			if (!tab[j])
			{
				freelestrucs(tab);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	(void)ac;
//     char **res = ft_supulitu(av[1]);
//     int i = 0;

//     if (!res)
//         return (1);

//     while (res[i])
//     {
//         printf("mot[%d] = \"%s\"\n", i, res[i]);
//         i++;
//     }

//     freelestrucs(res);
//     return (0);
// }