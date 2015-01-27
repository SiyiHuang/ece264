#ifndef PA03_H
#define PA03_H

#include <stdlib.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char ** dest, int * n, const char * src)
{
  size_t dest_len, src_len;
  if( (*dest == NULL) || ((dest_len = strlen(*dest)) + (src_len=strlen(src) + 1 >*n) ) )
    {
      *n = 1 + (dest_len + src_len) * 2;
      char * buffer = (char *)malloc(*n*sizeof(char));
      buffer = strcpy(buffer, *dest);
      free(*dest);
      dest = &buffer;
    }
  *dest = strcat(*dest, (char*)src);
  return *dest;
}



char * * explode(const char * str, const char * delims, int * arrLen)
{
  char * * strArr;
  
  return strArr;
}

char * implode(char * * strArr, int len, const char * glue)
{
  return 0;
}
void sortStringArray(char * * arrString, int len)
{
  
}
void sortStringCharacters(char * str)
{
  
}
void destroyStringArray(char * * strArr, int len)
{
  
}
#endif
