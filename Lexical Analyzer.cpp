#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<iostream>
#include<ctype.h>
#include<conio.h>
using namespace std;


void removeduplicate();
void final();
int Isiden(char ch);
int Isop(char ch);
int Isdel(char ch);
int Iskey(char * str);


char op[8]={'+','-','*','/','=','<','>','%'}; 
char del[8]={'}','{',';','(',')','[',']',','}; 
char *key[]={"int","void","main","char","float","return","cout","cin","if","else","while","for"}; 


int idi=0,idj=0,k,opi=0,opj=0,deli=0,uqdi=0,uqidi=0,uqoperi=0,kdi=0,liti=0,ci=0,ei=0; //heeeeeeeeeeeereeeeeeeeeeeeeeeeeeeeeeeeeeeee
int uqdeli[20],uqopi[20],uqideni[20],l=0,j; 
char uqdel[20],uqiden[20][20],uqop[20][20],keyword[20][20]; 
char iden[20][20],oper[20][20],delem[20],litral[20][20],lit[20],number[20][20],err[20][20]; 

void lexanalysis(char *str) 
 { 
   int i=0; 
   while(str[i]!='\0') 
    {
		 if(Isiden(str[i]))     //for identifiers 
       { 
          while(Isiden(str[i])) 
        { 
			
            iden[idi][idj++]=str[i++]; 
        } 
          iden[idi][idj]='\0'; 
          idi++;
	  idj=0; 
       }
 
      else
      if(str[i]=='"')         //for literals 
         { 
         lit[l++]=str[i]; 
         for(j=i+1;str[j]!='"';j++) 
           { 
            lit[l++]=str[j]; 
           } 
         lit[l++]=str[j];lit[l]='\0'; 
         strcpy(litral[liti++],lit); 
         i=j+1; 
         } 
      else 
      if(Isop(str[i]))        // for operators 
          { 
         while(Isop(str[i])) 
            { 
             oper[opi][opj++]=str[i++]; 
            } 
         oper[opi][opj]='\0'; 
         opi++;opj=0; 
          } 
       else 
       if(Isdel(str[i]))     //for delemeters 
          { 
          while(Isdel(str[i])) 
            { 
              delem[deli++]=str[i++]; 
            } 
           } 
        else 
           { 
            i++; 
        } 
     } 

   removeduplicate(); 
   final(); 
} 

int Isiden(char ch) 
 { 
   if(isalpha(ch)||ch=='_'||isdigit(ch)||ch=='.') 
   return 1; 
   else 
   return 0; 
 } 
int Iserror(char * str)		//heeeeeeeeeeeeeeeeeeeereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
 { 
   int x=0;
   if(isdigit(str[x]))
   {
	for (x=1;x<10;x++)
		if(isalpha(str[x]))
	return 1; 
   }
   else
	   return 0;
  }
int Isop(char ch) 
 { 
  int f=0,i; 
  for(i=0;i<8&&!f;i++) 
   { 
    if(ch==op[i]) 
     f=1; 
   } 
 return f; 
} 

int Isdel(char ch) 
 { 
  int f=0,i; 
  for(i=0;i<8&&!f;i++) 
   { 
    if(ch==del[i]) 
     f=1; 
   } 
 return f; 
 } 

int Iskey(char * str) 
{ 
  int i,f=0; 
  for(i=0;i<5;i++) 
   { 
    if(!strcmp(key[i],str)) 
      f=1; 
    } 
  return f; 
} 


void removeduplicate() 
 { 
   int i,j; 
   for(i=0;i<20;i++) 
    { 
     uqdeli[i]=0; 
     uqopi[i]=0; 
     uqideni[i]=0; 
    } 
   for(i=1;i<deli+1;i++)  //remove duplicate delemeters 
     { 
       if(uqdeli[i-1]==0) 
     { 
           uqdel[uqdi++]=delem[i-1]; 
           for(j=i;j<deli;j++) 
          { 
               if(delem[i-1]==delem[j]) 
                uqdeli[j]=1; 
          } 
      } 
     } 

    for(i=1;i<idi+1;i++)  //remove duplicate  identifiers 
       { 
      if(uqideni[i-1]==0) 
         { 
        strcpy(uqiden[uqidi++],iden[i-1]); 
        for(j=i;j<idi;j++) 
         { 
            if(!strcmp(iden[i-1],iden[j])) 
               uqideni[j]=1; 
         } 
          } 
    } 

     for(i=1;i<opi+1;i++)  //remove duplicate  operators 
     { 
        if(uqopi[i-1]==0) 
           { 
           strcpy(uqop[uqoperi++],oper[i-1]); 
           for(j=i;j<opi;j++) 
             { 
               if(!strcmp(oper[i-1],oper[j])) 
                 uqopi[j]=1; 
             } 
           } 
     } 

 } 

void final() 
 { 
  int i=0; 
  idi=0; 
  for(i=0;i<uqidi;i++) 
   { 
     if(Iskey(uqiden[i]))       
     strcpy(keyword[kdi++],uqiden[i]); 
    			//heeeeeeereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
	 else if(Iserror(uqiden[i]))
	strcpy(err[ei++],uqiden[i]);
	  else if(isdigit(uqiden[i][0]))    
     strcpy(number[ci++],uqiden[i]); 
     else 
     strcpy(iden[idi++],uqiden[i]); 
  	
   } 

	
 printf("\n\n##########################################################################\n\n\tDelemeter are : \n"); 
for(i=0;i<uqdi;i++) 
printf("\t%c\n",uqdel[i]); 

	cout<<"\n\tOperators are : \n";
	for (i = 0; i<uqoperi; i++)
	{
		cout<<"\t";
		puts(uqop[i]);
	}

	cout<<"\n\tIdentifiers are : \n";
	for (i = 0; i<idi; i++)
	{
		cout<<"\t";
		puts(iden[i]);
	}

	cout<<"\n\tKeywords are : \n";
	for (i = 0; i<kdi; i++)
	{
		cout<<"\t";
		puts(keyword[i]);
	}

	cout<<"\n\tNumbers are :\n";
	for (i = 0; i<ci; i++)
	{
		printf("\t");
		puts(number[i]);
	}

	cout<<"\n\tLiterals are :\n";
	for (i = 0; i<liti; i++)
	{
		cout<<"\t";
		puts(litral[i]);
	}
	
	cout<<"\n\tErrors are :\n";	//heeeeeeereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
	for (i = 0; i<ei; i++)
	{
		cout<<"\t";
		puts(err[i]);
	}
}
void main() 
{ 
	char str[500]; 
	cout<<"Enter your code then type # and press ENTER to implement Lexical Analyzer:\n";
	cin.getline(str,500,'#');
	lexanalysis(str); 
	getch(); 
}


