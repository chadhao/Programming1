/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  IMPORTANT: REMEMBER TO sync BEFORE YOU LEAVE THE EXAM ROOM
*
*******************************************************************************/

#include <stdio.h>

void draw_first_or_last_line(char horizontalchr, char cornerchr, int width)
{
	printf("%c", cornerchr);
	for (int i = 0; i < (width - 2); i++)
	{
		printf("%c", horizontalchr);
	}
	printf("%c\n", cornerchr);
}

void draw_box_body(char verticalchr, int width, int height)
{
	printf("%c", verticalchr);
	for (int i = 0; i < (width - 2); i++)
	{
		printf(" ");
	}
	printf("%c\n", verticalchr);
}

void draw_text_box(char horizontalchr, char verticalchr, char cornerchr, int width, int height)
{
	draw_first_or_last_line(horizontalchr, cornerchr, width);
	for (int i = 0; i < (height - 2); i++)
	{
		draw_box_body(verticalchr, width, height - 2);
	}
	draw_first_or_last_line(horizontalchr, cornerchr, width);
}

int main(int argc, char* argv[])
{
	draw_text_box('-', '|', '+', 5, 3);
	printf("\n");
	draw_text_box('o', 'x', 'O', 6, 4);
	printf("\n");
	draw_text_box('=', 'H', '#', 11, 5);
	printf("\n");
	draw_text_box('~', '|', '$', 16, 8);
	return 0;
}