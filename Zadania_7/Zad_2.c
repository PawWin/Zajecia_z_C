#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 180

int extract_game_number(char line[]) {
    int i = 0;
    int game_number = 0;
    int is_game_found = 0;

    // Find the position of "Game"
    while (line[i] != '\0') {
        if (line[i] == 'G' && line[i + 1] == 'a' && line[i + 2] == 'm' && line[i + 3] == 'e') {
            is_game_found = 1;
            break;
        }
        i++;
    }

    if (is_game_found) {
        i += 5; // Skip "Game "
        while (isdigit(line[i])) {
            game_number = game_number * 10 + (line[i] - '0');
            i++;
        }
    }

    return game_number;
}


int main(){
    const char *filename = "../input2.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Nie mozna otworzyc pliku.\n");
        exit(EXIT_FAILURE);
    }

    int sum_id = 0;
    int moc_sum = 0;
    char line[MAX_CHARS];
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;



    while (fgets(line, sizeof(line), file)) {
        int line_len = 0;
        int flag = 0;
        int min_red = 0;
        int min_green = 0;
        int min_blue = 0;

        //dlugosc linii
        for (int i = 0; i < strlen(line); i++){
            if(line[i] != NULL){
                line_len++;
            }
        }

        int game_number = extract_game_number(line);
        int number;

        for (int i = 8; i < line_len; i++) {
            if (isdigit(line[i])) {
                if (isdigit(line[i + 1])) {
                    number = (line[i] - '0') * 10 + (line[i + 1] - '0');
                    i++;
                } else {
                    number = line[i] - '0';
                }
            }

            if (strncmp(&line[i], "red", 3) == 0) {
                if (number > max_red) {
                    flag = 1;
                }
                if (number > min_red){
                    min_red = number;
                }
            }

            if (strncmp(&line[i], "green", 5) == 0) {
                if (number > max_green) {
                    flag = 1;
                }
                if (number > min_green){
                    min_green = number;
                }
            }

            if (strncmp(&line[i], "blue", 4) == 0) {
                if (number > max_blue) {
                    flag = 1;
                }
                if (number > min_blue){
                    min_blue = number;
                }
            }

        }

        moc_sum += (min_red * min_green * min_blue);

        if (flag == 0){
            sum_id += game_number;
        }
    }

    fclose(file);

    printf("Suma numerow gier, ktore mozna rozegrac: %d\n",sum_id);
    printf("Suma mocy zestawow wymaganych do rozegrania gier: %d",moc_sum);


    char stayclosed[999];
    scanf("%s", stayclosed);
    return 0;
}