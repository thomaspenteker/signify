/* Thomas Penteker 2016. Public Domain */

#ifndef linux_h
#define linux_h

#ifndef pledge
int pledge(const char *c, void *p) { return 0; }
#endif

#ifndef __dead
#define __dead
#endif

#endif
