/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:16:07 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/01 22:55:52 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int	g_flag = 1;

int	is_valid(int col, int row, int height, int **board);
int	up_valid_check(int col, int row, int height, int **board);
int	down_valid_check(int col, int row, int height, int **board);
int	left_valid_check(int col, int row, int height, int **board);
int	right_valid_check(int col, int row, int height, int **board);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	char c;

	c = nb + '0';
	write(1, &c, 1);
}

/* print borard */
int		**print_board(int **board, int row_size, int col_size)
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (r < row_size)
	{
		c = 0;
		while (c < col_size)
		{
			putnbr(board[r][c]);
			if (c != col_size - 1)
				ft_putchar(' ');
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
	return (board);
}

/* create board and init for 0*/
int		**create_board(int row_size, int col_size)
{
	int **board;
	int r;
	int c;

	r = 0;
	board = (int **)malloc(sizeof(int *) * row_size);
	while (r < row_size)
	{
		c = 0;
		board[r] = (int *)malloc(sizeof(int *) * col_size);
		while (c < col_size)
		{
			board[r][c] = 0;
			c++;
		}
		r++;
	}
	return (board);
}

int		**set_condition(int **board, int *cond, int row_size, int col_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < col_size - 2)
	{
		board[0][j + 1] = cond[i];
		board[row_size - 1][j + 1] = cond[i + col_size -2];
		i++;
		j++;
	}
	j = 0;
	while (j < row_size - 2)
	{
		board[j + 1][0] = cond[i];
		board[j + 1][col_size - 1] = cond[i + row_size - 2];
		i++;
		j++;
	}
	return (board);
}

void	set_box(int col, int row, int **board, int size)
{
	int height;

	if (g_flag == -1)
		return ;
	if (col == size + 1 && g_flag == 1)
	{
		print_board(board, 6, 6);
		g_flag = -1;
		return ;
	}
	else if(row == size + 1)
	{
		row = 1;
		set_box(col + 1, row, board, size);
	}
	else
	{
		height = 1;
		while (height <= size)
		{
			if (is_valid(col, row, height, board))
			{
				board[row][col] = height;
				set_box(col, row + 1, board, size);
				board[row][col] = 0;
			}
			height++;
		}
	}
	return ;
}

int main(void)
{
	int	**board;
	int cond[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};

	board = create_board(6, 6);
	set_condition(board, cond, 6, 6);
	print_board(board, 6, 6);

	printf("(1,1) in 1 up valid %d\n", up_valid_check(1, 1, 1, board));
	printf("(1,1) in 1 down valid %d\n", down_valid_check(1, 1, 1, board));
	printf("(1,1) in 1 left valid %d\n", left_valid_check(1, 1, 1, board));
	printf("(1,1) in 1 right valid %d\n", right_valid_check(1, 1, 1, board));

	board[1][1] = 1;
	printf("(2,1) in 1 up valid %d\n", up_valid_check(1, 2, 2, board));
	printf("(2,1) in 1 down valid %d\n", down_valid_check(1, 2, 2, board));
	printf("(2,1) in 1 left valid %d\n", left_valid_check(1, 2, 2, board));
	printf("(2,1) in 1 right valid %d\n", right_valid_check(1, 2, 2, board));

	board[2][1] = 2;
	printf("(3,1) in 1 up valid %d\n", up_valid_check(1, 3, 4, board));
	printf("(3,1) in 1 down valid %d\n", down_valid_check(1, 3, 4, board));
	printf("(3,1) in 1 left valid %d\n", left_valid_check(1, 3, 4, board));
	printf("(3,1) in 1 right valid %d\n", right_valid_check(1, 3, 4, board));

	board[3][1] = 3;
	printf("(4,1) in 3 up valid %d\n", up_valid_check(1, 4, 4, board));
	printf("(4,1) in 3 down valid %d\n", down_valid_check(1, 4, 4, board));
	printf("(4,1) in 3 left valid %d\n", left_valid_check(1, 4, 4, board));
	printf("(4,1) in 3 right valid %d\n", right_valid_check(1, 4, 4, board));

	int size = 4;
	set_box(1, 1, board, size);
	
	return (0);
}
