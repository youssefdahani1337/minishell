/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:36:03 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/26 12:04:46 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	printtoken(t_tokens *token)
{
		printf("[%d]", token->join);
	printf("type ");
	switch (token->type)
	{
		case pip :
			printf("pip ");
			break;
		case d_quote :
			printf("d_quote ");
			break;
		case s_quote :
			printf("s_quote ");
			break;
		case red_in :
			printf("red_in ");
			break;
		case red_out :
			printf("red_out ");
			break;
		case var :
			printf("var ");
			break;
		case var_ex :
			printf("var_ex ");
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
		case equal :
			printf("equal ");
			break;
		case equal_plus :
			printf("equal_plus ");
			break;
		case terminator :
			printf("terminator");
			break;
		case error :
			printf("error");
			break;
		
	}
	printf("Value[%s]\n", token->value);
	
}