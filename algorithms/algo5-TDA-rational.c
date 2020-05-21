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

typedef struct ratio{
    int N;
    int D;
} ratio;

int commomDivisor(int numerator, int denominator)
{
    int gcd, remainder;

    while (numerator != 0) {
        remainder = denominator % numerator;
        denominator = numerator;
        numerator = remainder;
    }

    gcd = denominator;
    return gcd;
}

ratio simplifyRatio(ratio r)
{
    int resultCD = commomDivisor(r.N, r.D);

    r.N = r.N / resultCD;
    r.D = r.D / resultCD;
    
    return r;
}

int main()
{
    int N, i;
    char operator;
    ratio R1, R2, R3, result;
    scanf("%d", &N);

    for (i = 0; i < N; ++i) {
        scanf("%d / %d %c %d / %d", &R1.N, &R1.D, &operator, &R2.N, &R2.D);

        switch (operator) {
            case '+':
                R3.N = R1.N * R2.D + R2.N * R1.D;
                R3.D = R1.D * R2.D;
                break;
            
            case '-':
                R3.N = R1.N * R2.D - R2.N * R1.D;
                R3.D = R1.D * R2.D;
                break;

            case '*':
                R3.N = R1.N * R2.N;
                R3.D = R1.D * R2.D;
                break;

            case '/':
                R3.N = R1.N * R2.D;
                R3.D = R1.D * R2.N;
                break;
        }
        result = simplifyRatio(R3);
        printf("%d/%d = %d/%d\n", R3.N, R3.D, result.N, result.D);
    }
    return 0;
}