#include <unistd.h>
#include "ft_des.h"
#include "libft.h"

static t_byte8 buffered_read
(
	t_des_ctx *ctx,
	t_byte1 buffer[FT_DES_BYTE_BLOCK_SIZE]
)
{
	t_byte8 total_readed;
	t_byte8 current_read;

	total_readed = 0;
	current_read = 0;
	while(total_readed < FT_DES_BYTE_BLOCK_SIZE)
	{
		if ((current_read = read(
			ctx->input_fd,
			buffer + total_readed,
			FT_DES_BYTE_BLOCK_SIZE - total_readed)) == 0)
			return (total_readed + current_read);
		total_readed += current_read;
	}
	return (total_readed);
}

static void	ouput
(
	t_des_ctx *ctx,
	t_byte1 buffer[FT_DES_BYTE_BLOCK_SIZE]
)
{
	if (ctx->b64)
		ft_base64_decode_chunk(
			&ctx->b64_ctx,
			FT_DES_BYTE_BLOCK_SIZE, buffer, &ctx->b64_decode_buffer);
	else
		write(ctx->output_fd, buffer, FT_DES_BYTE_BLOCK_SIZE);
}

static void	finish
(
	t_des_ctx *ctx,
	t_byte1 buffer[FT_DES_BYTE_BLOCK_SIZE]
)
{
	if (ctx->b64)
	{
	}
	else
	{
		if (buffer[7] < 0 || buffer[7] > 8)
			ft_des_print_error("wrong padding");
		write(ctx->output_fd, buffer, FT_DES_BYTE_BLOCK_SIZE - buffer[7]);
	}
}

void		ft_des_ecb_decrypt
(
	t_des_ctx *c
)
{
	t_byte8 readed;
	t_byte8 last_read;
	t_byte1 buffer[FT_DES_BYTE_BLOCK_SIZE];
	t_byte1 message[FT_DES_BYTE_BLOCK_SIZE];

	last_read = 0;
	while((readed = buffered_read(c, buffer)))
	{
		if (readed != FT_DES_BYTE_BLOCK_SIZE)
			ft_des_print_error("wrong message size");
		if (last_read)
			ouput(c, message);
		ft_des_process_block(buffer, c->round_keys, message);
		last_read = readed;
	}
	finish(c, message);
}