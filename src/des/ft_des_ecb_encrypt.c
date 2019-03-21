#include <unistd.h>
#include "ft_des.h"
#include "ft_base64.h"

void	ft_des_ecb_encrypt
(
	t_des_ctx *ctx
)
{
	t_byte1					buffer[FT_DES_READ_SIZE];
	t_byte8					readed;

	while((readed = read(ctx->input_fd, buffer, FT_DES_READ_SIZE)) > 0)
		ft_des_ecb_encode_process_chunk(ctx, readed, buffer);
	ft_des_ecb_finish_encrypt(ctx);
}