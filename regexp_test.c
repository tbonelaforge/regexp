
#include <stdio.h>

#include "regexp.h"

int match(char * regexp_text, char * input) {
    RegExp self = new_regexp(regexp_text);
    int result;

    if (!self) {
        printf("Ran out of memory!\n");
        return 0;
    }
    result = match_regexp(self, input);
    destroy_regexp(self);
    return result;
}

int main() {
    int result;
    RegExp test;

    printf("About to test terrry against ter*y\n");
    result = match("ter*y", "terrry");
    printf("The result is: %d\n", result);

    test = new_regexp("ter*y");


    printf("About to test terry against ter*y\n");
    result = match_regexp(test, "terry");
    printf("The result is: %d\n", result);

    printf("About to test tery against ter*y\n");
    result = match_regexp(test, "tery");
    printf("The result is: %d\n", result);

    printf("About to test tey against ter*y\n");
    result = match_regexp(test, "tey");
    printf("The result is: %d\n", result);

    printf("About to test ty against ter*y\n");
    result = match_regexp(test, "ty");
    printf("The result is: %d\n", result);

}
