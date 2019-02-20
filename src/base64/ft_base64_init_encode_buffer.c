#include "ft_base64.h"
#include "libft.h"

void	ft_base64_init_encode_buffer
(
	t_base64_encode_buffer *buff
)
{
	ft_bzero(buff->block, FT_BASE64_TRANS_SIZE);
	buff->readed = 0;
}