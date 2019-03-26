#include "ft_sha.h"

typedef struct 		s_hmac_sha256_ctx
{
	unsigned char	*key;
	unsigned char	*msg;
	unsigned char	out[FT_SHA256_DIGEST_LENGTH_BYTE];
	unsigned int	key_size;
	unsigned int	msg_size;
}					t_hmac_sha256_ctx;

void	ft_hmac_sha256_init_ctx
(
	t_hmac_sha256_ctx *ctx
);

void	ft_hmac_sha256
(
	t_hmac_sha256_ctx *ctx
);