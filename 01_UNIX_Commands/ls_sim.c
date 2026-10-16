#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char path[256];
    printf("Enter directory name: ");
    if (scanf("%255s", path) != 1) return 1;
    DIR *dir = opendir(path);
    if (!dir) { perror("opendir"); return 1; }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) puts(entry->d_name);
    closedir(dir);
    return 0;
}
