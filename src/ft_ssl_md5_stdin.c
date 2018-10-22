#include "ft_ssl.h"
#include "ft_md5.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"

void ft_ssl_md5_stdin(t_ft_ssl *ft_ssl)
{
	int len;
	BYTE1 digest[FT_MD5_DIGEST_LENGTH_BYTE];
	t_md5_ctx ctx;
	BYTE1 buf[FT_SSL_BUFFER_SIZE];

	(void)ft_ssl;
	ft_md5_init(&ctx);
	while ((len = read(0, buf, FT_SSL_BUFFER_SIZE)))
	{
		if (ft_ssl->flags.print_stdin)
			write(1, buf, len);
		ft_md5_update(&ctx, buf, len);
	}
	ft_md5_final(digest, &ctx);
	ft_ssl_md5_print(digest, ft_ssl);
}