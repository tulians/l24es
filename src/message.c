/* l24es - Custom messages module */
#include "message.h"

const char * errorHeader = ANSI_BOLD ANSI_COLOR_RED "ERROR: " ANSI_COLOR_RESET;

int stringLength(const char * str) {
  int length;
  for (length = 0; str[length] != '\0'; length++);
  return length;
}

char * strcatHeaderAndBody(const char * header, const char * body) {
  int i, j;

  /* The -1 its because the stringLength function returns the '\0's,
     and only one will be needed in the new message.
  */
  char * message = (char *)malloc(stringLength(header) + stringLength(body) - 1);

  for (i = 0; header[i] != '\0'; i++) {
    message[i] = header[i];
  }
  for (j = 0; body[j] != '\0'; j++) {
    message[i + j] = body[j];
  }
  message[i + j] = '\0';
  return message;
}

char * createErrorMessage(const char * body) {
  return strcatHeaderAndBody(errorHeader, body);
}
