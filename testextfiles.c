#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"
int main(int argc, char *argv[]){
    printf(1, "\n*** TEST 1: Checking READ/WRITE existing file without O_EXTENT flags *** \n");
	int fd1; 
	fd1 = open("text.txt", O_CREATE | O_RDWR);
    char string1[] = "TEST 1: Checking READ/WRITE without O_EXTENT flags";
	write(fd1, string1, sizeof(string1));
	close(fd1);

	// Should work successfully since the absense of O_EXTENT leads to creation of T_FILE
	
	printf(1, "\n*** TEST 2: Checking READ/WRITE with O_EXTENT flags *** \n");
	int fd2; 
	fd2 = open("extenttest2", O_CREATE | O_RDWR | O_EXTENT);
	char string2[] = "TEST 2: Checking READ/WRITE without O_EXTENT flags";
	write(fd2, string2, sizeof(string2));
	close(fd2);
	exit();
}
