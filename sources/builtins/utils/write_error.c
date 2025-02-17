#include "../../../includes/minishell.h"

void	write_error(const char *header, const char *error_message)
{
	write(STDERR_FILENO, header, ft_strlen(header));
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	write(STDERR_FILENO, "\n", 1);
}
