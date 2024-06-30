void	swap(List *stack)
{	
	struct Item temp;

	temp = malloc(sizeof(*temp);
	if(temp == NULL)
		exit(FAILURE);
	temp = stack->first->next;
	stack->first->next = stack->first->next->next;
	stack->first->previous = temp;
	stack->first = temp;
	free(temp);	
}
