/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seochoi@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:19:40 by seokchoi          #+#    #+#             */
/*   Updated: 2020/02/01 21:51:11 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Global variable g_num is 0 (num BY num) */
int		g_num = 0;
/* Global variable g_flag is 0 (0 : not completed, 1 : success) */
int		g_flag = 0;

/*
** Write the characters on display
**
** @param char *c
** @return void
*/

void	display(char *c)
{
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
}

/*
** Write the char array on display with whole size
**
** @param char **arr
** @return void
*/

void	full_display(int **arr)
{
	int		row_n;
	int		col_n;
	char	temp;

	row_n = 0;
	col_n = 0;
	while (row_n < g_num)
	{
		while (col_n < g_num)
		{
			temp = arr[row_n][col_n] + '0';
			write(1, &temp, 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

/*
** Validate or invalidate the input values
**
** @param int *patt : pattern
** @param int c : condition
** @return int : 1 (true), 0(false)
*/

int		is_valid(int *patt, int cond)
{
	int		max;
	int		i;
	int		count;
	int		flag;

	flag = 1;
	i = 0;
	max = 0;
	count = 0;
	while (i < g_num)
	{
		if (*patt > max)
		{
			max = *patt;
			count++;
		}
		if (*patt == -1)
			flag = 0;
		i++;
		patt++;
	}
	if (flag == 1)
	{
		if (count == cond)
			return (1);
	}
	else
	{
		if (count <= cond)
			return (1);
	}
	return (0);
}

/*
** Text function
**
** @param char *str : input argument vector's strings
** @return int p
*/

int		*text(char *str)
{
	int		*p;
	int		*temp;
	int		count;
	int		num;
	int		i;

	count = -1;
	p = malloc(sizeof(int) * 1);
	while (*str != '\0')
	{
		if (*str == ' ')
			str++;
		num = 0;
		while (*str >= '0' && *str <= '9')
		{
			num = num * 10 + *str - '0';
			str++;
		}
		count++;
		temp = p;
		p = malloc(sizeof(int) * (count));
		i = 0;
		while (i < count)
		{
			p[i] = temp[i];
			i++;
		}
		p[i] = num;
	}
	return (p);
}

/*
** are_valid function
**
** @param int i
** @param int j
** @param int *c
** @param int **arr
** @return int : 0 (false), 1 (true) 
*/

int		are_valid(int i, int j, int *c, int **arr)
{
	int	n;
	int count;
	int *patt;
	
	count = 0;
	patt = malloc(sizeof(int) * (g_num));
	n = -1;
	while (++n < g_num)
		patt[n] = arr[n][j];
	count += is_valid(patt, c[j]);
	while (--n > -1)
		patt[g_num - n - 1] = arr[n][j];
	count += is_valid(patt, c[4 + j]);
	count += is_valid(arr[i], c[8 + i]);
	while (++n < g_num)
		patt[n] = arr[i][g_num - 1 - n];
	count += is_valid(patt, c[12 + i]);
	if (count == 4)
		return (1);
	return (0);
}

/*
** Cal function
**
** @param int i
** @param int j
** @param int *c
** @param int **arr
** @return int : 0 (or recurrence relation)
*/

int		cal(int i, int j, int *c, int **arr)
{
	int		count;

	count = 0;
	while (count < g_num)
	{
		arr[i][j] = count;
		if(are_valid(i, j, c, arr))
		{
			if (j == (g_num - 1))
			{
				if (i == (g_num -1))
				{
					full_display(arr);
					g_flag = 1;
				}
				i++;
				j = 0;
			}
			else
				j++;
			cal(i, j, c, arr);
		}
		else
			return (0);
		count++;
		if (g_flag == 1)
			break;
	}
	return (0);
}

/*
** Rush function
**
** @param char *str : input argument vector's strings
** @return int result : cal function's return value
*/

void	rush(char *str)
{
	int		*raw;
	int		**num_arr;
	int		result;
	int		str_len;
	int		r;
	int		c;

	raw = text(str);
	str_len = 1;
	while (raw[str_len] > 0)
		str_len++;
	if (str_len % 4 != 0)
		return (0);
	g_num = str_len / 4;
	num_arr = (int **)malloc(g_num * sizeof(int *));
	r = 0;
	while (r < g_num)
	{
		c = 0;
		*num_arr = (int *)malloc(g_num * sizeof(int));
		while (c < g_num)
		{
			num_arr[r][c] = -1;
			c++;
		}
		r++;
	}
	cal(0, 0, raw, num_arr);
	if (g_flag == 0)
		return (0);
	return (1);
}

/*
** Main function
**
** @param int argc
** @param char **argv
** @return int : 0 (normal proceed)
** (@exception) : Write "Error" by display function when argv is not well input.
*/

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if(!rush(argv[1]))
			display("Error");
	}
	else
		display("Error");
	display("\n");
	return (0);
}
