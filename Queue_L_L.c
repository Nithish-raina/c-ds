#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

int choice,val;
// this declaration played a major role in this program
struct node * front = NULL;
struct node * rear = NULL;

void menu() {
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- \n");
    printf(" \n \t \t MENU OF YOUR QUEUE USING LINKED LIST \n");
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- ");
    printf(" \n \t \t \t \t \t @NITHISH RAINA \n");
    printf(" \n \t 1.ENQUEUE ELEMENTS TO THE STACK \n \t 2.DEQUEUE ELEMENTS FROM THE STACK \n \t 3.PEEK ELEMENT OF YOUR QUEUE \n \t 4.DISPLAY YOUR QUEUE \n \t 5.EXIT THE MENU \n \t");
}
int isFull() {
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    if( newnode == NULL) {
        return 1;
    }
    return 0;
}
void enqueue(int val) {
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(isFull()) {
        printf(" \n \t QUEUE OVERFLOW \n");
    }
    else if(front == NULL && rear == NULL) {
        front = rear = newnode;
    }
    else {
        //insertion at the start end
        rear->next = newnode;
        rear = newnode;
    }
    //return top;
}

int isEmpty() {
    if(front == NULL) {
        return 1;
    }
    return 0;
}

void dequeue() {
    if(isEmpty()) {
        printf(" \n \t QUEUE UNDERFLOW \n");
    }
    else {
        struct node * temp = front;
        front = front->next;
        printf("\n \t THE DELETED ELEMENT IS %d \n ",temp->data);
        free(temp);
        //return top;
    }
}

void peek() {
    if(front == NULL && rear == NULL) {
        printf("\n \t THERE IS NO PEEK ELEMENT TO BE DISPLAYED \n ");
    }
    else {
        printf("\n \t THE PEEK ELEMENT IS %d \n",front->data);
    }
}

void display() {
    if(front == NULL) {
        printf("\n \t THERE ARE NO ELEMENTS IN THE QUEUE TO DISPLAY \n");
    }
    else {
        struct node * temp = front;
        printf(" \n \t THE ELEMENTS IN THE QUEUE ARE \n \t ");
        printf(" \n \t ----------------------------------- \n \t ");
        while (temp != NULL)
        {   
            printf(" %d \t ",temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
   
    do {
        menu();
        printf("\n \t ENTER YOUR CHOICE \n \t ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: {
                printf(" \n \t ENTER THE VALUE YOU WANT TO ENQUEUE INTO THE QUEUE \n \t ");
                scanf("%d",&val);
                enqueue(val);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                peek();
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                printf("\n \t EXITING THE MENU \n");
                exit(1);
            }
            default: {
                printf(" \n \t PLEASE ENTER A VALID OPTION FROM (1/5) \n");
                break;
            }
        }
    } 
    while(choice != 5);   
    return ( 0 == 0 );
}

