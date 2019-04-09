#include <stdlib.h>
#include "ft_des.h"

void		ft_des
(
	t_des_ctx *ctx
)
{
	if (ctx->decode)
	{
		if (ctx->b64)
			ft_des_decrypt_b64(ctx);
		else
			ft_des_decrypt(ctx);
	}
	else
	{
		if (ctx->b64)
			ft_des_encrypt_b64(ctx);
		else
			ft_des_encrypt(ctx);
	}
	exit(0);
}