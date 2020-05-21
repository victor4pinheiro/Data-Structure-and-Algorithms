// You were invited to do a little job for your Mathematic teacher. The job is to read a Mathematic expression in format of two rational numbers (numerator / denominator) and present the result of the operation. Each operand or operator is separated by a blank space. The input sequence (each line) must respect the following format: number, (‘/’ char), number, operation char (‘/’, ‘*’, ‘+’, ‘-‘), number, (‘/’ char), number. The answer must be presented followed by ‘=’ operator and the simplified answer. If the answer can’t be simplified, it must be repeated after a ‘=’ operator.

// Considering N1 and D1 as numerator and denominator of the first fraction, follow the orientation about how to do each one of these 4 operations:

// Sum: (N1*D2 + N2*D1) / (D1*D2)
// Subtraction: (N1*D2 - N2*D1) / (D1*D2)
// Multiplication: (N1*N2) / (D1*D2)
// Division: (N1/D1) / (N2/D2), that means (N1*D2)/(N2*D1)

// Input
// The input contains several cases of test. The first value is an integer N (1 ≤ N ≤ 1*104), indicating the amount of cases of test that must be read. Each case of test contains a rational value X (1 ≤ X ≤ 1000), an operation (-, +, * or /) and another rational value Y (1 ≤ Y ≤ 1000).

// Output
// The output must be a rational number, followed by a “=“ sign and another rational number, that is the simplification of the first value. In case of the first value can’t be simplified, the same value must be repeated after the ‘=’ sign.

#include <stdio.h>

int gcd(int n, int m)
{
    int gcd, remainder;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    gcd = m;

    return gcd;
}

int main()
{
    int N; // Amount of cases of test that must be read
    int X[2];
    int Y[2];
    int i;
    char operator;

    scanf("%i", &N);

    int number1, number2, newNumerator, newDenominator;

    for (i = 0; i < N; i++) {
        scanf("%i / %i %c %i / %i", &X[0], &X[1], &operator, &Y[0], &Y[1]);

        switch (operator)
        {
            case '+':
                number1 = X[0]*Y[1] + Y[0]*X[1];
                number2 = X[1]*Y[1];
                newNumerator = number1 / gcd(number1, number2);
                newDenominator = number2 / gcd(number1, number2);
                printf("%i/%i = %i/%i\n", number1, number2, newNumerator, newDenominator);
                break;

            case '-':
                number1 = X[0]*Y[1] - X[1]*Y[0];
                number2 = X[1] * Y[1];
                newNumerator = number1 / gcd(number1, number2);
                newDenominator = number2 / gcd(number1, number2);
                printf("%i/%i = %i/%i\n", number1, number2, newNumerator, newDenominator);
                break;

            case '*':
                number1 = X[0] * Y[0];
                number2 = X[1] * Y[1];
                newNumerator = number1 / gcd(number1, number2);
                newDenominator = number2 / gcd(number1, number2);
                printf("%i/%i = %i/%i\n", number1, number2, newNumerator, newDenominator);
                break;

            case '/':
                number1 = X[0] * Y[1];
                number2 = X[1] * Y[0];
                newNumerator = number1 / gcd(number1, number2);
                newDenominator = number2 / gcd(number1, number2);
                printf("%i/%i = %i/%i\n", number1, number2, newNumerator, newDenominator);
                break;
        }
    }

    return 0;
}

