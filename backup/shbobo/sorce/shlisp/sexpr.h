
int sexmex = 0;
short mex = 0;
#include "mexpr.h"

//int sexmex = 0;
//short mex = 0;

void parse_sexpr(char ** tokan);
void parse_sexpr(char ** tokan) {
 //printf("sttrsex%c ", **tokan);
 int space_span = 
  strspn(*tokan,", \n\r\t");
 if (space_span > 0) {
  //tokan = tokan+space_span;
  *tokan = *tokan + space_span;
   parse_sexpr(tokan); return;
 }
   //todo implement idographic space
 if (strncmp(*tokan,IDEOSPAZ,sizeof(IDEOSPAZ)-1) == 0) {
  *tokan = *tokan+sizeof(IDEOSPAZ)-1;
   parse_sexpr(tokan); return;
 }
 
 int mymex;
 int numba_span = 
  strspn(*tokan,"+-1234567890");
 if (numba_span > 0) {
  mymex = atoi(*tokan);
  *tokan = *tokan+numba_span;
  if (situation_place==0) insituate(mymex);
  else if ((unsigned char)mymex==255) {
   insituate(255); insituate(0xF2); insituate(0);
  } else if (mymex==0) {
   insituate(255); insituate(0); 
  } else insituate(mymex);
  return;
 }

 
 if (**tokan == '{') {
  situatier();
  *tokan = *tokan + 1;
   parse_sexpr(tokan); return;
 }
 if (**tokan == '}') {
  situatend();
  insituate(0);
  *tokan = *tokan + 1; return;
 }
 if (**tokan == '(') {
  *tokan = *tokan + 1;
  insituate(0xFF); return;
 }
 if (**tokan == ')') {
  *tokan = *tokan + 1;
  insituate(0); return;
 } mex = 0;
 insituate( parse_mexpr(tokan));

}

