#include "../include/header.h"

int	count_left(int board[N][N], int row)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_right(int board[N][N], int row)
{
	int	i;
	int	max;
	int	count;

	i = N - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_top(int board[N][N], int col)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < N)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_bottom(int board[N][N], int col)
{
	int	i;
	int	max;
	int	count;

	i = N - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		i--;
	}
	return (count);
}
