#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

  char str[] = "RULDDLRULRL";
  int 	ejeX=0, 
  		ejeY=0;
  int strLength = strlen(str);

  for (int i = 0; i < strLength; i++) {

    printf("[%c]", str[i]);
    switch(str[i]) {
        case 'U' :
            ejeY++;
            break;
        case 'D' :
            ejeY--;
            break;
        case 'R' :
            ejeX++;
            break;
        case 'L' :
            ejeX--;
            break;
        default :
            break;
        }

  }

  if(ejeX == 0 && ejeY == 0) 
  {
      printf("true");
  }
  else 
  {
      printf("false");
  }

  return 0;
}