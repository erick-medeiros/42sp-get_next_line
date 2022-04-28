/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 05:38:20 by eandre-f          #+#    #+#             */
/*   Updated: 2022/04/28 05:39:31 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

void	check_sucess(int id);
void	check_error(int id, char const *gnl, char const *r);
void	check(int id, char *gnl, char const *r);

#endif
