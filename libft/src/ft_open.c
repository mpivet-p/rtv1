#include <fcntl.h>

int	ft_open(char *path, int flags, int *fd)
{
	*fd = open(path, flags);
	return (*fd);
}
