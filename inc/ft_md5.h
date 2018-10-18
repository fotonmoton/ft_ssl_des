#ifndef FT_MD5_H
# define FT_MD5_H

# include <stdint.h>

# define FT_MD5_BUFFER_SIZE 64 

typedef unsigned int BYTE4;
typedef unsigned char BYTE1;

typedef struct  s_md5_ctx
{
    BYTE4       a;
    BYTE4       b;
    BYTE4       c;
    BYTE4       d;
    BYTE1       buffer[FT_MD5_BUFFER_SIZE];
    uint64_t    message_len;
}               t_md5_ctx;

void            ft_md5_init(t_md5_ctx *ctx);
void            ft_md5_update(t_md5_ctx *ctx, BYTE1 *chunk, BYTE4 len);
void            ft_md5_transform(t_md5_ctx *ctx, BYTE1 buffer[64]);
void            ft_md5_final(t_md5_ctx *ctx, BYTE1 *chunk, BYTE4 len);

#endif
