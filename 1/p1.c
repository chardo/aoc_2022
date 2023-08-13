#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Parse input.txt and spit out the number of "calories" represented by the
// largest contiguous block
int main(void) {
  char in_elf, in_line;
  in_elf = in_line = FALSE;

  int max_cals, current_elf_cals, current_line_cals, elf_index, max_index;
  max_cals = current_elf_cals = current_line_cals = elf_index = max_index = 0;

  char current_char;
  while ((current_char = getchar()) != EOF) {
    if (current_char == '\n') {
      if (in_line) {
        // end of line, add to current elf cals
        in_line = FALSE;
        current_elf_cals += current_line_cals;
        // printf("Got line calorie value of %d\n", current_line_cals);
        // printf("After this line, elf %d's updated total is %d\n", elf_index,
        // current_elf_cals);
        current_line_cals = 0;
      } else {
        // printf("Elf %d has total cals of %d\n", elf_index, current_elf_cals);
        // got newline after another newline, end of elf
        if (current_elf_cals > max_cals) {
          max_cals = current_elf_cals;
          max_index = elf_index;
        }
        current_elf_cals = 0;
        elf_index++;
      }
    } else {
      in_line = TRUE;
      current_line_cals = current_line_cals * 10 + atoi(&current_char);
    }
  }

  printf("The max calorie value is %d belonging to elf %d\n", max_cals,
         max_index);
}
