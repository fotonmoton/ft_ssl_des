#include "ft_base64.h"
#include "libft.h"

t_byte8	ft_base64_encode_step
(
	t_base64_ctx *ctx,
	t_byte8 readed,
	t_byte1 *buffer
)
{
	while(readed >= FT_BASE64_TRANS_SIZE)
	{
		ft_base64_transform(ctx, buffer);
		ft_base64_write(ctx);
		readed -= FT_BASE64_TRANS_SIZE;
		buffer += FT_BASE64_TRANS_SIZE;
	}
	return readed;
}
