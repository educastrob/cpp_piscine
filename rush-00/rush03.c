/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol4 <ancarol4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:09:17 by mchamma           #+#    #+#             */
/*   Updated: 2023/03/05 15:43:14 by ancarol4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);

// first column
void	first_column(int amount_lines, int y)
{
	if (amount_lines == 1 || amount_lines == y)
		ft_putchar('A');
	else
		ft_putchar('B');
}

// last column
void	last_column(int amount_lines, int y)
{
	if (amount_lines == 1 || amount_lines == y)
		ft_putchar('C');
	else
		ft_putchar('B');
}

// mid column 
void	mid_column(int amount_lines, int y)
{
	if (amount_lines == 1 || amount_lines == y)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	amount_columns;
	int	amount_lines;

	amount_columns = 0;
	amount_lines = 0;
	while (++amount_lines <= y)
	{
		while (++amount_columns <= x)
		{
			if (amount_columns == 1)
				first_column(amount_lines, y);
			else if (amount_columns == x)
				last_column(amount_lines, y);
			else
				mid_column(amount_lines, y);
		}
		amount_columns = 0;
		ft_putchar('\n');
	}
}
