#include "ft_des.h"
#include "libft.h"

void ft_des_get_password
(
	t_des_ctx *ctx
)
{
	char *first_try[128];
	char *second_try[128];

	if (ctx->raw_key || ctx->raw_password)
		return ;
	ft_bzero(first_try, 128);
	ft_bzero(second_try, 128);
	ft_strcpy((char *)first_try, getpass("enter password:"));
	if (!ft_strlen((const char *)first_try))
		exit(1);
	ft_strcpy((char *)second_try, getpass("retype password:"));
	if (ft_strcmp((const char *)first_try, (const char *)second_try) != 0)
		ft_des_print_error("passwords doesn't match");
	ctx->raw_password = (char *)second_try;
}