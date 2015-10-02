#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE* file = fopen(argv[1], "r");
	int c;
	if (argc == 1 || file == NULL)
	{
		return 1;
	}
	else
	{
		while((c = getc(file)) != EOF)
		{
			putchar(c);
		}
	}
	fclose(file);
	return 0;
}