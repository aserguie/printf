#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include "include/ft_printf.h"
#include "include/libft.h"

#define pftest(A, B) printf(A, B); ft_printf(A, B);

int		main()
{
	wchar_t wc = 0x03D5;
	int len;
	wchar_t ws[] = {L' ', wc, L'\n', 0};

	setlocale(LC_ALL, "");
	pftest("'%p'\n", 0);

	return (0);
}
