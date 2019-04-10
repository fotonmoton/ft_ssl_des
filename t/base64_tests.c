#include <unistd.h>
#include "t.h"
#include "tests.h"
#include "ft_base64.h"
#include "libft.h"

static int init_ctx()
{
	t_base64_ctx ctx;
	char		alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz0123456789+/";

	ft_base64_init(&ctx);

	_IS(ctx.input_fd == STDIN_FILENO);
	_IS(ctx.output_fd == STDOUT_FILENO);

	_IS(ft_strcmp(alphabet, (char *)ctx.alphabet) == 0);

	_END("init ctx");
}

static int transform_block()
{
	t_base64_ctx	ctx;
	t_byte1			buff[FT_BASE64_DECODE_BLOCK_SIZE];

	ft_base64_init(&ctx);

	ft_base64_encode_transform(&ctx, (t_byte1 *)"Man", buff);
	_IS(ft_strncmp((char *)buff, "TWFu", 4) == 0);

	ft_base64_encode_transform(&ctx, (t_byte1 *)"LOL", buff);
	_IS(ft_strncmp((char *)buff, "TE9M", 4) == 0);

	_END("transform block");
}

int base64_tests(void)
{
	_SHOULD(init_ctx);
	_SHOULD(transform_block);
	return 0;
}