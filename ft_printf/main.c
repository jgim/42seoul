#include "ft_printf.h"
#include <stdio.h>

int main()
{

	int num = 4452591408;
	int *c = &num;

%-0 width.prec type



	printf("   printf : >%.10p<\n", 4452591408);
	ft_printf("ft_printf : >%.10p<\n", 4452591408);
	printf(">%5c<\n", '*');
	ft_printf(">%5c<\n", '*');
	printf("pt : %5p\n", 0);
	ft_printf("ft : %5p\n", 0);

	// c = '*';
	// printf(">%c<\n", c);
	// printf(">%.c<\n", c);
	// printf(">%-c<\n", c);
	// printf(">%-+c<\n", c);
	// printf(">%+c<\n", c);
	// printf(">%#c<\n", c);
	// printf(">%#-c<\n", c);
	// printf(">%#-+c<\n", c);
	// printf(">%#+c<\n", c);
	// printf(">% c<\n", c);
	// printf(">% -c<\n", c);
	// printf(">% -+c<\n", c);
	// printf(">% +c<\n", c);
	// printf(">% #c<\n", c);
	// printf(">% #-c<\n", c);
	// printf(">% #-+c<\n", c);
	// printf("1.>%5c<\n", c);
	// printf(">%.5c<\n", c);
	// printf(">%-5c<\n", c);
	// printf(">% 5c<\n", c);
	// printf(">%3c<\n", c);
	// printf(">%.3c<\n", c);
	// printf(">%10c<\n", c);
	// printf(">%.10c<\n", c);
	// printf(">%0c<\n", c);
	// printf(">%.0c<\n", c);
	// printf(">%-+0c<\n", c);
	// printf(">%+0c<\n", c);
	// printf(">%#-+0c<\n", c);
	// printf(">% #-+0c<\n", c);
	// printf(">% 05c<\n", c);
	// printf(">%03c<\n", c);
	// printf(">%-+03c<\n", c);
	// printf(">%+03c<\n", c);
	// printf(">%#-+03c<\n", c);
	// printf(">% #-+03c<\n", c);
	// printf(">%010c<\n", c);
	// printf(">%-+010c<\n", c);
	// printf(">%+010c<\n", c);
	// printf(">%#-+010c<\n", c);
	// printf(">% #-+010c<\n", c);
	// printf("\n");
	// ft_printf(">%c<\n", c);
	// ft_printf(">%.c<\n", c);
	// ft_printf(">%-c<\n", c);
	// ft_printf(">%-+c<\n", c);
	// ft_printf(">%+c<\n", c);
	// ft_printf(">%#c<\n", c);
	// ft_printf(">%#-c<\n", c);
	// ft_printf(">%#-+c<\n", c);
	// ft_printf(">%#+c<\n", c);
	// ft_printf(">% c<\n", c);
	// ft_printf(">% -c<\n", c);
	// ft_printf(">% -+c<\n", c);
	// ft_printf(">% +c<\n", c);
	// ft_printf(">% #c<\n", c);
	// ft_printf(">% #-c<\n", c);
	// ft_printf(">% #-+c<\n", c);
	// ft_printf("2.>%5c<\n", c);
	// ft_printf(">%.5c<\n", c);
	// ft_printf(">%-5c<\n", c);
	// ft_printf(">% 5c<\n", c);
	// ft_printf(">%3c<\n", c);
	// ft_printf(">%.3c<\n", c);
	// ft_printf(">%10c<\n", c);
	// ft_printf(">%.10c<\n", c);
	// ft_printf(">%0c<\n", c);
	// ft_printf(">%.0c<\n", c);
	// ft_printf(">%-+0c<\n", c);
	// ft_printf(">%+0c<\n", c);
	// ft_printf(">%#-+0c<\n", c);
	// ft_printf(">% #-+0c<\n", c);
	// ft_printf(">% 05c<\n", c);
	// ft_printf(">%03c<\n", c);
	// ft_printf(">%-+03c<\n", c);
	// ft_printf(">%+03c<\n", c);
	// ft_printf(">%#-+03c<\n", c);
	// ft_printf(">% #-+03c<\n", c);
	// ft_printf(">%010c<\n", c);
	// ft_printf(">%-+010c<\n", c);
	// ft_printf(">%+010c<\n", c);
	// ft_printf(">%#-+010c<\n", c);
	// ft_printf(">% #-+010c<\n", c);
	// // p_test
	// int num = 10;
	// int *c = '0';
	// int n = 30;

	// printf("1 >%*p<\n", n, c);
	// printf("2 >%-*p<\n", n, c);
	// printf("3 >%*.*p<\n", n, n, c); //error
	// printf("4 >%-p<\n", c);
	// printf("5 >%-.p<\n", c);
	// printf("6 >%.p<\n", c);
	// printf("7 >%10.4p<\n", c); //error
	// printf("8 >%.4p<\n", c);   //error
	// printf("9 >%.1p<\n", c);   //error
	// printf("A >%.p<\n", c);
	// printf("b >%.10p<\n", c);
	// printf("c >%5.2p<\n", c);

	// ft_printf("1 >%*p<\n", n, c);
	// ft_printf("2 >%-*p<\n", n, c);
	// ft_printf("3 >%*.*p<\n", n, n, c); //error
	// ft_printf("4 >%-p<\n", c);
	// ft_printf("5 >%-.p<\n", c);
	// ft_printf("6 >%.p<\n", c);
	// ft_printf("7 >%10.4p<\n", c); //error
	// ft_printf("8 >%.4p<\n", c);	  //error
	// ft_printf("9 >%.1p<\n", c);	  //error
	// ft_printf("A >%.p<\n", c);
	// ft_printf("b >%.10p<\n", c);
	// ft_printf("c >%5.2p<\n", c);

	// printf("%");
	// ft_printf("%");
	// return 0;
	// printf("hello, %s.\n", NULL);
	// ft_printf("hello, %s.\n", NULL);

	// printf("this %i number\n", 0);
	// ft_printf("this %i number\n", 0);
	// printf("%u\n", 4294967295u);
	// ft_printf("%u\n", 4294967295u);
	// printf("str : >%-5c<\n", '\0');
	// ft_printf("str : >%-5c<\n", '\0');
	// printf("percent : %\n");
	// printf("percent5 : %5\n");
	// printf("0percent : %05\n");
	// printf("percent -05 : %-05\n");
	// ft_printf("ft_percent : %\n");
	// ft_printf("ft_percent5 : %5\n");
	// ft_printf("ft_0percent : %05\n");
	// ft_printf("ft_percent -05 : %-05\n");

	// int main()
	// {
	printf("%05%\n");
	ft_printf("%05%\n");
	// 	return 0;
	// }
	// int main()
	// {
	printf("This is real  printf = %5d<-end\n", 52625);
	ft_printf("This is my ft_printf = %5d<-end\n", 52625);
	printf("This is real  printf = 1234567890<-end\n");
	printf("1. This is real  printf = %-5d\n", 1234567890);
	printf("2. This is real  printf = %-5.3d\n", 1234567890);
	printf("3. This is real  printf = %-3.5d\n", 1234567890);
	printf("4. This is real  printf = %-5d\n", -1234567890);
	printf("5. This is real  printf = %-5.3d\n", -1234567890);
	printf("6. This is real  printf = %-3.5d\n", -1234567890);
	printf("\n");
	printf("7. This is real  printf = %-5.10d<-end\n", 123);
	printf("8. This is real  printf = %-3.10d<-end\n", 12345);
	printf("9. This is real  printf = %-.10d<-end\n", 123);
	printf("10. This is real  printf = %-5.10d<-end\n", -123);
	printf("11. This is real  printf = %-3.10d<-end\n", -12345);
	printf("12. This is real  printf = %-.10d<-end\n", -123);
	printf("\n");
	printf("13. This is real  printf = %-10.5d<-end\n", 123);
	printf("14. This is real  printf = %-10.3d<-end\n", 12345);
	printf("15. This is real  printf = %-10d<-end\n", 123);
	printf("16. This is real  printf = %-10.4d<-end\n", -123);
	printf("17. This is real  printf = %-10.3d<-end\n", -12345);
	printf("18. This is real  printf = %-10d<-end\n", -123);
	printf("\n");
	printf("\n");
	printf("This is real  printf = 1234567890<-end\n");
	ft_printf("1. This is my ft_printf = %-5d\n", 1234567890);
	ft_printf("2. This is my ft_printf = %-5.3d\n", 1234567890);
	ft_printf("3. This is my ft_printf = %-3.5d\n", 1234567890);
	ft_printf("4. This is my ft_printf = %-5d\n", -1234567890);
	ft_printf("5. This is my ft_printf = %-5.3d\n", -1234567890);
	ft_printf("6. This is my ft_printf = %-3.5d\n", -1234567890);
	printf("\n");
	ft_printf("7. This is my ft_printf = %-5.10d\n", 123);
	ft_printf("8. This is my ft_printf = %-3.10d\n", 12345);
	ft_printf("9. This is my ft_printf = %-.10d\n", 123);
	ft_printf("10. This is my ft_printf = %-5.10d\n", -123);
	ft_printf("11. This is my ft_printf = %-3.10d\n", -12345);
	ft_printf("12. This is my ft_printf = %-.10d\n", -123);
	printf("\n");
	ft_printf("13. This is my ft_printf = %-10.5d\n", 123);
	ft_printf("14. This is my ft_printf = %-10.3d\n", 12345);
	ft_printf("15. This is my ft_printf = %-10d\n", 123);
	ft_printf("16. This is my ft_printf = %-10.4d\n", -123);
	ft_printf("17. This is my ft_printf = %-10.3d\n", -12345);
	ft_printf("18. This is my ft_printf = %-10d\n", -123);
	// // 	return 0;
	// char c;
	int a;
	int b;

	a = printf("1: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	b = ft_printf("2: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	printf("pf:%d\n", a);
	printf("ft:%d\n", b);

	// printf("-->|%-5c|<--\n", c);
	// printf("\n");
	// ft_printf("-->|%-5c|<--\n", c);
	// printf("\n");
	// printf("-->|%-2c|<--\n", c);:q!
	// printf("-->|%-1.c|<--\n", c);
	// printf("-->|%-1c|<--\n", c);
	// printf("-->|%.c|<--\n", c);
	// printf("-->|%c|<--\n", c);
	// printf("\n");

	// ft_printf("-->|%-2c|<--\n", c);
	// ft_printf("-->|%-1.c|<--\n", c);
	// ft_printf("-->|%-1c|<--\n", c);
	// ft_printf("-->|%.c|<--\n", c);
	// ft_printf("-->|%c|<--\n", c);
	// printf("\n");
	// printf("\n");
	// printf("\n");

	// printf("-->|%-2.c|<--\n", c);
	// printf("-->|%-2c|<--\n", c);
	// printf("-->|%-1.c|<--\n", c);
	// printf("-->|%-1c|<--\n", c);
	// printf("-->|%.c|<--\n", c);
	// printf("\n");
	// ft_printf("-->|%-2.c|<--\n", c);
	// ft_printf("-->|%-2c|<--\n", c);
	// ft_printf("-->|%-1.c|<--\n", c);
	// ft_printf("-->|%-1c|<--\n", c);
	// ft_printf("-->|%.c|<--\n", c);
	return 0;
}
