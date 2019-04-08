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

	ft_des_encryption_key_routine(ctx);
	ft_des_generate_encryption_round_keys(ctx->key, ctx->round_keys);
	while((readed = read(ctx->input_fd, buffer, FT_DES_READ_SIZE)) > 0)
		ft_des_ecb_encode_process_chunk(ctx, readed, buffer);
	ft_des_ecb_finish_encrypt(ctx);
}