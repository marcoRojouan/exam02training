#include <unistd.h>

int		is_alpha_plus(char c)
{
	if ((c >= 'a' && c <= 'x') || (c >= 'A' && c <= 'X'))
		return (1);
	if (c == 'z' || c == 'Z')
		return (2);
	return (0);
}

void	rotone(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_alpha_plus(str[i]) == 1)
		{
			str[i] += 1;
			write(1, &str[i], 1);
		}
		else if (is_alpha_plus(str[i]) == 2)
		{
			str[i] -= 25;
			write(1, &str[i], 1);
		}
		else 
			write(1, &str[i], 1);
		i++;
	}	
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rotone(av[1]);
}