#ifndef TESTER_EXTRA_H
#define TESTER_EXTRA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "tester.h"

  int tester_run_jna(
      struct tester_flags *flags,
      void (*init)(size_t instruction_mem_size, uint8_t *instruction_mem),
      void (*set_state)(struct state *state),
      void (*get_state)(struct state *state),
      int (*step)(void));

#ifdef __cplusplus
}
#endif

#endif
