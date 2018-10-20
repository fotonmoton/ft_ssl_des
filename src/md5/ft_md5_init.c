#include "ft_md5.h"
#include "libft.h"

void ft_md5_init(t_md5_ctx *ctx)
{
    ctx->a = 0x67452301;
    ctx->b = 0xefcdab89;
    ctx->c = 0x98badcfe;
    ctx->d = 0x10325476;
    ctx->bit_len = 0;
    ft_bzero(ctx->block, FT_MD5_BLOCK_SIZE);
}