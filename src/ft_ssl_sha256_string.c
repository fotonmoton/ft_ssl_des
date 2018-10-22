#include "ft_ssl.h"
#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void ft_ssl_sha256_string(const char *str, t_ft_ssl *ft_ssl)
{
	BYTE1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];
	BYTE1 digest_string[FT_SHA256_STRING_SIZE_BYTE];
	t_sha256_ctx ctx;

	(void)ft_ssl;
	ft_sha256_init(&ctx);
	ft_sha256_update(&ctx, (unsigned char *)str, ft_strlen((const char *)str));
	ft_sha256_final(digest, &ctx);
	ft_sha256_digest_string(digest, digest_string);
	ft_putstr((const char *)digest_string);
	ft_putstr("\n");
}