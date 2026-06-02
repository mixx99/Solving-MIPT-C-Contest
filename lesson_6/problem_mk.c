#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum opcode_t
{
  MOVI = 0, ADD = 8, SUB = 9, MUL = 10, DIV = 11, IN = 12, OUT = 13, LAST,
};

enum reg_t
{
  A = 0, B, C, D,
};

union operand_t
{
  struct { int rd, rs; } ops;
  int rop; // ?
  int imm;
};

struct instr_t
{
  enum opcode_t opcode;
  union operand_t operand;
};

                            /*A, B, C, D*/
unsigned char registers[4] = {0, 0, 0, 0};

void decode_command(unsigned char cmd)
{
  if (cmd == 0xF0)
    exit(0);

  unsigned char reg1;
  unsigned char reg2;

  if (((cmd >> 7) & 1) == 0) // MOVI
  {
    registers[D] = (cmd & 0x7F);
    return;
  }

  unsigned char opcode = cmd >> 4;
  reg1 = cmd & 0x3;

  if (((cmd >> 6) & 0x3) == 0x3) // IN / OUT
  {
    if ((cmd >> 2) & 1)
      printf("%hhu\n", registers[reg1]);
    else
      scanf("%hhu", &registers[reg1]);// registers[reg1] = cmd & 0x3;
    return;
  }

  reg1 = (cmd >> 2) & 0x3;
  reg2 = cmd & 0x3;
  switch (opcode)
  {
//     case IN: registers[reg1] = cmd & 0x3; break;
//     case OUT: printf("%hhu ", registers[reg1]); break;
    case ADD:
      registers[reg1] += registers[reg2];
      break;
    case SUB:
      registers[reg1] -= registers[reg2];
      break;
    case MUL:
      registers[reg1] *= registers[reg2];
      break;
    case DIV:
      assert(registers[reg2] != 0);
      registers[reg1] /= registers[reg2];
      break;
    default:
      printf("Failed to recognize the command\n");
      break;
  }
}

int main()
{
  unsigned char commands[1000];
  int index = 0;
  while (1)
  {
    scanf("%hhx", &commands[index]);
    if (commands[index] == 0xF0)
      break;
    index++;
  }
  index = 0;
  while(1)
  {
    if (commands[index] == 0xF0)
      break;
   decode_command(commands[index]);
   index++;
  }
}