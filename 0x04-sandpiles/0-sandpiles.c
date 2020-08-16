#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - print grid
 * @grid: grid to print
*/

static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * check_sandpile - check stability of grid
 * @grid1: grid to check
 * Return: return 1 if unstable
*/

int check_sandpile(int grid1[3][3])
{
	int i, j;
	int check = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (check);
}

/**
 * sum_grid - sum two grids
 * @grid1: grid to sum
 * @grid2: grid to sum
*/

void sum_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * sandpiles_aprox - feed a grid with sobrantes
 * @grid1: grid to evaluate
*/

void sandpiles_aprox(int grid1[3][3])
{
	int gridstore[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
	};
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0 && i - 1 < 3)
					gridstore[i - 1][j] += 1;
				if (j - 1 >= 0 && j - 1 < 3)
					gridstore[i][j - 1] += 1;
				if (i + 1 >= 0 && i + 1 < 3)
					gridstore[i + 1][j] += 1;
				if (j + 1 >= 0 && j + 1 < 3)
					gridstore[i][j + 1] += 1;
			}
		}
	}
	sum_grid(grid1, gridstore);
}

/**
 * sandpiles_sum - control the flux
 * @grid1: grid to sum
 * @grid2: grid to sum
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grid(grid1, grid2);
	while (!check_sandpile(grid1))
	{
		print_grid(grid1);
		sandpiles_aprox(grid1);
	}
}
