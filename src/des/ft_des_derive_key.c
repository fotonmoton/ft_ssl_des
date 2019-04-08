#include "ft_des.h"
#include "ft_pbkdf2.h"
#include "libft.h"

void	ft_des_derive_key
(
	t_byte1 key[FT_DES_BIT_BLOCK_SIZE],
	char salt[FT_DES_BYTE_BLOCK_SIZE],
	char *pass
)
{
	t_pbkdf2_sha256_ctx	pbkdf_ctx;
	t_byte1				byte_key[FT_DES_BYTE_BLOCK_SIZE];

	pbkdf_ctx.iterations = 10000;
	pbkdf_ctx.key = byte_key;
	pbkdf_ctx.salt_len = FT_DES_BYTE_BLOCK_SIZE;
	pbkdf_ctx.key_len = FT_DES_BYTE_BLOCK_SIZE;
	pbkdf_ctx.pass_len = ft_strlen(pass);
	pbkdf_ctx.pass = (t_byte1 *)pass;
	pbkdf_ctx.salt = (t_byte1 *)salt;
	ft_pbkdf2_sha256(&pbkdf_ctx);
	ft_des_byte_to_bits(byte_key, FT_DES_BYTE_BLOCK_SIZE, key,
		FT_DES_INITIAL_KEY_SIZE);
}