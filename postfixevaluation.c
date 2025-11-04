#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double compute(char symbol, double op1, double op2) {
    switch(symbol) {
        case '*': return op1 * op2;
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        default:
            printf("Invalid operator: %c\n", symbol);
            return 0.0;
    }
}

int main() {
    double stack[100];
    int top = -1;
    char postfix[100], symbol;
    double op1, op2, res;

    printf("\nEnter a valid postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];
        if (isdigit(symbol)) {
            stack[++top] = symbol - '0';   // convert char digit to number
        } else {
            op2 = stack[top--];
            op1 = stack[top--];
            res = compute(symbol, op1, op2);
            stack[++top] = res;
        }
    }

    printf("\nResult = %.2f\n", stack[top]);
    return 0;
}
