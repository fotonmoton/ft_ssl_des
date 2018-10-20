#include "ft_md5.h"
#include "libft.h"

static void init_chars(BYTE1 chars[16])
{
	chars[0] = '0';
	chars[1] = '1';
	chars[2] = '2';
	chars[3] = '3';
	chars[4] = '4';
	chars[5] = '5';
	chars[6] = '6';
	chars[7] = '7';
	chars[8] = '8';
	chars[9] = '9';
	chars[10] = 'a';
	chars[11] = 'b';
	chars[12] = 'c';
	chars[13] = 'd';
	chars[14] = 'e';
	chars[15] = 'f';
}

void ft_md5_digest_string(BYTE1 digest[FT_MD5_DIGEST_LENGTH_BYTE],
							BYTE1 string[FT_MD5_STRING_SIZE_BYTE])
{
	BYTE8 i;
	BYTE8 j;
	BYTE1 chars[16];

	i = 0;
	j = 0;
	init_chars(chars);
	while(i < FT_MD5_DIGEST_LENGTH_BYTE)
	{
		string[j] = chars[digest[i] / 16];
		string[j + 1] = chars[digest[i] % 16];
		i++;
		j += 2;
	}
	string[FT_MD5_STRING_SIZE_BYTE - 1] = 0;
}