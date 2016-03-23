/* taken from http://www.fefe.de/signify/ */
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int getentropy(void *buf, size_t len) {
  int fd=open("/dev/urandom",O_RDONLY);
  ssize_t r;
  if (fd==-1) return -1;
  if (len>256) {
    errno=EIO;
    return -1;
  }
  r=read(fd,buf,len);
  if (r!=(ssize_t)len) {
    errno=EAGAIN;
    close(fd);
    return -1;
  }
  close(fd);
  return 0;
}
