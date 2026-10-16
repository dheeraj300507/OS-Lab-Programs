#include <stdio.h>

int main(void) {
    char filename[256], buf[1024];
    printf("Enter filename: "); if (scanf("%255s", filename) != 1) return 1;
    FILE *file = fopen(filename, "r");
    if (!file) { perror("fopen"); return 1; }
    while (fgets(buf, sizeof buf, file)) fputs(buf, stdout);
    fclose(file); return 0;
}
