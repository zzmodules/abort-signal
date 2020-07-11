#ifndef ZZ_ABORT_SIGNAL_H
#define ZZ_ABORT_SIGNAL_H

#include <os/detect.h>

#if OS_IS_WINDOWS
  #include <process.h>
#else
  #include <stdlib.h>
#endif

void abort_signal_native_exit(int status) {
  _exit(status);
}

#endif
