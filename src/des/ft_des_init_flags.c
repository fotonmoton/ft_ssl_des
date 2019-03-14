#include "ft_des.h"

void	ft_des_init_flags
(
	t_des_flags *flags
)
{
	flags->decode = 0;
	flags->output_in_base64 = 0;
}