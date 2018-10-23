/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:07:36 by gtertysh          #+#    #+#             */
/*   Updated: 2018/10/23 19:36:23 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define FT_SSL_ALGS_COUNT 3
# define FT_SSL_BUFFER_SIZE 1024

typedef struct s_ft_ssl	t_ft_ssl;

typedef void			(*t_process_stdin)(t_ft_ssl *ft_ssl);
typedef void			(*t_process_string)(const char *string,
							t_ft_ssl *ft_ssl);
typedef void			(*t_process_file)(const char *filename,
							t_ft_ssl *ft_ssl);

typedef struct			s_flags
{
	int					quiet;
	int					reverse;
	int					print_stdin;
	int					something_printed;
}						t_flags;

typedef struct			s_alorithm
{
	const char			*name;
	t_process_stdin		process_stdin;
	t_process_file		process_file;
	t_process_string	process_string;
}						t_algorithm;

struct					s_ft_ssl
{
	t_flags				flags;
	t_process_stdin		process_stdin;
	t_process_file		process_file;
	t_process_string	process_string;
};

void					ft_ssl_usage(void);
void					ft_ssl_init(char *alg, t_ft_ssl *ft_ssl);

void					ft_ssl_md5_stdin(t_ft_ssl *ft_ssl);
void					ft_ssl_md5_string(const char *strng,
							t_ft_ssl *ft_ssl);
void					ft_ssl_md5_file(const char *filename,
							t_ft_ssl *ft_ssl);
void					ft_ssl_md5_print(const char *target,
							unsigned char *digest,
							t_ft_ssl *ft_ssl);

void					ft_ssl_sha256_stdin(t_ft_ssl *ft_ssl);
void					ft_ssl_sha256_string(const char *strng,
							t_ft_ssl *ft_ssl);
void					ft_ssl_sha256_file(const char *filename,
							t_ft_ssl *ft_ssl);
void					ft_ssl_sha224_print(const char *target,
							unsigned char *digest,
							t_ft_ssl *ft_ssl);

void					ft_ssl_sha224_stdin(t_ft_ssl *ft_ssl);
void					ft_ssl_sha224_string(const char *strng,
							t_ft_ssl *ft_ssl);
void					ft_ssl_sha224_file(const char *filename,
							t_ft_ssl *ft_ssl);
void					ft_ssl_sha256_print(const char *target,
							unsigned char *digest,
							t_ft_ssl *ft_ssl);

#endif
