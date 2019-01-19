/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:58:39 by gtertysh          #+#    #+#             */
/*   Updated: 2019/01/19 17:59:19 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# include <stdint.h>

# define FT_BASE64_BLOCK_SIZE 24

typedef uint64_t		t_byte8;
typedef unsigned char	t_byte1;

typedef struct			s_base64_ctx
{
	t_byte8				block_bit_index;
	t_byte1				block[FT_BASE64_BLOCK_SIZE];
}						t_base64_ctx;

void					ft_base64_init(t_base64_ctx *ctx);

#endif
