#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "uRun.h"

int test(int x);
void wait(int x, int y);
void waitlong();

int test(int x) {
  printf("Test function called with %d\n", x);
  return x + 1;
}

void wait(int x, int y) { printf("Wait function called with %d %d\n", x, y); }

void waitlong() { printf("WaitLong function called with NONE\n"); }

// void uRunRecieve(char *msg) {
//   scanf("%s", msg);
//   printf("HHIII");
//   return;
// }

union uRunUnion {
  struct function_holder f0;
  struct function_holder f1;
  struct function_holder f2;
};

int main() {
  char func_name[100];
  int a, b, c, d, e;

  // will eventually be :
  // function_holder f = {0};
  // f.addFunc(test, {sizeof(int)}, 1, "Test");
  static struct function_holder f[3];
  f[0] = (struct function_holder) {test, {sizeof(int)}, sizeof(int), 1, "test"};
  f[1] = (struct function_holder) {wait, {sizeof(int)}, 0, 2, "wait"};
  f[2] = (struct function_holder) {waitlong, {0}, 0, 0, "waitlong"};

  // this will be defined in some uRun function()
  // maybe uRunStart(&f)???
  // will also handle the return values appropriatly
  while (1) {
    uRunRecieve(s, func_name);

    int found = 0;
    int index = -1;
    for (int i = 0; i < 3; i++) {
      if (!strcmp(func_name, f[i].tag)) {
        found = 1;
        index = i;
        break;
      }
    }

    // using array of function holders
    if (!found) {
      printf("Command not found\n");
    } else {
      switch (f[index].func_return_types) {
      case 0:
      case sizeof(int):
        // needs to be a sub function duhhh
        switch (f[index].func_input_count) {
        case 0:
          ((void (*)())f[index].func)();
          break;
        case 1:
          uRunRecieve(d, &a);
          ((void (*)(int))f[index].func)(a);
          break;
        case 2:
          uRunRecieve(d, &a);
          uRunRecieve(d, &b);
          ((void (*)(int, int))f[index].func)(a, b);
          break;
        }
      }
    }
  }

  return 0;
}
