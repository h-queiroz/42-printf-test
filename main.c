#include "../ft_printf.h"
#include <stdio.h>
#include <assert.h>

void	test_returns(int og_return, int my_return)
{
	if (og_return != my_return)
	{
		printf("OG return: %d\n", og_return);
		printf("MY return: %d\n", my_return);
	}
	assert(og_return == my_return);
	printf("Return: %d\n\n", my_return);
}

int	main(void)
{
	int og_return;
	int my_return;

	/***************/
	/* Testing %c  */
	/***************/
	char c = 'a';
	ft_printf("Test 1: CHAR as sole argument, with a COMMON LETTER.\n");
	og_return =    printf("OG: Should be char \'c\': \'%c\'\n", c);
	my_return = ft_printf("MY: Should be char \'c\': \'%c\'\n", c);
	test_returns(og_return, my_return);

	c = '\n';
	ft_printf("Test 2: CHAR as sole argument, with BREAK LINE character.\n");
	og_return =    printf("OG: Should be char \'\\n\': \'%c\'\n", c);
	my_return = ft_printf("MY: Should be char \'\\n\': \'%c\'\n", c);
	test_returns(og_return, my_return);

	c = '\0';
	ft_printf("Test 3: CHAR as sole argument, with NULL TERMINATOR.\n");
	og_return =    printf("OG: Should be empty: \'%c\'\n", c);
	my_return = ft_printf("MY: Should be empty: \'%c\'\n", c);
	test_returns(og_return, my_return);

	c = '8';
	ft_printf("Test 4: CHAR as sole argument, with NUMBER CHARACTER.\n");
	og_return =    printf("OG: Should be char \'8\': \'%c\'\n", c);
	my_return = ft_printf("MY: Should be char \'8\': \'%c\'\n", c);
	test_returns(og_return, my_return);

	c = 40; // Char '('
	ft_printf("Test 5: CHAR as sole argument, with DIGIT instead of LETTER.\n");
	og_return =    printf("OG: Should be char \'\(\': \'%c\'\n", c);
	my_return = ft_printf("MY: Should be char \'\(\': \'%c\'\n", c);
	test_returns(og_return, my_return);

	/***************/
	/* Testing %s  */
	/***************/
	const char *str = "Rest in Piece";
	ft_printf("Test 6: %s\n", "STRING as sole argument, with COMMON TEXT.");
	og_return =    printf("OG: Should be string \"Rest in Piece\": \"%s\"\n", str);
	my_return = ft_printf("MY: Should be string \"Rest in Piece\": \"%s\"\n", str);
	test_returns(og_return, my_return);

	str = "";
	ft_printf("Test 7: %s\n", "STRING as sole argument, with EMPTY STRING.");
	og_return =    printf("OG: Should be empty: \"%s\"\n", str);
	my_return = ft_printf("MY: Should be empty: \"%s\"\n", str);
	test_returns(og_return, my_return);

	str = "\0";
	ft_printf("Test 8: %s\n", "STRING as sole argument, with NULL TERMINATOR at the start.");
	og_return =    printf("OG: Should be empty: \"%s\"\n", str);
	my_return = ft_printf("MY: Should be empty: \"%s\"\n", str);
	test_returns(og_return, my_return);

	/***************/
	/* Testing %p  */
	/***************/
	// I know this is wrong, but just don't know how it behaves yet.
	int p = 4242428;
	printf("Test 9: POINTER as sole argument, with POSITIVE NUMBER.\n");
	og_return =    printf("OG: Should be int \"0x40BBFC\": \"%p\"\n", &p);
	my_return = ft_printf("MY: Should be int \"0x40BBFC\": \"%p\"\n", &p);
	test_returns(og_return, my_return);

	/***************/
	/* Testing %d  */
	/***************/
	int d = 4047;
	printf("Test 10: INT as sole argument, with POSITIVE NUMBER.\n");
	og_return =    printf("OG: Should be int \"4047\": \"%d\"\n", d);
	my_return = ft_printf("MY: Should be int \"4047\": \"%d\"\n", d);
	test_returns(og_return, my_return);

	d = -833;
	printf("Test 11: INT as sole argument, with NEGATIVE number.\n");
	og_return =    printf("OG: Should be int \"-833\": \"%d\"\n", d);
	my_return = ft_printf("MY: Should be int \"-833\": \"%d\"\n", d);
	test_returns(og_return, my_return);

	d = 0;
	printf("Test 12: INT as sole argument, with ZERO.\n");
	og_return =    printf("OG: Should be int \"0\": \"%d\"\n", d);
	my_return = ft_printf("MY: Should be int \"0\": \"%d\"\n", d);
	test_returns(og_return, my_return);

	d = 2147483647;
	printf("Test 13: INT as sole argument, with INT_MAX.\n");
	og_return =    printf("OG: Should be int \"2147483647\": \"%d\"\n", d);
	my_return = ft_printf("MY: Should be int \"2147483647\": \"%d\"\n", d);
	test_returns(og_return, my_return);

	d = -2147483648;
	printf("Test 14: INT as sole argument, with INT_MIN.\n");
	og_return =    printf("OG: Should be int \"-2147483648\": \"%d\"\n", d);
	my_return = ft_printf("MY: Should be int \"-2147483648\": \"%d\"\n", d);
	test_returns(og_return, my_return);

	d = 0000021;
	printf("Test 15: INT as sole argument, with POSITIVE number and LEADING ZEROS.\n");
	og_return =    printf("OG: Should be int \"21\": \"%d\"\n", d);
	my_return = ft_printf("MY: Should be int \"21\": \"%d\"\n", d);
	test_returns(og_return, my_return);

	d = -0000066;
	printf("Test 16: INT as sole argument, with NEGATIVE number and LEADING ZEROS.\n");
	og_return =    printf("OG: Should be int \"-66\": \"%d\"\n", d);
	my_return = ft_printf("MY: Should be int \"-66\": \"%d\"\n", d);
	test_returns(og_return, my_return);
	
	/***************/
	/* Testing %i  */
	/***************/
	int i = 5;
	printf("Test 17: INT as sole argument, but using %%i instead of %%d.\n");
	og_return =    printf("OG: Should be int \"5\": \"%i\"\n", i);
	my_return = ft_printf("MY: Should be int \"5\": \"%i\"\n", i);
	test_returns(og_return, my_return);

	/***************/
	/* Testing %u  */
	/***************/
	unsigned int u = 1234;
	printf("Test 18: UNSIGNED INT as sole argument, with POSITIVE number\n");
	og_return =    printf("OG: Should be unsinged int \"1234\": \"%u\"\n", u);
	my_return = ft_printf("MY: Should be unsigned int \"1234\": \"%u\"\n", u);
	test_returns(og_return, my_return);

	// Isn't working on mine yet.
	u = -43;
	printf("Test 19: UNSIGNED INT as sole argument, with NEGATIVE number\n");
	og_return =    printf("OG: Should be unsinged int \"-43\": \"%u\"\n", u);
	my_return = ft_printf("MY: Should be unsigned int \"-43\": \"%u\"\n", u);
	test_returns(og_return, my_return);

	u = 0;
	printf("Test 20: UNSIGNED INT as sole argument, with ZERO\n");
	og_return =    printf("OG: Should be unsinged int \"0\": \"%u\"\n", u);
	my_return = ft_printf("MY: Should be unsigned int \"0\": \"%u\"\n", u);
	test_returns(og_return, my_return);


	/***************/
	/* Testing %x  */
	/***************/
	int x = 564213;
	printf("Test 21: LOWER HEX as sole argument, with POSITIVE number.\n");
	og_return =    printf("OG: Should be string \"89bf5\": \"%x\"\n", x);
	my_return = ft_printf("MY: Should be string \"89bf5\": \"%x\"\n", x);
	test_returns(og_return, my_return);

	x = -3254;
	printf("Test 22: LOWER HEX as sole argument, with NEGATIVE number.\n");
	og_return =    printf("OG: Should be string \"-cb6\": \"%x\"\n", x);
	my_return = ft_printf("MY: Should be string \"-cb6\": \"%x\"\n", x);
	test_returns(og_return, my_return);

	x = 0;
	printf("Test 23: LOWER HEX as sole argument, with ZERO.\n");
	og_return =    printf("OG: Should be zero: \"%x\"\n", x);
	my_return = ft_printf("MY: Should be zero: \"%x\"\n", x);
	test_returns(og_return, my_return);

	x = 000312;
	printf("Test 24: LOWER HEX as sole argument, with POSITIVE number and ZERO.\n");
	og_return =    printf("OG: Should be \"138\": \"%x\"\n", x);
	my_return = ft_printf("MY: Should be \"138\": \"%x\"\n", x);
	test_returns(og_return, my_return);

	x = -000432;
	printf("Test 25: LOWER HEX as sole argument, with NEGATIVE number and ZERO.\n");
	og_return =    printf("OG: Should be \"-1b0\": \"%x\"\n", x);
	my_return = ft_printf("MY: Should be \"-1b0\": \"%x\"\n", x);
	test_returns(og_return, my_return);

	/***************/
	/* Testing %X  */
	/***************/
	int X = 564213;
	printf("Test 26: UPPER HEX as sole argument, with POSITIVE number.\n");
	og_return =    printf("OG: Should be string \"89BF5\": \"%X\"\n", X);
	my_return = ft_printf("MY: Should be string \"89BF5\": \"%X\"\n", X);
	test_returns(og_return, my_return);

	X = -3254;
	printf("Test 27: UPPER HEX as sole argument, with NEGATIVE number.\n");
	og_return =    printf("OG: Should be string \"-CB6\": \"%X\"\n", X);
	my_return = ft_printf("MY: Should be string \"-CB6\": \"%X\"\n", X);
	test_returns(og_return, my_return);

	X = 0;
	printf("Test 28: UPPER HEX as sole argument, with ZERO.\n");
	og_return =    printf("OG: Should be zero: \"%X\"\n", X);
	my_return = ft_printf("MY: Should be zero: \"%X\"\n", X);
	test_returns(og_return, my_return);

	X = 000312;
	printf("Test 29: UPPER HEX as sole argument, with POSITIVE number and ZERO.\n");
	og_return =    printf("OG: Should be \"138\": \"%X\"\n", X);
	my_return = ft_printf("MY: Should be \"138\": \"%X\"\n", X);
	test_returns(og_return, my_return);

	X = -000432;
	printf("Test 30: UPPER HEX as sole argument, with NEGATIVE number and ZERO.\n");
	og_return = ft_printf("MY: Should be \"-1B0\": \"%X\"\n", X);
	my_return = ft_printf("MY: Should be \"-1B0\": \"%X\"\n", X);
	test_returns(og_return, my_return);

	/***************/
	/* Testing %%  */
	/***************/
	printf("Test 31: Percent Sign\n");
	og_return =    printf("OG: Should be a single percent sign: \'%%\'\n");
	my_return = ft_printf("MY: Should be a single percent sign: \'%%\'\n");
	test_returns(og_return, my_return);

    return (0);
}
