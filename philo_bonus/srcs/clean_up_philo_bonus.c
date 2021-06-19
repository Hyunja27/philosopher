/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_philo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:51:45 by spark             #+#    #+#             */
/*   Updated: 2021/06/19 17:00:09 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_up_philo(t_info *info, t_philosopher *philo)
{
	int		i;

	i = -1;
	sem_unlink("fork");
	sem_unlink("for_msg");
	free(philo);
	(void)info;
}
