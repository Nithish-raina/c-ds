#include<stdio.h>
#include<stdlib.h>

//with user interaction of pushing and popping of elements from the stack
//GLOBAL VARIABLE DECLARATION
int stack[100],n,choice,top,val;  
//FUNCTION PROTOTYPE WITH RETURN TYPE ARGUMENTS
void menu(void);
void push(void);
void pop(void);
void display(void);
void peek(void);
void stackTop(void);
void stackBottom(void);
int main()
{
    //clrscr();
    top=-1;
    printf("\n Enter the size of STACK: ");
    scanf("%d",&n);
    do
    {
        menu();
        printf("\n Enter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                peek();
                break;
            }
            case 5: 
            {
                stackTop();
                break;
            }
            case 6: 
            {
                stackBottom();
                break;
            }
            case 7: 
            {
                printf("\n \t EXITING MENU ");
                exit(1);
            } 
            default:
            {
                printf ("\n\t Please Enter a Valid Choice from (1/2/3/4) "); 
            }
                
        }
    }
    while(choice!=7);
    return 0;
}
void menu() {
    printf("\n \t STACK OPERATIONS USING ARRAY ");
    printf("\n \t-------------------------------- ");
    printf("\n \t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEK \n\t 5.STACKTOP \n\t 6.STACKBOTTOM \n\t 7.EXIT\n");
}
    
void push()
{
    if(top>=n-1)
    {
        printf("\n \t Stack over flow ");
        
    }
    else
    {
        printf(" Enter a value to be pushed: ");
        scanf("%d",&val);
        top++;
        stack[top]=val;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n \t Stack under flow ");
    }
    else
    {
        printf("\n \t The popped element are %d \n",stack[top]);
        stack[top] = 0;
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf(" \t The elements in Stack are \n");
        printf(" \t ------------------------ \n");
        for(int i=top; i>=0; i--){
            printf(" \t %d",stack[i]);
        }
        printf(" \n \n \t Select for the Next Choice \n");
    }
    else
    {
        printf(" \n The Stack is empty ");
    }
}
void peek() {
    if(top == -1) {
        printf(" \t NO ELEMENTS TO BE DISPLAYED \n ");
    }
    else {
        printf(" \t THE PEEK ELEMENT IS \n");
        printf(" \t -------------------- \n");
        printf(" \t %d \n",stack[top]);
    }
}
void stackTop() {
    if(top == -1) {
        printf(" \t NO ELEMENTS PRESENT AT THE TOP \n ");
    }
    else {
        printf(" \t THE ELEMENT AT THE TOP OF THE STACK IS \n");
        printf(" \t ---------------------------------------- \n");
        printf(" \t %d \n",stack[top]);
    }
}
void stackBottom() {
    if(top < 0) {
        printf(" \t NO ELEMENTS AT THE BOTTOM OF THE STACK ");
    }
    else {
        printf(" \t THE ELEMENT AT THE BOTTOM OF THE STACK IS \n");
        printf(" \t ---------------------------------------- \n ");
        printf(" \t %d \n",stack[top-top]);
    }
}