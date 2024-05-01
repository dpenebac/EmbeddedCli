#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef enum {
  VOID,
  INT,
  FLOAT,
} RET_TYPE;

struct function_holder {
  void *func;
  RET_TYPE func_return_types;
  RET_TYPE func_input_types;
  const char *tag;
};

// blocking recieve, meant to be overwritten
// #define uRunRecieveDefined // currently doesn't work
#ifndef uRunRecieveDefined
#define uRunRecieve(type, variable) scanf("%" #type, variable)
#else
void uRunRecieve(int type, char *msg);
#endif

#define addFunc(func, ret_type, input_type)                                                    \
  { func, ret_type, input_type, #func }

void uRunSend(char *msg);
void uRunStart(struct function_holder f[]);
uint32_t uRunRunFunc(struct function_holder f);