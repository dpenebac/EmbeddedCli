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

#define uRunFuncReturnType(f, int, float)                                      \
  switch (f.func_input_types) {                                                \
  case VOID:                                                                   \
    ((void (*)())f.func)();                                                    \
    break;                                                                     \
  case INT:                                                                    \
    uRunRecieve(d, &intVal);                                                   \
    ret = ((int (*)(int))f.func)((int)intVal);                                 \
    break;                                                                     \
  case FLOAT:                                                                  \
    uRunRecieve(f, &floatVal);                                                 \
    ret = ((float (*)(float))f.func)((float)floatVal);                         \
    break;                                                                     \
  }

uint32_t uRunRunFunc(struct function_holder f) {
  uint32_t ret = -1;
  int intVal = 0;
  float floatVal = 0;

  // possible types = int, float

  switch (f.func_return_types) {
  case VOID:
    uRunFuncReturnType(f, int, float); // 0 is irrelevant
    break;
  case INT:
    uRunFuncReturnType(f, int, float);
    break;
  case FLOAT:
    uRunFuncReturnType(f, int, float);
    break;
  }

  return ret;
}
