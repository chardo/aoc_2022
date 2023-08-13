#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 0

typedef struct StackNode {
  char value;
  struct StackNode *next;
} StackNode;

typedef struct Stack {
  struct StackNode *head;
} Stack;

int isEmpty(struct Stack *stack) { return stack->head == NULL; }

void push(struct Stack *stack, char value) {
  StackNode *new_head = malloc(sizeof(struct StackNode));
  if (new_head == NULL) {
    exit(1);
  }
  new_head->value = value;
  new_head->next = stack->head;
  stack->head = new_head;
}

char pop(struct Stack *stack) {
  if (stack == NULL || stack->head == NULL) {
    return '\0';
  }
  char v = stack->head->value;
  struct StackNode *tmp = stack->head;
  stack->head = stack->head->next;
  free(tmp);
  return v;
}

char peek(struct Stack *stack) {
  if (stack == NULL || stack->head == NULL) {
    return '\0';
  }
  return stack->head->value;
}

void move(struct Stack *from, struct Stack *to, int num) {
  for (int i = num; i > 0; i--) {
    char popped = pop(from);
    if (popped == '\0') {
      return;
    }

    push(to, popped);
  }
}

void reverse(struct Stack *s) {
  struct Stack tmp = {.head = NULL};
  while (s->head != NULL) {
    char v = pop(s);
    push(&tmp, v);
  }
  s->head = tmp.head;
}

int main(void) {
  Stack stack1 = {.head = NULL};
  Stack stack2 = {.head = NULL};
  Stack stack3 = {.head = NULL};
  Stack stack4 = {.head = NULL};
  Stack stack5 = {.head = NULL};
  Stack stack6 = {.head = NULL};
  Stack stack7 = {.head = NULL};
  Stack stack8 = {.head = NULL};
  Stack stack9 = {.head = NULL};
  Stack *stacks[] = {&stack1, &stack2, &stack3, &stack4, &stack5,
                     &stack6, &stack7, &stack8, &stack9};

  char line_buf[40];
  int char_index, current_line, tmp_num, src, dest, num;
  char_index = current_line = tmp_num = src = dest = num = 0;

  char current_char;
  while ((current_char = getchar()) != EOF) {
    if (current_line <= 7) {
      // parsing the input stacks:
      // store each line in a reusable array until EOL, then parse
      if (current_char == '\n') {
        for (int i = 0; i < 9; i++) {
          char v = line_buf[1 + 4 * i];
          if (v != ' ') {
            push(stacks[i], v);
          }
        }

        char_index = 0;
        current_line++;
      } else {
        line_buf[char_index] = current_char;
        char_index++;
      }

    } else if (current_line == 8) {
      // one-time: reverse stacks after reading them
      if (current_char == '\n') {
        for (int i = 0; i < 9; i++) {
          reverse(stacks[i]);
        }
        current_line++;
      }

    } else if (current_line >= 10) {
      // parsing the movement instructions

      if (current_char <= '9' && current_char >= '0') {
        tmp_num = 10 * tmp_num + (int)(current_char - '0');
      }

      if (current_char == '\n') {
        // end of instruction line, rip a move
        dest = tmp_num;

        // instructions are 1-indexed
        move(stacks[src - 1], stacks[dest - 1], num);

        current_line++;
        src = dest = num = tmp_num = 0;
      } else if (current_char == ' ') {
        if (tmp_num == 0) {
          // if we haven't read a number yet,
          // then we're on an irrelevant space
          // e.g., "move_" or "from_"
          continue;
        } else {
          if (num == 0) {
            num = tmp_num;
            tmp_num = 0;
          } else if (src == 0) {
            src = tmp_num;
            tmp_num = 0;
          }
        }
      }

    } else {
      // parsing nothing
      if (current_char == '\n') {
        current_line++;
      }
    }
  }

  printf("Reached end of file, let's read the stacks\n");
  for (int i = 0; i < 9; i++) {
    printf("%c ", peek(stacks[i]));
  }
  printf("\n");

  return 0;
}
