#include "get_next_line.h"

// static void ft_strdel(char **str) {
// 	if (*str) {
// 		free(*str);
// 		*str = NULL;
// 	}
// }

int recurse(int fd, char **line, int depth) {
	ssize_t ret;
	char buf[1];

	buf[0] = '\0';
	if ((ret = read(fd, buf, 1)) < 0) {
		write(2, "read error\n", strlen("read error\n"));
		return (ret);
	}

	if (buf[0] == '\n')
		buf[0] = '\0';
	if (buf[0] == '\0') {
		*line = malloc(sizeof(char *) * (depth + 1));
		if (!*line) {
			write(2, "allocation error\n", strlen("allocation error\n"));
			return (1);
		}
	}
	else {
		recurse(fd, line, depth + 1);
	}

	(*line)[depth] = buf[0];

	return (ret);
}

int get_next_line(int fd, char **line) {
	return (recurse(fd, line, 0));
}

// int main(int argc, char **argv) {
// 	if (argc != 2)
// 		return (0);
// 	(void)argv;

// 	char *line;

// 	int fd = open(argv[1], O_RDONLY);
// 	while (get_next_line(fd, &line) > 0) {
// 		printf("|%s|\n", line);
// 		ft_strdel(&line);
// 	}
// 	if (line) {
// 		printf("|%s|\n", line);
// 		ft_strdel(&line);
// 	}
	
// 	close(fd);
// 	return (0);
// }
