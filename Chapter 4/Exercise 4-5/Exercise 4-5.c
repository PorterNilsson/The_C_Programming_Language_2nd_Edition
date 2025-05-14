/* Exercise  4-5.  Add  access  to  library  functions  like  sin,  exp,  and  pow.  See  <math.h>  in  Appendix B, Section 4. */

/* ----- FILE 1 ----- */

#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <math.h>
#include <string.h>

#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define MATH_FUNC '1'

int getop(char []);
void push(double);
double pop(void);
void print_top(unsigned int);
void duplicate_stack();
void swap();
void clear();

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        printf("Operator/Operand: %s\n", s);
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break; 
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divsor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case MATH_FUNC:
                if (strcmp(s, "sin") == 0) {
                    push(sin(pop()));
                }
                else if (strcmp(s, "exp") == 0) {
                    push(exp(pop()));
                }   
                else if (strcmp(s, "pow") == 0) {
                    op2 = pop();
                    push(pow(pop(), op2));
                }
                else {
                   printf("error: unknown command %s\n", s); 
                }
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    printf("Stack Top:\n");
    print_top(3);

    duplicate_stack();

    swap();
    printf("Stack After Swapping the Top Two Elements:\n");
    print_top(3);

    clear();

    return 0;
}

/* ----- FILE 2 ----- */

#define MAXVAL  100  /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */     /* push:  push f onto value stack */
double new_stack[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* print_top: print the top n values on the stack */
void print_top(unsigned int n) {
    int index = sp - 1;
    int i = 1;
    while (index >= 0 && n > 0) {
        printf("%u: %f\n", i, val[index]);
        ++i;
        --index;
        --n;
    }
}

void duplicate_stack() {
    for (int i = 0; i < sp; i++) {
        new_stack[i] = val[i];
    }

    return;
}

void swap() {
    if (sp < 2) {
        return;
    } 
    else {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }

    return;
}

void clear() {
    sp = 0;
    return;
}

/* ----- FILE 3 ----- */

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop:  get next character or numeric operand */
int getop(char s[]) {
    int i, c, temp;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    temp = getch();
    if (!isdigit(c) && !isdigit(temp)) {
        ungetch(temp);
        
        i = 1;
        while ((c = getch()) != ' ' && c != '\t' && c != EOF) {
            s[i++] = c;
        }
        s[i] = '\0';

        if (i > 1) {
            return MATH_FUNC;
        }
        else {
            return s[0];      /* not a number */
        }
    }
    ungetch(temp);
    i = 0;
    if (isdigit(c) || c == '-')    /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* ----- FILE 4 ----- */

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void) { /* get a (possibly pushed-back) character */        
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
