#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int total_prio = 0;
  int this_prio = 0;
  char this_char = 0;
  char char_tracker[52] = {0};
  char current_line[80] = {0};
  char line_width = 0;

  char current_char;
  while ((current_char = getchar()) != EOF) {
    if (current_char == '\n') {
      // end of line, process it
      for (char i = 0; i < line_width; i++) {
        this_char = current_line[i];
        if (this_char >= 65 && this_char <= 90) {
          this_prio = this_char - 38;
        } else if (this_char >= 97 && this_char <= 122) {
          this_prio = this_char - 96;
        }
        if (i >= line_width / 2) {
          if (char_tracker[this_prio - 1] == 1) {
            printf("Got a line dupliate priority of %d\n", this_prio);
            total_prio += this_prio;
            break;
          }
        } else {
          char_tracker[this_prio - 1] = 1;
        }
      }

      // reset state for next line
      line_width = 0;
      for (char i = 0; i < 52; i++) {
        char_tracker[i] = 0;
      }
    } else {
      current_line[line_width] = current_char;
      line_width++;
    }
  }
  printf("Total prio is %d\n", total_prio);
}
