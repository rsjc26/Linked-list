 //Double Link list
 
 #include <stdio.h>
  #include <stdlib.h>

  struct node {
        int info;
        struct node *next, *prev;
  };

  struct node *head = NULL, *end = NULL;
  int nodeCount = 0;

  struct node * createNode(int info) {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof (struct node));
        newnode->info = info;
        newnode->next = NULL;
        newnode->prev = NULL;
        return (newnode);
  }

  void createnode() {
        head = (struct node *)malloc(sizeof (struct node));
        end = (struct node *)malloc(sizeof (struct node));
        head->info = end->info = 0;
        head->next = end;
        end->prev = head;
        head->prev = end->next = NULL;
  }

  void insert(int info, int pos) {
        struct node *newnode, *temp1;
        int count = 1;
        newnode = createNode(info);
        temp1 =  head;
        while (temp1) {
                if (count == pos) {
                        newnode->next = temp1->next;
                        newnode->prev = temp1;
                        temp1->next->prev = newnode;
                        temp1->next = newnode;
                        nodeCount++;
                        break;
                }
                temp1 = temp1->next;
                count++;
        }
        return;
  }

  void insertAtStart(int info) {
        struct node *newnode = createNode(info);
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        nodeCount++;
  }

  void insertAtEnd(int info) {
        struct node *newnode = createNode(info);
        newnode->next = end;
        newnode->prev = end->prev;
        end->prev->next = newnode;
        end->prev = newnode;
        nodeCount++;
  }

  void delete(int info) {
        struct node *temp1, *temp2;
        temp1 = head->next;
        while (temp1 != end) {
                if (temp1->info == info) {
                        temp2 = temp1;
                        temp1->prev->next = temp1->next;
                        temp1->next->prev = temp1->prev;
                        free(temp2);
                        nodeCount--;
                        return;
                }
                temp1 = temp1->next;
        }
        printf("Given node is not present in the List\n");
        return;
  }

  

  void disp() {
        struct node *ptr = head->next;
        int flag = 1, i = 1;
        if (head->next == end) {
                printf("List is Empty\n");
                return;
        }
        printf("info in List:\n");
        while (ptr != end) {
                if (ptr->prev != head) {
                        flag = 0;
                }
               
        }
  }

  int main() {
        int info, ch, pos;
        createnode();
        while (1) {
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
                                printf("Enter the node position(1 - %d)", nodeCount+1);
                                scanf("%d", &pos);
                                if (pos <= 0 || pos > nodeCount+1) {
                                        printf("Please enter correct position\n");
                                } else {
                                        printf("Enter ur info to insert\n");
                                        scanf("%d", &info);
                                        insert(info, pos);
                                }
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
        }
        return 0;
  }
