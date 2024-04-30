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
  RET_TYPE func_input_types[10]; // use this to determine what type of inputs the
                            // func has
  RET_TYPE func_return_types;
  int func_input_count;
  const char *tag;
};

// blocking recieve, meant to be overwritten
// #define uRunRecieveDefined // currently doesn't work
#ifndef uRunRecieveDefined
#define uRunRecieve(type, variable) scanf("%" #type, variable)
#else
void uRunRecieve(int type, char *msg);
#endif

void uRunSend(char *msg);
void uRunStart(struct function_holder f[]);
uint32_t uRunRunFunc(struct function_holder f);