#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main(void) {
  int s1, t1, s2, t2;
  s1 = t1 = s2 = t2 = 0;

  int first_pair = TRUE;
  int first_num = TRUE;

  int redundant_pairs = 0;

  int current_num = 0;
  char current_char;
  while ((current_char = getchar()) != EOF) {
    if (current_char == '\n') {
      t2 = current_num;
      if ((s1 <= s2 && t1 >= t2) || (s2 <= s1 && t2 >= t1)) {
        redundant_pairs++;
      }
      first_pair = first_num = TRUE;
      current_num = s1 = t1 = s2 = t2 = 0;
    } else {
      if (current_char == '-') {
        if (first_pair) {
          s1 = current_num;
          current_num = 0;
          first_num = FALSE;
        } else {
          s2 = current_num;
          current_num = 0;
        }
      } else if (current_char == ',') {
        t1 = current_num;
        current_num = 0;
        first_pair = FALSE;
      } else {
        current_num = current_num * 10 + (current_char - '0');
      }
    }
  }
  printf("Total overlapping pairs: %d\n", redundant_pairs);
}
