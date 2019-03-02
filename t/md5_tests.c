/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:06:22 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 21:06:33 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"
#include "ft_md5.h"
#include "libft.h"

static int init_ctx()
{
	t_md5_ctx ctx;

	ft_md5_init(&ctx);

	_is(ctx.a == 0x67452301);
	_is(ctx.b == 0xefcdab89);
	_is(ctx.c == 0x98badcfe);
	_is(ctx.d == 0x10325476);
	_is(ctx.bit_len == 0);
	for (int i = 0; i < FT_MD5_BLOCK_SIZE; i++)
		_is(ctx.block[i] == 0);

	_end("init ctx");
}

static int decode_string_to_int()
{
	t_byte1 block[FT_MD5_BLOCK_SIZE];
	t_byte4 words[FT_MD5_WORDS_COUNT];

	ft_bzero(block, FT_MD5_BLOCK_SIZE);
	block[0] = 'a';
	block[9] = 'b';
	block[63] = 'c';

	ft_md5_decode(words, block);

	_is((words[0] & 0xff) == 97);
	_is(((words[2] >> 8) & 0xff) == 98);
	_is(((words[15] >> 24) & 0xff) == 99);

	_end("decode string to int");
}

static int update_change_count()
{
	t_md5_ctx ctx;
	char message[] = "hello, World!";
	t_byte8 size = ft_strlen(message);

	ft_md5_init(&ctx);
	ft_md5_update(&ctx, (t_byte1 *)message, size);

	_is(size * 8 == ctx.bit_len);

	_end("update change count");
}

static int encode_bits_to_string()
{
	t_byte8 len;
	t_byte1 bits[FT_MD5_MESSAGE_LENGTH_BYTE];

	/*
		1111 0000 : 63 - 56
		0000 0000 : 55 - 48
		0000 0000 : 47 - 40
		0000 0000 : 39 - 32
		0000 0000 : 31 - 24
		0000 0000 : 23 - 16
		0110 0000 : 15 - 8
		1001 0000 : 7  - 0
	*/
	len = 17293822569102729360U;

	ft_md5_encode_len(bits, len);

	_is(bits[7] == (t_byte1)((len >> 56) & 0xff));
	_is(bits[0] == (t_byte1)(len & 0xff));
	_is(bits[1] == (t_byte1)((len >> 8) & 0xff));

	_end("encode bits to string");
}

static int encode_register()
{
	t_byte1 digest_part[4];
	t_byte4 reg;

	/*
		1000 0000 : 31 - 24
		1000 0000 : 23 - 16
		1000 0000 : 15 - 8
		1000 0000 : 7  - 0
	*/
	reg = 2155905152;

	ft_md5_encode_register(digest_part, reg);

	_is(digest_part[0] == (t_byte1)(reg & 0xff));
	_is(digest_part[1] == (t_byte1)((reg >> 8) & 0xff));
	_is(digest_part[2] == (t_byte1)((reg >> 16) & 0xff));
	_is(digest_part[3] == (t_byte1)((reg >> 24) & 0xff));

	_end("encode register");
}

static int create_digest()
{
	t_md5_ctx	ctx;
	t_byte1		digest[FT_MD5_DIGEST_LENGTH_BYTE];
	t_byte1		digest_string[FT_MD5_STRING_SIZE_BYTE];

	t_byte1		case1[] = "";
	t_byte1		case2[] = "a";
	t_byte1		case7[] = "1234567890123456789012345678901234567\
891234567890123456789012345678901234567890";

	ft_md5_init(&ctx);
	ft_md5_update(&ctx, case1, ft_strlen((const char *)case1));
	ft_md5_final(digest, &ctx);
	ft_md5_digest_string(digest, digest_string);

	_is(ft_strcmp((const char *)digest_string,
					"d41d8cd98f00b204e9800998ecf8427e") == 0);

	ft_md5_init(&ctx);
	ft_md5_update(&ctx, case2, ft_strlen((const char *)case2));
	ft_md5_final(digest, &ctx);
	ft_md5_digest_string(digest, digest_string);

	_is(ft_strcmp((const char *)digest_string,
					"0cc175b9c0f1b6a831c399e269772661") == 0);

	ft_md5_init(&ctx);
	ft_md5_update(&ctx, case7, ft_strlen((const char *)case7));
	ft_md5_final(digest, &ctx);
	ft_md5_digest_string(digest, digest_string);

	_is(ft_strcmp((const char *)digest_string,
					"2580a0aff7ef5e80f6b5432666530926") == 0);

	_end("create digest");
}

static int create_digest_string()
{
	t_byte1 digest[FT_MD5_DIGEST_LENGTH_BYTE];
	t_byte1 digest_string[FT_MD5_STRING_SIZE_BYTE];
	t_byte4 a;
	t_byte4 b;
	t_byte4 c;
	t_byte4 d;

	/* final registers values for empty input */
	a = 3649838548;
	b = 78774415;
	c = 2550759657;
	d = 2118318316;

	ft_md5_encode_register(digest, a);
	ft_md5_encode_register(&digest[4], b);
	ft_md5_encode_register(&digest[8], c);
	ft_md5_encode_register(&digest[12], d);

	ft_md5_digest_string(digest, digest_string);

	_is(ft_strcmp((const char *)digest_string,
		"d41d8cd98f00b204e9800998ecf8427e") == 0);

	_end("create digest string");
}

int md5_tests()
{
	_should(init_ctx);
	_should(decode_string_to_int);
	_should(update_change_count);
	_should(encode_bits_to_string);
	_should(encode_register);
	_should(create_digest);
	_should(create_digest_string);
	return 0;
}