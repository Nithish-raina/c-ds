#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

int choice,val;
// this declaration played a major role in this program
struct node * top = NULL;

void menu() {
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- \n");
    printf(" \n \t \t MENU OF YOUR STACK USING LINKED LIST \n");
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- ");
    printf(" \n \t \t \t \t \t @NITHISH RAINA \n");
    printf(" \n \t 1.PUSH ELEMENTS TO THE STACK \n \t 2.POP ELEMENTS FROM THE STACK \n \t 3.PEEK ELEMENT OF YOUR STACK \n \t 4.DISPLAY YOUR STACK \n \t 5.EXIT THE MENU \n \t");
}
int isFull() {
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    if( newnode == NULL) {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int isEmpty() {
    if(top == NULL) {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int val) {
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    if(isFull(top)) {
        printf(" \n \t STACK OVERFLOW \n");
    }
    else if(isEmpty(top)) 
    {
        newnode->data = val;
        newnode->next = NULL;
        top = newnode;  
    }
    else {
        //insertion at the start end
        newnode->data = val;
        newnode->next = top;
        top = newnode;
    }
    //return top;
}



void pop() {
    if(isEmpty(top)) {
        printf(" \n \t STACK UNDERFLOW \n");
    }
    else {
        struct node * temp = top;
        top = top->next;
        printf("\n \t THE DELETED ELEMENT IS %d \n ",temp->data);
        free(temp);
        //return top;
    }
}

void peek() {
    if(top == NULL) {
        printf("\n \t THERE IS NO PEEK ELEMENT TO BE DISPLAYED \n ");
    }
    else {
        printf("\n \t THE PEEK ELEMENT IS %d \n",top->data);
    }
}

void display() {
    if(top == NULL) {
        printf("\n \t THERE ARE NO ELEMENTS IN THE STACK TO DISPLAY \n");
    }
    else {
        struct node * temp = top;
        printf(" \n \t THE ELEMENTS IN THE STACK ARE \n \t ");
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
                printf(" \n \t ENTER THE VALUE YOU WANT TO PUSH \n \t ");
                scanf("%d",&val);
                push(val);
                break;
            }
            case 2: {
                pop();
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
    while( choice != 5 );   
    return (0 == 0);
}

