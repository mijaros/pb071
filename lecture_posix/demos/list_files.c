#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
    DIR *directory = opendir(".");
    if (!directory) {
        perror("opendir");
        return EXIT_FAILURE;
    }
    struct dirent *act_file = readdir(directory);
    while (act_file != NULL) {
       printf("%s\n", act_file->d_name);
       act_file = readdir(directory);
    }
    closedir(directory);

    return EXIT_SUCCESS; 
}
