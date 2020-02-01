/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:57:56 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/01 19:34:58 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* variable name 'col' means column_idex of box array.
*/

void	set_box(int col, int row, int board[][6], int size) 
{
	int height_box;

	heigth_box = 1;	
	if (col == size + 1)
	{
		print_boxes(board, size);
		return ;
	}
	else
	{
		while (row <= size)
		{
			while (heigth_box <= size)
			{
				if (is_valid(col, row, heigth_box, board))
				{
					board[row][col] = height_box;
					set_box(col + 1, row, board, size);
				}
				height_box++;
			}
			row++;
		}
	}
	return ;
}

int	main(int argc, char **argv)
{

	int **board;
	int size;
	int word_count;
	int i;

	if (argc == 1 || argc > 2)
		return (0);
	i = 0;
	word_count = 0;
	while (*(argv + 1)[i])
	{
		if (*(argv + 1)[i] == ' ')
			word_count++;
		i++;
	}
	i = 0;
	while (i * i < word_count)
		i++;
	if (i * i == word_count)
		size = i;
	board = (int *)malloc(sizeof(int *) * (size + 2));
	i = 0;
	while (i < size + 2)
	{
		board[i] = (int *)malloc(sizeof(int) * size);
	}
	set_box(1, 1, board, size)
	return (0);
}
