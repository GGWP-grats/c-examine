#include <stdio.h>
#include <unistd.h>
/*
** 0000 0000
*/
void print_byte(const void *addr)
{
	unsigned char p;
	p = *(unsigned char *)addr;
	//printf("%d\n", p);
	char x;
	x = '0';
	if (p > 16)
	{
		if (p / 16 > 9)
			x = p / 16 + 'a' - 10; 
		else
			x = p / 16 + '0';
	}
	write(1, &x, 1);
	if (p % 16 > 9)
		x = p % 16 + 'a' - 10;
	else
		x = p % 16 + '0';
	write(1, &x, 1);
}

void print_memory(const void *addr, size_t size)
{
	char str [17] = {0};
	for (size_t i = 0; i < size; i++)
	{	
		if (((unsigned char *)addr)[i] >= 33 && ((unsigned char *)addr)[i] <= 126)
			str[i % 16] = ((unsigned char *)addr)[i];
		else
			str[i % 16] = '.';
		print_byte((unsigned char *)addr + i);
		if (i % 2)
			write(1, " ", 1);
		if ((i + 1) % 16 == 0 || i + 1 == size)
		{
			write(1, str, (i % 16) + 1);
			write(1, "\n", 1);
		}
	}	
}

int main (void)
{
//	int	tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
	char tab[10] = {'\x61', '\x62', '\x00', 'a', 'z', '-', 'p'};
	printf("%zu %zu\n", sizeof(tab), sizeof(ctab));
	print_memory(tab, sizeof(tab));
	return (0);
}
