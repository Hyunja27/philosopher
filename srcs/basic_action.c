/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:02:51 by spark             #+#    #+#             */
/*   Updated: 2021/06/17 17:16:08 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			*check_dead(void *philosopher)
{
	t_philosopher	*philo;
	int				must_eat_count;
	int				time;

	philo = (t_philosopher *)philosopher;
	must_eat_count = philo->info->bucket_eat_time;
	while (1)
	{
		usleep(500);
		time = get_time() - philo->info->starting_time;
		if (must_eat_count != -1 && philo->eating_count >= must_eat_count)
			break ;
		if (time - philo->time_of_recent_meal > philo->info->life_time)
		{
			philo->action = DEAD;
			print_message(philo, time);
			philo->info->check_anyone_dead = 1;
			exit(0);
			break ;
		}
	}
	return (NULL);
}

int			taking_fork(t_philosopher *philo)
{
	int				time;

	if (philo->info->check_anyone_dead == 1)
		return (SOMEONE_DIED);
	pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
	time = get_time() - philo->info->starting_time;
	philo->action = TAKING_FORK;
	print_message(philo, time);
	return (NO_ONE_DIED);
}

int				eating(t_philosopher *philo)
{
	int				must_eat_count;
	int				start_time;

	must_eat_count = philo->info->bucket_eat_time;
	if (philo->info->check_anyone_dead == TRUE)
		return (SOMEONE_DIED);
	pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
	philo->time_of_recent_meal = get_time() - philo->info->starting_time;
	philo->action = EATING;
	print_message(philo, philo->time_of_recent_meal);
	start_time = get_time();
	while (get_time() - start_time <= philo->info->eat_time &&\
			philo->info->check_anyone_dead == FALSE)
		usleep(1000);
	++philo->eating_count;
	pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
	return (NO_ONE_DIED);
}

int				sleeping(t_philosopher *philo)
{
	int				time;
	int				start_time;

	if (philo->info->check_anyone_dead == TRUE)
		return (SOMEONE_DIED);
	time = get_time() - philo->info->starting_time;
	philo->action = SLEEPING;
	print_message(philo, time);
	start_time = get_time();
	while (get_time() - start_time <= philo->info->sleep_time && philo->info->check_anyone_dead == FALSE)
		usleep(1000);
	return (NO_ONE_DIED);
}

int				thinking(t_philosopher *philo)
{
	int				time;

	if (philo->info->check_anyone_dead == TRUE)
		return (SOMEONE_DIED);
	time = get_time() - philo->info->starting_time;
	philo->action = THINKING;
	print_message(philo, time);
	return (NO_ONE_DIED);
}
