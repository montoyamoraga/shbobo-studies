//The mascots of SHLISP are
//DSP
//Macroperation
//and finally, Situations

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h> 
#include <signal.h> 
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 

void insituate(unsigned char byte);
void situatier();
void situatend();

//#include "shlisp.h"
//"\u3000"
#define IDEOSPAZ "\xe3\x80\x80"


#include "chub.h" 
#include "situations.h"
#include "fexpr.h" //>sexpr>mexpr
void printar() {
#undef MEXPTOKE
#define MEXPTOKE(s,f,t,v,ningle) \
printf("%2x: %s %s: %s; %d pieces\n", v, s, f,t,ningle);
#undef JEXPTOKE
#define JEXPTOKE(s,f,ff,v,ningle) MEXPTOKE(s,f,ff,v,ningle)

  #include "tokes.c"
}
int simian;
void printarsimp() {
 simian = 8810202;
#undef MEXPTOKE
#define MEXPTOKE(s,f,t,v,ningle) \
if (simian!=v) \
 printf("%2x: %s %s: %s; %d pieces\n", v, s, f,t,ningle); //simian = v;
#undef JEXPTOKE
#define JEXPTOKE(s,f,ff,v,ningle) MEXPTOKE(s,f,ff,v,ningle)

  #include "tokes.c"
  
}

int main(int argc, char * argv[]) {
 //sexmex = 0;
 char * inputfile;
 chubOPEN();
	int offset = 0;
 if (argc > 1) inputfile = strdup(argv[1]);
 else chubRUN();
 if (*inputfile == '-') {
	 if (*(inputfile+1) == 'h') {
		 printarsimp();return 0;}
	 if (*(inputfile+1) == 'z') {
		 printar();return 0;}
	 if (*(inputfile+1) == 'b') {
		 mastroBarcode = atoi(inputfile+2);
		 offset = 1; 
	 }
   
 } 
 if (argc > (offset+1)) inputfile = strdup(argv[offset+1]);
 else chubRUN();
 FILE * filefish;
 filefish = fopen(inputfile,"r");
 
 if (filefish) {
  printf("filefish\n");
  long lSize;
  bytesz = 0;
  char * buffer;
  size_t result;
  fseek (filefish , 0 , SEEK_END);
  lSize = ftell (filefish);
  rewind (filefish);
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer) {
   result = fread (buffer,1,lSize,filefish);
   char * pch; 
   commentstripper(buffer);
 
   parse_fexpr(buffer);
//return 0;
   situsb();
   free (buffer);
  } //fclose(filefish); 
 } 
 if (argc > (offset+2)) {
  while (masterbytesz < 0x10000)
   write_bytez(0);
  inputfile = strdup(argv[offset+2]);
  filefish = fopen(inputfile,"rb");
  if (filefish) {
   
   int c;
   if (0 == fseek (filefish , 0x20000 , SEEK_SET)) {
    c = fgetc (filefish);
    while (c != EOF) {  
     //if (masterbytesz < 195600)
     write_bytez((unsigned char)c);
     c = fgetc (filefish); 
    } 
   }
  //fclose(filefish);
  }
 }  
 int j;
 for (j = 0; j < 16; j++)
 write_bytez(0);
 chubSENDEND();//bytebuff,1);
 printf("\n");
}



