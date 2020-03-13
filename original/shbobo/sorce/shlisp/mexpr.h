

short parse_mexpr(char ** tokan);
short parse_mexpr(char ** tokan) {
 int space_span = 
  strspn(*tokan,", \n\r\t");
 if (space_span > 0) {
  *tokan = *tokan + space_span;
  return parse_mexpr(tokan);
 }
    //todo implement idographic space
 if (strncmp(*tokan,IDEOSPAZ,sizeof(IDEOSPAZ)-1) == 0) {
  *tokan = *tokan+sizeof(IDEOSPAZ)-1;
  return parse_mexpr(tokan);
 }
 if (**tokan == '[') {
  sexmex = 1;
  mex = 0;
  *tokan = *tokan + 1;
  return parse_mexpr(tokan);
 } 
 if (**tokan == ']') {
  sexmex = 0;
  *tokan = *tokan + 1;
  return mex;
 } 
 if (sexmex == 1) {
  //mex |= parse
 #define MEXPTOKE(s,f,ff,v,ningle) \
 if (strncmp(*tokan,s,sizeof(s)-1) == 0) { \
  mex |= (v); \
  *tokan = *tokan +sizeof(s)-1; \
  return parse_mexpr(tokan); \
 }
 #define JEXPTOKE(s,f,ff,v,ningle) MEXPTOKE(s,f,ff,v,ningle)
 #include "tokes.c"
 #include "alpha.def"
 } else while (strspn(*tokan,", \n\r\t-(){}")==0) {
  while (1) {
   #undef MEXPTOKE
   #define MEXPTOKE(s,f,ff,v,ningle) \
   if (strncmp(*tokan,s,sizeof(s)-1) == 0) { \
    *tokan = *tokan +sizeof(s)-1; \
    mex |= (v); break; \
   }
  #undef JEXPTOKE
   #define JEXPTOKE(s,f,ff,v,ningle) MEXPTOKE(s,f,ff,v,ningle)
   #include "tokes.c"
   #include "alpha.def"
   printf("inv%c ", **tokan);
   *tokan = *tokan +1;
   break;
  }
 }  
 return mex;
 //parse_shlisp(++tokan); 
}

