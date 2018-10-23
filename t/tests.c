/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:00:24 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 21:05:47 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "tests_macros.h"

MunitTest g_md5_tests[] = {
	IT("/init_ctx", should_init_ctx, NULL, NULL, 0, NULL),
	IT("/updates_ctx_count", update_should_change_count, NULL, NULL, 0, NULL),
	IT("/decode_string_to_int", decode_string_to_int, NULL, NULL, 0, NULL),
	IT("/encode_bits_to_string", encode_bits_to_string, NULL, NULL, 0, NULL),
	IT("/encode_register", encode_register, NULL, NULL, 0, NULL),
	IT("/creates_digest", create_digest, NULL, NULL, 0, NULL),
	IT("/creates_string", create_string, NULL, NULL, 0, NULL),
	END_IT
};

MunitTest g_sha_tests[] = {
	IT("/init_ctx_256", should_init_ctx_sha256, NULL, NULL, 0, NULL),
	IT("/init_ctx_224", should_init_ctx_sha224, NULL, NULL, 0, NULL),
	IT("/decode_string", decode_string_to_int_sha256, NULL, NULL, 0, NULL),
	IT("/encode_len", encode_len_to_string_sha256, NULL, NULL, 0, NULL),
	IT("/enc_register", encode_register_to_string_sha256, NULL, NULL, 0, NULL),
	IT("/update_bit_count", update_bit_count_sha256, NULL, NULL, 0, NULL),
	IT("/fill_buffer", fill_buffer_sha256, NULL, NULL, 0, NULL),
	IT("/add_right_padding", add_right_padding_sha256, NULL, NULL, 0, NULL),
	IT("/compute_digest_256", compute_digest_sha256, NULL, NULL, 0, NULL),
	IT("/compute_digest_224", compute_digest_sha224, NULL, NULL, 0, NULL),
	IT("/creates_string_256", create_digest_string_sha256, NULL, NULL, 0, NULL),
	IT("/creates_string_224", create_digest_string_sha224, NULL, NULL, 0, NULL),
	END_IT};

static const MunitSuite g_ft_ssl_suites[] = {
	{(char *)"/md5_suite", g_md5_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE},
	{(char *)"/sha_suite", g_sha_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE},
	{NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE}
};

static const MunitSuite g_main_suite = {
	(char *)"/ft_ssl",
	NULL,
	(MunitSuite *)g_ft_ssl_suites,
	1,
	MUNIT_SUITE_OPTION_NONE
};

int	main(int argc, char **argv)
{
	return (munit_suite_main(&g_main_suite, NULL, argc, argv));
}
