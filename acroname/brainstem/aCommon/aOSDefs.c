
#ifdef aUNIX

#include <sys/types.h>
#include <string.h>
#include "aOSDefs.h"

/* safe routines */
size_t strlcpy(char *dst, const char *src, size_t siz)
{
  char *d = dst;
  const char *s = src;
  size_t n = siz;

  /* Copy as many bytes as will fit */
  if (n != 0) {
    while (--n != 0) {
      if ((*d++ = *s++) == '\0')
	break;
    }
  }

  /* Not enough room in dst, add NUL and traverse rest of src */
  if (n == 0) {
    if (siz != 0)
      *d = '\0';                /* NUL-terminate dst */
    while (*s++)
      ;
  }

  return(s - src - 1);        /* count does not include NUL */
}


size_t strlcat(char *dst, const char *src, size_t siz)
{
  char *d = dst;
  const char *s = src;
  size_t n = siz;
  size_t dlen;

  /* Find the end of dst and adjust bytes left but don't go past end */
  while (n-- != 0 && *d != '\0')
    d++;
  dlen = d - dst;
  n = siz - dlen;

  if (n == 0)
    return(dlen + strlen(s));
  while (*s != '\0') {
    if (n != 1) {
      *d++ = *s;
      n--;
    }
    s++;
  }
  *d = '\0';

  return(dlen + (s - src));        /* count does not include NUL */
}

#endif

#ifdef aWINCE

#include <stdarg.h>

int 
sprintf_s(char *buffer, 
	  size_t sizeOfBuffer, 
	  const char *format, 
	  ...)
{
  va_list va;
  va_start(va, format);
  vsprintf(buffer, format, va);
  va_end(va);
}

#if 0
int scanf_s(const char *format, ...)
{
  va_list va;
  va_start(va, format);
  vsprintf(buffer, format, va);
  va_end(va);
}
#endif

#endif
