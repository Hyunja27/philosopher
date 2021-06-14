/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:18:13 by spark             #+#    #+#             */
/*   Updated: 2021/06/14 22:17:05 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     show_error(char *str)
{
    printf("%s",str);
    return (FALSE);
}

int	ft_atoi(const char *str)
{
	int rt;
	int indic;
	int repeat;

	rt = 0;
	repeat = 0;
	indic = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			indic *= -1;
	while ('0' <= *str && *str <= '9')
	{
		rt *= 10;
		rt += (indic * (*(str++) - '0'));
		repeat++;
		if (repeat > 10 && indic == -1)
			return (0);
		else if (repeat > 10 && indic != -1)
			return (-1);
	}
	return (rt);
}

void		print_message(t_philosopher *philo, int time)
{
	pthread_mutex_lock(&philo->info->for_not_twisted_msg);
	if (philo->info->check_anyone_dead == FALSE)
	{
		if (philo->action == TAKING_FORK)
			printf(C_GREN "[%d ms]" C_NRML " %d philo has taken a fork\n", time, philo->number);
		else if (philo->action == EATING)
		{
			printf(C_GREN "[%d ms]" C_NRML " %d philo has taken a fork\n", time, philo->number);
			printf(C_RED "[%d ms]" C_NRML " %d philo start eat         =%d times=\n",
					time, philo->number, philo->eating_count + 1);
		}
		else if (philo->action == SLEEPING)
			printf(C_YLLW "[%d ms]" C_NRML " %d philo is sleeping..\n", time, philo->number);
		else if (philo->action == THINKING)
			printf(C_BLCK "[%d ms]" C_NRML " %d philo start thinking\n", time, philo->number);
		else if (philo->action == DEAD)
			printf(C_GREN "[%d ms]" C_NRML " %d philo died\n", time, philo->number);
	}
	pthread_mutex_unlock(&philo->info->for_not_twisted_msg);
}