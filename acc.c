//Jack Liegey
//CS 304
//October 4, 2018
//Program for an accumulator which gives users a menu to choose whether to
//be in hex, decimal, or octal mode, if they want to clear the accumulator,
//if they want to run it, and if they want to quit. If they run it, then
//they are asked to enter a value based on the mode and it converts it to the other two.

#include <stdio.h>
#include <string.h>


short get_operand(char mode)
{
  int acc;

  switch(mode)
  {
    case 'H':
    {
      printf("Enter hex value: ");
      scanf("%X", &acc);
      printf("%X\n", acc);
      break;

    }
    case 'O':
    {
      printf("Enter octal value: ");
      scanf("%o", &acc);
      printf("%o\n", acc);
      break;

    }
    case 'D':
    {
      printf("Enter decimal value: ");
      scanf("%d", &acc);
      printf("%d\n", acc);
      break;

    }
  }
  return acc;

}

void print_acc(short acc)
{
  printf("****************************************\n");
  printf("* Accumulator:                         *\n");
  printf("*   Hex     :  %04hX", acc);
  printf("                    *\n");
  printf("*   Octal   :  %06ho", acc);
  printf("                  *\n");
  printf("*   Decimal :  %-10hd", acc);
  printf("              *\n");
  printf("****************************************\n\n");

}

char print_menu(void)
{
  char option[10];
  char valid_input[7] = "HODCSQ"; //valid entries
  char hodcsq; //stores option to check validity

  int loop = 1; //used to run while loop until valid input is available for return

  do
  {
    printf("Please select one of the following options:\n\n");
    printf("O Octal Mode\n");
    printf("H Hexidecimal Mode\n");
    printf("D Decimal Mode\n\n");
    printf("C Clear Accumulator\n");
    printf("S Set Accumulator\n\n");
    printf("Q Quit\n\n");
    printf("Option: ");
    scanf("%s", option);
    printf("%s\n", option);
    hodcsq = toupper(option[0]);
    if(strlen(option) > 1 || (!strchr(valid_input, hodcsq))) {
      printf("\n");
      printf("Invalid option: %s", option);
      printf("\n\n");
    }
    else {
      loop = 0; //terminates loop
    }

  }
  while(loop);
  return toupper(option[0]);
}

int main(void)
{
  int acc = 0; //variable for storing values entered by user
  int loop = 1; //used to run while loop

  print_acc(0);

  char mode = 'D';

  do
  {
    char option = print_menu();

    switch(option)
    {
      case 'H':
      {
          printf("Mode is Hexadecimal\n");
          printf("\n");
          mode = 'H';
          print_acc(acc);
          break;

      }
      case 'O':
      {
        printf("Mode is Octal\n");
        printf("\n");
        print_acc(acc);
        mode = 'O';
        break;

      }
      case 'D':
      {
        printf("Mode is Decimal\n");
        printf("\n");
        print_acc(acc);
        mode = 'D';
        break;

      }
      case 'C':
      {
        printf("\n");
        acc = 0;
        print_acc(acc);
        break;

      }
      case 'S':
      {
        acc = get_operand(mode);
        printf("\n");
        print_acc(acc);
        break;

      }
      case 'Q':
      {
        loop = 0;
        break;

      }
    }
  }
  while(loop);
}
