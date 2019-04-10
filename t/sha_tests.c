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

	_IS(ctx.a == 0x6a09e667);
	_IS(ctx.b == 0xbb67ae85);
	_IS(ctx.c == 0x3c6ef372);
	_IS(ctx.d == 0xa54ff53a);
	_IS(ctx.e == 0x510e527f);
	_IS(ctx.f == 0x9b05688c);
	_IS(ctx.g == 0x1f83d9ab);
	_IS(ctx.h == 0x5be0cd19);
	_IS(ctx.bit_len == 0);
	for (int i = 0; i < 64; i++)
		_IS(ctx.block[i] == 0);

	_END("init sha256 ctx");
}

static int init_sha224_ctx()
{
	t_sha256_ctx ctx;

	ft_sha224_init(&ctx);

	_IS(ctx.a == 0xc1059ed8);
	_IS(ctx.b == 0x367cd507);
	_IS(ctx.c == 0x3070dd17);
	_IS(ctx.d == 0xf70e5939);
	_IS(ctx.e == 0xffc00b31);
	_IS(ctx.f == 0x68581511);
	_IS(ctx.g == 0x64f98fa7);
	_IS(ctx.h == 0xbefa4fa4);
	_IS(ctx.bit_len == 0);
	for (int i = 0; i < 64; i++)
		_IS(ctx.block[i] == 0);

	_END("init sha224 ctx");
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

	_IS(words[0] == 0x61626300);

	_END("decode string to int sha256");
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

	_IS(bits[0] == (t_byte1)((len >> 56) & 0xff));
	_IS(bits[7] == (t_byte1)(len & 0xff));
	_IS(bits[6] == (t_byte1)((len >> 8) & 0xff));

	_END("encode len to string sha256");
}

static int encode_register_to_string_sha256()
{
	t_byte1 digest_part[4];
	t_byte4 reg;

	reg = 0xba7816bf;

	ft_sha256_encode_register(digest_part, reg);

	_IS(digest_part[0] == 0xba);
	_IS(digest_part[1] == 0x78);
	_IS(digest_part[2] == 0x16);
	_IS(digest_part[3] == 0xbf);

	_END("encode register to string sha256");
}

static int update_bit_count_sha256()
{
	t_sha256_ctx ctx;
	t_byte1 message[] = "abc";

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, sizeof(message));

	_IS(ctx.bit_len == sizeof(message) * 8);

	_END("update bit count sha256");
}

static int fill_buffer_sha256()
{
	t_sha256_ctx ctx;
	t_byte1 message[] = "abc";

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, sizeof(message));

	_IS(ft_strcmp((const char *)message, (const char *)ctx.block) == 0);

	_END("fill buffer sha256");
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

	_IS(ft_memcmp(ctx.block, block_with_message_and_pading,
		FT_SHA256_BLOCK_SIZE) == 0);

	_END("add right padding sha256");
}

static int compute_digest_sha256()
{
	t_byte1			message[] = "abc";
	t_sha256_ctx	ctx;
	t_byte1			digest[FT_SHA256_DIGEST_LENGTH_BYTE];

	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha256_final(digest, &ctx);

	_IS(ctx.a == 0xba7816bf);
	_IS(ctx.b == 0x8f01cfea);
	_IS(ctx.c == 0x414140de);
	_IS(ctx.d == 0x5dae2223);
	_IS(ctx.e == 0xb00361a3);
	_IS(ctx.f == 0x96177a9c);
	_IS(ctx.g == 0xb410ff61);
	_IS(ctx.h == 0xf20015ad);

	_END("compute digest sha256");
}

static int compute_digest_sha224()
{
	t_byte1 message[] = "abc";
	t_sha256_ctx ctx;
	t_byte1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];

	ft_sha224_init(&ctx);
	ft_sha224_update(&ctx, message, ft_strlen((const char *)message));
	ft_sha224_final(digest, &ctx);

	_IS(ctx.a == 0x23097d22);
	_IS(ctx.b == 0x3405d822);
	_IS(ctx.c == 0x8642a477);
	_IS(ctx.d == 0xbda255b3);
	_IS(ctx.e == 0x2aadbce4);
	_IS(ctx.f == 0xbda0b3f7);
	_IS(ctx.g == 0xe36c9da7);

	_END("computee digst sha224");
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

	_IS(ft_strcmp((const char *)message_digest,
		(const char *)digest_string) == 0);

	_END("create digest string sha256");
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

	_IS(ft_strcmp((const char *)message_digest,
		(const char *)digest_string) == 0);

	_END("create digest strinf sha224");
}

int sha_tests()
{
	_SHOULD(init_sha256_ctx);
	_SHOULD(init_sha224_ctx);
	_SHOULD(decode_string_to_int_sha256);
	_SHOULD(encode_len_to_string_sha256);
	_SHOULD(encode_register_to_string_sha256);
	_SHOULD(update_bit_count_sha256);
	_SHOULD(fill_buffer_sha256);
	_SHOULD(add_right_padding_sha256);
	_SHOULD(compute_digest_sha256);
	_SHOULD(compute_digest_sha224);
	_SHOULD(create_digest_string_sha256);
	_SHOULD(create_digest_string_sha224);

	return 0;
}