
#include<stdio.h>
#include<stdlib.h>

struct ArrayQueue
{
	int front , rear;
	int capacity ;
	int *array;
};
struct ArrayQueue * createNode(int capacity)
{
	struct ArrayQueue* Q = malloc(sizeof (struct ArrayQueue));
	if(!Q) 
		return (NULL);
	Q->capacity = capacity;
	Q->front= Q->rear = -1 ;
	Q->array= malloc(Q->capacity * sizeof(int));
	if(!Q->array)
		return(NULL);
	return(Q);
		
}
int isEmptyQueue(struct ArrayQueue *Q)
{
	return(Q->front == -1 );
	
}
int isFullQueue(struct ArrayQueue *Q)
{
	return((Q->rear+1)%Q->capacity==Q->front);
}
int QueueSize(struct ArrayQueue *Q)
{
	return((Q->capacity - Q->front + Q->rear +1 )% Q->capacity);
}

void enQueue(struct ArrayQueue *Q , int data)
{
	if(isFullQueue(Q))
	{
		printf("overflow");
	}
	else
	{
		Q->rear= (Q->rear+1)%Q->capacity	;
		Q->array [Q->rear]= data;
		if(Q->front== -1)
		Q->front= Q->rear;
	}
}
int deQueue(struct ArrayQueue *Q)
{
	int data = -1 ;
	if(isEmptyQueue(Q))
	{
		printf("Queue is empty");
		return(-1);
		
	}
	else
	{
		data = Q->array[Q->front];
		if(Q->front == Q->rear)
			Q->front= Q->rear =-1;
		else
			Q->front = (Q->front+1)% Q->capacity;
			
	}
	return data;
}

main()
{
	int choice , input;
	struct  ArrayQueue * Queue ;
	Queue = createNode(4);
	while(1)
	 {
		printf("\n1. enQueue\n2. deQueue\n3. exit\n");
		printf("\nenter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element to insert in Queue: ");
				scanf("%d",&input);
				enQueue(Queue ,  input);
				break;
			case 2: 
				input= deQueue(Queue);
				if(input== -1)
				{
					printf("\nstack is empty");
				}
				else
				printf ("\nDeQueue value is %d", input);
				break;
				
			case 3:	
			    exit(0);
		}
		
	}
	
}




