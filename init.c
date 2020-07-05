/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jocaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 20:31:08 by user42            #+#    #+#             */
/*   Updated: 2020/07/05 17:28:42 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_params(t_params *p, t_padd *padd)
{
	p->type = 0;
	p->minus = 0;
	p->zero = 0;
	p->prec = 0;
	p->prec_val = 0;
	p->width = 0;
	padd->zeros = 0;
	padd->sp = 0;
}
