#include "uRun.h"

#ifndef uRunSend
void uRunSend(char *msg) {
  printf("%s", msg);
  return;
}
#endif

void uRunStart(struct function_holder f[]) {
  char func_name[100];

  while (1) {
    uRunRecieve(s, func_name);

    int found = 0;
    int index = -1;
    for (int i = 0; i < 4; i++) {
      if (!strcmp(func_name, f[i].tag)) {
        found = 1;
        index = i;
        break;
      }
    }

    uint32_t ret = 0;
    if (!found) {
      printf("Command not found\n");
    } else {
      ret = uRunRunFunc(f[index]);
    }

    printf("%d %f\n", ret, (float)ret);
  }
}

uint32_t uRunRunFunc(struct function_holder f) {
  uint32_t ret = -1;

  switch (f.func_return_types) {
  case VOID:
    ((void (*)())f.func)();
    break;
  case INT:
    ret = ((int (*)())f.func)();
    break;
  case FLOAT:
    ret = ((float (*)())f.func)();
    break;
  }

  return ret;
}
