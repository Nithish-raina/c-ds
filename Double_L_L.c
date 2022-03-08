#include <stdio.h>
#include <stdlib.h>
//GLOBAL VARIABLE DECLARATION
struct node *head = NULL;
struct node *temp = NULL;
int choice, value, pos, key;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void menu()
{
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- \n");
    printf(" \n \t \t YOUR DOUBLY LINKED LIST MENU \n");
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- ");
    printf(" \n \t \t \t \t \t @NITHISH RAINA \n");
    printf(" \n \t 1.CREATE A LINKED LIST \n \t 2.INSERT AT THE START \n \t 3.INSERT AT THE END \n \t 4.INSERT AT A POS \n \t 5.DELETE AT THE START \n \t 6.DELETE AT THE END \n \t 7.DELETE AT MID \n \t 8.DISPLAY YOUR LINKED LIST \n \t 9.LENGTH OF YOUR LINKED LIST \n \t 10.SEARCH FOR AN ELEMENT \n \t 11.EXIT THE MENU \n\t");
}
struct node *create(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    // head = 0;
    // temp = 0;
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL && temp == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
    return head;
}

void traverse(struct node *head)
{
    if (head == NULL && temp == NULL)
    {
        printf(" \n \t THERE ARE NO ELEMENTS TO DISPLAY HERE PLEASE FIRST CREATE A LINKED LISTS \n ");
    }
    else
    {
        struct node *temp = head;
        printf("\n \t THE ELEMENTS IN THE LINKED LISTS ARE \n");
        printf(" \t --------------------------------------------- \n");
        while (temp != NULL)
        {
            printf(" \t %d ", temp->data);
            temp = temp->next;
        }
    }
}

struct node *insertStart(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (head == NULL && temp == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = NULL;
        head = newnode;
    }
    return head;
}
struct node *insertEnd(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *q = head;
    newnode->data = value;
    if (head == NULL && temp == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = newnode;
        newnode->prev = q;
        newnode->next = NULL;
        q = newnode;
    }
    return head;
}
struct node *insertMid(int pos, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    // newnode->next = NULL;
    if (head == NULL && temp == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        struct node *p = head;
        int i = 1;
        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        newnode->prev = p;
        newnode->next = p->next;
        p->next = newnode;
        newnode->next->prev = newnode;
    }
    return head;
}
struct node *deleteStart()
{
    if (head == NULL)
    {
        printf("\n \t NO ELEMENTS TO BE DELETED!!PLEASE CREATE A L.L \n\t");
    }
    else
    {
        struct node *p = head;

        head = head->next;
        printf("\n \t THE DELETED ELEMENT IS %d \n", p->data);
        free(p);
        return head;
    }
}
struct node *deleteEnd()
{
    if (head == NULL)
    {
        printf("\n \t NO ELEMENTS TO BE DELETED!!PLEASE CREATE A L.L \n\t");
    }
    else
    {
        struct node *p = head;
        struct node *q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;

        printf("\n \t THE DELETED ELEMENT IS %d \n", q->data);
        free(q);
        return head;
    }
}
struct node *deletePos(int pos)
{
    if (head == NULL)
    {
        printf("\n \t NO ELEMENTS TO BE DELETED!!PLEASE CREATE A L.L \n\t");
    }
    else
    {
        struct node *p = head;
        struct node *q = head->next;
        int i = 1;
        while (i < pos - 1)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        q->next->prev = p;
        printf("\n \t THE DELETED ELEMENT IS %d \n", q->data);
        free(q);
        return head;
    }
}
int getCount(struct node *head)
{
    //printf("\n\t CALLING THIS COUNT FUNCTION \n\t");
    if (head == NULL)
    {
        printf("\n\t NO ELEMENTS IN YOUR L.L \n\t ");
        exit(0);
    }
    else
    {
        struct node *temp = head;
        int count = 1;
        while (temp->next != NULL)
        {
            count = count + 1;
            temp = temp->next;
        }
        return count;
    }
}
void search(struct node *head, int key)
{
    if (head == NULL)
    {
        printf("\n\t NO ELEMENTS IN YOUR L.L \n\t ");
    }
    else
    {
        struct node *temp = head;
        while (temp->data != key && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->data == key)
        {
            printf("\n \t ELEMENT PRESENT %d\n", temp->data);
        }
        else
        {
            printf("\n \t BETTER LUCK NEXT TIME!! NO ELEMENT FOUND \n\t ");
        }
    }
}

int main()
{

    do
    {
        menu();
        printf(" \n \t ENTER YOUR CHOICE \n \t ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf(" \n \t ENTER THE DATA OF THE NODE \n \t ");
            scanf("%d", &value);
            head = create(value);
            break;
        }
        case 2:
        {
            printf(" \n \t ENTER THE VALUE YOU WANT TO INSERT AT THE START \n \t ");
            scanf("%d", &value);
            insertStart(value);
            break;
        }
        case 3:
        {
            printf(" \n \t ENTER THE VALUE YOU WANT TO INSERT AT THE END \n \t ");
            scanf("%d", &value);
            insertEnd(value);
            break;
        }
        case 4:
        {
            printf(" \n \t ENTER THE POSITION WHERE YOU WANT TO INSERT AN ELEMENT \n \t ");
            scanf("%d", &pos);
            printf(" \n \t ENTER THE VALUE YOU WANT TO INSERT AT THE MID POSITION \n \t ");
            scanf("%d", &value);
            insertMid(pos, value);
            break;
        }
        case 5:
        {
            deleteStart();
            break;
        }
        case 6:
        {
            deleteEnd();
            break;
        }
        case 7:
        {
            printf(" \n \t ENTER THE POSITION YOU WHERE YOU WANT TO DELETE \n \t ");
            scanf("%d", &pos);
            deletePos(pos);
            break;
        }
        case 8:
        {
            traverse(head);
            break;
        }
        case 9:
        {
            int len = getCount(head);
            printf(" \n \t THE NO OF ELEMENTS IN YOUR LINKED LISTS ARE %d\n\t", len);
            break;
        }
        case 10:
        {
            printf("\n \t ENTER THE ELEMENT THAT YOU WANT TO SEARCH FOR \n\t ");
            scanf("%d", &key);
            search(head, key);
            break;
        }
        case 11:
        {
            printf(" \n \t ---------------------------------- \n");
            printf(" \n \t EXITING MENU !!!! HAVE A NICE DAY MY DEAR GEEKY !!!! \n");
            printf(" \n \t ---------------------------------- \n");
            exit(1);
        }
        default:
        {
            printf(" \n \t PLEASE ENTER A VALID OPTION FROM(1/9) \n ");
            break;
        }
        }
    } while (choice != 11);
    return (0 == 0);
}