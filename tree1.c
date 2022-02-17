 //Binary Search Tree Operation

# include <stdio.h>
# include <stdlib.h>

struct node
{
	int info;
	struct node *l;
	struct node *r;
}*root;



void find(int item,struct node **second,struct node **first)
{
	struct node *ptr,*ptrsave;

	if(root==NULL)  
	{
		*first=NULL;
		*second=NULL;
		return;
	}
	if(item==root->info) 
	{
		*first=root;
		*second=NULL;
		return;
	}
	
	if(item<root->info)
		ptr=root->l;
	else
		ptr=root->r;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{       *first=ptr;
			*second=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->info)
			ptr=ptr->l;
		else
			ptr=ptr->r;
	 }
	 *first=NULL;   
	 *second=ptrsave;
}

void insert(int item)
{       struct node *newnode,*p,*q;
	find(item,&p,&q);
	if(q!=NULL)
	{
		printf("Item present");
		return;
	}

	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=item;
	newnode->l=NULL;
	newnode->r=NULL;

	if(p==NULL)
		root=newnode;
	else
		if(item<p->info)
			p->l=newnode;
		else
			p->r=newnode;
}


void a(struct node *second,struct node *first )
{
	if(second==NULL) 
		root=NULL;
	else
		if(first==second->l)
			second->l=NULL;
		else
			second->r=NULL;
}

void b(struct node *second,struct node *first)
{
	struct node *child;

	
	if(first->l!=NULL) 
		child=first->l;
	else                
		child=first->r;

	if(second==NULL )   
		root=child;
	else
		if( first==second->l)  
			second->l=child;
		else                  
			second->r=child;
}

void c(struct node *second,struct node *first)
{
	struct node *ptr,*ptrsave,*s,*r;

	
	ptrsave=first;
	ptr=first->r;
	while(ptr->l!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->l;
	}
	s=ptr;
	r=ptrsave;

	if(s->l==NULL && s->r==NULL)
		a(r,s);
	else
		b(r,s);

	if(second==NULL) 
		root=s;
	else
		if(first==second->l)
			second->l=s;
		else
			second->r=s;

	s->l=first->l;
	s->r=first->r;
}
int del(int item)
{
	struct node *p,*q;
	if(root==NULL)
	{
		printf("Tree empty");
		return 0;
	}

	find(item,&p,&q);
	if(q==NULL)
	{
		printf("Item not present in tree");
		return 0;
	}

	if(q->l==NULL && q->r==NULL)
		a(p,q);
	if(q->l!=NULL && q->r==NULL)
		b(p,q);
	if(q->l==NULL && q->r!=NULL)
		b(p,q);
	if(q->l!=NULL && q->r!=NULL)
		c(p,q);
	free(q);
}

int preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return 0;
	}
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->info);
		preorder(ptr->l);
		preorder(ptr->r);
	}
}

void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->l);
		printf("%d  ",ptr->info);
		inorder(ptr->r);
	}
}

void postorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->l);
		postorder(ptr->r);
		printf("%d  ",ptr->info);
	}
}

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->r, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->l, level+1);
	}
}
int main()
{
	int choice,num;
	root=NULL;
	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Postorder Traversal\n");
		printf("6.Display\n");
		printf("7.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			preorder(root);
			break;
		 case 5:
			postorder(root);
			break;
		 case 6:
			display(root,1);
			break;
		 case 7:
            break;
		 default:
			printf("Wrong choice\n");
		}
	}
}

