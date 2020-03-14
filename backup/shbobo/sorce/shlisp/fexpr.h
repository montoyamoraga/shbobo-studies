void parse_fatomevil(char** tokan);
void commentstripper(char * buffer);
void parse_fexpr(char * tokan);
void parse_fevil(char** tokan);
void parse_fexprswitch(char * tokan);

#include "sexpr.h"



void commentstripper(char * buff) {
 char * commentstrip, *commentend;
 commentstrip = strpbrk(buff,";");
 if (commentstrip) {
  commentend = strpbrk(commentstrip,"\n");
  while (commentstrip < commentend) 
   *commentstrip++ = 32; //put whitespace
  commentstripper(commentstrip);
 }
}

void parse_fevil(char** tokan) {
#define LISPDICT(s,v) \
if (strncmp(*tokan,s,sizeof(s)-1) == 0) { \
 printf(v); \
 *tokan = *tokan +sizeof(s)-1; \
}
  LISPDICT("cons","CONZ")
  LISPDICT("car","CAR")
  LISPDICT("define","DEVINE")
  LISPDICT("cons","CONZ")
}

#if defined(STEVEJOBS) || defined(BILLGATES)
char* strndup(char* str, size_t n) {
	// Stupid implementation of strndup since macos isn't born with
	// one.
	size_t len = strlen(str);
	if (len <= n)
		return strdup(str);
	char* result = new char[n+1];
	size_t i;
	for (i = 0; i <= n; i++)
		result[i] = str[i];
	result[i] = '\0';
	return result;
}
#endif

void parse_fatomevil(char** tokan) {
 int letra_span = 0;
 // strspn(*tokan,"abcdefghijklmnopqrstuvwxyz");
 if (letra_span > 0) {
  char * boson = strndup(*tokan, letra_span);
  //printf("%s ", boson);
  *tokan = *tokan + letra_span;
  //parse_fexpr(*tokan);

 } else parse_sexpr(tokan);

}


 

void parse_fexpr(char * tokan) {
 if (*tokan == '\0') return;
 int space_span = 
  strspn(tokan,", \n\r\t");
 if (space_span > 0) {
  //tokan = tokan+space_span;
  parse_fexpr(tokan+space_span);
  return;
 }
 //todo implement idographic space
 if (strncmp(tokan,IDEOSPAZ,sizeof(IDEOSPAZ)-1) == 0) {
  parse_fexpr(tokan+sizeof(IDEOSPAZ)-1);
  return;
 }
 if (*tokan == '<') {
  printf("%c ", *tokan);
  ++tokan;
  parse_fevil(&tokan);
  parse_fexpr(tokan);
  return;
 }
 if (*tokan == '>') {
  printf("%c ", *tokan);
  //++tokan;
  parse_fexpr(++tokan);
  return;
 }
 parse_fatomevil(&tokan);
 //printf("lef%c ", *tokan);
 
 parse_fexpr(tokan);
}

void parse_fexprswitch(char * tokan) {
 while (*tokan != '\0') {
  //printf("lef%c ", *tokan);
  switch (*tokan) {
   //case '\0': return;
   case ' ':
   case '\n':
   case '\r':
   case '\t': tokan++; break;
   case '<': 
    printf("%c ", *tokan);
    tokan++; break;
   case '>': 
    printf("%c ", *tokan);
    tokan++; break;
   default:
    
    parse_sexpr(&tokan);
    //parse_lisp(tokan);
  }
 }
}
