#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int * arr;
};

int val;
int isFull(struct queue * q) {
    if(q->rear == q->size - 1) {
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty(struct queue * q) {
    if(q->front == -1 && q->rear == -1) {
        return 1;
    }
    else if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        return 0;
    }
}
void enqueue(struct queue * q, int val) {
    printf(" \n \t ENTER THE VALUE YOU WANT TO ENQUEUE \n \t ");
    scanf("%d",&val);

    if(isFull(q)) {
        printf(" \n \t QUEUE OVERFLOW \n ");
    }
    else {
        q->rear = q->rear + 1;
        q->arr[q->rear] = val;       
    }
}
void dequeue(struct queue * q) {
    if(isEmpty(q)) {
        printf(" \n \t QUEUE UNDERFLOW \n ");
    }
    else {
        q->front++;
        int del_ele = q->arr[q->front];
        printf(" \n \t DELETED ELEMENT IS %d\n",del_ele);
        //q->front = 0;
        //q->front++;
    }
}

void peek(struct queue * q) {
    if(q->front == -1 && q->rear == -1) {
        printf("\n \t NO ELEMENTS TO BE DISPLAYED ");
    }
    else {
        printf(" \n \t THE PEEK ELEMENT IS \n \t ");
        printf("%d ",q->arr[q->front]);
    }
}
void display(struct queue * q) {
    if(q->front == -1 && q->rear == -1) {
        printf("\n \t THERE ARE NO ELEMENTS TO BE DISPLAYED!!! PLEASE ENQUEUE SOME ELEMENTS \n");
    }
    else {
        printf(" \n \t DISPLAYING THE QUEUE ELEMENTS \n \t ");
        printf(" \n \t ------------------------------------------ ");
        for(int i = q->front + 1; i < q->size; i++) {
            printf(" \n \t %d ",q->arr[i]);
        }
    }
}
void menu() {
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- \n");
    printf(" \n \t \t MENU OF YOUR QUEUE USING ARRAYS \n");
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- ");
    printf(" \n \t \t \t \t \t @NITHISH RAINA \n");
    printf(" \n \t 1.ENQUEUE ELEMENTS TO THE QUEUE \n \t 2.DEQUEUE ELEMENTS FROM THE QUEUE \n \t 3.PEEK ELEMENT OF YOUR QUEUE \n \t 4.DISPLAY YOUR QUEUE \n \t 5.EXIT THE MENU \n \t");
}

int main()
{
    int choice,n;
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = -1;
    printf("\n \t ENTER THE SIZE OF THE QUEUE \n \t ");
    scanf("%d",&n);
    q->size = n;
    q->arr = (int *)malloc(q->size * sizeof(int));
    do {
        menu();
        printf("\n \t ENTER YOUR CHOICE \n \t ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: {
                enqueue(q,val);
                break;
            }
            case 2: {
                dequeue(q);
                break;
            }
            case 3: {
                peek(q);
                break;
            }
            case 4: {
                display(q);
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