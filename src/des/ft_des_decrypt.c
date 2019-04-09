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

void		ft_des_decrypt
(
	t_des_ctx *c
)
{
	t_byte8 readed;
	t_byte8 last_read;
	t_byte1 buffer[FT_DES_BYTE_BLOCK_SIZE];
	t_byte1 message[FT_DES_BYTE_BLOCK_SIZE];

	ft_des_decryption_key_routine(c);
	ft_des_generate_decryption_round_keys(c->key, c->round_keys);
	last_read = 0;
	while((readed = buffered_read(c, buffer)))
	{
		if (readed != FT_DES_BYTE_BLOCK_SIZE)
			ft_des_print_error("wrong message size");
		if (last_read)
			write(c->output_fd, message, FT_DES_BYTE_BLOCK_SIZE);
		c->mode(buffer, c->round_keys, c->iv, message);
		last_read = readed;
	}
	if (message[7] < 0 || message[7] > 8)
		ft_des_print_error("wrong padding");
	write(c->output_fd, message, FT_DES_BYTE_BLOCK_SIZE - message[7]);
}