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

    // using array of function holders
    uint32_t ret = 0;
    if (!found) {
      printf("Command not found\n");
    } else {
      ret = uRunRunFunc(f[index]);
    }

    printf("%d %f\n", ret, (float)ret);
  }
}

#define uRunFuncReturnType(f, types, ...)                                      \
  switch (f.func_return_types) {                                               \
  case VOID:                                                                   \
    ((void(*) types)f.func)(__VA_ARGS__);                                      \
    break;                                                                     \
  case INT:                                                                    \
    intVal = ((int(*) types)f.func)(__VA_ARGS__);                              \
    return (uint32_t)intVal;                                                   \
    break;                                                                     \
  case FLOAT:                                                                  \
    floatVal = ((float(*) types)f.func)(__VA_ARGS__);                          \
    return (uint32_t)floatVal;                                                 \
    break;                                                                     \
  default:                                                                     \
    break;                                                                     \
  }

#define uRunFuncInputCount(f, argc, types, ...)                                \
  uRunFuncReturnType(f, types, __VA_ARGS__);

uint32_t uRunRunFunc(struct function_holder f) {

  // return types first, 1 input, int input type
  int a, b, c, d, e;
  float g, h, i, j, l;
  int intVal = 0;
  float floatVal = 0.0;

  switch (f.func_input_count) {
  case 2:
    switch (f.func_input_types[0]) {
    case INT:
      uRunRecieve(d, &a);
    }
    switch (f.func_input_types[1]) {
    case FLOAT:
      uRunRecieve(f, &l);
    }
    uRunFuncInputCount(f, 2, (int, float), a, l); // NEED TO BE ABLE TO GENERATE THIS IN MACRO
    break;
  }

  // uRunFuncInputTypes(f, 2, (int, float));

  return -1;
}

// need to use macros with the type parameter
// this would remove the switches for return/input types but not the
// input count switch, but that is plenty ngl
// start simple and PLAN

// uint32_t uRunRunFunc(struct function_holder f) {
//   int a, b;
//   int intVal = 0;
//   float floatVal = 0.0;

//   switch (f.func_input_count) {
//   case 0:
//     switch (f.func_return_types) {
//     case VOID:
//       ((void (*)())f.func)();
//       break;
//     case INT:
//       intVal = ((int (*)())f.func)();
//       return (uint32_t)intVal;
//       break;
//     case FLOAT:
//       floatVal = ((float (*)())f.func)();
//       return (uint32_t)floatVal;
//       break;
//     }
//     break;
//   case 1:
//     // need to do switch here as well xdddd
//     uRunRecieve(d, &a);
//     switch (f.func_return_types) {
//     case VOID:
//       ((void (*)(int))f.func)(a);
//       break;
//     case INT:
//       intVal = ((int (*)(int))f.func)(a);
//       return (uint32_t)intVal;
//       break;
//     case FLOAT:
//       floatVal = ((float (*)(int))f.func)(a);
//       return (uint32_t)floatVal;
//       break;
//     }
//     break;
//   case 2:
//     uRunRecieve(d, &a);
//     uRunRecieve(d, &b);
//     switch (f.func_return_types) {
//     case VOID:
//       ((void (*)(int, int))f.func)(a, b);
//       break;
//     case INT:
//       intVal = ((int (*)(int, int))f.func)(a, b);
//       return (uint32_t)intVal;
//       break;
//     case FLOAT:
//       floatVal = ((float (*)(int, int))f.func)(a, b);
//       return (uint32_t)floatVal;
//       break;
//     }
//     break;
//   }

//   return 0;
// }
