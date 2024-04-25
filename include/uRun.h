struct function_holder {
  struct {
    void (*func)();
    int arr[10]; // use this to determine what type of inputs the func has
    int func_input_count;
    const char *tag;
  } functions[3];
};