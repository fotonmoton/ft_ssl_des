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

	ft_des_generate_encryption_round_keys(ctx->key, ctx->round_keys);
	if (ctx->raw_password)
	{
		write(ctx->output_fd, "Salted__", 8);
		write(ctx->output_fd, ctx->salt, FT_DES_BYTE_BLOCK_SIZE);
	}
	while((readed = read(ctx->input_fd, buffer, FT_DES_READ_SIZE)) > 0)
		ft_des_ecb_encode_process_chunk(ctx, readed, buffer);
	ft_des_ecb_finish_encrypt(ctx);
}