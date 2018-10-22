#include "ft_ssl.h"
#include "libft.h"

static t_algorithm	*init_algorithms(void)
{
	static t_algorithm algs[FT_SSL_ALGS_COUNT] = {
		{
			"md5",
			ft_ssl_md5_stdin,
			ft_ssl_md5_file,
			ft_ssl_md5_string,
		},
		{
			"sha256",
		 	ft_ssl_sha256_stdin,
		 	ft_ssl_sha256_file,
		 	ft_ssl_sha256_string,
		},
		{
			"sha224",
		 	ft_ssl_sha224_stdin,
		 	ft_ssl_sha224_file,
		 	ft_ssl_sha224_string,
		}
	};
	return algs;
}

static void			set_algorithm(t_algorithm *alg, t_ft_ssl *ft_ssl)
{
	ft_ssl->process_file = alg->process_file;
	ft_ssl->process_string = alg->process_string;
	ft_ssl->process_stdin = alg->process_stdin;
}

void				ft_ssl_init(char *alg_name, t_ft_ssl *ft_ssl)
{
	int i;
	t_algorithm *alg;
	t_algorithm *alg_walker;

	i = 0;
	alg = 0;

	alg_walker = init_algorithms();
	while (i < FT_SSL_ALGS_COUNT)
	{
		if (ft_strcmp(alg_name, alg_walker[i].name) == 0)
		{
			alg = &alg_walker[i];
			break;
		}
		i++;
	}
	if (!alg)
		ft_ssl_usage();
	set_algorithm(alg, ft_ssl);
}