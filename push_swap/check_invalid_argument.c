#include "push_swap.h"

int		check_ascending(t_stack a)
{
	while(--a.length)
	{
		if (a.top->data.value > a.top->down->data.value)
			return (1);
		a.top = a.top->down;
	}
	return (0);
}
int		check_num(const char *str)
{
    int i;

    i = -1;
    if (str[0] == '-' || str[0] == '+')
        ++i;
    while (str[++i])
    {
        if (!('0' <= str[i] && str[i] <= '9'))
            return (0);
    }
    return (1);
}

int 	check_int(char *str)
{
    if (str[0] == '+' || ('0' <= str[0] && str[0] <= '9'))
    {
        if (ft_atoi(str) < 0)
            return (0);
    }
    else if (str[0] == '-')
    {
        if (ft_atoi(str) >= 0)
            return (0);
    }
    return (1);
}
