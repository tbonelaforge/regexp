
#ifndef _REGEXP_H_
#define _REGEXP_H_

struct regexp {
    char * regex_text;
    int length;
    int pos;
};

typedef struct regexp * RegExp;

RegExp new_regexp(char *);
void destroy_regexp(RegExp);

int match_regexp(RegExp, char *);
int is_starred(RegExp);
int is_match(RegExp, char);
int advance(RegExp);

#endif
