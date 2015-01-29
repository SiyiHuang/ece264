#ifndef PA03_H
#define PA03_H

#include <stdlib.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char ** dest, int * n, const char * src)
{
  size_t dest_len = 0, src_len = strlen(src);
  if( (*dest == NULL) || ((dest_len = strlen(*dest)) + src_len + 1 > *n) )
    {
      int N = 1 + (dest_len + src_len) * 2;
      *n = N;
      char * buffer = malloc(N * sizeof(char));
      buffer = strcpy(buffer, (const char*) *dest);
      free(*dest);
      dest = &buffer;
    }
  *dest = strcat(*dest, (char*)src);
  return *dest;
}



char * * explode(const char * str, const char * delims, int * arrLen)
{
  
  int * delimPos;
  int ind;
  int N = 0;
  for(ind = 0; ind < *arrLen; ind++)
    {
      if(strchr(delims, str[ind]) != NULL) delimPos[N++] = ind;
    }
  char * newArr = malloc((* arrLen + 1) * sizeof(char) );
  newArr = strcpy(newArr,(char *)str);
  char * * strArr = malloc((N+1) * sizeof(char *));
    strArr[0] = newArr;
  for(ind = 0; ind < N; ind++)
    {
      newArr[delimPos[ind]] = '\0';
      strArr[ind+1] = &(newArr[delimPos[ind]+1]);
    }
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
