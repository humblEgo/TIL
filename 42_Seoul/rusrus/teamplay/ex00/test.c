
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g_num = 4;

int		**create_board(void)
{
	int **board;
	int r;
	int c;

	r = 0;
	board = (int **)malloc(sizeof(int *) * g_num);
	while (r < g_num)
	{
		c = 0;
		board[r] = (int *)malloc(sizeof(int *) * g_num);
		while (c < g_num)
		{
			board[r][c] = -1;
			c++;
		}
		r++;
	}
	return (board);
}


int	rush(int *str)
{
	int		*raw;
	int		**num_arr;
	int		str_len;
	int		r;
	int		c;

	num_arr = create_board();
	for (int i  = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", num_arr[i][j]);
		}
		printf("\n");
	}
	return (0);
}

/*
** Main function
**
** @param int argc
** @param char **argv
** @return int
*/
int main(void)
{
	int cond[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};

	printf("%d\n",rush(cond));
	return (0);
}
