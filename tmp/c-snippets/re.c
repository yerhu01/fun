#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

// regex.h
// https://www.gnu.org/software/libc/manual/html_node/Regular-Expressions.html
// POSIX REGEX SYNTAX
// https://en.wikibooks.org/wiki/Regular_Expressions/POSIX_Basic_Regular_Expressions#Syntax
// https://en.wikibooks.org/wiki/Regular_Expressions/POSIX-Extended_Regular_Expressions
/* A-Z, a-z, 0-9, .
 * [], [^]
 * ^, $
 * *, +, ?, {m,n}, {m,}, {,n}, {m}
 * | = or
 * () = grouping and subexpressions
 * \ = escape NOTE: need to have \\ so the C string will have one \
*/

static void find_match(){
    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    char *pattern = "^[a-z]+\\.v[0-9]+\\..*$";
    reti = regcomp(&regex, pattern , REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    /* Execute regular expression */
    char *path = "testfile.v021.ma";
    reti = regexec(&regex, path, 0, NULL, 0);
    if (!reti) {
        puts("Match");
    }
    else if (reti == REG_NOMATCH) {
        puts("No match");
    }
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
}

static void extract_str() {
    regex_t regex;
    int reti;
    char msgbuf[100];

    size_t nmatch = 3; // 0 = whole match, 1 = 1st, 2 = 2nd etc.
    regmatch_t pmatch[nmatch];

    // Extract subexpression
    char *pattern = "^([a-z]+)\\.v([0-9]+)\\..*$";
    reti = regcomp(&regex, pattern , REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    /* Execute regular expression */
    char *path = "testfile.v021.ma";
    reti = regexec(&regex, path, nmatch, pmatch, 0);
    if (!reti) {
        puts("Match");
        printf("With the whole expression, "
               "a matched filename substring \"%.*s\" is found at position %d to %d.\n",
               pmatch[1].rm_eo - pmatch[1].rm_so, &path[pmatch[1].rm_so],
               pmatch[1].rm_so, pmatch[1].rm_eo - 1);
        printf("With the whole expression, "
               "a matched version substring \"%.*s\" is found at position %d to %d.\n",
               pmatch[2].rm_eo - pmatch[2].rm_so, &path[pmatch[2].rm_so],
               pmatch[2].rm_so, pmatch[2].rm_eo - 1);
    }
    else if (reti == REG_NOMATCH) {
        puts("No match");
    }
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
}

int main() {
    find_match();
    extract_str();
}
