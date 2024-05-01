#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "uRun.h"

int test();
float test_float();
void wait();
void waitlong();

int test() {
  printf("Test function called.\n");
  return 0;
}

float test_float() {
  printf("Test_Float function called.\n");
  return 0.0;
}

void wait() { printf("Wait function called.\n"); }

void waitlong() { printf("WaitLong function called.\n"); }

// placed on hold, doesn't work
// #ifdef uRunRecieveDefined
//   void uRunRecieve(int type, char *msg) {
//     scanf("%s", msg);
//     return;
//   }
// #endif

int main() {
  static struct function_holder f[4] = {
      addFunc(test, INT),
      {test_float, FLOAT, "test_float"},
      {wait, VOID, "wait"},
      {waitlong, VOID, "waitlong"}};

  uRunStart(f);

  return 0;
}
