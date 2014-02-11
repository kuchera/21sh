#include "my_maths.h"

double my_pow(double a, int b)
{
	if (b == 0)
		return 1.0;
	else if (b > 0)
		return a * my_pow(a, b - 1);
	else
		return a / my_pow(a, b + 1);
}

double my_getnumber(const char* str)
{
	if (str == NULL)
		return -1;

	int floating = 0;
	double out = 0;
	int i = 0;
	char* s;
	my_rmchar(str, &s, ' ');
	if (s[0] == '-')
		i = 1;

	while (i < my_strlen(s))
	{
		switch (s[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (floating)
				{
					out += ((int)(s[i]) - ((int)'0')) / my_pow(10, floating);
					floating++;
				}
				else
				{
					out *= 10;
					out += ((int)(s[i])) - ((int)'0');
				}
				break;
			case '.':
			case ',':
				if (floating)
				{
					free(s);
					return 0;
				}
				else
					floating = 1;
				break;
			default:
				return 0;
				break;
		}	
		i++;
	}

	if (s[0] == '-')
		out = -out;
	return out;
}
