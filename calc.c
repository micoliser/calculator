#include "main.h"

/**
 * main - The body of the calculator
 *
 * Return: 0 if compiled successfully
 */
int main(void)
{
	/* Declaring varables that can be used in the calculator, and inserted into functions. */
	float a, b, c, d, e, f, h;
	char op;

	printf("A Calculator written in C\n");
	printf("Enter a letter to perform an operation\n"
			"Operations:\n"
			"0 - (x) - Exit\n"
			"1 - (a) - Addition\n"
			"2 - (s) - Subtraction\n"
			"3 - (m) - Multiplication\n"
			"4 - (d) - Division\n"
			"5 - (p) - Power\n"
			"6 - (f) - Factorial\n"
			"7 - (r) - Root\n"
			"8 - (q) - Quadratic\n"
			"9 - (l) - Simultaneous\n");
	scanf("%c", &op);

	while (op != 'x')
	{
		if (op == 'a')
		{
			printf("Enter two numbers to be added\n");
			scanf("%f %f", &a, &b);
			h = add(a, b);
		}
		else if (op == 's')
		{
			printf("Enter two numbers to be subtracted\n");
			scanf("%f %f", &a, &b);
			h = sub(a, b);
		}
		else if (op == 'm')
		{
			printf("Enter two numbers to be multiplied\n");
			scanf("%f %f", &a, &b);
			h = mul(a, b);
		}
		else if (op == 'd')
		{
			printf("Enter two numbers to be divided\n");
			scanf("%f %f", &a, &b);
			h = div(a, b);
		}
		else if (op == 'p')
		{
			printf("Enter two numbers to find a to the power of b\n");
			scanf("%f %f", &a, &b);
			h = powr(a, b);
		}
		else if (op == 'f')
		{
			printf("Enter a number to find its factorial\n");
			scanf("%f", &a);
			h = fact(a);
		}
		else if (op == 'q')
		{
			printf("Enter coefficients of x2, x1 and x0\n");
			scanf("%f %f %f", &a, &b, &c);
			quad(a, b, c);
		}
		else if (op == 'l')
		{
			printf("Enter coefficients of the simultaneoys equation\n");
			scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
			simu(a, b, c, d, e, f);
		}
		else
		{
			printf("%.2f was the last result\n", h);
		}

		printf("\nEnter a new operation or exit\n");
		scanf("%c", &op);
	}

	return (0);
}
