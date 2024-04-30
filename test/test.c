#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "uRun.h"

int test(int x);
float test_float(int x);
void wait(int x, float y);
void waitlong();

int test(int x) {
  printf("Test function called with %d\n", x);
  return x + 1;
}

float test_float(int x) {
  printf("Test_Float function called with %d\n", x);
  return (float)(x + 1);
}

void wait(int x, float y) { printf("Wait function called with %d %f\n", x, y); }

void waitlong() { printf("WaitLong function called with NONE\n"); }

// placed on hold, doesn't work
// #ifdef uRunRecieveDefined 
//   void uRunRecieve(int type, char *msg) {
//     scanf("%s", msg);
//     return;
//   }
// #endif

int main() {
  static struct function_holder f[4] = {
      {test, {sizeof(int)}, INT, 1, "test"},
      {test_float, {sizeof(int)}, FLOAT, 1, "test_float"},
      {wait, {sizeof(int), sizeof(float)}, VOID, 2, "wait"},
      {waitlong, {0}, VOID, 0, "waitlong"}};

  uRunStart(f);

  return 0;
}
