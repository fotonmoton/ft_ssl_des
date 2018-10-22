#include "ft_ssl.h"
#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void ft_ssl_sha224_string(const char *str, t_ft_ssl *ft_ssl)
{
	BYTE1 digest[FT_SHA224_DIGEST_LENGTH_BYTE];
	BYTE1 digest_string[FT_SHA224_STRING_SIZE_BYTE];
	t_sha256_ctx ctx;

	(void)ft_ssl;
	ft_sha224_init(&ctx);
	ft_sha224_update(&ctx, (unsigned char *)str, ft_strlen((const char *)str));
	ft_sha224_final(digest, &ctx);
	ft_sha224_digest_string(digest, digest_string);
	ft_putstr((const char *)digest_string);
	ft_putstr("\n");
}