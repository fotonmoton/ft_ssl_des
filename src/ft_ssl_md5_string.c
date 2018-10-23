#include "ft_ssl.h"
#include "ft_md5.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void ft_ssl_md5_string(const char *str, t_ft_ssl *ft_ssl)
{
	BYTE1 digest[FT_MD5_DIGEST_LENGTH_BYTE];
	t_md5_ctx ctx;

	ft_md5_init(&ctx);
	ft_md5_update(&ctx, (unsigned char *)str, ft_strlen((const char *)str));
	ft_md5_final(digest, &ctx);
	ft_ssl_md5_print(str, digest, ft_ssl);
}