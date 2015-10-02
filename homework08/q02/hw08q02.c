/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw08q02.c
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - http://en.wikipedia.org/wiki/Linked_list
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* p_next;
	int data;
};

struct Node* g_p_first = 0;

void add_new_node(int data);
void remove_node(int data);
void print_all_nodes();

void add_new_node(int data)
{
	struct Node* new = malloc(sizeof(struct Node));
	new->data = data;
	new->p_next = g_p_first;
	g_p_first = new;
}

void remove_node(int data)
{
	struct Node* now = g_p_first;
	struct Node* before = 0;
	int is_match = 0;
	while (is_match == 0)
	{
		if (now != 0)
		{
			if (now->data == data)
			{
				if (now == g_p_first)
				{
					g_p_first = now->p_next;
				}
				else
				{
					before->p_next = now->p_next;
				}
				free(now);
				is_match++;
			}
			else
			{
				before = now;
				now = now->p_next;
			}
		}
		else
		{
			is_match = -1;
		}
	}
	if (is_match == -1)
	{
		printf("No data matched!\n");
	}
}

void print_all_nodes()
{
	struct Node* now = g_p_first;
	int i = 0;
	while (now != 0)
	{
		i++;
		printf("[N%d: address is %p, data is %d, p_next is %p] -> ", i, now, now->data, now->p_next);
		now = now->p_next;
	}
	printf("null\n");
}

int main(int argc, char* argv[])
{
	printf("1) Print the nodes: \n");
	print_all_nodes();
	
	add_new_node(10);
	add_new_node(20);
	add_new_node(30);
	
	printf("2) Print the nodes: \n");
	print_all_nodes();
	
	add_new_node(40);
	add_new_node(50);
	add_new_node(60);
	add_new_node(15);
	add_new_node(25);
	add_new_node(35);
	
	printf("3) Print the nodes: \n");
	print_all_nodes();
	
	remove_node(20);
	
	printf("4) Print the nodes: \n");
	print_all_nodes();
	
	remove_node(50);
	remove_node(15);
	
	printf("5) Print the nodes: \n");
	print_all_nodes();
	
	return 0;
}