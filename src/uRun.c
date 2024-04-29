#include "uRun.h"
#include <stdio.h>


// Init object and return success
int uRunInit() { return 0; }

// add function to uRun object
int uRunAddFunc() { return 0; }

#ifndef uRunSend
void uRunSend(char *msg) {
  printf("%s", msg);
  return;
}
#endif

// void uRunStart(struct function_holder f) {}

// runs function in function_holder
// this is necessary to communicate other information back
// eg, return values, status?? others idek
// basically just return values
int uRunRunFunc() { return 0; }
