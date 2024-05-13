#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

#define MAX_CHARS 180

int extract_game_number(string line) {
    int i = 0;
    int game_number = 0;
    bool is_game_found = false;

    // Find the position of "Game"
    while (i < line.length()) {
        if (line[i] == 'G' && line[i + 1] == 'a' && line[i + 2] == 'm' && line[i + 3] == 'e') {
            is_game_found = true;
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

int main() {
    const string filename = "../input2.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Nie można otworzyć pliku." << endl;
        exit(EXIT_FAILURE);
    }

    int sum_id = 0;
    int moc_sum = 0;
    string line;
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;

    while (getline(file, line)) {
        int line_len = line.length();
        int flag = 0;
        int min_red = 0;
        int min_green = 0;
        int min_blue = 0;

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

            if (line.compare(i, 3, "red") == 0) {
                if (number > max_red) {
                    flag = 1;
                }
                if (number > min_red) {
                    min_red = number;
                }
            }

            if (line.compare(i, 5, "green") == 0) {
                if (number > max_green) {
                    flag = 1;
                }
                if (number > min_green) {
                    min_green = number;
                }
            }

            if (line.compare(i, 4, "blue") == 0) {
                if (number > max_blue) {
                    flag = 1;
                }
                if (number > min_blue) {
                    min_blue = number;
                }
            }
        }

        moc_sum += (min_red * min_green * min_blue);

        if (flag == 0) {
            sum_id += game_number;
        }
    }

    file.close();

    cout << "Suma numerow gier, ktore mozna rozegrac: " << sum_id << endl;
    cout << "Suma mocy zestawow wymaganych do rozegrania gier: " << moc_sum << endl;

    string stayclosed;
    cin >> stayclosed;
    return 0;
}
