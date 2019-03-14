#include "ft_des.h"
#include "libft.h"

void	ft_des_print_error
(
	const char *error
)
{
	ft_putstr("des: ");
	ft_putstr(error);
	ft_putstr("\n");
	exit(1);
}