#include "ft_ssl.h"
#include "libft.h"

static int find_flag(const char *expected, char *real)
{
	return ft_strcmp(real, expected) == 0;
}

static int process_flags(int argc, char **argv, t_ft_ssl *ft_ssl)
{
	int		i;

	i = 2;
	while (i < argc)
	{
		if (find_flag("-r", argv[i]))
			ft_ssl->flags.reverse = 1;
		else if (find_flag("-q", argv[i]))
			ft_ssl->flags.quiet = 1;
		else if (find_flag("-p", argv[i]))
			ft_ssl->flags.print_stdin = 1;
		else
			break;
		i++;
	}
	return i;
}

int main(int argc, char **argv)
{
	t_ft_ssl	ft_ssl;
	int			i;

	if (argc < 2)
		ft_ssl_usage();
	ft_ssl_init(argv[1], &ft_ssl);
	i = process_flags(argc, argv, &ft_ssl);
	if (ft_ssl.flags.print_stdin || i == argc)
		ft_ssl.process_stdin(&ft_ssl);
	while (i < argc)
	{
		if (find_flag("-s", argv[i]) && ++i < argc)
			ft_ssl.process_string(argv[i++], &ft_ssl);
		else
			ft_ssl.process_file(argv[i++], &ft_ssl);
	}
	if (argc == 2)
		ft_ssl.process_stdin(&ft_ssl);
	return (0);
}