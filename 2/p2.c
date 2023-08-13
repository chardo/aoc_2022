#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char opp_play, my_play;
  opp_play = my_play = '_';

  int score = 0;

  char current_char;
  while ((current_char = getchar()) != EOF) {
    if (current_char >= 65 && current_char <= 67) {
      opp_play = current_char - 64;
    } else if (current_char == 88) {
      // lose - play whatever loses to opp
      // opp 1 -> I play 3
      // opp 2 -> I play 1
      // opp 3 -> I play 2
      my_play = opp_play - 1;
      if (my_play == 0) {
        my_play = 3;
      }
      score += my_play;
    } else if (current_char == 89) {
      // draw - play the same thing as opp
      score += (3 + opp_play);
    } else if (current_char == 90) {
      // win - play whatever beats opp
      // opp 1 -> I play 2
      // opp 2 -> I play 3
      // opp 3 -> I play 1
      my_play = opp_play + 1;
      if (my_play == 4) {
        my_play = 1;
      }
      score += (6 + my_play);
    }
  }
  printf("Final score is %d\n", score);
}
