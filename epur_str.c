#include <unistd.h>

int is_space(char c)
{
	if(c <= ' ')
		return (1);
	return (0);
}

void epur_str(char *str)
{
	int i = 0;

	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		if (is_space(str[i]) && is_space(str[i + 1]))
			i++;
		else
		{
			if (str[i + 1] == '\0')
				return ;
			write(1, &str[i], 1);
			i++;
		}
	}

}

int main (int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	epur_str(av[1]);
}
