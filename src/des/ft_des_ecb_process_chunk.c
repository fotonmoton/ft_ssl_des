#include <unistd.h>
#include "ft_des.h"
#include "libft.h"

static void	ft_des_ecb_write
(
	t_des_ctx *ctx
)
{
	t_byte1 cyphertext[FT_DES_BYTE_BLOCK_SIZE];
	ft_des_process_block(ctx->buffer, ctx->round_keys, cyphertext);
	write(ctx->output_fd, cyphertext, FT_DES_BYTE_BLOCK_SIZE);
}

void	ft_des_ecb_process_chunk
(
	t_des_ctx *ctx,
	t_byte8 readed,
	t_byte1 buffer[FT_DES_READ_SIZE]
)
{
	t_byte8		free_space_in_buffer;
	t_byte8		buffer_index;
	t_byte8		idx;

	buffer_index = ctx->readed % FT_DES_BYTE_BLOCK_SIZE;
	ctx->readed += readed;
	free_space_in_buffer = FT_DES_BYTE_BLOCK_SIZE - buffer_index;
	if (readed >= free_space_in_buffer)
	{
		ft_memcpy(&ctx->buffer[buffer_index], buffer, free_space_in_buffer);
		ft_des_ecb_write(ctx);
		idx = free_space_in_buffer;
		while(idx + FT_DES_BYTE_BLOCK_SIZE <= readed)
		{
			ft_des_ecb_write(ctx);
			idx += FT_DES_BYTE_BLOCK_SIZE;
		}
		buffer_index = 0;
	}
	else
		idx = 0;
	ft_memcpy(&ctx->buffer[buffer_index], &buffer[idx], readed - idx);
}