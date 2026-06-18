#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int c, char **v) {
    char buf[1024];
    FILE *f = fopen(v[1], "r");
    fgets(buf, 1024, f);
    fclose(f);

    int s[99], t = 0;
    char *tok = strtok(buf, " \n");
    while (tok) {
        if      (*tok == '+') s[t-2] += s[t-1], t--;
        else if (*tok == '-') s[t-2] -= s[t-1], t--;
        else if (*tok == '*') s[t-2] *= s[t-1], t--;
        else if (*tok == '/') s[t-2] /= s[t-1], t--;
        else if (*tok == '%') s[t-2] %= s[t-1], t--;
        else if (*tok == '.') printf("%d\n", s[--t]);
        else if (*tok == '`') printf("%c", s[--t]);
        else                  s[t++] = atoi(tok);
        tok = strtok(NULL, " \n");
    }
}