#include "ft_des.h"

void	ft_des_ecb_finish_decrypt
(
	t_des_ctx *ctx,
	t_des_decrypt_buffer *buff
)
{
	t_byte1 idx;

	idx = 0;
	ctx->readed += buff->readed[buff->current_buffer];
	if (ctx->readed % FT_DES_BYTE_BLOCK_SIZE != 0)
		ft_des_print_error("wrong message size, maybe corrupted?");
	while (idx + FT_DES_BYTE_BLOCK_SIZE <=)
}