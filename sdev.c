/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:30:34 by smamba            #+#    #+#             */
/*   Updated: 2016/06/12 10:30:35 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ft_dev_space(t_fi_list **begin, int *tab)
{
	t_fi_list	*tmp;

	tmp = *begin;
	tab[0] = 0;
	tab[1] = 0;
	while (tmp != NULL)
	{
		if (tmp->device != 0)
		{
			if (ft_nb_chiffre(major(tmp->device)) > tab[0])
				tab[0] = ft_nb_chiffre(major(tmp->device));
			if (ft_nb_chiffre(minor(tmp->device)) > tab[1])
				tab[1] = ft_nb_chiffre(minor(tmp->device));
		}
		tmp = tmp->next;
	}
	return (tab);
}
