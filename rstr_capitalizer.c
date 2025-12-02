#include <unistd.h>

void to_lowercase(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}	
}

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_whitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void rstr_capitalizer(char *s)
{
	int i = 0;
	
	to_lowercase(s);
	while(s[i])
	{
		if((ft_isalpha(s[i]) && ft_whitespace(s[i + 1])) 
			|| (ft_isalpha(s[i]) && s[i + 1] == '\0'))
				s[i] -= 32;		
		write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 1;

	while (i < ac)
	{
		rstr_capitalizer(av[i]);
		i++;
	}
}