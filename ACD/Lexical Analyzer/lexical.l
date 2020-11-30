%{
  int yylineno;

//Keywords
  #define WHILE 1
  #define VOID 2
  #define RETURN 3
  #define MAINFUNC 4
  #define BREAK 5
  #define CONTINUE 7
  #define IF 8
  #define INT 10
  #define CHAR 11
  #define UNSIGNED 12
  #define SIGNED 13
  #define LONG 14
  #define SHORT 15
  #define ELSE 16
  #define FOR 17
  #define STRUCT 18

//Identifier and Constant
  #define ID 20
  #define CONST 21

//Operators
  #define RELOP 22

//Logical
  #define LOGOP 26

//Assignment
  #define SIMPAS 29
  	//   =	Simple assignment operator.
  #define COMPAS 30

//Arithmetic
  #define ARITHOP 31
  #define PP 40
  	// ++
  #define MM 41
  	// --

//Bitwise Ops
  #define BITOP 42

// Miscelaneous tokens
  #define SEMICOLON 53
  #define BA1 54
  	// '(' bracket
  #define BA2 55
  	// ')' bracket
  #define BB1 56
  	// '[' bracket
  #define BB2 57
  	// ']' bracket
  #define BC1 58
  	// '{' bracket
  #define BC2 59
  	//'}' bracket
  #define COMMA 60
  	// ','
  #define Q 61
  	// Quote "
  #define SQ 62
  	// Single Quote '
  #define HEAD 63
  	// Header file
  #define ARR 64
	// Array
  #define SLC 65
	// Single comment '/'
  #define MLCO 66
  	// Multiline Comment Open '/*'
  #define MLCC 67
  	// Multilien Comment Close '*/'
  #define DEF 68
    // Macro
  #define PRINTF 69
  #define SCANF 70
  #define FUNC 71
  #define STRING 72
  #define INTCONST 73
  #define FLOATCONST 74
  #define CHARCONST 75
  #define INVALIDSTRING 76
  #define DOT 80

%}
at [@||$||*]
alpha [A-Z||a-z]
digit [0-9]
und [_]
space [ ]
com [,]

%%
\n	{yylineno++;}
"main(void)" return MAINFUNC;
"main()" return MAINFUNC;
"main(int argc, char **argv)" return MAINFUNC;
"main(int argc, char *argv[])" return MAINFUNC;
"return"	return RETURN;
void return VOID;
break	return BREAK;
if return IF;
while return WHILE;
for return FOR;
printf return PRINTF;
continue return CONTINUE;
scanf return SCANF;
int return INT;
char return CHAR;
signed return SIGNED;
unsigned return UNSIGNED;
long return LONG;
short return SHORT;
const return CONST;
else return ELSE;
struct return STRUCT;

#include<{alpha}{alpha}*\.h> return HEAD;

#define.* return DEF;
"/*" return MLCO;
"*/" return MLCC;

" " return 1000000;
{digit}({alpha}|{und})({alpha}|{digit}|{und})*  return 333;
{at}({alpha}|{und})({at})?({alpha}|{digit}|{und})*({at})?  return 333;
({alpha}|{und})({at})({alpha}|{digit}|{und})*({at})?  return 333;
({alpha}|{und})({at})?({alpha}|{digit}|{und})*({at})  return 333;
{alpha}({alpha}|{digit}|{und})*    return ID;
{alpha}({alpha}|{digit}|{und})*\[{digit}*\] return ARR;
{digit}+  return INTCONST;
({digit}+)\.({digit}+) return FLOATCONST;

\"[^\n|^\"]*[\n] return INVALIDSTRING;

{alpha}({alpha}|{digit}|{und})*\({alpha}({alpha}|{digit}|{und}|{space})*\) return FUNC;

\"[^\n]*\" return STRING;
\'{alpha}\' return CHARCONST;

\<= |
\>= |
\< |
\!= |
\> |
\== {return RELOP;}

"[|][|]" |
"&&" |
"!" return LOGOP;

"=" return SIMPAS;

"+=" |
"-=" |
"*=" |
"/=" |
"%=" return COMPAS;

"+" |
"-" |
"*" |
"/" |
"%" return ARITHOP;

"++" return PP;
"--" return MM;

"&" |
"[|]" |
"~" |
"<<" |
">>" return BITOP;

"//" return SLC;


";" return SEMICOLON;
"(" return BA1;
")" return BA2;
"[" return BB1;
"]" return BB2;
"{" return BC1;
"}" return BC2;
"," return COMMA;
"\"" return Q;
"'" return SQ;
\t ;
"." return DOT;
%%

//Data Structure for the symbol and constant table
struct symbol
{
	char token[100];	// Name of the token
	char type[100];		// Token type: Identifier, string constant, floating point constant etc
}symbolTable[100000];

int i=0; // Number of symbols in the symbol table
int kw=0;

//Insert function for symbol/constant table
void symbolInsert(struct symbol table[], int index, char* tokenName, char* tokenType)
{
  strcpy(table[index].token, tokenName);
  strcpy(table[index].type, tokenType);
}

int main(void)
{
  int newToken, // The current token being processed
      j,k, // Iterators
      ba_c=0,ba_o=0,ba_l, // Number of open and close paranthesis, last line where the open parantesis was used
      bb_o=0,bb_c=0,bb_l, // Number of open and close square braces,  last line where the open sqaure brace was used
      bc_o=0,bc_c=0,bc_l, // Number of open and close curly braces,  last line where the open curly brace was used

      rep=0; // Flag to denote whether the current token is already in symbol table

  //Taking the input program
  yyin= fopen("var.c","r");

  //Reading a single token from the program
  newToken = yylex();
  printf("\n");

  int mlc=0, // Flag to denote whether current token is part of a multiline comment
      slcline=0, // Line number of the single line comment
      mlcline; // Starting line number of multi line comment

  while(newToken)
  {
    rep = 0;

    if(yylineno==slcline) // If token belongs to a single line comment, ignore all the tokens
    {
      newToken=yylex();
      continue;
    }

    for(k=0;k<i;k++) // Checking whether token already exists in symbol table
    {
      if(!(strcmp(symbolTable[k].token,yytext)))
      {
        rep = 1;
        break;
      }

    }



    if(rep==0 && newToken!=65 && newToken!=66 && newToken!=67 && mlc==0)
    {
      strcpy(symbolTable[i].token,yytext);
    }
    if(newToken ==333  && mlc==0)
    {

      printf("%s\t\t\tInvalid identifier\t\tLine %d\n",yytext,yylineno);
    }

    if(newToken ==1 && mlc==0)
    {
      kw++;
      printf("%s\t\t\tWhile Loop\t\t\tLine %d\n",yytext,yylineno);
    }
       else if(newToken==67 && mlc==1)
    {
      mlc=0;
      printf("%s\t\t\tMulti Line Comment End\t\tLine %d\n",yytext,yylineno);
      mlcline=0;
    }
    else if(newToken ==4 && mlc==0)
    {
      printf("%s\t\t\tMain function\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken ==8 && mlc==0)
    {
       kw++;
      printf("%s\t\t\tIf statement\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken ==16 && mlc==0)
    {
 kw++;
      printf("%s\t\t\tElse statement\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken ==17 && mlc==0)
    {
 kw++;
      printf("%s\t\t\tFor Loop\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken ==18 && mlc==0)
    {
 kw++;
      printf("%s\t\t\tStruct definition/declaration\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(((newToken>=1 && newToken<=15)) && mlc==0) // Keywords
    {
       kw++;
      printf("%s\t\t\tKeyword\t\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==20 && mlc==0) // Identifiers
    {
      if(rep == 0)
      {	symbolInsert(symbolTable, i, yytext, "ID");
      	i++;
      }
      printf("%s\t\t\tIdentifier\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==73 && mlc==0)
    {

      printf("%s\t\t\tInteger Constant\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==74 && mlc==0)
    {

      printf("%s\t\t\tFloating Point Constant\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==22 && mlc==0)
    {
      printf("%s\t\t\tRelational Operator\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==26 && mlc==0)
    {
      printf("%s\t\t\tLogical Operator\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==29 && mlc==0)
    {
      printf("%s\t\t\tSimple Assignment Operator\tLine %d\n",yytext,yylineno);
    }
    else if(newToken==30 && mlc==0)
    {
      printf("%s\t\t\tCompound Assignment Operator\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==31 && mlc==0)
    {
      printf("%s\t\t\tArithmetic Operator\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==42 && mlc==0)
    {
      printf("%s\t\t\tBitwise Operator\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==40 && mlc==0)
    {
      printf("%s\t\t\tIncrement Operator\t\tLine %d\n",yytext,yylineno);
    }
    else if(newToken==41 && mlc==0)
    {
      printf("%s\t\t\tDecrement Operator\t\tLine %d\n",yytext,yylineno);
    }


    else if((newToken>=53 && newToken<=62 ||newToken==80) && mlc==0)
    {
      if(newToken==54)
      {
        ba_o++;
	    ba_l = yylineno;
      }
      if(newToken==55)
        ba_c++;
      if(newToken==56)
      {
        bb_o++;
        bb_l = yylineno;
      }
      if(newToken==57)
        bb_c++;
      if(newToken==58)
      {
        bc_o++;
        bc_l = yylineno;
      }
      if(newToken==59)
        bc_c++;
        if(!newToken==60 && !newToken==53)
      printf("%s\t\t\tSpecial Character\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==63 && mlc==0)
    {
      printf("%s\tHeader\t\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==64 && mlc==0)
    {
      char id[100] = "";
      for(int t = 0; ; t++)
      {
        if(yytext[t] == '[')
          break;
        id[t] = yytext[t];
      }

      for(k=0;k<i;k++) // Checking whether token already exists in symbol table
      {
      	if(!(strcmp(symbolTable[k].token,id)))
      	{
        	rep = 1;
       		break;
      	}
      }

      if(rep == 0)
      {
        symbolInsert(symbolTable, i, id, "ID");
      	i++;
      }
      printf("%s\t\t\tArray Identfier\t\t\tLine %d\n",yytext,yylineno);
    }

    else if(newToken==65 && mlc==0)
    {
      printf("%s\t\t\tSingle Line Comment\t\tLine %d\n",yytext,yylineno);
      slcline=yylineno;
    }

    else if(newToken==66)
    {
      mlc=1;
      printf("%s\t\t\tMulti Line Comment Start\tLine %d\n",yytext,yylineno);
      mlcline = yylineno;

    }

    else if(newToken==66 && mlc==1)
    {
      printf("%s\t\t\tNested multi Line Comment Start\t\tLine %d\n",yytext,yylineno);
    }

 

    else if(newToken==67 && mlc==0)
      printf("\n\t\t\t-----ERROR : UNMATCHED NESTED END COMMENT\t\t\t---\n");

    else if(newToken==68 && mlc==0)
    {
      printf("%s\t\t\tPreprocessor Directive\t\t\tLine %d\n",yytext,yylineno);
      newToken=yylex();
      continue;
    }

    else if(newToken>=69 && newToken<=70 && mlc==0)
    {
      printf("%s\t\t\tPre Defined Function\t\tLine %d\n",yytext,yylineno);

    }

    else if(newToken==71 && mlc==0)
    {
      char id[100] = "";
      for(int t = 0; ; t++)
      {
        if(yytext[t] == '(')
          break;
        id[t] = yytext[t];
      }

      for(k=0;k<i;k++) // Checking whether token already exists in symbol table
      {
      	if(!(strcmp(symbolTable[k].token,id)))
      	{
        	rep = 1;
       		break;
      	}
      }

      if(rep == 0)
      {
        symbolInsert(symbolTable, i, id, "ID");
      	i++;
      }

      printf("%s\t\tUser Defined Function\t\tLine %d\n",yytext,yylineno);

    }

    else if(newToken==72 && mlc==0)
    {

      printf("%s\t\t\tString literal\t\t\tLine %d\n",yytext, yylineno);
    }

    else if(newToken==75 && mlc==0)
    {

      printf("%s\t\t\tCharacter ConstantLine %d\n",yytext,yylineno);
    }

    else if(newToken==76 && mlc==0)
    {
	printf("\n--------------------ERROR : INCOMPLETE STRING starting at Line %d------------\n",yylineno);
    }

    newToken=yylex();
  }

  if(mlc==1)
    printf("\n--------------------ERROR : UNMATCHED COMMENT starting at Line %d------------\n",mlcline);

  if(ba_c<ba_o)
    printf("\n--------------------ERROR : UNMATCHED '(' at Line %d ------------------------\n",ba_l);

  if(bb_c<bb_o)
    printf("\n--------------------ERROR : UNMATCHED '[' at Line %d ------------------------\n",bb_l);

  if(bc_c<bc_o)
    printf("\n--------------------ERROR ! UNMATCHED '{' at Line %d ------------------------\n",bc_l);



    if(ba_c > ba_o){
    ba_o++;
      printf("\n-------------ERROR : UNMATCHED ')' at Line %d------------------\n", yylineno-1);}

    if(bb_c>bb_o)
      printf("\n-------------ERROR : UNMATCHED ']' at Line %d------------------\n", yylineno-1);

    if(bc_c>bc_o)
      printf("\n-------------ERROR : UNMATCHED '}' at Line %d------------------\n", yylineno-1);


  printf("\n------------Symbol Table---------------------\n\nSNo\tToken\t\tAttribute\n\n");

  for(j=0;j<i;j++)
    printf("%d\t%s\t\t< %s >\t\t\n",j+1,symbolTable[j].token,symbolTable[j].type);



	printf("\nNumber of keywords is: %d\n", kw);
  printf("Number of identifiers is: %d\n", i);
  return 0;
}

int yywrap(void)
{
	return 1;
}
