#include<stdio.h>
#include<stdlib.h>
int i ;
struct stud 
{
	char name[25]; 
	int roll;
	struct stud *next;
	
}*temp, *NEW ;
struct stud* head = NULL;
struct stud* tail = NULL;

struct stud* createRecord()
{
	struct stud* NEW ;
	
	NEW = (struct stud*)malloc(sizeof(struct stud));
	printf("enter name: ");
	fflush(stdin);
	gets(NEW->name);
	printf("enter roll number: ");
	fflush(stdin);
	scanf("%d", &NEW->roll);
	NEW->next = NULL;
	return(NEW);
		
}
insertAtBgin()  
{
	
	NEW = createRecord();	
	if(head == NULL)
	{
		head = tail = NEW;
	}
	else
	{
		temp = head;
		head = NEW;
		head->next = temp;	
	}
	printf("Record is added");
	
			
}
InsertAtEnd()  // insert record at end of list
{
	NEW = createRecord();
	
	if(tail == NULL)
	{
		head = tail = NEW;
	}
	else
	{	
		tail->next = NEW;
		tail = tail->next;	
	}
	printf("record is added");
	  	
}
insertAtLocation()  // insert new record at location
{
	int location, count=1;
	struct stud *temp2;
	NEW = createRecord();
	l2:
		
	printf("enter location you want to add a record: ");
	scanf("%d",&location);
	count=1;
	temp = temp2 = head ;
	if(temp == NULL)
	{
		head = NEW;
	}
	while(temp != NULL)
	{
//			temp2 = temp2->next;
		
		if(location == count)
		{
			
			if(1 == count)
			{
				NEW->next = temp;	
				head = NEW;
			}
			else
			{
				temp2->next = NEW;	
				NEW->next = temp;	
			}
			printf("record is added at location: %d",location);
			break;
		}
		if(count != 1)
		temp2 = temp2->next;
		count++;
		temp = temp->next;
		if (temp==NULL)
		{
			system("cls");
			printf("\nthis location not found in list\n");
			
			goto l2;
		}
	}
		
}

display()
{
	temp = head;
	if(temp == NULL )
	{
		printf("\nList is empty");	
	}
	else
	{
		while(temp!= NULL)
		{
			printf("\nname: %s",temp->name);
			printf("\nroll: %d",temp->roll);
			printf("\n_______________________");
			temp= temp->next ;	
		}
	}
}
deleteAtBegin()
{
	if(head== NULL)
	{
		printf("\nlist is empty\n");
	}
	else
	{
		temp = head ;
		printf("name: %s\nroll: %d\n", temp->name,temp->roll);
	   
		if (head== tail)
		{
			free(head);
			tail=head=NULL;	
		}
		else
		{
			head = head->next;
			free(temp);
		}
		printf("\nremoved succesfully");  
	}

}
deleteAtEnd()
{
	if(tail == NULL)
	{
		printf("List is empty");
	}
	else
	{	
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
			tail->next = NULL;
		}
		printf("\nremoved succesfully");
		
	}
}
DeleteAtLocation()
{
	int location, count=1;
	struct stud *temp2;


	l2:
		
	printf("enter location for removing record: ");
	scanf("%d",&location);
	count=1;
	temp = temp2 = head ;

//	
	if(temp == NULL)
	{
		printf("\nlist is empty");
	}
	while(temp != NULL)
	{
//			temp2 = temp2->next;
	
		if(location == count)
		{	
			if(1 == count)
			{
				head = temp->next;
				free(temp);		
			}
			else
			{		
				temp2->next = temp->next;
				free(temp);	
			}
			printf("record is deleted at location: %d",location);
			break;
		}
		if(count != 1)
		{
			temp2 = temp2->next;
		}
		count++;
		temp = temp->next;
		if (temp==NULL)
		{
			system("cls");
			printf("\nthis location not found in list\n");
			goto l2;
		}
	}
		
}
search()
{
	int srch;
	temp = head;
	if(temp== NULL)
		printf("\nList is empty");
	else
	{
		printf("\nenter roll no that you want to search: ");
		scanf("%d",&srch);
		while(temp!= NULL)
		{
			if(srch==temp->roll)
			{
				printf("\nrecord found");
				printf("\nname: %s",temp->name);
				printf("\nroll: %d",temp->roll);
				break;
			}
			temp = temp->next;
		}
		if(temp== NULL)
		printf("\nRecord not found");
	}
}
countRecord()
{
	int count=0;
	if(head== NULL)
	printf("List is empty\n0 record");
	else
	{
		temp = head;
		while(temp!=NULL)
		{
			count++;
			temp = temp->next;
		}
		printf("\nTotal record: %d",count);
	}
}
Update()
{
	int roll, option;
	temp = head;
	if(temp== NULL)
		printf("\nList is empty");
	else
	{
		printf("\nenter roll no: ");
		scanf("%d",&roll);
		while(temp!= NULL)
		{
			if(roll==temp->roll)
			{
				printf("\nname: %s",temp->name);
				printf("\nroll: %d",temp->roll);
				l1:
				printf("\n\n1. Change my roll");
				printf("\n2. Change name");
				printf("\nenter your option: ");
				scanf("%d",&option);
				switch(option)
				{
					case 1:
						printf("\nenter new roll number: ");
						scanf("%d",&temp->roll);
						printf(" roll number is changed ");
						break;
					case 2:
						printf("\nenter new name: ");
						scanf("%s",&temp->name);
						printf("\n name is changed");
						break;
					default:
						printf("\ninvalid option\nretype");
						goto l1;				
				}
				break;
			}
			temp = temp->next;
		}
		if(temp== NULL)
		printf("\nRecord not found of this roll number");
	};
	
}
main()
{
	int choice;
	char choice2;
	do
	{
		system("cls");
		printf("\n\t");
		for (i=0; i<49; i++)
		printf("%c",1);
		printf("\n\t%c\t 1. Insert At Begin\t\t\t%c",178,178);
		
		printf("\n\t%c\t 2. Insert At End\t\t\t%c",178,178);
		printf("\n\t%c\t 3. Insert At Location\t\t\t%c",178,178);
		printf("\n\t%c\t 4. Delete At Begin\t\t\t%c",178,178);
		printf("\n\t%c\t 5. Delete At End\t\t\t%c",178,178);
		printf("\n\t%c\t 6. Delete At Location\t\t\t%c",178,178);
		printf("\n\t%c\t 7. Search\t\t\t\t%c",178,178);
		printf("\n\t%c\t 8. Update\t\t\t\t%c",178,178);
		printf("\n\t%c\t 9. Count Record\t\t\t%c",178,178);
	
		printf("\n\t%c\t10. Display\t\t\t\t%c",178,178);

		printf("\n\t%c\t 0. Exit\t\t\t\t%c",178,178);
		printf("\n\t\t\tenter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertAtBgin();
				break;
			case 2:
				InsertAtEnd();
				break;
			case 3:
				insertAtLocation();
				break;
			case 4:
				deleteAtBegin();
				break;
			case 5:
				deleteAtEnd();
				break;
			case 6:
				DeleteAtLocation();
				break;	
			case 7:
				search();
				break;
			case 8:
				Update();
				break;
			case 9:
				countRecord();
				break;	
			case 10:
				display();
				break;
			case 0:
				exit(1);
				break;
		
			default:
				printf("\n invalid option")	;
						
		}
		printf("\n\ndo you want to do more operation [y/n]");
		choice2 = toupper(getche());
	}while(choice2 == 'y' ||choice2 == 'Y');

}











