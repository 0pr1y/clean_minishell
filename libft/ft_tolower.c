

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
// int main(void)
// {
//     printf("%c\n", ft_tolower(66));
//     return (0);
// }
