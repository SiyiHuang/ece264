

#include <stdio.h>
#include <string.h>
#include "answer03.h"

int main(int argc, char **argv)
{
  char * src;
  char * dest;
  char * result;
  int n;

  src="World!";
  dest=NULL;
  result=strcat_ex(&dest, &n, src);
  printf("src=\"World!\";\ndest=NULL;\nstrcat_ex(&dest, &n, src);\n --> gives %s with n=%d\n",result,n);
  result=strcat_ex(&dest, &n, "");
  printf("Then strcat_ex(&dest, &n, \"\") yields --> gives %s with n=%d\n",result,n);
  strcpy(dest,"abc");
  result=strcat_ex(&dest, &n, "def");
  printf("Then strcpy(dest,\"abc\"); strcat_ex(&dest, &n, \"def\") yields --> gives %s with n=%d\n",result,n);  
  free(dest);

  int outlen;
  int index;
  char * glue;
  char * save;
  char **outstrings=explode("abc\tdef\fghi","\t\f",&outlen);
  printf("explode(\"abc\\tdef\\fghi\",\"\\t\\f\",&outlen); yields:\n");
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
  }
  glue="";
  printf("implode with glue \"%s\" gives \"%s\"\n",glue,save=implode(outstrings,outlen,glue));
  free(save);
  printf("After sorting:\n");
  sortStringArray(outstrings,outlen);
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
    free(outstrings[index]);
  }
  free(outstrings);
  
  outstrings=explode("abc\t\fghi","\t\f",&outlen);
  printf("explode(\"abc\\t\\fghi\",\"\\t\\f\",&outlen); yields:\n");
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
  }
  glue="++";
  printf("implode with glue \"%s\" gives \"%s\"\n",glue,save=implode(outstrings,outlen,glue));
  free(save);
  printf("After sorting:\n");
  sortStringArray(outstrings,outlen);
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
    free(outstrings[index]);
  }
  free(outstrings);

  outstrings=explode("abc\t\fghi","\f",&outlen);
  printf("explode(\"abc\\t\\fghi\",\"\\f\",&outlen); yields:\n");
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
  }
  glue="|";
  printf("implode with glue \"%s\" gives \"%s\"\n",glue,save=implode(outstrings,outlen,glue));
  free(save);
  printf("After sorting:\n");
  sortStringArray(outstrings,outlen);
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
    free(outstrings[index]);
  }
  free(outstrings);

  outstrings=explode("","\f",&outlen);
  printf("explode(\"\",\"\\f\",&outlen); yields:\n");
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
  }
  glue="\t";
  printf("implode with glue \"%s\" gives \"%s\"\n",glue,save=implode(outstrings,outlen,glue));
  free(save);
  printf("After sorting:\n");
  sortStringArray(outstrings,outlen);
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
    free(outstrings[index]);
  }
  free(outstrings);

  outstrings=explode("\f\f\f\f","\f",&outlen);
  printf("explode(\"\\f\\f\\f\\f\",\"\\f\",&outlen); yields:\n");
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
  }
  glue="";
  printf("implode with glue \"%s\" gives \"%s\"\n",glue,save=implode(outstrings,outlen,glue));
  free(save);
  printf("After sorting:\n");
  sortStringArray(outstrings,outlen);
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
    free(outstrings[index]);
  }
  free(outstrings);

  outstrings=explode("\f\f\f\f","",&outlen);
  printf("explode(\"\\f\\f\\f\\f\",\"\",&outlen); yields:\n");
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
  }
  glue="|||";
  printf("implode with glue \"%s\" gives \"%s\"\n",glue,save=implode(outstrings,outlen,glue));
  free(save);
  printf("After sorting:\n");
  sortStringArray(outstrings,outlen);
  for (index=0; index<outlen; index++) {
    printf("\t%d:\"%s\"\n",index,outstrings[index]);
    free(outstrings[index]);
  }
  free(outstrings);

  return 0;
}  
