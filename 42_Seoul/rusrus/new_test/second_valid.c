/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:35:00 by jakang            #+#    #+#             */
/*   Updated: 2020/02/01 20:07:30 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isValid(int *patt, int c)
{
	int		max;
	int		i;
	int		count;

	i = 0;
	max = 0;
	count = 0;
	while (i < g_num)
	{
		if (*str > max)
		{
			max = *str;
			count++;
		}
		i++;
		str++;
	}
	if (count == c)
		return (1);
	return (0);
}

int		areValid(int i, int j, int *c, int **arr)
{
	int	n;
	int count;
	int *patt;
	
	count = 0;
	patt = malloc(sizeof(int) * (g_num));
	n = -1;
	while (++n < g_num)
		patt[n] = arr[n][j];
	count += isValid(patt, );
	while (--n > -1)
		patt[n] = arr[n][j];
	count += isValid(patt,  );
	count += isValid(arr[i], );
	while (++n < g_num)
		patt[n] = arr[i][g_num - 1 - j];
	count += isValid(patt,  );
	if (count == 4)
		return (1);
	return (0);
}
