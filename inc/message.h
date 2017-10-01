/* l24es - Custom mesages module header */

#ifndef _MESSAGE_H
#define _MESSAGE_H

#define ANSI_BOLD          "\e[1m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* stringLength
    Returns the length in bytes of a string.
    -->f()
        str: string to calculate its length.
    f()-->
        Integer value representing the length of str.
*/
int stringLength(const char *);

/* strcatHeaderAndBody
    Joins the header and the body of a message together.
    -->f()
        header: string indicating message type.
        body: description of the message.
    f()-->
        Message to show in stdout.
*/
char * strcatHeaderAndBody(const char *, const char *);

/* createErrorMessage
    Returns an error message.
    -->f()
        body: string with the error description.
    f()-->
        The input body with the concatenated error header.
*/
char * createErrorMessage(const char *);

#endif /* #ifndef _MESSAGE_H_ */
