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
        str_temp[i-1] = str[i];
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
            } else {
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
    char mass[5][6] = {"docks", "ducks", "bugs", "dogs", "joggs"};
    char substr[] = "gs";
    for (int i = 0; i < (sizeof(mass) / sizeof(mass[0])); i++) {
        printf("%s\n", substring(mass[i], substr));
        printf("%s\n", my_substring(mass[i], substr));
    }
}

int main() {

    setlocale(LC_ALL, "Rus");

    char str[] = "abcd";
    char substr[] = "abcd";
    printf("%s\n", substring(str, substr));
    printf("%s\n", my_substring(str, substr));

    printf("\n");

    char str1[] = "abcd";
    char substr1[] = "ab";
    printf("%s\n", substring(str1, substr1));
    printf("%s\n", my_substring(str1, substr1));

    printf("\n");
    
    char str2[] = "abcd";
    char substr2[] = "cd";
    printf("%s\n", substring(str2, substr2));
    printf("%s\n", my_substring(str2, substr2));

    printf("\n");

    char str3[] = "abcd";
    char substr3[] = "fg";
    printf("%s\n", substring(str3, substr3));
    printf("%s\n", my_substring(str3, substr3));

    printf("\n");

    char str4[] = "abcd";
    char substr4[] = "b";
    printf("%s\n", substring(str4, substr4));
    printf("%s\n", my_substring(str4, substr4));

    return 0;
}