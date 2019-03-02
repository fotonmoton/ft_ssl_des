/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:06:43 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 21:06:44 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"
#include "ft_sha.h"
#include "libft.h"

static int init_sha256_ctx()
{
	t_sha256_ctx ctx;

	ft_sha256_init(&ctx);

	_is(ctx.a == 0x6a09e667);
	_is(ctx.b == 0xbb67ae85);
	_is(ctx.c == 0x3c6ef372);
	_is(ctx.d == 0xa54ff53a);
	_is(ctx.e == 0x510e527f);
	_is(ctx.f == 0x9b05688c);
	_is(ctx.g == 0x1f83d9ab);
	_is(ctx.h == 0x5be0cd19);
	_is(ctx.bit_len == 0);
	for (int i = 0; i < 64; i++)
		_is(ctx.block[i] == 0);

	_end("init sha256 ctx");
}

static int init_sha224_ctx()
{
	t_sha256_ctx ctx;

	ft_sha224_init(&ctx);

	_is(ctx.a == 0xc1059ed8);
	_is(ctx.b == 0x367cd507);
	_is(ctx.c == 0x3070dd17);
	_is(ctx.d == 0xf70e5939);
	_is(ctx.e == 0xffc00b31);
	_is(ctx.f == 0x68581511);
	_is(ctx.g == 0x64f98fa7);
	_is(ctx.h == 0xbefa4fa4);
	_is(ctx.bit_len == 0);
	for (int i = 0; i < 64; i++)
		_is(ctx.block[i] == 0);

	_end("init sha224 ctx");
}

static int decode_string_to_int_sha256()
{
	t_byte1 block[FT_SHA256_BLOCK_SIZE];
	t_byte4 words[FT_SHA256_WORDS_COUNT];

	ft_bzero(block, FT_SHA256_BLOCK_SIZE);
	block[0] = 'a';
	block[1] = 'b';
	block[2] = 'c';

	ft_sha256_decode(words, block);

	_is(words[0] == 0x61626300);

	_end("decode string to int sha256");
}

static int  encode_len_to_string_sha256()
{
	t_byte8 len;
	t_byte1 bits[FT_SHA256_MESSAGE_LENGTH_BYTE];

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

	ft_sha256_encode_len(bits, len);

	_is(bits[0] == (t_byte1)((len >> 56) & 0xff));
	_is(bits[7] == (t_byte1)(len & 0xff));
	_is(bits[6] == (t_byte1)((len >> 8) & 0xff));

	_end("encode len to string sha256");
}

static int encode_register_to_string_sha256()
{
	t_byte1 digest_part[4];
	t_byte4 reg;

	reg = 0xba7816bf;

	ft_sha256_encode_register(digest_part, reg);

	_is(digest_part[0] == 0xba);
	_is(digest_part[1] == 0x78);
	_is(digest_part[2] == 0x16);
	_is(digest_part[3] == 0xbf);

	_end("encode register to string sha256");
}

static int update_bit_count_sha256()
{
	t_sha256_ctx ctx;
	t_byte1 message[] = "abc";

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, sizeof(message));

	_is(ctx.bit_len == sizeof(message) * 8);

	_end("update bit count sha256");
}

static int fill_buffer_sha256()
{
	t_sha256_ctx ctx;
	t_byte1 message[] = "abc";

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, sizeof(message));

	_is(ft_strcmp((const char *)message, (const char *)ctx.block) == 0);

	_end("fill buffer sha256");
}

static void block_with_right_padding
(
	t_byte1 *message,
	t_byte8 message_len,
	t_byte1 padding[FT_SHA256_BLOCK_SIZE]
)
{
	ft_bzero(padding, FT_SHA256_BLOCK_SIZE);
	ft_memcpy(padding, message, message_len);
	padding[message_len] = 0x80;
}

static int add_right_padding_sha256()
{
	t_sha256_ctx ctx;
	t_byte1 message[] = "abc";
	t_byte8 buff_index;
	t_byte8 padding_len;
	t_byte1 padding[FT_SHA256_BLOCK_SIZE];
	t_byte1 block_with_message_and_pading[FT_SHA256_BLOCK_SIZE];
	int i;

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, sizeof(message));
	buff_index = (ctx.bit_len / 8) % 64;
	padding_len = (buff_index < 56) ? (56 - buff_index) : (120 - buff_index);
	ft_sha256_padding(padding);
	ft_sha256_update(&ctx, padding, padding_len);

	block_with_right_padding(message, sizeof(message),
		block_with_message_and_pading);

	i = 0;

	_is(ft_memcmp(ctx.block, block_with_message_and_pading,
		FT_SHA256_BLOCK_SIZE) == 0);

	_end("add right padding sha256");
}

static int compute_digest_sha256()
{
	t_byte1			message[] = "abc";
	t_sha256_ctx	ctx;
	t_byte1			digest[FT_SHA256_DIGEST_LENGTH_BYTE];

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha256_final(digest, &ctx);

	_is(ctx.a == 0xba7816bf);
	_is(ctx.b == 0x8f01cfea);
	_is(ctx.c == 0x414140de);
	_is(ctx.d == 0x5dae2223);
	_is(ctx.e == 0xb00361a3);
	_is(ctx.f == 0x96177a9c);
	_is(ctx.g == 0xb410ff61);
	_is(ctx.h == 0xf20015ad);

	_end("compute digest sha256");
}

static int compute_digest_sha224()
{
	t_byte1 message[] = "abc";
	t_sha256_ctx ctx;
	t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];

	ft_sha224_init(&ctx);
	ft_sha224_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha224_final(digest, &ctx);

	_is(ctx.a == 0x23097d22);
	_is(ctx.b == 0x3405d822);
	_is(ctx.c == 0x8642a477);
	_is(ctx.d == 0xbda255b3);
	_is(ctx.e == 0x2aadbce4);
	_is(ctx.f == 0xbda0b3f7);
	_is(ctx.g == 0xe36c9da7);

	_end("computee digst sha224");
}

static int create_digest_string_sha256()
{
	t_byte1 message[] = "abc";
	t_byte1 message_digest[] =
		"ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
	t_sha256_ctx ctx;
	t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];
	t_byte1 digest_string[FT_SHA256_STRING_SIZE_BYTE];

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha256_final(digest, &ctx);
	ft_sha256_digest_string(digest, digest_string);

	_is(ft_strcmp((const char *)message_digest,
		(const char *)digest_string) == 0);

	_end("create digest string sha256");
}

static int create_digest_string_sha224()
{
	t_byte1 message[] = "abc";
	t_byte1 message_digest[] =
		"23097d223405d8228642a477bda255b32aadbce4bda0b3f7e36c9da7";
	t_sha256_ctx ctx;
	t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];
	t_byte1 digest_string[FT_SHA224_STRING_SIZE_BYTE];

	ft_sha224_init(&ctx);
	ft_sha224_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha224_final(digest, &ctx);
	ft_sha224_digest_string(digest, digest_string);

	_is(ft_strcmp((const char *)message_digest,
		(const char *)digest_string) == 0);

	_end("create digest strinf sha224");
}

int sha_tests()
{
	_should(init_sha256_ctx);
	_should(init_sha224_ctx);
	_should(decode_string_to_int_sha256);
	_should(encode_len_to_string_sha256);
	_should(encode_register_to_string_sha256);
	_should(update_bit_count_sha256);
	_should(fill_buffer_sha256);
	_should(add_right_padding_sha256);
	_should(compute_digest_sha256);
	_should(compute_digest_sha224);
	_should(create_digest_string_sha256);
	_should(create_digest_string_sha224);

	return 0;
}