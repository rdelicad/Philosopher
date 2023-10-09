/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:06:58 by rdelicad          #+#    #+#             */
/*   Updated: 2023/10/09 20:08:32 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	taken_fork(t_philo *p)
{
	pthread_mutex_lock(&p->l_fork);
	printf_action(p, "has taken a fork");
	if (p->t->n_philo != 1)
	{
		pthread_mutex_lock(&*p->r_fork);
		printf_action(p, "has taken a fork");
	}
	else
		return ;
}

void	ft_eat(t_philo *p)
{
	printf_action(p, "is eating");
	ft_usleep(p->t->eat_to_time);
	pthread_mutex_lock(&p->t->table);
	p->last_eat = time_start_prog();
	p->meals++;
	pthread_mutex_unlock(&p->t->table);
}

void	ft_sleep(t_philo *p)
{
	printf_action(p, "is sleeping");
	ft_usleep(p->t->sleep_to_time);
}

void	ft_thinking(t_philo *p)
{
	printf_action(p, "is thinking");
}