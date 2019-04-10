#include "libft.h"

void	ft_des_usage
(
	void
)
{
	ft_putstr("des cipher usage:\n\n");
	ft_putstr("ft_ssl des-{mode} [flags]\n\n");
	ft_putstr("flags:\n");
	ft_putstr(" -a\t\tdecode/encode the input/output in base64\n");
	ft_putstr(" -e\t\tecrypt mode\n");
	ft_putstr(" -d\t\tdecrypt mode\n");
	ft_putstr(" -i\t\tinput file for message\n");
	ft_putstr(" -o\t\toutput file for message\n");
	ft_putstr(" -p pass\tpassword in ascii format\n");
	ft_putstr(" -k key\t\tkey in hex format\n");
	ft_putstr(" -s salt\tsalt in hex format\n");
	ft_putstr(" -v vector\tinitialization vector in hex format\n\n");
	ft_putstr("where {mode} is one of:\n");
	ft_putstr("ecb\ncbc\npcbc\n");
	exit(1);
}