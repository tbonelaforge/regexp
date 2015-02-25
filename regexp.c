
#include <string.h>
#include <stdlib.h>

#include "regexp.h"

RegExp new_regexp(char * regex_text) {
    int length = strlen(regex_text);
    char * copy;
    RegExp self;

    copy = malloc((length + 1) * sizeof(char));
    if (!copy) {
        return NULL;
    }
    self = malloc(sizeof(struct regexp));
    if (!self) {
        free(copy);
        return NULL;
    }
    strcpy(copy, regex_text);
    self->regex_text = copy;
    self->length = length;
    self->pos = 0;
    return self;
}

void destroy_regexp(RegExp self) {
    free(self->regex_text);
    free(self);
}

int match_regexp(RegExp self, char * input) {
    int input_length = strlen(input);
    int i = 0;
    int pos;
    char c;

    self->pos = 0;
    pos = self->pos;
    while (pos > -1 && i < input_length) {
        c = input[i];
        if (is_starred(self) && !is_match(self, c)) {
            pos = advance(self);
        } else if (is_starred(self) && is_match(self, c)) {
            i += 1;
        } else if (!is_starred(self) && !is_match(self, c)) {
            return 0;
        } else { // !is_starred(self) && is_match(self, c)
            pos = advance(self);
            i += 1;
        }
    }
    if (pos == -1 && i >= input_length) {
        return 1;
    }
    return 0;
}

int is_starred(RegExp self) {
    char next;

    if (self->pos >= self->length) {
        return 0;
    }
    next = self->regex_text[self->pos + 1];
    return ( next == '*' ) ? 1 : 0;
}

int is_match(RegExp self, char c) {
    char my_c = self->regex_text[self->pos];

    if (my_c == '.') {
        return 1;
    }
    return ( c == my_c ) ? 1 : 0;
}

int advance(RegExp self) {
    if (is_starred(self)) {
        if (self->pos >= self->length - 2) {
            self->pos = -1;
        } else {
            self->pos += 2;
        }
    } else {
        if (self->pos >= self->length - 1) {
            self->pos = -1;
        } else {
            self->pos += 1;
        }
    }
    return self->pos;
}
