#include "../include/header.h"

int	num_is_valid(int board[N][N], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (board[row][i] == num || board[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_row(int board[N][N], int views[4][N], int row)
{
	if (views[2][row] != count_left(board, row))
		return (0);
	if (views[3][row] != count_right(board, row))
		return (0);
	return (1);
}

int	check_col(int board[N][N], int views[4][N], int col)
{
	if (views[0][col] != count_top(board, col))
		return (0);
	if (views[1][col] != count_bottom(board, col))
		return (0);
	return (1);
}

int	check_row_col(int board[N][N], int views[4][N], int row, int col)
{
	int	check_r;
	int	check_c;

	check_r = 1;
	check_c = 1;
	if (col == N - 1)
		check_r = check_row(board, views, row);
	if (row == N - 1)
		check_c = check_col(board, views, col);
	if (check_r == 1 && check_c == 1)
		return (1);
	else
		return (0);
}

int	solve_board(int board[N][N], int views[4][N], int row, int col)
{
	int	num;
	int	check;

	if (row == N)
		return (1);
	if (col == N)
		return (solve_board(board, views, row + 1, 0));
	num = 1;
	while (num <= N)
	{
		if (num_is_valid(board, row, col, num))
		{
			board[row][col] = num;
			check = 1;
			check = check_row_col(board, views, row, col);
			if (check == 1)
				if (solve_board(board, views, row, col + 1) == 1)
					return (1);
			board[row][col] = 0;
		}
		num++;
	}
	return (0);
}
