/* ------------------------------------------------------------------------- */
/*                                                                           */
/*       ft_atoi.c                                                           */
/*                                                                           */
/*   ,d88~~\      e      888   | Y88b      /      e       e88~~\  888~~      */
/*   8888        d8b     888   |  Y88b    /      d8b     d888     888___     */
/*   `Y88b      /Y88b    888   |   Y88b  /      /Y88b    8888 __  888        */
/*    `Y88b,   /  Y88b   888   |    Y888/      /  Y88b   8888   | 888        */
/*      8888  /____Y88b  Y88   |     Y8/      /____Y88b  Y888   | 888        */
/*   \__88P' /      Y88b  "8__/       Y      /      Y88b  "88__/  888___     */
/*                                                                           */
/*       Updated: 29/01/2026 23:35:59                                        */
/*       Created: 29/01/2026 23:35:54                                        */
/*       Created by: sauvage                                                 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/*       ft_atoi.c                                                           */
/*                                                                           */
/*   ,d88~~\      e      888   | Y88b      /      e       e88~~\  888~~      */
/*   8888        d8b     888   |  Y88b    /      d8b     d888     888___     */
/*   `Y88b      /Y88b    888   |   Y88b  /      /Y88b    8888 __  888        */
/*    `Y88b,   /  Y88b   888   |    Y888/      /  Y88b   8888   | 888        */
/*      8888  /____Y88b  Y88   |     Y8/      /____Y88b  Y888   | 888        */
/*   \__88P' /      Y88b  "8__/       Y      /      Y88b  "88__/  888___     */
/*                                                                           */
/*       Updated: 29/01/2026 23:32:55                                        */
/*       Created: 29/01/2026 23:32:45                                        */
/*       Created by: sauvage                                                 */
/* ------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (-1);
}

int	ft_pow10(int pow)
{
	int	nb;
	int	i;

	i = -1;
	nb = 10;
	while (++i < pow)
		nb *= 10;
	return (nb);
}

int	ft_atoi(const char *s_nombre)
{
	int	signe;
	int	i_nombre;
	int	i;
	int	j;

	signe = 1;
	i_nombre = 0;
	i = 0;
	while (s_nombre[i] == ' ')
		i++;
	if (s_nombre[i] == '-' || s_nombre[i] == '+')
	{
		if (s_nombre[i] == '-')
			signe *= -1;
		i++;
	}
	j = i;
	while (is_num(s_nombre[j]) == 0)
		j++;
	j -= i + 1;
	while (is_num(s_nombre[i]) == 0 && j != 0)
	{
		i_nombre += (s_nombre[i] - '0') * ft_pow10(j-1);
		i++;
		j--;
	}
	if (is_num(s_nombre[i]) == 0)
		i_nombre += (s_nombre[i] - '0');
	return (i_nombre * signe);
}

/*int	main()
{
	char	test[] = " +12345ezaaae";

	printf("personal %s\n%i\n", test, ft_atoi(test));
	printf("orignal  %s\n%i\n", test, atoi(test));

	return (0);
}*/
