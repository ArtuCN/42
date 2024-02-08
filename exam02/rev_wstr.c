#include <unistd.h>
#include <stdlib.h>

int is_whitespace(char c) {
    return c == ' ' || c == '\t';
}

void reverse_words_order(char *str) {
    int start = 0;
    int end = 0;

    while (str[end] != '\0')
        end++;
    while (end > 0)
    {
        end--;
        while (end > 0 && !is_whitespace(str[end - 1]))
            end--;
        for (int i = end; i < start; i++)
        {
            write(1, &str[i], 1);
        }
        if (end > 0)
            write(1, " ", 1);

        start = end;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }

    reverse_words_order(argv[1]);
    write(1, "\n", 1);

    return 0;
}
