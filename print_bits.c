#include <unistd.h>
#include <stdlib.h>
void print_bits(int octet)
{ 
	int i = 7;
 
	while (i >= 0)
	{
		if ((octet >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
	write(1, "\n", 1);
}

int	swap_bits(int octet)
{
	return (octet << 4 | octet >> 4);
}

// int get_bit(unsigned char octet, int n)
// {
// 	return ((octet >> n) & 1);
// }

// unsigned char set_bit(unsigned char octet, int n)
// { 
// 	unsigned char	mask;
//	
// 	mask = 1 << n;
// 	octet = mask | octet;
// 	return (octet);
// }

unsigned char toggle_bit(unsigned char octet, int n)
{
	unsigned char	mask;
	
	mask = 1 << n;
	print_bits(mask);
	octet = mask ^ octet;
	return (octet);
} 

// int main(int ac, char **av)
// {
// 	int new_octet;

// 	(void)ac;
// 	print_bits(atoi(av[1]));
// 	new_octet = toggle_bit(atoi(av[1]), 2);
// 	print_bits(new_octet);
// }

