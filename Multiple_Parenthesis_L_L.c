#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node * next;
};

struct node * top = NULL;


int isFull(struct node * s) {
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(struct node * s) {
    if(top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
void push(struct node * s, char ch) {
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ch;
    //newnode->next = NULL;
    if(isFull(top)) {
        printf("STACK OVERFLOW \n");
    }
    else {
        if(top == NULL) {
            top = newnode;
        }
        else {
            printf("PUSHING CHARACTER TO THE STACK %c\n",ch);
            newnode->next = top;
            top = newnode;
        }
    }
}
void pop(struct node * s) {
    if(isEmpty(top)) {
        printf("STACK UNDERFLOW \n");
    }
    else {
        struct node * temp = top;
        char item = temp->data;
        top = top->next;
        free(temp);
        printf("DELETED CHARACTER IS %c\n",item);         
    }
}

int stackTop(struct node * s) {
    return top->data;
}

int isMatch(char ch_1, char ch_2) {
    if(ch_1 == ')' && ch_2 == '(') {
        return 1;
    }
    else  if(ch_1 == '}' && ch_2 == '{') {
        return 1;
    }
    else if(ch_1 == ']' && ch_2 == '[') {
        return 1;
    }
    else {
        return 0;
    }
}
int findParenthesis(char * exp) {
    struct node * s = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    while(exp[i] != '\0') {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(s,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] ==  '}' || exp[i] == ']') {
            if(isEmpty(s)) {
                return -1;
            }
            else if(isMatch(exp[i], stackTop(s))){
                pop(s);
            }
            else {
                break;
            }
        }
        i++;
    }
    if(isEmpty(s)) {
        return 1;
    }
    return 0;
}
int main()
{
    char * exp = "({[]})()";
    // printf("ENTER YOUR EXPRESSION \n");
    // scanf("%d",&expression);
    int res = findParenthesis(exp);
    if(res == 1) {
        printf("BALANCED PARENTHESIS \n");
    }
    else {
        printf("UNBALANCED PARENTHESIS \n");
    }
    return ( 0 == 0 );
}