#include <stdio.h>
#include "uRun.h"

// Init object and return success
int uRunInit() { return 0; }

// add function to uRun object
int uRunAddFunc() { return 0; }

#ifndef uRunSend
  void uRunSend(char *msg) {
    scanf("%s", msg);
    return;
  }
#endif

// runs function in function_holder
int runFunc() { return 0; }
