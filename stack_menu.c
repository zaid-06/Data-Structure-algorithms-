#include<stdio.h>
#include<stdlib.h>
struct array_stack
{
	int top ;
	int capacity;
	int *array;
	
};
struct array_stack* create_stack(int cpcity)
{
	struct array_stack * Stack;
	Stack = malloc(sizeof(struct array_stack));
	Stack->capacity = cpcity;
	Stack->top = -1 ;
	Stack->array = malloc(sizeof (int )* Stack->capacity);
	return (Stack);
	
}
int is_full(struct array_stack *stack)
{
	if(stack->capacity-1 == stack->top)
	return (1);
	else 
	return (0);
	
}
int  is_empty(struct array_stack *stack)
{
	if(stack->top == -1)
	return (1);
	else 
	return (0);
	
}
void push(struct array_stack *stack , int input)
{
	if(!is_full(stack))
	{

		
		stack-> top++ ;
		stack-> array[stack->top]= input;
	}
}
int  pop(struct array_stack *stack )
{
	int input;
	if(!is_empty(stack))
	{
		
		input = stack->array[stack->top];
		stack->top--;
		return(input);
	}
	return(-1);
	
}
main()
{
	int choice , input;
	struct array_stack *stack;
	stack= create_stack(4);
	while(1)
	{
		printf("\n1. push\n2. pop\n3. exit\n");
		printf("\nenter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				
				if(stack->top == stack->capacity-1)
				printf("\nstack is full");
				else
				{ 
				    printf("\nenter a number: ");
					scanf("%d",&input);
					push(stack, input);
					
				}
			
				break;
			case 2: 
				input= pop(stack);
				if(input== -1)
				{
					printf("\nstack is empty");
				}
				else
				printf("\npop value is %d", input);
				break;
			case 3:	
			    exit(0);
		}
		
	}
	
}






