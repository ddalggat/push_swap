#include "push_swap.h"

int main(int arc, const char **arv)
{
	(void)arc;
	int res;
	t_struct *stack_a;
	res = ft_parser(arv, &stack_a);
	printf("|%d|\n", res); 
}