#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <malloc.h>
//#include <string.h>

int main(void)
{
    DIR* dirp;
    struct dirent* direntp;
    char* userResponse = (char*) malloc(sizeof(char));

    printf("What is the path you want to search?\n");
    scanf("%s", userResponse);

    dirp = opendir(userResponse);
    if (dirp == NULL) {
        perror( "Can't open path to dir" );
    } else {
        for(;;) {
            direntp = readdir(dirp);
            if( direntp == NULL ) break;

            if (direntp->d_name[0] == '.')
              printf("It's a hidden file or directory:  ");
              printf("%s\n", direntp->d_name);
              printf("\n");
            
        }
        
        closedir(dirp);
    }
    
    return EXIT_SUCCESS;
}
