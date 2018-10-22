#include "ft_md5.h"
#include "ft_ssl.h"
#include "libft.h"

void ft_ssl_md5_print(unsigned char *digest,
					  t_ft_ssl *ft_ssl)
{
	BYTE1 digest_string[FT_MD5_STRING_SIZE_BYTE];
	(void)ft_ssl;
	ft_md5_digest_string(digest, digest_string);
	ft_putstr((const char *)digest_string);
	ft_putstr("\n");
}