/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:58:04 by spark             #+#    #+#             */
/*   Updated: 2021/06/19 17:38:45 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

# define CN "\033[0m"
# define CB "\033[30m"
# define CR  "\033[31m"
# define CG "\033[32m"
# define CY "\033[33m"
# define CBL "\033[34m"
# define CP "\033[35m"
# define CA "\033[36m"

# define FALSE 0
# define TRUE 1

# define NO_ONE_DIED 2
# define SOMEONE_DIED 3

# define TAKING_FORK 4
# define EATING 5
# define SLEEPING 6
# define THINKING 7
# define DEAD 8

typedef struct		s_info
{
	int				philo_num;
	int				eat_time;
	int				sleep_time;
	int				life_time;
	int				bucket_eat_time;
	int				starting_time;
	int				check_anyone_dead;
	sem_t			*fork;
	sem_t			*for_not_twisted_msg;
}					t_info;

typedef struct		s_philosopher
{
	int				number;
	int				eating_count;
	int				time_of_recent_meal;
	int				action;
	t_info			*info;
	pid_t			pid;
}					t_philosopher;

int					main(int ac, char *av[]);
int					show_error(char *str);
int					ft_atoi(const char *str);
int					get_time(void);
void				init_philo(t_info *info, t_philosopher **philo);
void				init_info(t_info *info, t_philosopher **philo);
void				running_philo(t_info *info, t_philosopher *philo);
void				*check_dead(void *philosopher);
void				print_message(t_philosopher *philo, int time);
void				*doing_all(void *philosopher);
int					taking_fork(t_philosopher *philo);
int					eating(t_philosopher *philo);
int					sleeping(t_philosopher *philo);
int					thinking(t_philosopher *philo);
void				clean_up_philo(t_info *info, t_philosopher *philo);

#endif
