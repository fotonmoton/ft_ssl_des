#include <unistd.h>
#include "ft_base64.h"

void	ft_base64_decode(t_base64_ctx *ctx)
{
	t_byte1					read_buff[FT_BASE64_READ_SIZE];
	t_base64_decode_buffer	decode_buff;
	t_byte8					readed;

	ft_base64_init_decode_buffer(&decode_buff);
	while((readed = read(ctx->input_fd, read_buff, FT_BASE64_READ_SIZE)) > 0)
	{
		readed = ft_base64_decode_filter(readed, read_buff);
		ft_base64_decode_chunk(ctx, readed, read_buff, &decode_buff);
	}
	ft_base64_decode_finish(&decode_buff);
}