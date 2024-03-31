/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:52:53 by eliagarc          #+#    #+#             */
/*   Updated: 2023/09/17 18:52:54 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*aux_l;

	aux_l = (t_list *)malloc(1 * sizeof(t_list));
	if (!aux_l)
		return (NULL);
	aux_l->content = content;
	aux_l->next = NULL;
	return (aux_l);
}
