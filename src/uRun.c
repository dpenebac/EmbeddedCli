#include "uRun.h"
#include <stdio.h>
#include <string.h>

#ifndef uRunSend
void uRunSend(char *msg) {
  printf("%s", msg);
  return;
}
#endif

void uRunStart(struct function_holder f[]) {
  char func_name[100];
  int a, b, c, d, e, s;
  
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
}

// runs function in function_holder
// this is necessary to communicate other information back
// eg, return values, status?? others idek
// basically just return values
int uRunRunFunc() { return 0; }
