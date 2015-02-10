#include <stdlib.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char ** dest, int * n, const char * src)
{
  if(*dest == NULL)
    {
      *n = strlen(src) * 2 + 1;
      char * buffer = (char *) malloc(*n);
      /* Pleas be very careful: If *dest is null. It can't be copied or concatenated. Thus it is very non-intuitive to write these two cases together.  */
      *dest = buffer;
    }
  else
    {
      size_t N = 1 + (strlen(*dest) + strlen(src)) * 2;
      if(N+1>*n)
	{
	  *n = N;
	  char * buffer = (char*) malloc(N);
	  buffer = strcpy(buffer, (const char*) *dest);
	  free(*dest);
	  *dest = buffer;
	}
    }
  *dest = strcat(*dest, (char*)src);
  return *dest;
}



char * * explode(const char * str, const char * delims, int * arrLen)
{
  
  int delimPos[20];
  int ind;
  int N = 0;
  for(ind = 0; str[ind] != '\0'; ind++)
    {
      if(strchr(delims, str[ind]) != NULL) delimPos[N++] = ind;
    }
  * arrLen = N+1;
  char * newArr = malloc(ind+1);
  newArr = strcpy(newArr,str);
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
  int ind;
  int n = 0;
  char * str = 0;
  for(ind = 0; ind < len; ind++)
    {
      str = strcat_ex(& str, &n, strArr[ind]);
      str = strcat_ex(& str, &n, glue);
    }
  return str;
}
void sortStringArray(char * * arrString, int len)
{
  int compare (const void ** a, const void ** b)
  {
    return ( (int)(*a)[0] - (int)(*b)[0] );
  }
  
  qsort(arrString, len, sizeof(char*), compare);
  
}
void sortStringCharacters(char * str)
{
  
}
void destroyStringArray(char * * strArr, int len)
{
  
}

