#include "main.h"

int check(int arg, char *s);

/**
 * main - The body of the calculator
 *
 * Return: 0 if compiled successfully
 */
int main(int argc, char *argv[])
{
	/* Declaring varables that can be used in the calculator, and inserted into functions. */
	float res, prev, prev_mul, num;
	int i, c, ch;

	prev = 0;
	prev_mul = 1;

	/* checking for no arguments */
	if (argc == 1)
	{
		printf("No operation passed as arguments\n");
		printf("Usage: ./calculator <<operation>> <<argument(s)>>\n"
			"Usage: ./calculator menu\n");

		return (1);
	}

	/* Printing a menu for help */
	c = strcmp(argv[1], "menu");

	if (c == 0)
	{
		printf("To use the calculator, run:\n"
			"./calculator <<operation>> <<argument(s)>>\n");
		printf("Available functions\n"
			"Addition (add) (a) (b) (c) (...)\n"
			"Subtraction (subtract) (a) (b) (c) (...)\n"
			"Multiplication (multiply) (a) (b) (c) (...)\n"
			"Division (divide) (a) (b) (c) (...)\n"
			"Factorial (factorial) (a)\n"
			"Power (power) (a) (b)\n"
			"Converting bases (base) \n"
			"Quadratic (quadratic)\n"
			"Root (root)\n"
			"Silmultaneous (simultaneous)\n"
			);
		return (0);
	}

	c = strcmp(argv[1], "add");

	if (c == 0)
	{
		ch = check(argc, argv[1]);
		
		if (ch == 1)
			return (1);

		for (i = 2; i < argc; i++)
		{
			num = atof(argv[i]);

			res = add(prev, num);

			prev = res;
		}

		printf("The result of the addition is: %.2f\n", res);

		return (0);
	}

	c = strcmp(argv[1], "subtract");

	if (c == 0)
	{
		ch = check(argc, argv[1]);

		if (ch == 1)
			return (1);

		num = atof(argv[2]);
		for (i = 2; i < argc; i++)
		{
			/* prev = next number, starts as 0 */
			res = sub(num, prev);
			num = res;
			if (argv[i + 1])
			{
				prev = atof(argv[i + 1]);
			}
		}
		printf("The result of the subtraction is: %.2f\n", res);

		return (0);
	}

	c = strcmp(argv[1], "multiply");

	if (c == 0)
	{
		ch = check(argc, argv[1]);

		if (ch == 1)
			return (1);

		for ( i = 2; i < argc; i++)
		{
			num = atof(argv[i]);

			res = mul(prev_mul, num);

			if (res > FLT_MAX)
			{
				printf("Exceeded maximum result value\n");
				return (1);
			}

			prev_mul = res;
		}

		printf("The result of the multiplication is: %.2f\n", res);

		return (0);
	}

	c = strcmp(argv[1], "divide");

	if (c == 0)
	{
		ch = check(argc, argv[1]);

		if (ch == 1)
			return (1);

		res = divi(atof(argv[2]), atof(argv[3]));
		printf("The result of the division is: %.2f\n", res);

		return (0);
	}

	c = strcmp(argv[1], "factorial");

	if (c == 0)
	{
		ch = check(argc, argv[1]);

		if (ch == 1)
			return (1);

		for (i = 2; i < argc; i++)
		{
			res = fact(atof(argv[i]));
			printf("The factorial of %.2f is %.2f\n", atof(argv[i]), res);
		}

		return (0);
	}

	c = strcmp(argv[1], "power");

	if (c == 0)
	{
		ch = check(argc, argv[1]);

		if (ch == 1)
			return (1);

		res = _pow(atof(argv[2]), atoi(argv[3]));
		printf("%.2f raised to the power of %d is %.2f\n", atof(argv[2]), atoi(argv[3]), res);

		return (0);
	}

	printf("Error: Invalid function to calulate!\n"
			"Available functions: Name and how to call it in brackets\n\n"
			"Addition (add)\n"
			"Subtraction (subtract)\n"
			"Multiplication (multiply)\n"
			"Division (divide)\n"
			"Factorial (factorial)\n"
			"Power (power)\n");

}

/**
 * check - checks if arg is equal to 2
 * @arg: arg to check
 * @s: function name
 *
 * Return: 1 if arg is 2 and 0 otherwise
 */
int check(int arg, char *s)
{
	if (arg == 2 && s != "menu")
	{
		printf("Error: Insufficient values passed to %s function\n", s);
		return (1);
	}
	else
	{
		return (0);
	}
}
