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
    if(s->top == s->size - 1) {
        return 1;
    }
    return 0;
}
void push(struct stack * s, char ch) {
    if(isFull(s)) {
        printf("STACK OVERFLOW \n");
    }
    else {
        s->top++;
        s->arr[s->top] = ch;
    }
}

void pop(struct stack * s) {
    if(isEmpty(s)) {
        printf("STACK UNDERFLOW \n");
    }
    else {
        char del_ele = s->arr[s->top];
        s->top--;
        printf("DELTED ITEM IS %c\n",del_ele);
    }
}
//precedence table 
int operator(char ch) {
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}
int precedence(char ch) {
    if(ch == '(' || ch == ')') {
        return 3;
    }
    if(ch == '*' || ch == '/') {
        return 2;
    }
    if(ch == '+' || ch == '-') {
        return 1;
    } 
    return 0;
}

int stackTop(struct stack * s) {
    return s->arr[s->top];
}
char inToPo(char * inExp) {
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char * pos = (char *)malloc(s->size  * sizeof(char));
    int i = 0;
    int j = 0;
    while(inExp[i] != '\0') {
        if(!operator(inExp[i])) {
            pos[j] = inExp[i];
            j++;
            i++;
        }
        else {
            if(precedence(inExp[i]) > precedence(stackTop(s))) {
                push(s,inExp[i]);                              
                i++;    
            }
            else {
                pos[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)) {
        pos[j] = pop(s);
        j++;
    } 
    return 1;
}


int main()
{
    char * exp = "a+b(5-6)+3(2-3)+5";
    printf("%d",inToPo(exp));
    return ( 0 == 0 );

}