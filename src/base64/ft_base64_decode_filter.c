#include "ft_base64.h"
#include "libft.h"

t_byte8	ft_base64_decode_filter
(
	t_byte8 readed,
	t_byte1 *buffer
)
{
	t_byte8 i;
	t_byte8 last_free_index;

	i = 0;
	last_free_index = 0;
	while(i < readed)
	{
		if (!ft_isspace(buffer[i]))
		{
			buffer[last_free_index] = buffer[i];
			last_free_index++;
		}
		i++;
	}
	return (last_free_index);
}