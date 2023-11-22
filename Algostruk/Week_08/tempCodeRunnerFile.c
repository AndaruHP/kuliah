#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct
{
    char data[max];
    int top;
} Stack;

int cek(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(Stack *s, char c[max])
{
    if (s->top >= max)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = c;
}

char pop(Stack *s)
{
    if (s->top < 0)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

int main()
{
    char prefix[20];
    char temp[20];
    scanf("%[^\n]", prefix);

    int x = strlen(prefix) - 1;

    Stack s;
    s.top = -1;

    // pemrosesan membalik string
    for (int i = x; i >= 0; i--)
    {
        temp[x - i] = prefix[i];
    }
    temp[x + 1] = '\0';
    printf("%s\n", temp);

    // pemrosesan postfix
    for (int i = 0; i <= x; i++)
    {
        char c = temp[i];
        if (cek(c))
        {
            char op1 = pop(&s);
            char op2 = pop(&s);
            char infix[max];
            sprintf(infix, "(%c%c%c)", op1, c, op2);
            push(&s, infix[max]);
        }
        else
        {
            push(&s, c);
        }
    }

    printf("Infix: %c\n", s.data[s.top]);

    return 0;
}
