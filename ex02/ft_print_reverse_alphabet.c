/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:28:38 by edcastro          #+#    #+#             */
/*   Updated: 2023/03/07 12:20:58 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	reverse_letter;

	reverse_letter = 'z';
	while (reverse_letter >= 'a')
	{
		write(1, &reverse_letter, 1);
		reverse_letter--;
	}
}
