#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Define types of tokens */
typedef enum {
  TOKEN_NUMBER,
  TOKEN_PLUS,
  TOKEN_EOF
} type;

/* Token definition */
typedef struct {
  type type;
  int value;
} token;

/* Lexer definition */
typedef struct {
  const char *input;
  uint32_t position;
} lexer;

/* Lexer Initializer */
void lexer_init(lexer *lexer, const char *input) {
  lexer->input = input;
  lexer->position = 0;
}

int is_symbol(char token) {
  if (token == '+') {
    return 1;
  } else {
    return 0;
  }
}

/* Get next token */
token get_next_token(lexer *lexer) {
  token token;
  char current_token = lexer->input[lexer->position];
  token.value = current_token;
  token.type = TOKEN_NUMBER;
  
  return token;
}

int main() {
  const char *input = "99";
  lexer lexer;
  lexer_init(&lexer, input);
  token current_token = get_next_token(&lexer);

  printf("Token value: %d/n", current_token.value);

  return 0;
}
