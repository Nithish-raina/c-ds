#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack {
    int size;
    int top;       
    char * arr;
};

int isEmpty(struct stack * s) {
    if(s->top == -1) {
        return 1;
    }
    return 0;
}
int isFull(struct stack * s) {
    if(s->top >= s->size - 1) {
        return 1;
    }
    return 0;
}
void push(struct stack * s, char ch) {
    if(isFull(s)) {
        printf("STACK OVERFLOW \n");
    }
    else {
        s->top = s->top + 1;
        s->arr[s->top] = ch;
    }
}

void pop(struct stack * s) {
    if(isEmpty(s)) {
        printf("STACK UNDERFLOW \n ");
    }
    else {
        char item = s->arr[s->top];
        s->top--;
        // printf("DELETED CHARACTER IS %d\n",item);
    }
}
int findBalanced(char * exp) {
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 50;
    s->arr = (char *)malloc(s->size * sizeof(char));
   //traversing through the given expression upto the end (i.e)---->>>>>'\0'
    int i = 0;
    while(exp[i] != '\0') {
        if(exp[i] == '(') {
            push(s,'(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(s)) {
                return -1;
            }
            else {
                pop(s);
            }
        }
        i++;
    }
    if(isEmpty(s)) {
            return 1;
        }
    else {
        return 0;
    }
}
int main()
{
    char * exp = "((8)*--$$9))";
    int res = findBalanced(exp);
    if( res == 1) {
        printf(" BALANCED PARANTHESES \n");
    }
    else {
        printf(" UNBALANCED PARANTHESES \n");
    }
    return ( 0 == 0 );
}