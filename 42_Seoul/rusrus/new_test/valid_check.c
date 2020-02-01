/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:11:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/01 22:46:56 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		left_valid_check(int col, int row, int height, int **board)
{
	int	i;
	int	max;
	int	count;
	int condition;

	count = 0;
	max = 0;
	i = 1;
	condition = board[row][0];
	while (i <= col)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		if (board[row][i] == height)
			return (0);
		i++;
	}
	if (height > max)
		count++;
	if (col == 4)
		if (condition == count)
			return (1);
	if (col < 4 && condition >= count)
		return (1);
	return (0);
}

int		right_valid_check(int col, int row, int height, int **board)
{
	int	i;
	int	max;
	int	count;
	int condition;

	count = 0;
	max = 0;
	i = 4;						
	condition = board[row][5];
	while (i >= col)
	{
		if (board[row][i] > max)   
		{
			max = board[row][i];
			count++;
		}
		if (board[row][i] == height)
			return (0);
		i--;
	}
	if (height > max)
		count++;
	if (col == 4)
		if (condition == count)
			return (1);
	if (col < 4 && condition >= count)
		return (1);
	return (0);
}

int		up_valid_check(int col, int row, int height, int **board)
{
	int	i;
	int	max;
	int	count;
	int condition;

	count = 0;
	max = 0;
	i = 1;
	condition = board[0][col];
	while (i <= row)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		if (board[i][col] == height)
			return (0);
		i++;
	}
	if (height > max)
		count++;
	if (row == 4)
		if (condition == count)
			return (1);
	if (row < 4 && condition >= count)
		return (1);
	return (0);
}

int		down_valid_check(int col, int row, int height, int **board)
{
	int	i;
	int	max;
	int	count;
	int condition;

	count = 0;
	max = 0;
	i = 4;							//size 값
	condition = board[5][col];
	while (i >= row)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		if (board[i][col] == height)
			return (0);
		i--;
	}
	if (height > max)
		count++;
	if (row == 4)
		if (condition == count)
			return (1);
	if (row < 4 && condition >= count)
		return (1);
	return (0);
}

int		is_valid(int col, int row, int height, int **board)
{
	if (left_valid_check(col, row, height, board) &&
		right_valid_check(col, row, height, board) &&
		up_valid_check(col, row, height, board) &&
		down_valid_check(col, row, height, board))
		return (1);
	return (0);
}
