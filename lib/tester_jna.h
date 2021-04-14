#ifndef TESTER_EXTRA_H
#define TESTER_EXTRA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tester.h"

struct byte_array {
  size_t length;
  u8 *bytes;
};

int tester_run_extra(
  struct tester_flags *flags,
  void (*init)(struct byte_array *instruction_mem),
  void (*set_state)(struct state *state),
  void (*get_state)(struct state *state),
  int (*step)(void)
);

#ifdef __cplusplus
}
#endif

#endif