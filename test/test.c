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

// placed on hold, doesn't work
// #ifdef uRunRecieveDefined 
//   void uRunRecieve(int type, char *msg) {
//     scanf("%s", msg);
//     return;
//   }
// #endif

int main() {
  static struct function_holder f[3] = {
      {test, {sizeof(int)}, sizeof(int), 1, "test"},
      {wait, {sizeof(int)}, 0, 2, "wait"},
      {waitlong, {0}, 0, 0, "waitlong"}};

  uRunStart(f);

  return 0;
}
