#include "ft_ssl.h"
#include "libft.h"

void	ft_ssl_usage(void)
{
	ft_putstr("\n\nusage: \n");
	ft_putstr("ft_ssl algorithm [-p|-q|-r] [[-s string...] [file...]]\n\n");
	ft_putstr("algorithms:\n");
	ft_putstr("md5		sha256		sha224\n\n\n");
	exit(1);
}