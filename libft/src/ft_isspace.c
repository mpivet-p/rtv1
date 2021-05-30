int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}
