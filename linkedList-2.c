// Functions:
//  Initialize the application
//  List all processes of PC
//  Search a process
//  Create a process
//  Delete a process
//  Restart the RAM (restart the application)

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void)
{
    DIR* dirp;
    struct dirent* direntp;

    dirp = opendir("/path/to/dir/");
    if (dirp == NULL) {
        perror( "Can't open path to dir" );
    } else {
        for(;;) {
            direntp = readdir(dirp);
            if( direntp == NULL ) break;

            printf( "%s\n", direntp->d_name );
        }
        
        closedir(dirp);
    }
    
    return EXIT_SUCCESS;
}
