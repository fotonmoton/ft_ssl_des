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
static void process_strings_and_files
(
	int i,
	int argc,
	char **argv,
	t_ft_ssl *ft_ssl
)
{
	while (i < argc)
	{
		if (find_flag("-s", argv[i]))
		{
			if (i + 1 >= argc)
				ft_ssl_usage();
			ft_ssl->process_string(argv[++i], ft_ssl);
			i++;
		}
		else
			ft_ssl->process_file(argv[i++], ft_ssl);
	}
}
int main(int argc, char **argv)
{
	t_ft_ssl	ft_ssl;
	int			i;

	if (argc < 2)
		ft_ssl_usage();
	ft_ssl_init(argv[1], &ft_ssl);
	i = process_flags(argc, argv, &ft_ssl);
	if (ft_ssl.flags.print_stdin)
		ft_ssl.process_stdin(&ft_ssl);
	process_strings_and_files(i, argc, argv, &ft_ssl);
	if (!ft_ssl.flags.something_printed)
		ft_ssl.process_stdin(&ft_ssl);
	return (0);
}