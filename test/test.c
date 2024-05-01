#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "uRun.h"

int test(int x);
float test_float(float x);
void wait();
void waitlong();

int test(int x) {
  printf("Test function called. : %d\n", x);
  return x + 1;
}

float test_float(float x) {
  printf("Test_Float function called. : %f\n", x);
  return x + 1.5;
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
      addFunc(test, INT, INT),
      {test_float, FLOAT, FLOAT, "test_float"},
      {wait, VOID, VOID, "wait"},
      {waitlong, VOID, VOID, "waitlong"}};

  uRunStart(f);

  return 0;
}
