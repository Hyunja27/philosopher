/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:57:20 by spark             #+#    #+#             */
/*   Updated: 2021/06/14 21:04:40 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char *av[])
{
    int				rt;
    t_info			info;
    t_philosopher	*philo;
    

    rt = 0;
    if (ac < 5 || ac > 6)
       rt =  show_error("Argment Num is Incorrect.");
    else
    {
        info.philo_num = ft_atoi(av[1]);
        info.life_time = ft_atoi(av[2]);
        info.eat_time = ft_atoi(av[3]);
        info.sleep_time = ft_atoi(av[4]);
        if (ac == 6)
            info.bucket_eat_time = ft_atoi(av[5]);
        else
            info.bucket_eat_time = -1;
        if (info.bucket_eat_time < 0 || info.eat_time < 0 ||\
            info.sleep_time < 0 || info.life_time < 0 || info.philo_num < 0)
            rt =  show_error("Argment Value is Incorrect.");
        // printf("\nphilo num: %d\nlife_time: %d\neat_time: %d\nsleep_time: %d\nbucket_eat_time %d\n\n", info.philo_num, info.life_time, info.eat_time, info.sleep_time, info.bucket_eat_time);
        init_philo(&info, &philo);
        running_philo(&info, philo);
        clean_up_philo(&info, philo);
    }
    return (rt);
}
 