#ifndef _EMU_HLT_H
#define _EMU_HLT_H

#if 0
#include "emu_defs.h"
#endif
#include "bios.h"

typedef void (*emu_hlt_func)(Bit16u offs, void *arg);

typedef struct {
  emu_hlt_func  func;
  const char   *name;
  int           len;
  void         *arg;
  int           ret;
} emu_hlt_t;

#define HLT_INITIALIZER { NULL, NULL, 1, NULL, HLT_RET_NORMAL }

enum { HLT_RET_NONE, HLT_RET_FAIL, HLT_RET_NORMAL, HLT_RET_SPECIAL };

extern void hlt_init(void);
extern Bit16u hlt_register_handler(emu_hlt_t handler);
extern int hlt_handle(void);

#endif /* _EMU_HLT_H */
