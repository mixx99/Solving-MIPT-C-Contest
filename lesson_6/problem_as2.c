#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse(int cmd)
{
  unsigned char left[2];
  unsigned char right[2];
  char command[4] = "000";
  char s1, s2;
  command[0] = (cmd >> 6) & 1;
  command[1] = (cmd >> 5) & 1;
  command[2] = (cmd >> 4) & 1;
  
  left[0] = (cmd >> 3) & 1;
  left[1] = (cmd >> 2) & 1;
  right[0] = (cmd >> 1) & 1;
  right[1] = cmd & 1;
  

  if(left[0] == 0 && left[1] == 0) s1 = 'A';
  if(left[0] == 0 && left[1] == 1) s1 = 'B';
  if(left[0] == 1 && left[1] == 0) s1 = 'C';
  if(left[0] == 1 && left[1] == 1) s1 = 'D';

  if(right[0] == 0 && right[1] == 0) s2 = 'A';
  if(right[0] == 0 && right[1] == 1) s2 = 'B';
  if(right[0] == 1 && right[1] == 0) s2 = 'C';
  if(right[0] == 1 && right[1] == 1) s2 = 'D';

  // IN R
  if(command[0] == 1 && command[1] == 0 && command[2] == 0 && s1 == 'A'){
    printf("IN %c\n", s2);
    return 1; }
  
  // OUT R
  if(command[0] == 1 && command[1] == 0 && command[2] == 0 && s1 == 'B'){
    printf("OUT %c\n", s2);
    return 1; }
  
  // ADD R, R
  if(command[0] == 0 && command[1] == 0 && command[2] == 0){
    printf("ADD %c, %c\n", s1, s2);
    return 1; }

  //SUB R, R 
  if(command[0] == 0 && command[1] == 0 && command[2] == 1){
    printf("SUB %c, %c\n", s1, s2);
    return 1;}
  
  // MUL R, R
  if(command[0] == 0 && command[1] == 1 && command[2] == 0){
    printf("MUL %c, %c\n", s1, s2);
    return 1;}
  
  // DIV R, R
  if(command[0] == 0 && command[1] == 1 && command[2] == 1){
    printf("DIV %c, %c\n", s1, s2);
    return 1;}

  return 0;
}


int main()
{
  unsigned char res, cmd;
  
  while(1)
  {
    res = scanf("%hhx", &cmd);
    if(res != 1)
      break;
    if(((cmd >> 7) & 1) == 0)
    {
      printf("MOVI %d\n", cmd);
      continue;
    }
      if(!parse(cmd)){ printf("ERROR\n"); break; }
    
  }
  
}
