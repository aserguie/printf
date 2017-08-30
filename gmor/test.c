#include "include/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>
#include <unistd.h>

#define pftest(A, B) printf(A, B); ft_printf(A, B);

void	_PrintByte(unsigned char byte, int n)
{
	if (n == 0)
		return ;
	_PrintByte(byte >> 1, n - 1);
	printf("%d", byte & 1);
}

void	PrintByte(unsigned char byte)
{
	_PrintByte(byte, 8);
}

void	PrintBytes(void *n, size_t len)
{
	int i;
	for (i = 0; i < len - 1; ++i)
	{
		PrintByte(*((unsigned char *)(n + i)));
		printf(" ");
	}
	PrintByte(*((unsigned char *)(n + i)));
}

int		get_mb_len(wchar_t wc)
{
	if (wc < 0x80)
		return (1);
	if (wc < 0x800)
		return (2);
	if (wc < 0x10000)
		return (3);
	return (4);
}

int		wctomb(char *s, wchar_t wc)
{
	int len;
	int i;
	
	len = get_mb_len(wc);
	if (len == 1)
	{
		s[0] = wc;
		return (1);
	}
	i = len - 1;
	while (i > 0)
	{
		s[i--] =  0x80 | (0xFF >> 2 & wc);
		wc >>= 6;
	}
	s[0] = wc | (0xFF << (8 - len));
	return (len);
}

int		main(int argc, char *argv[])
{
	wchar_t wc;
	char s[MB_CUR_MAX], *locale;
	mbstate_t	*ps;
	int i, j, len;

	printf("MB_CUR_MAX = %d\n", MB_CUR_MAX);
//	locale = setlocale(LC_ALL, "");
	printf("locale = %s\n", locale);
	printf("MB_CUR_MAX = %d\n", MB_CUR_MAX);
	for (i = 0; i < 255; ++i)
		printf("%c", i);

	return (0);
}
