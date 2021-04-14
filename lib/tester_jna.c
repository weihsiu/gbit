#include "tester_jna.h"

static void (*hack_init)(struct byte_array *instruction_mem);

static void call_hack_init(size_t instruction_mem_size, uint8_t* instruction_mem) {
  struct byte_array mem;
  mem.length = instruction_mem_size;
  mem.bytes = instruction_mem;
  return hack_init(&mem);
}

int tester_run_extra(
  struct tester_flags *flags,
  void (*init)(struct byte_array *instruction_mem),
  void (*set_state)(struct state *state),
  void (*get_state)(struct state *state),
  int (*step)(void)
) {
  hack_init = init;
  struct tester_operations operations;
  operations.init = &call_hack_init;
  operations.set_state = set_state;
  operations.get_state = get_state;
  operations.step = step;
  return tester_run(flags, &operations);
}