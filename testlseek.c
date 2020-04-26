#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
    
    int fd;
    
    fd = open("text.txt", O_CREATE | O_RDWR );
    

    write(fd, "This is for testing purposes. hello! test test test test\n" , 60);

    if (lseek(fd, 8) < 0){
        printf(1, "Error changing pointer\n");
    }
    // invalid offset
    int boff = lseek(fd, -1);
    if (boff < 0){
        printf(1, "lseek() failed: invalid offset\n");
    }

    //invalid file descriptor
    int bfd = lseek(-1, 4);
     if (bfd < 0){
        printf(1, "lseek() failed: invalid file desriptor\n");
    }

    write(fd, "UPDATE\n", 7);
    close(fd);

    int fd2; 
	fd2 = open("lseek.txt", O_CREATE | O_RDWR | O_EXTENT);
    char string[] = "Testing: Checking lseek functionality with EXTENT files ";
    write(fd2, string, sizeof(string));
	lseek(fd2, 4);
	char string2[] = "NEW\n";
	write(fd2, string2, sizeof(string2));
	close(fd2);

    return 0; 
}


