#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>

char* substring(char* str, char* substr) {
    char* p;
    while (*str) {
        char* s = substr;
        p = str;
        while (*s && *(p++) == *(s++));
        if (!*s)
            return str;
        str++;
    }
    return NULL;
}

char* del_first_sim(char* str) {
    char* str_temp = (char*)calloc(strlen(str), sizeof(char) * (strlen(str)));
    for (int i = 1; i < strlen(str); i++) {
        str_temp[i - 1] = str[i];
    }
    return str_temp;
}

char* my_substring(char* str, char* substr) {
    char* p;
    while (strcmp(str, "")) {
        char* s = substr;
        p = str;
        while (s != NULL && p[0] == s[0]) {
            if (strlen(p) != 1 && strlen(s) != 1) {
                p = del_first_sim(p);
                s = del_first_sim(s);
            }
            else {
                p = del_first_sim(p);
                s = del_first_sim(s);
                break;
            }
        }
        if (!strcmp(s, "")) {
            return str;
        }
        str++;
    }
    return NULL;
}

void visov() {
    char mass[5][6] = { "docks", "ducks", "bugs", "dogs", "joggs" };
    char substr[] = "gs";
    int k1 = 0, k2 = 0;
    for (int i = 0; i < (sizeof(mass) / sizeof(mass[0])); i++) {
        char* temp1 = substring(mass[i], substr);
        char* temp2 = my_substring(mass[i], substr);
        if (temp1 != NULL) {
            k1++;
        }
        if (temp2 != NULL) {
            k2++;
        }
        printf("%s\n", substring(mass[i], substr));
        printf("%s\n\n", my_substring(mass[i], substr));
    }
    printf("Количество ненулев в исходной функции: %d, количество ненулев в собственной функции: %d", k1, k2);
}

int main() {

    setlocale(LC_ALL, "Rus");

    visov();

    return 0;
}