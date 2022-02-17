//Single Link List

#include<stdio.h>
#include<stdlib.h>

  struct node* newnode(int);
  struct node {
        int info;
        struct node *next;
  };

  struct node *head = NULL;
  struct node *end = NULL;

 
  struct node * newnode(int info) {
        struct node *ptr = (struct node *) malloc(sizeof (struct node));
        ptr->info = info;
        ptr->next = NULL;
        return ptr;
  }


  void insertAtStart(int info) {
        struct node *ptr = newnode(info);

        if (head == NULL) {
                head = ptr;
                end = ptr;
                return;
        }
        ptr->next = head;
        head = ptr;
  }

  void insertAtEnd(int info) {
        struct node *ptr =  newnode(info);

        if (end == NULL) {
                head = ptr;
                end = ptr;
        }
        end->next = ptr;
        end = ptr;
  }

  void insertAtPos(int pos, int info) {
        struct node *temp, *ptr = newnode(info);
        int i = 1, inserted = 0;

        if (head == NULL || pos == 1) {
                if (!head) {
                        head = ptr;
                        end = ptr;
                        return;
                }
                ptr->next = head;
                head = ptr;
                return;
        }
        temp = head;
        while (temp) {
                
                if (pos == i + 1) {
                        ptr->next = temp->next;
                        temp->next = ptr;
                        
                        if (ptr->next == NULL)
                                end = ptr;
                        inserted = 1;
                        break;
                }
                i++;
                temp = temp->next;
        }
        if (!inserted)
                printf("u ve entered wrong position\n");
  }


  void delete(int info) {
        struct node *ptr, *temp;
        int res = 0;
        ptr = head;
        if (ptr->info == info) {
                if (ptr->next == NULL) {
                        free(ptr);
                        head = end = NULL;
                }
                head =  ptr->next;
                free(ptr);
                return;
        }

        while (ptr != NULL && ptr->next != NULL) {
                if (ptr->next->info == info) {
                        temp = ptr->next;
                        ptr->next = temp->next;
              
                        if (ptr->next == NULL)
                                end = ptr;
                        free (temp);
                        res = 1;
                }
                ptr = ptr->next;
        }
        if (!res)
                printf("Operation failed - Give info unavailable in list\n");

  }


  void disp() {
        if (head)
                printf("List is available\n");
        else
                printf("List is unavailable\n");
  }

  int main () {
        int flag = 1, ch, info, pos, result;
        while (flag) {
                printf("1. Insert info at begining\n2. Insert At intermediate position\n");
                printf("3. Insert at End\n");
                printf("4. Delete\n");
                printf("5. Display\n6. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter value at Begining\n");
                                scanf("%d", &info);
                                insertAtStart(info);
                                break;
                        case 2:
                                printf("Enter value at position\n");
                                scanf("%d%d", &pos, &info);
                                insertAtPos(pos, info);
                                break;
                                
                        case 3:
                                printf("Enter value at End\n");
                                scanf("%d", &info);
                                insertAtEnd(info);
                                break;

                        
                        case 4:
                                printf("Enter value to delete node\n");
                                scanf("%d", &info);
                                delete(info);
                                break;
                        
                        case 5:
                                disp();
                                break;
                        case 6:
                                exit(0);
                        default:
                                printf("You have entered wrong option\n");
                                break;
                }
                printf("\n\n");
        }
  }
