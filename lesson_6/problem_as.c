#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

 // MOVI, IN, OUT, ADD, SUB, MUL, DIV

void parse_movi()
{
  int val, scanres;
  char res;
  scanres = scanf("%d", &val);
  if (scanres != 1)
  {
    printf("ERROR\n");
    exit(1);
  }
  res = val;
  res = res & (~(1 << 7));
  printf("0x%x ", res);

}

void parse_in()
{
  char val[2], res, scan;
  int out = 0;
  scan = scanf("%s", val);
  if (scan != 1)
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(val, "A") == 0)
    res = 0;
  else if (strcmp(val, "B") == 0)
    res = 1;
  else if (strcmp(val, "C") == 0)
    res = 2;
  else if (strcmp(val, "D") == 0)
    res = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  out |= (1 << 7);
  out |= (1 << 6);
  out |= res;
  printf("0x%x ", out);
}

void parse_out()
{
  char val[2], res, scan;
  int out = 0;
  scan = scanf("%s", val);
  if (scan != 1)
  {
    printf("ERROR");
    exit(3);
  }
  if (strcmp(val, "A") == 0)
    res = 0;
  else if (strcmp(val, "B") == 0)
    res = 1;
  else if (strcmp(val, "C") == 0)
    res = 2;
  else if (strcmp(val, "D") == 0)
    res = 3;
  else
  {
    printf("ERROR");
    exit(9);
  }
  out |= (1 << 7);
  out |= (1 << 6);
  out |= (1 << 2);
  out |= res;
  printf("0x%x ", out);
}

void parse_add()
{
  char first[5], second[5];
  int scanres;
  int out = 0;
  scanres = scanf("%s%s", first, second);
  if (scanres != 2)
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(first, "A,") == 0)
    *first = 0;
  else if (strcmp(first, "B,") == 0)
    *first = 1;
  else if (strcmp(first, "C,") == 0)
    *first = 2;
  else if (strcmp(first, "D,") == 0)
    *first = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(second, "A") == 0)
    *second = 0;
  else if (strcmp(second, "B") == 0)
    *second = 1;
  else if (strcmp(second, "C") == 0)
    *second = 2;
  else if (strcmp(second, "D") == 0)
    *second = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  out |= (1 << 7);
  out |= ((*first) << 2);
  out |= (*second);
  printf("0x%x ", out);
}


void parse_sub()
{
  char first[5], second[5];
  int scanres;
  int out = 0;
  scanres = scanf("%s%s", first, second);
  if (scanres != 2)
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(first, "A,") == 0)
    *first = 0;
  else if (strcmp(first, "B,") == 0)
    *first = 1;
  else if (strcmp(first, "C,") == 0)
    *first = 2;
  else if (strcmp(first, "D,") == 0)
    *first = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(second, "A") == 0)
    *second = 0;
  else if (strcmp(second, "B") == 0)
    *second = 1;
  else if (strcmp(second, "C") == 0)
    *second = 2;
  else if (strcmp(second, "D") == 0)
    *second = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  out |= (1 << 7);
  out |= (1 << 4);
  out |= ((*first) << 2);
  out |= (*second);
  printf("0x%x ", out);
}

void parse_mul()
{
  char first[5], second[5];
  int scanres;
  int out = 0;
  scanres = scanf("%s%s", first, second);
  if (scanres != 2)
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(first, "A,") == 0)
    *first = 0;
  else if (strcmp(first, "B,") == 0)
    *first = 1;
  else if (strcmp(first, "C,") == 0)
    *first = 2;
  else if (strcmp(first, "D,") == 0)
    *first = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(second, "A") == 0)
    *second = 0;
  else if (strcmp(second, "B") == 0)
    *second = 1;
  else if (strcmp(second, "C") == 0)
    *second = 2;
  else if (strcmp(second, "D") == 0)
    *second = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  out |= (1 << 7);
  out |= (1 << 5);
  out |= ((*first) << 2);
  out |= (*second);
  printf("0x%x ", out);
}

void parse_div()
{
  char first[5], second[5];
  int scanres;
  int out = 0;
  scanres = scanf("%s%s", first, second);
  if (scanres != 2)
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(first, "A,") == 0)
    *first = 0;
  else if (strcmp(first, "B,") == 0)
    *first = 1;
  else if (strcmp(first, "C,") == 0)
    *first = 2;
  else if (strcmp(first, "D,") == 0)
    *first = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  if (strcmp(second, "A") == 0)
    *second = 0;
  else if (strcmp(second, "B") == 0)
    *second = 1;
  else if (strcmp(second, "C") == 0)
    *second = 2;
  else if (strcmp(second, "D") == 0)
    *second = 3;
  else
  {
    printf("ERROR");
    exit(1);
  }
  out |= (1 << 7);
  out |= (1 << 5);
  out |= (1 << 4);
  out |= ((*first) << 2);
  out |= (*second);
  printf("0x%x ", out);
}

int main()
{
  char cmd[32];
  int scanres = 0;
  while(1)
  {
  scanres = scanf("%s", cmd);
  if (scanres != 1)
    break;
  if (strcmp(cmd, "MOVI") == 0)
    parse_movi();
  if (strcmp(cmd, "IN") == 0)
    parse_in();
  if (strcmp(cmd, "OUT") == 0)
    parse_out();
  if (strcmp(cmd, "ADD") == 0)
    parse_add();
  if (strcmp(cmd, "SUB") == 0)
    parse_sub();
  if (strcmp(cmd, "MUL") == 0)
    parse_mul();
  if (strcmp(cmd, "DIV") == 0)
    parse_div();
  }
}