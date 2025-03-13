#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

const char* cregex = "^[[:alnum:]_.-]+@[[:alnum:]_.-]+\\.[[:alpha:]]{2,}$";

int main() {
  int res;
  char s[256];
  scanf("%255s", s);

  regex_t regex;
  regcomp(&regex, cregex, REG_EXTENDED | REG_ICASE);

  res = regexec(&regex, s, 0, NULL, 0);

  printf("%d\n", (res == 0) ? 1 : 0);
  
  regfree(&regex);
  return 0;
}

