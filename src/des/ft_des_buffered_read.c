#include <unistd.h>
#include "ft_des.h"

int ft_des_buffered_read
(
	int fd,
	char *buffer,
	size_t buff_size
)
{
	size_t total_readed;
	size_t current_read;

	total_readed = 0;
	current_read = 0;
	while(total_readed < buff_size)
	{
		if ((current_read = read(
			fd,
			buffer + total_readed,
			buff_size - total_readed)) == 0)
			return (total_readed + current_read);
		total_readed += current_read;
	}
	return (total_readed);
}