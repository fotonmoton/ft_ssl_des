#include "ft_ssl.h"
#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void ft_ssl_sha256_stdin(t_ft_ssl *ft_ssl)
{
	int len;
	BYTE1 digest[FT_SHA256_DIGEST_LENGTH_BYTE];
	BYTE1 digest_string[FT_SHA256_STRING_SIZE_BYTE];
	t_sha256_ctx ctx;
	BYTE1 buf[FT_SSL_BUFFER_SIZE];

	(void)ft_ssl;
	ft_sha256_init(&ctx);
	while ((len = read(0, buf, FT_SSL_BUFFER_SIZE)))
		ft_sha256_update(&ctx, buf, len);
	ft_sha256_final(digest, &ctx);
	ft_sha256_digest_string(digest, digest_string);
	ft_putstr((const char *)digest_string);
	ft_putstr("\n");
}