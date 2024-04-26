#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "uRun.h"

void test(int x);
void wait(int x, int y);
void waitlong();

// Initialize the structure
static struct function_holder f = {
    {{test, {sizeof(int)}, 1, "Test"},
     {wait, {sizeof(int), sizeof(int)}, 2, "Wait"},
     {waitlong, {0}, 0, "WaitLong"}}};

void test(int x) { printf("Test function called with %d\n", x); }

void wait(int x, int y) { printf("Wait function called with %d %d\n", x, y); }

void waitlong() { printf("WaitLong function called with NONE\n"); }

// void uRunRecieve(char *msg) {
//   scanf("%s", msg);
//   printf("HHIII");
//   return;
// }

int main() {
  char func_name[100];
  int a, b, c, d;
  while (1) {
    uRunRecieve(s, func_name);

    int found = 0;
    int index = -1;
    for (int i = 0; i < 3; i++) {
      if (!strcmp(func_name, f.functions[i].tag)) {
        found = 1;
        index = i;
        break;
      }
    }

    if (!found) {
      printf("Command not found\n");
    } else {
      void (*func)() = f.functions[index].func;
      switch (f.functions[index].func_input_count) {
      case 0:
        func();
        break;
      case 1:
        uRunRecieve(d, &a);
        func(a);
        break;
      case 2:
        uRunRecieve(d, &a);
        uRunRecieve(d, &b);
        func(a, b);
        break;
      }
    }
  }

  return 0;
}
