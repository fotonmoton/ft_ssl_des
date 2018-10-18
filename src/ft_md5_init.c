#include "ft_md5.h"
#include "libft.h"
void ft_md5_init(t_md5_ctx *ctx)
{
    ctx->a = 0x67452301;
    ctx->a = 0xefcdab89;
    ctx->a = 0x98badcfe;
    ctx->a = 0x10325476;
    ft_bzero(ctx->buffer, FT_MD5_BUFFER_SIZE);
}