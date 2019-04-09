#include "ft_des.h"

static	void encrypt
(
	t_byte1 input[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 keys[FT_DES_ROUND_COUNT][FT_DES_ROUND_KEY_SIZE],
	t_byte1 iv[FT_DES_BYTE_BLOCK_SIZE],
	t_byte1 output[FT_DES_BYTE_BLOCK_SIZE]
)
{
	(void)iv;
	ft_des_process_block(input, keys, output);
}

void		ft_des_ecb
(
	int argc,
	char **argv
)
{
	t_des_ctx ctx;

	ft_des_init_ctx(&ctx);
	ft_des_parse_args(argc, argv, &ctx);
	ctx.encrypt = encrypt;
	ctx.decrypt = encrypt;
	ft_des(&ctx);
}