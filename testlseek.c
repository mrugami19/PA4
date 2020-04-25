#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
    
    int fd;
    fd = open("text.txt", O_CREATE | O_RDWR );
    char *text = "This is for testing purposes. hello! test test test test\n";

    write(fd, text, strlen(text));

    if (lseek(fd, 8) < 0){
        printf(1, "Error changing pointer\n");
    }

    write(fd, "UPDATE\n", 7);
    close(fd);
    return 0; 
}