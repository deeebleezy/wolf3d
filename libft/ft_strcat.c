/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:48:59 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/06 22:50:10 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ret;

	ret = s1;
	while (*s1)
		s1++;
	while (*s2)
		*(s1++) = *(s2++);
	*s1 = 0;
	return (ret);
}
