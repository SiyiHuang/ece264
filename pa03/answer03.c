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
  int ind, ind2;
  *arrLen = 1;
  for(ind = 0; str[ind] != '\0'; ind++)
    if(strchr(delims, str[ind]) != NULL) *arrLen += 1;
  int delimPos[*arrLen+1];
  delimPos[0] = -1;
  ind2 = 1;
  for(ind = 0; str[ind]!='\0'; ind++)
    if(strchr(delims, str[ind]) != NULL) delimPos[ind2++] = ind;
  delimPos[*arrLen] = strlen(str);
  char ** strArr = malloc(*arrLen * sizeof(char*));
  for(ind = 0; ind < *arrLen; ind++)
    {
      size_t strl = (delimPos[ind+1]-delimPos[ind]-1);
      strArr[ind] = malloc((strl+1) * sizeof(char));
      strArr[ind] = memcpy(strArr[ind], (str+delimPos[ind] + 1),strl);
      strArr[ind][strl] = '\0';
    }
  return strArr;

      
  //The code bellow is not good. Because freeing some certain string is not
  //possible. The space is malloc-ed as a whole
  /*  int delimPos[20];
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
  */

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
   int compare (const void * a, const void * b)
  {
    return ( (int)((char*)b)[0] - (int)((char*)a)[0] );
  }
  
  qsort(arrString, len, sizeof(char*), compare);
  
}
void sortStringCharacters(char * str)
{
  
}
void destroyStringArray(char * * strArr, int len)
{
  
}

