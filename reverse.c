
#include "stack.h"
#include "string.h"
#include "stdlib.h"

#define MAX_CHAR 156
/* Include here any other headers you need */

/**
 * @brief: Reverses a string
 * @param str, String to reverse
 * @return A newly allocated string with the reversed string
 **/

char *string_invert(char *str) {

  Stack *s=NULL;
  char *strinv = NULL,*straux=NULL;
  int i=0, n=0;

  s = stack_new();
  if(s==NULL){

    return NULL;
  }

  if(str==NULL){

    return NULL;
  }

  n=strlen(str);

  strinv= (char *)malloc((n+1)*sizeof(char));
  if(strinv==NULL){

    return NULL;
  }

  straux= (char *)malloc(MAX_CHAR*sizeof(char));
  if(straux==NULL){

    return NULL;
  }

  for(i=0; i<n; i++){

    if(stack_push(s, &(str[i]))==ERROR){

      return NULL;
    }
  }

  for(i=0; stack_isEmpty(s)==false; i++){

    strcpy(straux, (char *)stack_top(s));
    strinv[i] = straux[0];
    stack_pop(s);
  }

  strinv[n] = '\0';

  free(straux);
  stack_free(s);

  return strinv;
  
}

/**
 * @brief: Reverse the words of an input string to an output string.
 *
 * @example: "Hello World" => "olleH dlroW"
 * The words in the input string are separated by a space character.
 * The strings may not overlap, and the destination string strout
 * must be large enough to receive the inverted expression.
 *
 * @param strout, Pointer to the output buffer
 * @param strin, Pointer to the input expression
 * @return The function returns OK or ERROR
 **/

Status reverseWords(char *strout, char *strin) {

  Stack *s;
  int i, n, j, k;
  char *straux = NULL, *space = NULL;

  space = (char *)malloc(MAX_CHAR*sizeof(char));
  if(space == NULL){

    return ERROR;
  }

  straux = (char *)malloc(MAX_CHAR*sizeof(char));
  if(straux == NULL){

    return ERROR;
  }

  n = strlen(strin);

  strcpy(space, " ");

  s=stack_new();
  if(s==NULL){

    return ERROR;
  }

  for(i=k=0; i<n; i++){

    if(strncmp(&(strin[i]), space, 1)==0){

      for(j=0; stack_isEmpty(s)==false; j++){

        strcpy(straux, (char *)stack_top(s));
        strout[k] = straux[0];
        k++;
        stack_pop(s);
      }

      strcpy(&(strout[k]) , space);
      k++;

    }else{

      if(stack_push(s, &(strin[i]))==ERROR){

        return ERROR;
      }

      if(i==n-1){

        for(j=0; stack_isEmpty(s)==false; j++){

        strcpy(straux, (char *)stack_top(s));
        strout[k] = straux[0];
        k++;
        stack_pop(s);
      }

      }

    }
  }

  strout[n] = '\0';

  free(space);
  free(straux);
  stack_free(s);
  return OK;
}