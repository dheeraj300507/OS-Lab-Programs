#include <stdio.h>
#include <string.h>

int main(void) {
    char filename[256], pattern[256], line[2048];
    printf("Enter file name: "); if (scanf("%255s", filename) != 1) return 1;
    printf("Enter pattern: "); if (scanf("%255s", pattern) != 1) return 1;
    FILE *file = fopen(filename, "r");
    if (!file) { perror("fopen"); return 1; }
    while (fgets(line, sizeof line, file)) if (strstr(line, pattern)) fputs(line, stdout);
    fclose(file); return 0;
}
