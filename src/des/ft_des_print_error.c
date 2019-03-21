#include <unistd.h>
#include "ft_des.h"
#include "libft.h"

void	ft_des_print_error
(
	const char *error
)
{
	ft_putstr_fd("des: ", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}