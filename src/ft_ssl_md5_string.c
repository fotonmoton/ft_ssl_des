#include "ft_ssl.h"
#include "ft_md5.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void ft_ssl_md5_string(const char *str, t_ft_ssl *ft_ssl)
{
	BYTE1 digest[FT_MD5_DIGEST_LENGTH_BYTE];
	BYTE1 digest_string[FT_MD5_STRING_SIZE_BYTE];
	t_md5_ctx ctx;

	(void)ft_ssl;
	ft_md5_init(&ctx);
	ft_md5_update(&ctx, (unsigned char *)str, ft_strlen((const char *)str));
	ft_md5_final(digest, &ctx);
	ft_md5_digest_string(digest, digest_string);
	ft_putstr((const char *)digest_string);
	ft_putstr("\n");
}