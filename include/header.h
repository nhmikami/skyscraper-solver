#ifndef SOLVE_H
# define SOLVE_H

# include <unistd.h>

# ifndef N
#  define N 4
# endif

int	solve_board(int board[N][N], int views[4][N], int row, int col);
int	count_left(int board[N][N], int row);
int	count_right(int board[N][N], int row);
int	count_top(int board[N][N], int col);
int	count_bottom(int board[N][N], int col);

#endif