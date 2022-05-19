#include <stdio.h>
#include <locale.h>
#include <string.h>

int count_letters1(char* str) {
    int i, res = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            res++;
        }
    }
    return res;
}

int count_spaces(char* str) {
    int i, res = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            res++;
        }
    }
    return res;
}

int count_numbers(char* str) {
    int i, res = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res++;
        }
    }
    return res;
}

int count_words(char* str) {
    int res = 0, buk = 0, num = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            buk++;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            num++;
        }
        if ((str[i] == ' ' || i == strlen(str)-1) && buk != 0 && num == 0) {
            res++;
        }
        if (str[i] == ' ') {
            num = 0;
            buk = 0;
        }
    }
    return res;
}

int main() {

    setlocale(LC_ALL, "Rus");
    char f[9] = "hg55 jgh";
    char g[] = "Katherine Mansfield, an outstanding English short - story writer of the 20th century, was born in New Zealand in 1888 and died in 1923. She is the author of a number of excellent short stories which deal with human nature and psychology.";
    int y = count_numbers(f);
    printf("%d\n", y);
    printf("%d\n", count_spaces(f));
    printf("%d\n", count_words(g));

    return 0;
}


/*

Упражнения.

1.  Напишите программу подсчитывающую в строке:
1.1 буквы латинского алфавита используя приведённые в примере функции;
1.2 цыфры и пробелы, модифицируйте для этого приведённые функции;
1.3 слова (под словами будем понимать последовательность только из букв латинского алфавитта,
    отделённую пробелами), модифицируйте для этого приведённые функции.

*/
