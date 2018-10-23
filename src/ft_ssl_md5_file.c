#include "ft_ssl.h"
#include "ft_md5.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void	ft_ssl_md5_file(const char *filename, t_ft_ssl *ft_ssl)
{
	int			fd;
	int			len;
	BYTE1		digest[FT_MD5_DIGEST_LENGTH_BYTE];
	t_md5_ctx	ctx;
	BYTE1		buf[FT_SSL_BUFFER_SIZE];

	(void)ft_ssl;
	if((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("Error: ");
		exit(1);
	}
	ft_md5_init(&ctx);
	while ((len = read(fd, buf, FT_SSL_BUFFER_SIZE)) > 0)
		ft_md5_update(&ctx, buf, len);
	ft_md5_final(digest, &ctx);
	ft_ssl_md5_print(filename, digest, ft_ssl);
}