#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"
int main(int argc, char *argv[]){
    printf(1, "\n*** TEST 1: Creating regular file and testing write ***\n");
	int fd1; 
	fd1 = open("text.txt", O_CREATE | O_RDWR);
    char string1[] = "TEST 1: Checking READ/WRITE without O_EXTENT flags";
	write(fd1, string1, sizeof(string1));
    struct stat normalFile;
    int rc = fstat(fd1, &normalFile);
    if (rc != 0)
    {
       printf(2,"fstat error, retruned %d",rc);
       exit();
    }
    printf(1, "File type %d \n", normalFile.type);
    printf(1, "Number of Links %d \n", normalFile.nlink);
    printf(1, "File size %d bytes\n", normalFile.size);
	close(fd1);

	
	printf(1, "\n*** TEST 2: Creating an extent based file and testing write ***\n");
	int fd2; 
	fd2 = open("extenttest2", O_CREATE | O_RDWR | O_EXTENT);
	char string2[] = "TEST 2: Checking READ/WRITE with O_EXTENT flags";
	write(fd2, string2, sizeof(string2));

    struct stat extFileInfo;
    int rc2 = fstat(fd2, &extFileInfo);
    if (rc2 != 0)
    {
       printf(2,"fstat error, retruned %d",rc);
       exit();
    }

    printf(1, "File type %d \n", extFileInfo.type);
     printf(1, "Number of Links %d \n",extFileInfo.nlink);
    printf(1, "File size %d bytes\n", extFileInfo.size);
    
	close(fd2);
	exit();
}
