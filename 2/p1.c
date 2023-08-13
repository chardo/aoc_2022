#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char opp_play, my_play;
  opp_play = my_play = '_';

  int score = 0;

  char current_char;
  while ((current_char = getchar()) != EOF) {
    if (current_char == '\n') {
      // add score stuff
      score += my_play;
      if (my_play == opp_play) {
        score += 3;
      } else if ((my_play == 3 && opp_play == 2) ||
                 (my_play == 2 && opp_play == 1) ||
                 (my_play == 1 && opp_play == 3)) {
        score += 6;
      }
    } else if (current_char >= 65 && current_char <= 67) {
      opp_play = current_char - 64;
    } else if (current_char >= 88 && current_char <= 90) {
      my_play = current_char - 87;
    }
  }
  printf("Final score is %d\n", score);
}
