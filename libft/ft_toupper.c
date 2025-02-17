

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
// int main(void)
// {
//     printf("%c\n", ft_toupper(130));
//     return (0);
// }
