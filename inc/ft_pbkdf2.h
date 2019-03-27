
#ifndef FT_PBKDF2_H
# define FT_PBKDF2_H

#define FT_PBKDF2_RESULT 32

typedef struct 		s_hmac_sha256_ctx
{
	unsigned char	*key;
	unsigned char	*msg;
	unsigned char	out[FT_PBKDF2_RESULT];
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

#endif