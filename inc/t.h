/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:36:58 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:40:12 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_H
# define T_H
# include <stdio.h>

# define FAIL() printf("\nfail in %s() %s:%d\n\n", __func__, __FILE__, __LINE__)
# define _is(t) do { if (!(t)) { FAIL(); return 1; } } while(0)
# define _should(t) do { int r = t(); if(r) return r; } while(0)
# define _p_start(m) do { printf("%s\n", m); } while(0)
# define _verify(m, t) do { _p_start(m); int r = t(); if(r) return r; } while(0)
# define _end(m) do { printf("  %s - OK\n", m); return 0; } while(0)

#endif
