#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void) {
  int total_prio = 0;
  int this_prio = 0;
  char char_tracker[52] = {0};

  char dup_found = FALSE;

  char line_ctr = 0;

  char current_char;
  while ((current_char = getchar()) != EOF) {
    if (current_char == '\n') {
      line_ctr++;
      if (line_ctr == 3) {
        // reset tracking state
        line_ctr = 0;
        dup_found = FALSE;
        for (char i = 0; i < 52; i++) {
          char_tracker[i] = 0;
        }
      }
    } else if (!dup_found) {
      if (current_char >= 65 && current_char <= 90) {
        this_prio = current_char - 38;
      } else if (current_char >= 97 && current_char <= 122) {
        this_prio = current_char - 96;
      }

      // use a lil bitset to track which rows the this character has been seen
      // in. once the tracker has a val of 0b111 (7), we found it
      char_tracker[this_prio - 1] =
          char_tracker[this_prio - 1] | (1 << line_ctr);
      if (char_tracker[this_prio - 1] == 0b111) {
        printf("Found badge in group with value %c and priority %d\n",
               current_char, this_prio);
        dup_found = TRUE;
        total_prio += this_prio;
      }
    }
  }
  printf("Total prio is %d\n", total_prio);
}
