#include <stdio.h>
#include <stdlib.h>

void printBinary(char c) {
  int i;
  for (i = 0; i < 8; i++) {
    printf("%d", !!((c << i) & 0x80));
  }
  printf("\n");
}

int main(void) {
  char set[26] = {0};
  char buf[4] = {0};
  int buf_i, count;
  buf_i = count = 0;

  char current_char;
  while ((current_char = getchar()) != EOF) {
    buf[buf_i] = current_char;
    if (count >= 4) {
      char valid = 1;
      for (int i = 0; i < 4; i++) {
        if (set[buf[i] - 'a'] == 1) {
          valid = 0;
          break;
        } else {
          set[buf[i] - 'a'] = 1;
        }
      }

      if (valid) {
        // WIN
        printf("On char %d, buf index %d\n", count + 1, buf_i);
        printf("Last 4 chars were:\n");
        for (int i = 0; i < 4; i++) {
          int idx = buf_i - i;
          if (idx < 0) idx = 4 + idx;
          printf("%c", buf[idx]);
        }
        printf("\n");
        return 0;
      }
      // clear set
      for (int i = 0; i < 26; i++) {
        set[i] = 0;
      }
    }

    count++;
    buf_i = count % 4;
  }

  printf("No signal found, uh oh!\n");
  return 0;
}
