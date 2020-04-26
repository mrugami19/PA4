#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
    
    int fd;
    //int nvfd = -1;
    //int boff=-1;
    // printf(1, "about to open\n");
    fd = open("text.txt", O_CREATE | O_RDWR );
    //ßprintf(1, "did open\n");

    write(fd, "This is for testing purposes. hello! test test test test\n" , 60);

    if (lseek(fd, 8) < 0){
        printf(1, "Error changing pointer\n");
    }
    // invalid offset
    if (lseek(fd, -1) < 0){
        printf(1, "Error changing pointer: invalid offset\n");
    }
    //invalid file descriptor
     if (lseek(-1, 4) < 0){
        printf(1, "Error changing pointer: invalid file desriptor\n");
    }

    write(fd, "UPDATE\n", 7);
    close(fd);
    return 0; 
}


