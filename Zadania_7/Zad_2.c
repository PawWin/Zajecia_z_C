#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 180
#define MAX_COLORS 3
#define MAX_COLOR_NAME_LENGTH 6  // increased by 1 to accommodate "green"

void processFile(const char *filename);

int main() {
    const char *filename = "../input2.txt";
    processFile(filename);

    return 0;
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int sum = 0;
    int min_sum = 0;
    int max_colors[] = {12, 13, 14};
    char line[MAX_LINE_LENGTH];

    int min_colors[MAX_COLORS] = {0}; // Moved outside the loop to accumulate minimum powers

    while (fgets(line, sizeof(line), file)) {
        int actual_line_len = strlen(line);
        int flag = 0;

        int game_number;
        sscanf(line + 5, "%d", &game_number);

        for (int i = 8; i < actual_line_len; i++) {
            int number;
            if (isdigit(line[i])) {
                sscanf(line + i, "%d", &number);
                while (isdigit(line[i])) i++;
            }

            char color[MAX_COLOR_NAME_LENGTH];
            sscanf(line + i, "%s", color);

            if (strncmp(color, "red", 3) == 0) {
                if (number > max_colors[0]) {
                    flag = 1;
                }
                if (number > min_colors[0]) {
                    min_colors[0] = number;
                }
            } else if (strncmp(color, "green", 5) == 0) {
                if (number > max_colors[1]) {
                    flag = 1;
                }
                if (number > min_colors[1]) {
                    min_colors[1] = number;
                }
            } else if (strncmp(color, "blue", 4) == 0) {
                if (number > max_colors[2]) {
                    flag = 1;
                }
                if (number > min_colors[2]) {
                    min_colors[2] = number;
                }
            }
        }

        printf("Minimum powers: red=%d, green=%d, blue=%d\n", min_colors[0], min_colors[1], min_colors[2]);

        int min_product = 1;
        for (int i = 0; i < MAX_COLORS; i++) {
            min_product *= min_colors[i];
        }
        min_sum += min_product;

        if (!flag) {
            sum += game_number;
        }
    }

    fclose(file);

    printf("Sum of game numbers that can be played: %d\n", sum);
    printf("Sum of powers required to play the games: %d\n", min_sum);
}
