#include <stdio.h>
#include <stdlib.h>
#include "destinador.h"
#include <string.h>


void scanner_fgets(char *buffer, int tamanho) {
    if (fgets(buffer, tamanho, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        buffer[0] = '\0';
    }
}