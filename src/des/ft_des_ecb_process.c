#include <unistd.h>
#include "ft_des.h"

void	ft_des_ecb_process
(
	t_des_ctx *ctx
)
{
	t_byte1	buffer[FT_DES_READ_SIZE];
	t_byte8	readed;

	ft_des_generate_encryption_round_keys(ctx->key, ctx->round_keys);
	while((readed = read(ctx->input_fd, buffer, FT_DES_READ_SIZE)) > 0)
		ft_des_ecb_process_chunk(ctx, readed, buffer);
	ft_des_ecb_finish_process(ctx);
}