#include <stdio.h>
#include <stdlib.h>
struct node //Creating a node structure with address and value 
{
    int data;
    struct node* next;
};
struct node* head = NULL;
void InsertNode(int data)
{
    struct node* temp;
    temp = (struct node*)malloc(1*sizeof(struct node)); //dynamic memory allocation
    temp-> data = data;
    temp->next = head;
    head = temp;
}
void DeleteNode()
{
    struct node* temp;
    temp = head;
    if(head==NULL) //head usually points to the bottom most element(or the first one to be inserted)
        printf("\nStack underflow\n");
    else
    {
        head = temp->next;
        free(temp);
    }
}
void DisplayList()
{
    struct node* temp;
    temp = head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}

void FindNode(int value)
{
    struct node* temp = head;
    int j=1;
    int flag = 0;
    while(temp!=NULL)
    {
        if(temp->data == value)
        {
            printf("\n%d found at node no. %d\n",value, j);
            flag = 1;
        }
        j++;
        temp = temp->next;
    }
    if(flag==0)
    {
        printf("\nNot found\n");
    }
}
int main()
{
    int choice, d, i;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Find\n0.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter Element to be Pushed: ");
            scanf("%d",&d);
            InsertNode(d);
            break;
            case 2: DeleteNode();
            break;
            case 3: DisplayList();
            break;
            case 4: printf("\nEnter Element to be searched: ");
            scanf("%d",&d);
            FindNode(d);
            break;
            case 0: break;
            default: printf("\nPlease Enter Valid option: ");
        }
    }while(choice!=0);
    return 0;
}
