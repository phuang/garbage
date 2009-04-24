#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdio.h>

int main (int argc, char **argv)
{
    char *p;

    int fd = shmget (9999, 4096, IPC_CREAT | S_IRUSR | S_IWUSR);
    perror("shmget");
    fprintf (stderr, "fd=%d\n", fd);
    p = (char *) shmat (fd, NULL, 0);
    perror("shmat");
    fprintf (stderr, "%10s\n", p);
    if (argc > 1)
    strcpy (p, argv[1]);
}
