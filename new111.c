#include<stdio.h> 
#include<string.h> 
#include<ctype.h> 
void main() 
{
char a[20]; 
int i,j=0,x,k; 
FILE *fp; 
if(( fp = fopen("z.dat", "r")) != 0) 
 { 
 while(fscanf(fp,"%s", a) != EOF) 
 { 
 i=0; 
 if( strlen(a)==6) 
 { 
 i=i+3; 
 if(islower(a[i])) 
  printf("lw $t%d, (%c)\n", j++,a[i]); 
 else 
{
for(i=3;i < strlen(a);i++) 
  { 
if(isdigit(a[i]))              
  { 
x= a[i] - '0'; 
k=k*10+x;              
  } 
  } 
printf("li $t%d, %d\n", j,k); 
}
i=i+2; 
if(islower( a[i])) 
printf("lw $t%d, (%c)\n", j++,a[i]); 
 else 
{ 
for(i=3;i < strlen(a);i++) 
  { 
 if(isdigit(a[i]))              
  { 
x= a[i] - '0'; 
  k=k*10+x;              
  } 
}
printf("li $t%d, %d\n", j,k); 
}
i=i-1;              
if(a[i] == '+') 
printf("add $t%d, $t%d, $t%d\n", j,j-1,j-2); 
else if( a[i] == '-') 
printf("sub $t%d, $t%d, $t%d\n", j,j-2,j-1); 
else if( a[i] == '*') 
 printf("mul $t%d, $t%d, $t%d\n", j,j-2,j-1); 
else if( a[i] == '/') 
printf("div $t%d, $t%d, $t%d\n", j,j-2,j-1); 
}              
else if(strlen(a)==4) { 
i=i+3;              
if(islower(a[i]))              
{
printf("lw $t%d, %c\n",j,a[i]); 
printf("copy %c, $t%d\n", a[i-3],j);  
}
else              
 printf("li $t%d, %c\n",j,a[i]); 
} 
j=j+1; 
} 
  } 
  } 

/*
output:
li $t0, 3
lw $t1, (b)
lw $t2, (c)
add $t3, $t2, $t1
lw $t4, y
copy x, $t4
*/