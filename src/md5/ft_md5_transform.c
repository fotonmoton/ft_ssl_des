/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:08:38 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 20:10:00 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "libft.h"

static void	round_1(t_md5_intr_registers *r, t_byte4 w[FT_MD5_WORDS_COUNT])
{
	FF(r->a, r->b, r->c, r->d, w[0], S11, 0xd76aa478);
	FF(r->d, r->a, r->b, r->c, w[1], S12, 0xe8c7b756);
	FF(r->c, r->d, r->a, r->b, w[2], S13, 0x242070db);
	FF(r->b, r->c, r->d, r->a, w[3], S14, 0xc1bdceee);
	FF(r->a, r->b, r->c, r->d, w[4], S11, 0xf57c0faf);
	FF(r->d, r->a, r->b, r->c, w[5], S12, 0x4787c62a);
	FF(r->c, r->d, r->a, r->b, w[6], S13, 0xa8304613);
	FF(r->b, r->c, r->d, r->a, w[7], S14, 0xfd469501);
	FF(r->a, r->b, r->c, r->d, w[8], S11, 0x698098d8);
	FF(r->d, r->a, r->b, r->c, w[9], S12, 0x8b44f7af);
	FF(r->c, r->d, r->a, r->b, w[10], S13, 0xffff5bb1);
	FF(r->b, r->c, r->d, r->a, w[11], S14, 0x895cd7be);
	FF(r->a, r->b, r->c, r->d, w[12], S11, 0x6b901122);
	FF(r->d, r->a, r->b, r->c, w[13], S12, 0xfd987193);
	FF(r->c, r->d, r->a, r->b, w[14], S13, 0xa679438e);
	FF(r->b, r->c, r->d, r->a, w[15], S14, 0x49b40821);
}

static void	round_2(t_md5_intr_registers *r, t_byte4 w[FT_MD5_WORDS_COUNT])
{
	GG(r->a, r->b, r->c, r->d, w[1], S21, 0xf61e2562);
	GG(r->d, r->a, r->b, r->c, w[6], S22, 0xc040b340);
	GG(r->c, r->d, r->a, r->b, w[11], S23, 0x265e5a51);
	GG(r->b, r->c, r->d, r->a, w[0], S24, 0xe9b6c7aa);
	GG(r->a, r->b, r->c, r->d, w[5], S21, 0xd62f105d);
	GG(r->d, r->a, r->b, r->c, w[10], S22, 0x2441453);
	GG(r->c, r->d, r->a, r->b, w[15], S23, 0xd8a1e681);
	GG(r->b, r->c, r->d, r->a, w[4], S24, 0xe7d3fbc8);
	GG(r->a, r->b, r->c, r->d, w[9], S21, 0x21e1cde6);
	GG(r->d, r->a, r->b, r->c, w[14], S22, 0xc33707d6);
	GG(r->c, r->d, r->a, r->b, w[3], S23, 0xf4d50d87);
	GG(r->b, r->c, r->d, r->a, w[8], S24, 0x455a14ed);
	GG(r->a, r->b, r->c, r->d, w[13], S21, 0xa9e3e905);
	GG(r->d, r->a, r->b, r->c, w[2], S22, 0xfcefa3f8);
	GG(r->c, r->d, r->a, r->b, w[7], S23, 0x676f02d9);
	GG(r->b, r->c, r->d, r->a, w[12], S24, 0x8d2a4c8a);
}

static void	round_3(t_md5_intr_registers *r, t_byte4 w[FT_MD5_WORDS_COUNT])
{
	HH(r->a, r->b, r->c, r->d, w[5], S31, 0xfffa3942);
	HH(r->d, r->a, r->b, r->c, w[8], S32, 0x8771f681);
	HH(r->c, r->d, r->a, r->b, w[11], S33, 0x6d9d6122);
	HH(r->b, r->c, r->d, r->a, w[14], S34, 0xfde5380c);
	HH(r->a, r->b, r->c, r->d, w[1], S31, 0xa4beea44);
	HH(r->d, r->a, r->b, r->c, w[4], S32, 0x4bdecfa9);
	HH(r->c, r->d, r->a, r->b, w[7], S33, 0xf6bb4b60);
	HH(r->b, r->c, r->d, r->a, w[10], S34, 0xbebfbc70);
	HH(r->a, r->b, r->c, r->d, w[13], S31, 0x289b7ec6);
	HH(r->d, r->a, r->b, r->c, w[0], S32, 0xeaa127fa);
	HH(r->c, r->d, r->a, r->b, w[3], S33, 0xd4ef3085);
	HH(r->b, r->c, r->d, r->a, w[6], S34, 0x4881d05);
	HH(r->a, r->b, r->c, r->d, w[9], S31, 0xd9d4d039);
	HH(r->d, r->a, r->b, r->c, w[12], S32, 0xe6db99e5);
	HH(r->c, r->d, r->a, r->b, w[15], S33, 0x1fa27cf8);
	HH(r->b, r->c, r->d, r->a, w[2], S34, 0xc4ac5665);
}

static void	round_4(t_md5_intr_registers *r, t_byte4 w[FT_MD5_WORDS_COUNT])
{
	II(r->a, r->b, r->c, r->d, w[0], S41, 0xf4292244);
	II(r->d, r->a, r->b, r->c, w[7], S42, 0x432aff97);
	II(r->c, r->d, r->a, r->b, w[14], S43, 0xab9423a7);
	II(r->b, r->c, r->d, r->a, w[5], S44, 0xfc93a039);
	II(r->a, r->b, r->c, r->d, w[12], S41, 0x655b59c3);
	II(r->d, r->a, r->b, r->c, w[3], S42, 0x8f0ccc92);
	II(r->c, r->d, r->a, r->b, w[10], S43, 0xffeff47d);
	II(r->b, r->c, r->d, r->a, w[1], S44, 0x85845dd1);
	II(r->a, r->b, r->c, r->d, w[8], S41, 0x6fa87e4f);
	II(r->d, r->a, r->b, r->c, w[15], S42, 0xfe2ce6e0);
	II(r->c, r->d, r->a, r->b, w[6], S43, 0xa3014314);
	II(r->b, r->c, r->d, r->a, w[13], S44, 0x4e0811a1);
	II(r->a, r->b, r->c, r->d, w[4], S41, 0xf7537e82);
	II(r->d, r->a, r->b, r->c, w[11], S42, 0xbd3af235);
	II(r->c, r->d, r->a, r->b, w[2], S43, 0x2ad7d2bb);
	II(r->b, r->c, r->d, r->a, w[9], S44, 0xeb86d391);
}

void		ft_md5_transform(t_md5_ctx *ctx, t_byte1 block[FT_MD5_BLOCK_SIZE])
{
	t_byte4					words[FT_MD5_WORDS_COUNT];
	t_md5_intr_registers	t;

	ft_md5_decode(words, block);
	t.a = ctx->a;
	t.b = ctx->b;
	t.c = ctx->c;
	t.d = ctx->d;
	round_1(&t, words);
	round_2(&t, words);
	round_3(&t, words);
	round_4(&t, words);
	ctx->a += t.a;
	ctx->b += t.b;
	ctx->c += t.c;
	ctx->d += t.d;
	ft_bzero(words, sizeof(words));
}
