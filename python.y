%{ 
#include<stdio.h> 
#include<stdlib.h> 
#include "y.tab.h"
#include<string.h>

char temp_var[100];
int m = 0;        //string length for temp_var
int unop =0;
int paramno=0;
char final_out[1024];
void first_val(char *first, char *temp)
{
    int i=0;int n=strlen(first);
    while(i<n && first[i]!=',')
    {
      temp[i]=first[i];i++;
    }
}

void expand(char *str, char *temp)
{

  char *pt;int a=0,b=0,c=0,i=0; char buffer[1024]="";
  pt = strtok(str,",");
  if(pt==NULL)
  {
    if(strlen(str)==0)
    {
    strcat(temp,"");
    return;
    }
  }
  a=atoi(pt);
  pt = strtok(NULL,",");
  if(pt==NULL)
  {
    i=0;
    while(i<a-1)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i++;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return;
  }
  b=atoi(pt);
  pt = strtok (NULL,",");
  if(pt==NULL)
  {
    i=a;
    while(i<b-1)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i++;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return;
  }  
  c=atoi(pt);
  i=a;
  if(c>0)
  {
  while(i<b-c)
  {
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);strcat(temp,",");
    i+=c;
  }
  sprintf(buffer,"%d",i);
  strcat(temp,buffer);
  return;
  }
  else 
  {

    while(i>b-c)
    {
      sprintf(buffer,"%d",i);
      strcat(temp,buffer);strcat(temp,",");
      i+=c;
    }
    sprintf(buffer,"%d",i);
    strcat(temp,buffer);
    return; 
  }

}

void len(char *val,char *temp)
{
  int t=strlen(val);
  t=t-t/2;
  sprintf(temp,"%d",t);
}

int tempno = 0, ln = 0; //temp variable no, label no
int exprno = -1; //expr no

%} 




%union{ struct{char value[1024]; int type;struct Node *node;char lhs[1024]  ;char code[1024];char begin[1024]; char end[1024];}ctype; char val[1024]; }; //chars for prod rules
%token DOT LINE FALSE NONE TRUE LAND BREAK CONTINUE ELIF DEL ELSE FOR IF IN NOT LOR INPUT PRINT INT FLOAT STR LIST SPLIT MAP APPEND POP INSERT LEN ID CINT CFLOAT SEMI COMMA CSTR EPOP MUL DIV FDIV MOD ADD SUB ASOP G L GE LE EOP NEOP XOR BAND BOR LPAREN RPAREN LBRACKET RBRACKET RANGE COLON
%type <ctype> Exp Const Or_Exp And_Exp In_Exp Eq_Exp Rel_Exp Bit_Exp Add_Exp Mul_Exp Pow_Exp Unary_Exp Primary_Exp ID Iterable Param_list Translation_unit Stmt Assignment_stmt Simple_stmt Compound_stmt Jump_stmt Print_stmt If_stmt Elif_stmt Else_stmt For_stmt Expression_stmt Start
%type<val> DOT LINE FALSE NONE TRUE LAND BREAK CONTINUE ELIF DEL ELSE FOR IF IN NOT LOR INPUT PRINT INT FLOAT STR LIST SPLIT MAP APPEND POP INSERT LEN  CINT CFLOAT SEMI COMMA CSTR EPOP MUL DIV FDIV MOD ADD SUB ASOP G L GE LE EOP NEOP XOR BAND BOR LPAREN RPAREN LBRACKET RBRACKET RANGE COLON 
%% 
Start: Translation_unit //parent
{
  //printf("Here's the start statement!\n");
  printf("%s",$1.code);
  //printf("End of start statement!\n");
}
;
Translation_unit: Stmt Translation_unit  //child
{
  //printf("Here's the translation unit!\n");
  sprintf($$.code,"%s\n%s",$1.code,$2.code); //sprintf: joining multiple parameters and storing the resultant string in one variable($$.code)
  //printf("End of translation unit!\n");
}
| Stmt
{
  strcpy($$.code,$1.code);
}
;
Stmt: Simple_stmt 
{
  strcpy($$.code,$1.code);
}
| Compound_stmt //if, for
{
  strcpy($$.code,$1.code);
}
| Assignment_stmt 
{
  strcpy($$.code,$1.code);
}
;
Assignment_stmt: ID ASOP Exp 
{
  char buff[3]="";
  sprintf(buff,"%d",$3.type); 
  insert("ID",$1.value,buff,$3.value,-1); //inserting var entry to sym table
  sprintf($$.code,"\n=\t%s\t\t%s\n",$3.lhs,$1.value);
};
Simple_stmt: Expression_stmt 
{
  strcpy($$.code,$1.code);
}
| Print_stmt 
{
  paramno=0;
  strcpy($$.code,$1.code);
}
| Jump_stmt 
{
  strcpy($$.code,$1.code);
}
;
Compound_stmt: If_stmt 
{
  strcpy($$.code,$1.code);
} 
| For_stmt 
{
  strcpy($$.code,$1.code);
}
;
Jump_stmt: BREAK 
{
  sprintf($$.code,"goto\t \t \tL%d",ln);

}
| CONTINUE 
{
}
;
Print_stmt: PRINT LPAREN Param_list RPAREN 
{
  sprintf($$.code,"%s\ncall\t \tprint\t%d\n",$3.code,++paramno);
}
;
Param_list: Param_list COMMA Exp  
{
  //printf("reading range parameters\n");
  $$.type=50+$3.type;strcat($$.value,",");
  strcat($$.value,$3.value);
  sprintf($$.lhs,$1.lhs);
  sprintf($$.code,"%s\n\t%s\nparam\t \t \t%s\n",$1.code,$3.code,$3.lhs);
  paramno++;

}
| Exp 
{  
  sprintf($$.lhs,"%s",$1.lhs);
  sprintf($$.code,"%sParam\t\t\t%s\n",$1.code,$1.lhs);
  printf("%s", $1.code);
  //paramno++;
} 
;
If_stmt: IF Exp COLON Translation_unit  
{
  //printf("Value of ln: %d",ln);
  char s[1024]="";
  sprintf(s, "L%d", ln);
  insert("Label",s,NULL,NULL,-1);
  printf("%s\n", $2.code);
  printf("IfFalse\t t%d goto \t%s\n",tempno-1, s );
  printf("%s\n", $4.code);
  printf("Label %s\n", s);
  ln++;
}Elif_stmt Else_stmt
{
	printf("%s\n", $7.code);
}
;
Elif_stmt: ELIF Exp COLON Translation_unit Elif_stmt
{
  char s[1024]="";
  sprintf(s, "L%d", ln);
  insert("Label",s,NULL,NULL,-1);
  printf("%s\n", $2.code);
  printf("IfFalse \tt%d goto \t%s\n",tempno-1, s );
  printf("%s\n", $4.code);
  printf("Label %s\n", s);
  ln++;
} 
| {
  sprintf($$.begin,"L%d",ln);
  sprintf($$.end,"L%d",ln);
  }
;
Else_stmt: ELSE COLON 
{
  char s[1024]="";
  sprintf(s, "L%d", ln);
  //ln++;
  
  
} Translation_unit
{
	printf("%s\n", $4.code);
}
;

For_stmt: FOR ID IN Iterable COLON Translation_unit 
{
  char s[1024]="";
  char s1[1024]="";
  sprintf(s, "L%d", ln);
  sprintf(s1, "L%d", ln+1);
  insert("Label",s,NULL,NULL,-1);
  insert("for_out_Label",s1,NULL,NULL,-1);
  char temp[1024]="";
  first_val($4.value,temp);
  char buff[3]="";
  sprintf(buff,"%d",$4.type%10);
  insert("ID",$2.value,buff,temp,-1);
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s2[1024]="";
  sprintf(s2, "t%d", tempno-1);
  insert("Temp",s2,NULL,NULL,-1);
  sprintf($$.code,"%s",$4.code);
  sprintf($$.code,"\n%sin\t%s\t%s\t%s\nIfFalse\t%s\tgoto\t%s\n\t\t\t\nLabel\t\t \t%s\n%s\ngoto\t\t\t%s\nLabel\t\t\tL%d",$4.code, $2.value,"RANGE", s2,s2,  s1 , s, $6.code,s, ln+1);
  ln+=2;
}
;
Iterable: LBRACKET Param_list RBRACKET  
{
}
| RANGE LPAREN Param_list RPAREN 
{
  $$.type=51;
  char temp[1024]="";
  char s1[1024]="";
  expand($3.value,temp);
  strcpy($$.value,temp);
  sprintf($$.code,"%s",$3.code);
}
; 
Expression_stmt: Exp 
{
  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
;
Exp: Or_Exp 
{
  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
;
Const: CINT 
{
  $$.type=1;
  strcpy($$.value,$1);
  sprintf($$.lhs,"%s",$1);
  exprno=0;
}
| CFLOAT 
{
  $$.type=2;
  strcpy($$.value,$1);
  sprintf($$.lhs,"%s",$1);
  exprno=0;
}
| CSTR 
{
  $$.type=3;
  strcpy($$.value,$1);
  sprintf($$.lhs,"%s",$1);
  exprno=0;
}
| TRUE 
{
  $$.type=4;
  strcpy($$.value,$1);
  sprintf($$.lhs,"%s",$1);
  exprno=0;
}
| FALSE 
{
  $$.type=4;
  strcpy($$.value,$1);
  sprintf($$.lhs,"%s",$1);
  exprno=0;
}
| NONE 
{
  $$.type=5;
  strcpy($$.value,$1);
  sprintf($$.lhs,"%s",$1);
  exprno=0;
}
| INPUT LPAREN RPAREN 
{
  $$.type=3;
  strcpy($$.value,"");
  
  
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  printf("call\t%s\tinput\t0\n",temp_var);
  sprintf($$.lhs,"%s",temp_var);
}
;
Primary_Exp: ID 
{
 
  $$=$1; 
  
  sprintf($$.lhs,"%s",$1.value);
  exprno=0;
}
| Const 
{
  $$=$1;  
}
| LPAREN Exp RPAREN 
{
  $$=$2;
  strcpy($$.code,$2.code);
  sprintf($$.lhs,"%s",temp_var);
  exprno=1;
}
| Iterable 
{
  $$=$1;
  
}
| LEN LPAREN Iterable RPAREN 
{
  $$.type=1;
  char buffer[10]="";
  len($3.value,buffer) ;
  strcpy($$.value,buffer);
  
}
| INT LPAREN Exp RPAREN 
{
  $$.type=1;
  strcpy($$.value,$3.value);
  
}
| FLOAT LPAREN Exp RPAREN 
{
  $$.type=2;
  strcpy($$.value,$3.value);
  
}
| STR LPAREN Exp RPAREN 
{
  $$.type=3;
  strcpy($$.value,$3.value);
  
}
;
Unary_Exp: SUB Primary_Exp 
{
  $$.type=$2.type;
  char buffer[1024]="-";
  strcat(buffer,$2.value);
  strcpy($$.value,buffer);
  

  tempno++;
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf($$.lhs,temp_var);

  printf("Uminus\t%s\t \t%s\n",$2.lhs,$$.lhs);
  sprintf($$.code,"Uminus\t%s\t \t%s\n",$2.lhs,$$.lhs);

  strcpy($$.lhs,$2.lhs);

  exprno=2;
  unop=1;
}
| ADD Primary_Exp 
{

  strcpy($$.code,$2.lhs);


  exprno=2;
  unop=0;


  tempno++;
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf($$.lhs,temp_var);
  sprintf($$.code,"%s = %s ",$$.lhs,$2.lhs);

  printf("Uplus\t%s\t \t%s\n",$2.lhs,$$.lhs);

  
  exprno=2;

}
| NOT Primary_Exp 
{
  $$.type=$2.type;
  char buffer[1024]="-";
  strcat(buffer,$2.value);
  strcpy($$.value,buffer);
  
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy($$.lhs,temp_var);
  sprintf($$.code,"%s = not %s ",temp_var,$2.lhs);

  printf("not\t%s\t\t%s\n",$2.lhs,$$.lhs);


  strcpy($$.code,$2.lhs);


  exprno=2;
  unop=2;

}
| Primary_Exp 
{
  

  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
;
Pow_Exp: Unary_Exp 
{
  
  strcpy($$.code,$1.code);

  }
| Pow_Exp EPOP Unary_Exp 
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n**\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);


  exprno=1;
}
;
Mul_Exp: Pow_Exp 
{
  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
| Mul_Exp MUL Pow_Exp 
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n*\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);

  exprno=1;

}
| Mul_Exp DIV Pow_Exp 
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n/\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);
  printf("/\t%s\t%s\t%s\n",$1.lhs,$3.code,temp_var);
  exprno=1;
}
| Mul_Exp FDIV Pow_Exp 
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n//\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);


}
| Mul_Exp MOD Pow_Exp
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy($$.lhs,temp_var);
  sprintf($$.code,"%s = %s % %s",temp_var,$1.lhs,$3.code);

}
;
Add_Exp: Mul_Exp 
{

  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
| Add_Exp ADD Mul_Exp 
{

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy($$.lhs,temp_var);
  sprintf($$.code,"%s%s\n+\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);
  exprno=1;
}
| Add_Exp SUB Mul_Exp
{

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n-\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);
  
  exprno=1;
}
;
Bit_Exp: Add_Exp 
{

  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
| Bit_Exp XOR Add_Exp 
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n^\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);
  exprno=1;

}
| Bit_Exp BAND Add_Exp 
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  sprintf($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n&\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);
  exprno=1;
}
| Bit_Exp BOR Add_Exp
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  sprintf($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n|\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var); 
  exprno=1;
}
;
Rel_Exp: Bit_Exp 
{
  

  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
| Rel_Exp G Bit_Exp 
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);

  sprintf($$.code,">\t%s\t%s\t%s\n", $1.lhs, $3.lhs, temp_var);
  strncpy($$.lhs, temp_var, m+1);
}
| Rel_Exp GE Bit_Exp 
{
  


  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);


  sprintf($$.code,"%s\n%s\n>=\t%s\t%s\t%s\n", $1.code, $3.code,$1.lhs,$3.lhs, temp_var);
  strncpy($$.lhs, temp_var, m+1);
}
| Rel_Exp L Bit_Exp 
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);

  sprintf($$.code,"%s\n%s\n<\t%s\t%s\t%s\n", $1.code, $3.code,$1.lhs,$3.lhs, temp_var);
  strncpy($$.lhs, temp_var, m+1);
}
| Rel_Exp LE Bit_Exp
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);

  sprintf($$.code,"<=\t%s\t%s\t%s\n", $1.code, $3.code, temp_var);
  strncpy($$.lhs, temp_var, m+1);
}
;
Eq_Exp: Rel_Exp 
{
  

  strcpy($$.code,$1.code);
}
| Eq_Exp EOP Rel_Exp 
{
  

  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);



  strcpy($$.lhs,temp_var);
  sprintf($$.code,"%s\n%s\n==\t%s\t%s\t%s\n", $1.code, $3.code,$1.lhs,$3.lhs, temp_var);
}
| Eq_Exp NEOP Rel_Exp 
{
  


  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  sprintf("%s\n%s\n!=\t%s\t%s\t%s\n", $1.code, $3.code,$1.lhs,$3.lhs, temp_var);

  strncpy($$.lhs, temp_var, m+1);   //check out
}
;
In_Exp: Eq_Exp 
{
  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
| Eq_Exp IN In_Exp   
{ 
}
;
And_Exp: In_Exp 
{
  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
| In_Exp LAND And_Exp   
{
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy($$.lhs,temp_var);
  sprintf($$.code,"%s%s\nand\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);
}
;
Or_Exp: And_Exp 
{
  $$=$1;  
  strcpy($$.code,$1.code);
  strcpy($$.lhs,$1.lhs);
}
| And_Exp LOR Or_Exp 
{
  $$=$1;  
  sprintf(temp_var,"t%d",tempno++);
  m = strlen(temp_var);
  temp_var[m] = '\0';
  char s[1024]="";
  sprintf(s, "t%d", tempno-1);
  insert("Temp",s,NULL,NULL,-1);
  strcpy($$.lhs,temp_var);
  sprintf($$.code,"%s%s\nor\t%s\t%s\t%s\n",$1.code,$3.code,$1.lhs,$3.lhs,temp_var);
}
;

%% 
int yyerror(char *msg) 
{ 
  printf("Syntax Error\n"); 
  return 1;
} 
 
int main() 
{ 
  yyparse();  
  display_symbol();
  return 0;
}

// /\*(.|\n)*?\*/
// ^[ ]*?//.*
