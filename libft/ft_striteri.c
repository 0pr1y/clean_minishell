

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
// int main(void)
// {
//     char s[] = "0000000000";
// 	ft_striteri(s, &iter);
//     printf("%s\n", s);
//     return (0);
// }
