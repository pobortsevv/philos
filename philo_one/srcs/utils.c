/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:14:05 by sabra             #+#    #+#             */
/*   Updated: 2021/04/18 18:19:38 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_space(char sym)
{
	if (sym == ' ' || (sym >= 9 && sym <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		else if (result < -2147483648 && sign == -1)
			return (0);
	}
	return (result * sign);
}
