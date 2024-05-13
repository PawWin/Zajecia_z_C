#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int wordToNumber(const string &word) {
    if (word == "zero") return 0;
    if (word == "one") return 1;
    if (word == "two") return 2;
    if (word == "three") return 3;
    if (word == "four") return 4;
    if (word == "five") return 5;
    if (word == "six") return 6;
    if (word == "seven") return 7;
    if (word == "eight") return 8;
    if (word == "nine") return 9;
    return -1; // -1 in case of no match
}

int calculateEnergySum(const string &filename, int option) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }

    string words[] = {"zero","one", "two", "three" ,"four", "five" ,"six" ,"seven", "eight", "nine"};

    int sum = 0;
    string line;

    while (getline(file, line)) {
        int number_front = -1;
        int number_back = -1;
        int line_len = line.length();

        if (option == 1) {
            // Check from the beginning
            for (int i = 0; i < line_len; i++) {
                if (isdigit(line[i])) {
                    number_front = line[i] - '0';
                    break;
                }
            }
            // Check from the end
            for (int i = line_len - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    number_back = line[i] - '0';
                    break;
                }
            }
        } else if (option == 2) {
            // Check from the beginning and end for words
            for (int i = 0; i < line_len; i++) {
                if (isdigit(line[i])) {
                    number_front = line[i] - '0';
                    break;
                } else {
                    for (int j = 0; j < 10; j++) {
                        if (line.compare(i, words[j].length(), words[j]) == 0) {
                            number_front = wordToNumber(words[j]);
                            break;
                        }
                    }
                    if (number_front != -1) {
                        break;
                    }
                }
            }
            for (int i = line_len - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    number_back = line[i] - '0';
                    break;
                } else {
                    for (int j = 0; j < 10; j++) {
                        if (line.compare(i, words[j].length(), words[j]) == 0) {
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

    file.close();
    return sum;
}

int main() {
    const string filename = "../input.txt";
    int energySum1 = calculateEnergySum(filename, 1);
    cout << "I Suma wartosci energetycznych: " << energySum1 << endl;

    int energySum2 = calculateEnergySum(filename, 2);
    cout << "II Suma wartosci energetycznych: " << energySum2 << endl;

    string stayclosed;
    cin >> stayclosed;
    return 0;
}
