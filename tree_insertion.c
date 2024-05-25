#include<stdio.h>
#include<stdlib.h>

struct BSTNode
{
	int data;
	struct BSTNode *left ;
    struct BSTNode * right;
    
};

struct BSTNode * root = NULL;
void Insert( int data)
{
	struct BSTNode *par;
	struct BSTNode *n=malloc(sizeof(struct BSTNode));
//	if(n==NULL)

	n->left=NULL;
	n->data=data;
	n->right=NULL;
	
	if(root==NULL)
	{
		root=n;
	    printf("memory not allocated");
	}
	    
	else
	{
     	par=root;
		while(par!=NULL)
		{
			
			if(par->data > data) {
				if(par->left==NULL)
					par->left=n;
				par=par->left;
			}
			if(par->data < data)
			 {
				if(par->right==NULL)
				    par->right=n;
				par=par->right;
	    	}
		} //end of while
	}//end of else

}
main()
{
	
	int data , n;
	
	printf("enter number many store: ");o
	scanf("%d",&n);
	while(n!= 0 )
	{
		printf("enter a number to store in tree: ");
		scanf("%d",&data);
		Insert( data);
		
		n--;
	}	
	
}













