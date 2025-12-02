#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int i = 0;
	int multi = 1;
	int res = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			multi *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * multi);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else if(nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void	do_op(int nb1, int nb2, char operator)
{
	if (operator == '+')
		ft_putnbr(nb1 + nb2);
	else if (operator == '-')
		ft_putnbr(nb1 - nb2);
	else if (operator == '*')
		ft_putnbr(nb1 * nb2);
	else if (operator == '/')
		ft_putnbr(nb1 / nb2);
	else if (operator == '%')
		ft_putnbr(nb1 % nb2);
}

int main(int ac, char **av)
{
	if(ac != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	do_op(ft_atoi(av[1]), ft_atoi(av[3]), av[2][0]);
	return (0);
}

