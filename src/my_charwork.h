#ifndef MY_CHARWORK_DEFINE
#define MY_CHARWORK_DEFINE

#include <stdio.h>
#include <stdlib.h>
#include <my_list.h>

my_list* my_split(const char* str, const char* separators);
int my_rmat(const char* str, char** out, int i);
int my_rmata(char** str, int i);
char* my_stralloc(const char* str);
int my_strcat(char** string, const char* s1, const char* s2);
void my_readline(char** string);
void my_clrbuf();
int my_strlen(const char* str);
void my_ltostr(const my_list* l, char** out);
int my_strsearch(const char *str, const char *c);
int my_substr(const char *str, char** out, int start, int length);
int my_substra(char** str, int start, int length);
int my_rmchar(const char* str, char** out, char c);
int my_rmchara(char** str, char c);
int my_rmstr(const char* str, char** out, const char* rm);
int my_rmstra(char** str, const char* rm);

#endif //MY_CHARWORK_DEFINE
