#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct
{
    // agar bisa mengisi string juga
    char data[max][max];
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

void push(Stack **s, char *c)
{
    if ((*s)->top >= max)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    strcpy((*s)->data[++(*s)->top], c);
}

char *pop(Stack **s)
{
    if ((*s)->top < 0)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    return (*s)->data[(*s)->top--];
}

int main()
{
    char prefix[20];
    char temp[20];
    scanf("%[^\n]", prefix);

    int x = strlen(prefix) - 1;

    Stack *s;
    s = malloc(sizeof(Stack));
    s->top = -1;

    // pemrosesan membalik string
    for (int i = x; i >= 0; i--)
    {
        temp[x - i] = prefix[i];
    }
    temp[x + 1] = '\0';

    // pemrosesan postfix
    for (int i = 0; i <= x; i++)
    {
        char c = temp[i];
        if (c != ' ')
        {
            if (cek(c))
            {
                char *op1 = pop(&s);
                char *op2 = pop(&s);
                char infix[max];
                sprintf(infix, "(%s%c%s)", op1, c, op2);
                push(&s, infix);
            }
            else
            {
                char op[2] = {c, '\0'};
                push(&s, op);
            }
        }
    }

    printf("Infix: %s\n", s->data[s->top]);

    return 0;
}
