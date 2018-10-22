#include "ft_ssl.h"
#include "ft_sha.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"

void ft_ssl_sha224_file(const char *filename, t_ft_ssl *ft_ssl)
{
	int fd;
	int len;
	BYTE1 digest[FT_SHA224_DIGEST_LENGTH_BYTE];
	BYTE1 digest_string[FT_SHA224_STRING_SIZE_BYTE];
	t_sha256_ctx ctx;
	BYTE1 buf[FT_SSL_BUFFER_SIZE];

	(void)ft_ssl;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		perror("Error: ");
		exit(1);
	}
	ft_sha224_init(&ctx);
	while ((len = read(fd, buf, FT_SSL_BUFFER_SIZE)) > 0)
		ft_sha224_update(&ctx, buf, len);
	ft_sha224_final(digest, &ctx);
	ft_sha224_digest_string(digest, digest_string);
	ft_putstr((const char *)digest_string);
	ft_putstr("\n");
}