/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:36:03 by yodahani          #+#    #+#             */
/*   Updated: 2023/05/22 01:39:59 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	printtoken(t_tokens *token)
{
	printf("type ");
	switch (token->type)
	{
		case pip :
			printf("pip ");
			break;
		case red_in :
			printf("red_in ");
			break;
		case red_out :
			printf("red_out ");
			break;
		case red_app :
			printf("red_app");
			break;
		case herdoc :
			printf("herdoc ");
			break;
		case string :
			printf("string ==");
			break;
		case d_qoute :
			printf("Double quote ==");
			break;
		case s_qoute :
			printf("s_quote ==");
		case space :
			printf("space ==");
			break;
		case terminator :
			printf("terminator ==");
			break;
		
	}
	printf(" Value[%s]\n", token->value);
	
}