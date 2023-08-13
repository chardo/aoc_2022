#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Same thing as a.c but now calculate the total carried by the THREE elves with
// the most
int main(void) {
  char in_elf, in_line;
  in_elf = in_line = FALSE;

  int current_elf_cals, current_line_cals, elf_index;
  current_elf_cals = current_line_cals = elf_index = 0;

  int max_cals[3] = {0, 0, 0};

  char current_char;
  while (TRUE) {
    current_char = getchar();
    if (current_char == '\n' || current_char == EOF) {
      if (in_line) {
        in_line = FALSE;
        current_elf_cals += current_line_cals;
        current_line_cals = 0;
      } else {
        if (current_elf_cals > max_cals[2]) {
          max_cals[0] = max_cals[1];
          max_cals[1] = max_cals[2];
          max_cals[2] = current_elf_cals;
        } else if (current_elf_cals > max_cals[1]) {
          max_cals[0] = max_cals[1];
          max_cals[1] = current_elf_cals;
        } else if (current_elf_cals > max_cals[0]) {
          max_cals[0] = current_elf_cals;
        }
        current_elf_cals = 0;
        elf_index++;
      }

      if (current_char == EOF) {
        break;
      }
    } else {
      in_line = TRUE;
      current_line_cals = current_line_cals * 10 + atoi(&current_char);
    }
  }

  int total_cals = max_cals[2] + max_cals[1] + max_cals[0];
  printf("The total calories carried by the three strongest elves: %d\n",
         total_cals);
}
