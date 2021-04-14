#include "tester_jna.h"

int tester_run_jna(
    struct tester_flags *flags,
    void (*init)(size_t instruction_mem_size, uint8_t *instruction_mem),
    void (*set_state)(struct state *state),
    void (*get_state)(struct state *state),
    int (*step)(void))
{
  struct tester_operations operations;
  operations.init = init;
  operations.set_state = set_state;
  operations.get_state = get_state;
  operations.step = step;
  return tester_run(flags, &operations);
}
