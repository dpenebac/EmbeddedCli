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
    for (int i = 0; i < 3; i++) {
      if (!strcmp(func_name, f[i].tag)) {
        found = 1;
        index = i;
        break;
      }
    }

    // using array of function holders
    uint32_t ret = 0;
    if (!found) {
      printf("Command not found\n");
    } else {
      ret = uRunRunFunc(f[index]);
    }

    if (f[index].func_return_types == INT) {
      printf("Ret Val = %d\n", ret);
    } else if (f[index].func_return_types == FLOAT) {
      printf("Ret Val = %f\n", ret);
    }
  }
}

int uRunReturnType(struct function_holder f, RET_TYPE T, int count) {
  switch (T) {
  case INT:
    break;
  default:
    return -1;
  }

  return -1;
}

int uRunInputCount(struct function_holder f) { return -1; }

// runs function in function_holder
// this is necessary to communicate other information back
// eg, return values, status?? others idek
// basically just return values
uint32_t uRunRunFunc(struct function_holder f) {
  int a, b;
  int intVal = 0;
  float floatVal = 0.0;

  switch (f.func_input_count) {
  case 0:
    switch (f.func_return_types) {
    case VOID:
      ((void (*)())f.func)();
      break;
    case INT:
      intVal = ((int (*)())f.func)();
      return (uint32_t)intVal;
      break;
    case FLOAT:
      floatVal = ((float (*)())f.func)();
      return (uint32_t)floatVal;
      break;
    }
    break;
  case 1:
    // need to do switch here as well xdddd
    uRunRecieve(d, &a);
    switch (f.func_return_types) {
    case VOID:
      ((void (*)(int))f.func)(a);
      break;
    case INT:
      intVal = ((int (*)(int))f.func)(a);
      return (uint32_t)intVal;
      break;
    case FLOAT:
      floatVal = ((float (*)(int))f.func)(a);
      return (uint32_t)floatVal;
      break;
    }
    break;
  case 2:
    uRunRecieve(d, &a);
    uRunRecieve(d, &b);
    switch (f.func_return_types) {
    case VOID:
      ((void (*)(int, int))f.func)(a, b);
      break;
    case INT:
      intVal = ((int (*)(int, int))f.func)(a, b);
      return (uint32_t)intVal;
      break;
    case FLOAT:
      floatVal = ((float (*)(int, int))f.func)(a, b);
      return (uint32_t)floatVal;
      break;
    }
    break;
  }

  return 0;
}
