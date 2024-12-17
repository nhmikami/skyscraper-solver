#include "../include/header.h"

int	define_views(char *str, int views[4][N])
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '0' + N)
		{
			views[n / N][n % N] = str[i] - '0';
			i++;
			n++;
			if (str[i] >= '1' && str[i] <= '0' + N)
				return (0);
		}
		else
			return (0);
		if (str[i] == ' ')
			i++;
	}
	if (n != 4 * N || i != (8 * N - 1)) 
		return (0);
	return (1);
}

void	put_zero(int board[N][N])
{
	int	row;
	int	col;

	row = 0;
	while (row < N)
	{
		col = 0;
		while (col < N)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	return ;
}

void	print_board(int board[N][N])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < N)
	{
		col = 0;
		while (col < N)
		{
			c = board[row][col] + '0';
			write(1, &c, 1);
			if (col != N - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
	return ;
}

int	main(int ac, char **av)
{
	int	board[N][N];
	int	views[4][N];

	if (ac == 2)
	{
		put_zero(board);
		if (define_views(av[1], views) == 0)
		{
			write(1, "Usage: ./skyscraper-solver \"col1up ... colNup col1down ... colNdown row1left ... rowNleft row1right ... rowNright\"\n", 115);
			return (0);
		}
		if (solve_board(board, views, 0, 0) == 1)
		{
			print_board(board);
			return (0);
		}
		else
		{
			write(1, "Could not solve the grid\n", 25);
			return (0);
		}
	}
	write(1, "Usage: ./skyscraper-solver \"col1up ... colNup col1down ... colNdown row1left ... rowNleft row1right ... rowNright\"\n", 115);
	return (0);
}
