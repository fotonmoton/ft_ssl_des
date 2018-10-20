#include "ft_md5.h"
#include "libft.h"

void	ft_md5_padding(BYTE1 padding[FT_MD5_BLOCK_SIZE])
{
	padding[0] = 0x80;
	ft_bzero(&padding[1], FT_MD5_BLOCK_SIZE - 1);
}