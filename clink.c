//Circular Link List

#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *link;
};

struct node *insertAtStart(struct node *last,int data)
{
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->link=last->link;
        last->link=newnode;
        return last;
}

struct node * insertAtEnd(struct node *last,int data)
{
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->link=last->link;
        last->link=newnode;
        last=newnode;
        return last;
}

struct node *addafter(struct node *last,int data,int item)
{
        struct node *newnode,*p;
        p=last->link;
        do
        {
                if(p->data==item)
                {
                        newnode=(struct node *)malloc(sizeof(struct node));
                        newnode->data=data;
                        newnode->link=p->link;
                        p->link=newnode;
                        if(p==last)
                                last=newnode;
                        return last;
                }
                p=p->link;
        }while(p!=last->link);
        printf("%d not present in the list\n",item);
        return last;
}

struct node * delete(struct node *last,int data)
{
        struct node *newnode,*p;
        if(last==NULL)
        {
                printf("List is empty\n");
                return last;
        }
        
        if(last->link==last && last->data==data)
        {
                newnode=last;
                last=NULL;
                free(newnode);
                return last;
        }
       
        if(last->link->data==data)
        {
                newnode=last->link;
                last->link=newnode->link;
                free(newnode);
                return last;
        }
        
        p=last->link;
        while(p->link!=last)
        {
                if(p->link->data==data)
                {
                        newnode=p->link;
                        p->link=newnode->link;
                        free(newnode);
                        return last;
                }
                p=p->link;
        }
        
        if(last->data==data)
        {
                newnode=last;
                p->link=last->link;
                last=p;
                free(newnode);
                return last;
        }
        printf("\nElement %d not found\n",data);
        return last;
}

void display(struct node *last)
{
        struct node *p;
        if(last==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        p=last->link;
        do
        {
                printf("%d ",p->data);
                p=p->link;
        }while(p!=last->link);
        printf("\n");
}

int main( )
{
        int ch,data,item;
        struct node     *last=NULL;

        while(1)
        {
                 printf("1. Insert value at begining\n2. Insert At intermediate position\n");
                printf("3. Insert at End\n");
                printf("4. Delete\n");
                printf("5. Display\n6. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                {
                
                 case 1:
                        printf("\nEnter value at Begining\n");
                        scanf("%d",&data);
                        last=insertAtStart(last,data);
                        break;
                 case 2:
                        printf("Enter value at Position\n");
                        scanf("%d",&data);
                        printf("Enter the element after which to insert : ");
                        scanf("%d",&item);
                        last=addafter(last,data,item);
                        break;
                        
                 case 3:
                        printf("Enter value at End\n");
                        scanf("%d",&data);
                        last= insertAtEnd(last,data);
                        break;
                 case 4:
                        printf("Enter value to delete node\n");
                        scanf("%d",&data);
                        last= delete(last,data);
                        break;
                 case 5:
                        display(last);
                        break;
                 case 6:
                        exit(0);
                 default:
                        printf("You have entered wrong option\n");
                }
        }

        return 0;
        }
}

