#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "uRun.h"

void test(int x, ...);
void wait(int x, int y);
void waitlong();

// Initialize the structure
static struct function_holder f = {{{test, {0}, 0, "Test"},
                                    {wait, {0}, 0, "Wait"},
                                    {waitlong, {0}, 0, "WaitLong"}}};

void test(int x, ...) { printf("Test function called with %d\n", x); }

void wait(int x, int y) { printf("Wait function called with %d %d\n", x, y); }

void waitlong() { printf("WaitLong function called with NONE\n"); }

int main() {
  char c[100];
  char d[100];
  while (1) {
    scanf("%s %s", c, d);
    int found = 0;
    int index = -1;
    for (int i = 0; i < 3; i++) {
      if (!strcmp(c, f.functions[i].tag)) {
        found = 1;
        index = i;
        break;
      }
    }
    if (!found) {
      printf("Command not found\n");
    } else {
      void (*func)(int, ...) = f.functions[index].func;
      func(index, d);
    }
  }

  return 0;
}
