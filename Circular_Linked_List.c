#include<stdio.h>
#include<stdlib.h>
int i ;
struct stud 
{
	char name[25]; 
	int roll;
	struct stud *next;
	struct stud *pre;
	
}*temp, *ptr ,*fresh, *NEW ;

struct stud* head = NULL;
struct stud* tail = NULL;
static int c;
void color(char clor[]) 					// select color 
{				
	if (!strcmp("red",clor))
  		printf("\033[1;31m");
  	else if (!strcmp("green",clor))
  		printf("\033[1;32m");
  	else if (!strcmp("lblue",clor))
  		printf("\033[1;36m");
  	else if (!strcmp("blue",clor))
  		printf("\033[1;34m");
  	else if (!strcmp("white",clor))
  		printf("\033[0m");	
}
struct stud* createRecord()                // create node or allocate memory 
{
	struct stud* NEW ; 
	NEW = (struct stud*)malloc(sizeof(struct stud));
	system("cls");
	printf("\n\n\t\t______________________\n");
	color("white");
	printf("\n\t\tEnter Name: ");
	fflush(stdin);
	gets(NEW->name);
	printf("\t\tEnter Roll Number: ");
	fflush(stdin);
	scanf("%d", &NEW->roll);
	NEW->next = NULL;
	return(NEW);
		
}
insertAtBgin()  							// Insert at begin
{	
	fresh = createRecord();	
	if(head == NULL){
		head = tail = fresh;
		tail->next = head;
	}	
	else
	{
		fresh->next=head;
		head=fresh;
		tail->next = head;
	}
	c++;
	color("green");
	printf("\n\t\tRecord is added ");	
}

InsertAtEnd()  								// insert record at end of list
{
	fresh = createRecord();
	if(tail == NULL)
	{
		head = tail = fresh;
		tail->next = head;
	}
	else
	{	
		tail->next = fresh;
		tail = tail->next;
		tail->next = head;	
	}
	c++;
	color("green");
	printf("\n\t\tRecord is added ");
}

insertAtLocation()  						// insert new record at location
{
	int location, count=1,i;
	struct  stud *temp2=NULL;
	system("cls");
	l2:
	
	color("lblue");	
	printf("\n\tEnter your location for adding record: ");
	scanf("%d",&location);
	count=1;
	i = c;
	if (location > i+1){system("cls");
		color("red");
		printf("\n\n\tThis Location Not Found in list\ttry again: \n");
		goto l2;
	}
	if(location==1)
	 	insertAtBgin();
	else if(location==i+1)
		InsertAtEnd();
	else
	{
		
	 	ptr = head;
		while(count<=i)
	    {	
			if(location == count)
			{
				fresh = createRecord();
				temp->next=fresh;
				fresh->next=ptr;
				c++;
				color("green");
				printf("Record added ");
				break;
			}
			count++;
			temp=ptr;
			ptr=ptr->next;		
		}
	}
	printf("at location %d",location);		
}

display()									// Display all
{	
	int i =1;
	ptr = head;
	system("cls");
	color("blue");
	printf("\n\t____________________________________________");
	if(ptr == NULL  )
	{
		color("red");
		printf("\n\n\tList is empty");	
	}
	else
	{
		printf("\n\tSno\t\tName\t\t\tRoll");
		color("white");
		do
		{
			printf("\n\t%d\t\t%s\t\t\t%d",i, ptr->name, ptr->roll);
			ptr = ptr->next;
			i++;
		}while (ptr != head);
	}
}

deleteAtBegin()								// Delete at begin
{
	system("cls");
	color("blue");
	printf("\n\t____________________________________________");
	if(head== NULL)
	{
		color("red");
		printf("\n\n\tlist is empty\n");
	}
	else{
		temp = head ;
		color("green");
		printf("\n\tname: %s\n\troll: %d\n", temp->name,temp->roll);
		if (head== tail)
		{
			free(head);
			tail=head=NULL;	
		}
		else
		{
			head = head->next;
			tail->next = head;
			free(temp);
		}
		printf("\n\tRecord is deleted succesfully");
		c--;
	}		
}


deleteAtEnd()								// Delete at End
{
	system("cls");
	color("blue");
	printf("\n\t____________________________________________");
	if(tail == NULL)
	{
		color("red");
		printf("\n\n\tList is empty");
	}
	else
	{	color("white");
		printf("\n\tname: %s\n\troll: %d\n", tail->name,tail->roll);	
		if(head == tail)
		{
			free(tail);
			tail=head=NULL;
		}
		else{
			temp= head;
			while(temp->next!= tail)
				temp= temp->next;
			
			free(tail);
			tail = temp;
			tail->next = head;
		}
		color("green");
		printf("\n\tremoved succesfully");
		c--;	
	}
	
}

DeleteAtLocation()							//delete at location
{
	int location, i , count=1;
	struct stud *temp2;
	l2:	
	if(head == NULL)
	{
		printf("\nlist is empty");
//		goto l1;
	}
	color("white");
	printf("enter location for removing record: ");
	scanf("%d",&location);
	count=1;
	i =c;
	if (location> i)
	{
		system("cls");
		color("red");
		printf("\n\n\tThis location not found in list\n");
		goto l2;
	}
	temp = temp2 = head ;
	if(location ==1)
		deleteAtBegin();
	else if(location == i)	
		deleteAtBegin();
	else
	{
		while(count < i)
		{
			if(location == count)
			{	
				temp->next = ptr->next;
				free(ptr);
				printf("record is deleted at location: %d",location);
				break;
			}
			count++;
			temp = ptr;
			ptr = ptr->next;
		}
		c--;
	}
}
search()									// search
{
	int srch, i =1;
	temp = head;
	ptr = NULL;
	system("cls");
	
	if(temp== NULL)
	{
		color("blue");		
		printf("\n\t_____________________________________");
		color("red");
		printf("\n\n\tList is empty");
	}		
	else
	{	
		printf("\n\n\tEnter roll no to search:  ");
		scanf("%d",&srch);
		while(ptr != tail)
		{
			if(srch==temp->roll)
			{
				color("blue");		
				printf("\n\t_____________________________________");
				color("white");
				printf("\n\tSno\t\tName\t\tRoll");
				printf("\n\t%d\t\t%s\t\t%d",i, temp->name, temp->roll);
				break;
			}
			ptr = temp;
			temp = temp -> next;
			i++;
		}
		if(ptr==tail)	{	color("red");
			printf("\n\n\tRecord not found");
		}
	}
}

countRecord()								// Count record
{
	if(c==0){
		color("red"); printf("\n\n\tList is empty : 0 record");
	}	
	else{
		color("green");	printf("\n\n\tTotal record: %d",c);
	}
		
}

Update()									// Update a record
{
	int Roll, option;
	system("cls");
	color("blue");		
	printf("\n\t_____________________________________");
	if(head==NULL){color("red");
		printf("\n\n\tList is empty");
	}
	else
	{
		ptr = head;
		color("white");
		printf("\n\tEnter roll no to search: ");
		scanf("%d",&Roll);
		do
		{
			if(ptr->roll == Roll)
			{
				printf("\n\tname: %s\troll: %d",ptr->name,ptr->roll);
				printf("\n\t_____________________________________");
				
				color("blue");
				l1:
				color("lblue");
				printf("\n\n\t[1] Change  roll\t[2]Change name");
				color("blue");
				printf("\n\n\tEnter your option: ");
				scanf("%d",&option);
				switch(option)
				{
					case 1:
						printf("\n\tEnter new roll number: ");
						fflush(stdin);
						scanf("%d",&ptr->roll);
						color("green");
						printf("\n\tRoll number is changed ");
						break;
					case 2:
						printf("\n\tEnter new name: ");
						fflush(stdin);
						gets(ptr->name);
						color("green");
						printf("\n\tName is changed");
						break;
					default:
						printf("\n\tinvalid option\tretype..");
						goto l1;				
				}
				ptr = NULL;
				break;
			}
			ptr = ptr->next;
		}while (ptr != head);
		
		if(ptr == head){
			color("red");printf("\n\tRecord not found ");
		}
					
	}
}

main()										// main
{
	int  choice;
	char choice2;
	do
	{
		system("cls");
		color("lblue");
//		printf("\n\t\t *****CIRCULAR LINEAR LINKED LIST*****\n\n\t");
		printf("\n\t\t     *****Circular Linked List*****\n\n\t");
		for (i=0; i<57; i++)
		printf("%c",178);
		printf("\n\t%c\t\t\t\t\t\t\t%c\n\t%c\t[1] Insert At Begin",178,178,178);
		printf("\t[2] Insert At End\t%c",178,178);
		printf("\n\t%c\t\t\t\t\t\t\t%c\n\t%c\t[3] Insert At Location",178,178,178);
		printf("\t[4] Delete At Begin\t%c",178,178);
		printf("\n\t%c\t\t\t\t\t\t\t%c\n\t%c\t[5] Delete At End",178,178,178);
		printf("\t[6] Delete At Location\t%c",178,178);
		printf("\n\t%c\t\t\t\t\t\t\t%c\n\t%c\t[7] Search\t",178,178,178);
		printf("\t[8] Update\t\t%c",178,178);
		printf("\n\t%c\t\t\t\t\t\t\t%c\n\t%c\t[9] Count Record",178,178,178);
		printf("\t[10] Display\t\t%c",178,178);
		printf("\n\t%c\t\t\t\t\t\t\t%c\n\t%c\t[0] Exit\t\t\t\t\t%c\n\t%c\t\t\t\t\t\t\t%c\n\t",178,178,178,178,178,178);
		for (i=0; i<57; i++)
		printf("%c",178);
		color("blue");
		printf("\n\n\n\tEnter your option: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertAtBgin();printf("at begin");	
				break;
			case 2:
				InsertAtEnd();printf("at end");	
				break;
			case 3:
				insertAtLocation();
				break;
			case 4:
				deleteAtBegin();
				break;
			case 5:
				deleteAtEnd();break;
			case 6:
				DeleteAtLocation();break;	
			case 7:
				search();break;
			case 8:
				Update();break;
			case 9:
				countRecord();break;	
			case 10:
				display();break;
			case 0:
				exit(1);	break;
			default:
				printf("\n invalid option")	;			
		}
		color("red");
		printf("\n\n\n Do you want to do more operation [y/n]");
		choice2 = toupper(getche());
	}while(choice2 == 'Y');
	
}











