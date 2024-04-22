#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int wordToNumber(char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; // -1 in case of no match
}

int calculateEnergySum(const char *filename, int option) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }
    char* words[] = {"zero","one", "two", "three" ,"four", "five" ,"six" ,"seven", "eight", "nine"};

    int sum = 0;
    char line[80];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        int number_front = -1;
        int number_back = -1;
        int actual_line_len = strlen(line);

        if (option == 1) {
            // Check from the beginning
            for (int i = 0; i < actual_line_len; i++) {
                if (isdigit(line[i])) {
                    number_front = line[i] - '0';
                    break;
                }
            }
            // Check from the end
            for (int i = actual_line_len - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    number_back = line[i] - '0';
                    break;
                }
            }
        } else if (option == 2) {
            // Check from the beginning and end for words
            for (int i = 0; i < actual_line_len; i++) {
                if (isdigit(line[i])) {
                    number_front = line[i] - '0';
                    break;
                } else {
                    for (int j = 0; j < 10; j++) {
                        if (strncmp(&line[i], words[j], strlen(words[j])) == 0) {
                            number_front = wordToNumber(words[j]);
                            break;
                        }
                    }
                    if (number_front != -1) {
                        break;
                    }
                }
            }
            for (int i = actual_line_len - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    number_back = line[i] - '0';
                    break;
                } else {
                    for (int j = 0; j < 10; j++) {
                        if (strncmp(&line[i], words[j], strlen(words[j])) == 0) {
                            number_back = wordToNumber(words[j]);
                            break;
                        }
                    }
                    if (number_back != -1) {
                        break;
                    }
                }
            }
        }

        sum += (number_front * 10) + number_back;
    }

    fclose(file);
    return sum;
}

int main() {
    const char *filename = "../input.txt";
    int energySum1 = calculateEnergySum(filename, 1);
    printf("I Suma wartosci energetycznych: %d\n", energySum1);

    int energySum2 = calculateEnergySum(filename, 2);
    printf("II Suma wartosci energetycznych: %d\n", energySum2);

    return 0;
}
