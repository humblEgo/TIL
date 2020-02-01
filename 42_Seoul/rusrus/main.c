/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:02:13 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/01 17:11:42 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		rush(char *str)
{
	int		*raw;
	int		**num_arr;
	int		**result;
	int		i;

	raw = parsing_text(str);

	return (1);
}


int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if(!rush(argv[1])
			dsplay("Error");
	}
	else
		display("Error");
	display("\n");
	return (0);
}
