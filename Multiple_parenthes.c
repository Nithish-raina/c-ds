#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    char * arr;
};

int isFull(struct stack * s) {
    if(s->top == s->size - 1) {
        return 1;
    }
    return 0;
}
int isEmpty(struct stack * s) {
    if(s->top == -1) {
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

char pop(struct stack * s) {
    char del;
    if(isEmpty(s)) {
        printf("STACK UNDERFLOW ");
    }
    else{
        del = s->arr[s->top];
        s->top--;
    }
    return del;
}
int isMatch(char ch_1, char ch_2) {
    if(ch_1 == ')' && ch_2 == '(') {
        return 1;
    }
    else if(ch_1 == '}' && ch_2 == '{') {
        return 1;
    }
    else if(ch_1 == ']' && ch_2 == '[') {
        return 1;
    }
    else {
        return 0;
    }
}
char stackTop(struct stack * s) {
    return s->arr[s->top];
}
int findParentheses(char * exp) {
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 20;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int i = 0;
    while(exp[i] != '\0') {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(s,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(isEmpty(s)) {
                return -1;
            }
            else if(isMatch(exp[i],stackTop(s))) {
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
    char * exp = "({[]})";
    int res = findParentheses(exp);
    if(res == 1) {
        printf("BALANCED PARANTHESES \n");
    }
    else {
        printf("UNBALANCED PARENTHESES \n");
    }
    return ( 0 == 0 );

}