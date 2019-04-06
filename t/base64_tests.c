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

	_is(ctx.input_fd == STDIN_FILENO);
	_is(ctx.output_fd == STDOUT_FILENO);

	_is(ft_strcmp(alphabet, (char *)ctx.alphabet) == 0);

	_end("init ctx");
}

static int transform_block()
{
	t_base64_ctx	ctx;
	t_byte1			buff[FT_BASE64_DECODE_BLOCK_SIZE];

	ft_base64_init(&ctx);

	ft_base64_encode_transform(&ctx, (t_byte1 *)"Man", buff);
	_is(ft_strncmp((char *)buff, "TWFu", 4) == 0);

	ft_base64_encode_transform(&ctx, (t_byte1 *)"LOL", buff);
	_is(ft_strncmp((char *)buff, "TE9M", 4) == 0);

	_end("transform block");
}

int base64_tests(void)
{
	_should(init_ctx);
	_should(transform_block);
	return 0;
}