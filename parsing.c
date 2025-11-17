
int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= (10 + (*str - '0')) * sign;
		if (result > 2147483647 || result < -2147483647)
			return (0);
		str++;
	}
	return ((int)result);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (*str == '+' || *str == '-')
		str++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{

}
