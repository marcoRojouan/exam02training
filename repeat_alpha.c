#include <unistd.h>

void repeat_alpha(char *str)
{
	char cur;
	char alphabet[27] = " abcdefghijklmnopqrstuvwxyz";
	char alphabetM[27] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		cur = str[i];
		if (str[i] >= 'a' && str[i] <= 'z')
		{	
			while (alphabet[j] != cur)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{	
			while (alphabetM[j] != cur)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	repeat_alpha(av[1]);
}