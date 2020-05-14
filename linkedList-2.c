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
#include <malloc.h>

int main(void)
{
    DIR* dirp;
    struct dirent* direntp;
    char* userResponse = (char*) malloc(sizeof(char));

    printf("What is the path you want to search?");
    scanf("%s", userResponse);

    dirp = opendir(userResponse);
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
