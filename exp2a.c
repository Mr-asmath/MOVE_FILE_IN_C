#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd1, fd2, i;
    char buf[2];

    if (argc < 3) {
        printf("Usage: %s file1.txt file2.txt\n", argv[0]);
        return 1;
    }

    char *f1 = argv[1];
    char *f2 = argv[2];

    printf("\n File 1 = %s File 2 = %s\n", f1, f2);

    fd1 = open(f1, O_RDONLY);
    if (fd1 < 0) {
        perror("Error opening source file");
        return 1;
    }

    fd2 = creat(f2, 0777);
    if (fd2 < 0) {
        perror("Error creating destination file");
        close(fd1);
        return 1;
    }

    while ((i = read(fd1, buf, 1)) > 0) {
        write(fd2, buf, 1);
    }

    close(fd1);
    close(fd2);

    if (unlink(f1) != 0) {
        perror("Error deleting source file");
    }

    return 0;
}

