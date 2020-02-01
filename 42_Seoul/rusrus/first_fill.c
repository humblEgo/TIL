
void	col_up(int **board)
{
	int		c;
	int		r;
	c = -1;
	while (++c < 6)
	{
		if (board[0][c] == 1)
			board[1][c] = 4;
		else if (board[0][c] == 4)
		{
			r = 0;
			while (++r < 5)
				board[r][c] = r;
		}
	}
}
void	col_down(int **board)
{
	int		c;
	int		r;
	int		n;
	c = 6;
	while (--c >= 0)
	{
		if (board[5][c] == 1)
			board[4][c] = 4;
		else if (board[5][c] == 4)
		{
			r = 0;
			n = 4;
			while (++r < 5)
			{
				board[r][c] = n;
				n--;
			}
		}
	}
}
void	row_left(int **board)
{
	int		r;
	int		c;
	r = -1;
	while (++r < 6)
	{
		if (board[r][0] == 1)
			board[r][1] = 4;
		else if (board[r][0] == 4)
		{
			c = 0;
			while (++c < 5)
				board[r][c] = c;
		}
	}
}

void	row_right(int **board)
{
	int		r;
	int		c;
	int		n;
	r = 6;
	while (--r >= 0)
	{
		if (board[r][5] == 1)
			board[r][4] = 4;
		else if (board[r][5] == 4)
		{
			c = 0;
			n = 4;
			while (++c < 5)
			{
				board[r][c] = n;
				n--;
			}
		}
	}
}

void	first_fill(int **board)
{
	col_up(board);
	col_down(board);
	row_left(board);
	row_right(board);
}
