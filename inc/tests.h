/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:36:58 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:40:12 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# define MUNIT_ENABLE_ASSERT_ALIASES
# include "munit.h"

/*
** MD5
*/
MunitResult	should_init_md5_ctx(const MunitParameter test_params[],
			void *test_data);
MunitResult	md5_update_change_count(const MunitParameter test_params[],
			void *test_data);
MunitResult	md5_decode_string_to_int(const MunitParameter test_params[],
			void *test_data);
MunitResult	md5_encode_bits_to_string(const MunitParameter test_params[],
			void *test_data);
MunitResult	md5_encode_register(const MunitParameter test_params[],
			void *test_data);
MunitResult	md5_create_digest(const MunitParameter test_params[],
			void *test_data);
MunitResult	md5_create_string(const MunitParameter test_params[],
			void *test_data);

/*
** SHA256
*/
MunitResult	should_init_ctx_sha256(const MunitParameter test_params[],
			void *test_data);
MunitResult	decode_string_to_int_sha256(const MunitParameter test_params[],
			void *test_data);
MunitResult	encode_len_to_string_sha256(const MunitParameter test_params[],
			void *test_data);
MunitResult	encode_register_to_string_sha256(const MunitParameter test_params[],
			void *test_data);
MunitResult	update_bit_count_sha256(const MunitParameter test_params[],
			void *test_data);
MunitResult	fill_buffer_sha256(const MunitParameter test_params[],
			void *test_data);
MunitResult	add_right_padding_sha256(const MunitParameter test_params[],
			void *test_data);
MunitResult	compute_digest_sha256(const MunitParameter test_params[],
			void *test_data);
MunitResult	create_digest_string_sha256(const MunitParameter test_params[],
			void *test_data);

/*
** SHA224
*/
MunitResult	should_init_ctx_sha224(const MunitParameter test_params[],
			void *test_data);
MunitResult	compute_digest_sha224(const MunitParameter test_params[],
			void *test_data);
MunitResult	create_digest_string_sha224(const MunitParameter test_params[],
			void *test_data);

/*
** BASE64
*/
MunitResult	should_init_base64_ctx(const MunitParameter test_params[],
			void *test_data);

MunitResult	should_fill_base64_buffer(const MunitParameter test_params[],
			void *test_data);

MunitResult should_transform_base64_block(const MunitParameter test_params[],
			void *test_data);
#endif
