#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define CLEAR(x) memset(x,'\0',1000)
char inp[1000];
char left[1000];
char right[1000];
char leftt[1000];
char rightt[1000];
char bufferr[1000];
char bufferl[1000];
char leftf[1000];
char rightf[1000];

int sizeleft=0;
int sizeright=0;
bool checkbase(int baseinp){
	bool isgood=true;
	int value;
	int i;
	for (i = 0; i < baseinp; i++) {
		if(inp[i]!='.'){
			if((int)inp[i]>=48 && (int)inp[i]<=57){
				value = ((int)inp[i]) -48;
				if (value>=baseinp){
					isgood=false;
				}
			}
			else if((int)inp[i]>=65 && (int)inp[i]<=90){
				value = ((int)inp[i]) -55;
				if (value>=baseinp){
					isgood=false;
				}
			}
			else if((int)inp[i]>=97 && (int)inp[i]<=122){
				value = ((int)inp[i]) -87;
				if (value>=baseinp){
					isgood=false;
				}
			}
		}
	}
	return isgood;
	
}

int totenl(int baseinp){
	int tote=0;
	int be=0;
	int i;
	for(i=strlen(leftt)-1;i>-1;i--){
		int rest=0;
		
		if ((int)leftt[i]>=48 && (int)leftt[i]<=57){
			rest=48;
		}
		else if((int)leftt[i]>=97 && (int)leftt[i]<=122){
			rest=87;
		}
		tote+=(((int)leftt[i]-rest)*(int)pow(baseinp,be));
		/*printf("leftt=%s\n",leftt);
		printf("strlen=%d\n",strlen(leftt));
		printf("long=%d\n",strlen(leftt));
		printf("baseinp =%d be=%d POWER=%lf\n",baseinp,be,pow(baseinp,be));
		printf("leftt=%d  rest=%d\n",(int)leftt[i]-rest,rest);
		printf("TOTE=%d\n",tote);*/
		be++;
	}
	snprintf(bufferl, sizeof(bufferl), "%d", tote);
	return 0;

}
int totenr(int baseinp){
		int be=1;
		double tota=0;
		int i;
		for(i=0;i<strlen(rightt);i++){
			int rest=0;
			if ((int)rightt[i]>=48 && (int)rightt[i]<=57){
				rest=48;
			}
			else if((int)rightt[i]>=97 && (int)rightt[i]<=122){
				rest=87;
			}
			tota+=((int)rightt[i]-rest)* 1/pow(baseinp,be);
			/*printf("leftt=%s\n",rightt);
			printf("strlen=%d\n",strlen(rightt));
			printf("long=%d\n",strlen(rightt));
			printf("baseinp =%d be=%d POWER=%.15f\n",baseinp,be,1/pow(baseinp,be));
			printf("rightt=%d  rest=%d\n",rightt[i]-rest,rest);*/
		//	printf("TOTE=%lf\n",tota);
			be++;
		}
			snprintf(bufferr, sizeof(bufferr), "%.15f", tota);
	return 0;
}
int mod (int a, int b)
{
   if(b < 0) //you can check for b == 0 separately and do what you want
     return mod(a, -b);   
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

int tobasel(int baseout,int number){
	char leftff[9999];
	CLEAR(leftff);
	int pos=0;
	leftf[0]='0';
	while(div(number,baseout).quot>=0 && number!=0 ){
		//printf("number=%d MOD%d\n",number,mod(number,baseout));
			if(mod(number,baseout)<10){
				leftff[pos]=(char)(mod(number,baseout)+48);
				pos++;
				number=div(number,baseout).quot;
			}
			else{
				leftff[pos]=(char)(mod(number,baseout)+87);
				pos++;
				number=div(number,baseout).quot;
			}
		//printf("FINALnumber=%d MOD%d\n",number,mod(number,baseout));
	}
	int i;
	for (i=0;i<strlen(leftff);i++){
		leftf[i]=leftff[strlen(leftff)-1-i];
	}
	//printf("leftF=%s pos=%d",leftf,pos);
	return 0;
}
int tobaser(int baseout,double number){
	int times=15;
	int pos=0;
	rightf[0]='0';
	while (times!=0){
		//printf("NUMBER=%.15f\n",number);
	//	printf("TRUNCATED=%d\n",(int)(number*baseout));
		if((int)(number*baseout)<10){
		
			rightf[pos]=(char)((int)(number*baseout)+48);
			number=(number*baseout)-(int)(number*baseout);
		}
		else{
			rightf[pos]=(char)((int)(number*baseout)+87);
			number=(number*baseout)-(int)(number*baseout);
		}
		times--;
		pos++;
	}
//	printf("\nRIGHTF=%s",rightf);
return 0;
}
int fullconversion(int baseinp,int baseout){

	int l=0;
	int r=0;
	int lefts;
	double rights;
	bool point =false;
	leftt[0]='0';
	rightt[0]='0';
	int i;
	for(i=0;i<strlen(inp);i++){
		if(inp[i]!='.'){
		
			if(!point){
				leftt[l]=inp[i];
				l++;
			}
			else{
				rightt[r]=inp[i];
				r++;
			}
		}
		else{
			point=true;
		}
	}
//	printf("Leftt= %s\n",leftt);
//	printf("righttt= %s\n",rightt);
	if(baseinp!=10){
		if(baseout==10){
			totenl(baseinp);
			totenr(baseinp);
			char nb[1000];
			CLEAR(nb);
			int i;
			for(i=2;i<strlen(bufferr);i++){
				nb[i-2]=bufferr[i];
			}
			int zeros=0;
			if(nb[strlen(nb)-1]=='0'){
				zeros=1;
				int i;
				for(i=strlen(nb)-1;i>1;i--){
					if(nb[i]=='0'&& nb[i-1]=='0'){
						zeros++;
					}
					else{
						break;
					}
				}
			}
			printf("%s.",bufferl);
			
			for(i=0;i<strlen(nb)-zeros;i++){
				printf("%c",nb[i]);
			}
			printf("\n");
		}
		else{
		
			totenl(baseinp);
			totenr(baseinp);
		/*	printf("TENLEFT=%s",bufferl);
			printf("TENRIGHT=%s",bufferr);
			printf("number form l =%d\n",atoi(bufferl));
			printf("number form l =%.15f\n",atof(bufferr));
			printf("SIZE=%d",strlen(bufferr));*/
			tobasel(baseout,atoi(bufferl));
			tobaser(baseout,atof(bufferr));
			int zeros=0;
			if(rightf[strlen(rightf)-1]=='0'){
				zeros=1;
				int i;
				for(i=strlen(rightf)-1;i>1;i--){
					if(rightf[i]=='0'&& rightf[i-1]=='0'){
						zeros++;
					}
					else{
						break;
					}
				}
			}
			printf("%s.",leftf);
			int i;
			for(i=0;i<strlen(rightf)-zeros;i++){
				printf("%c",rightf[i]);
			}
			printf("\n");
		}
	}
	else{	
			char nf[1000];
			CLEAR(nf);
			nf[0]='0';
			nf[1]='.';
			int i;
			for(i=0;i<strlen(rightt);i++){
				nf[i+2]=rightt[i];
			}
			tobasel(baseout,atoi(leftt));
			tobaser(baseout,atof(nf));
			int zeros=0;
			if(rightf[strlen(rightf)-1]=='0'){
				zeros=1;
				int i;
				for(i=strlen(rightf)-1;i>1;i--){
					if(rightf[i]=='0'&& rightf[i-1]=='0'){
						zeros++;
					}
					else{
						break;
					}
				}
			}
			printf("%s.",leftf);
			
			for(i=0;i<strlen(rightf)-zeros;i++){
				printf("%c",rightf[i]);
			}
			printf("\n");
	}
	return 0;
}


int main(){
	int baseinp;
	int baseout;
	int out;
	int count=0;
	
	scanf("%d",&count);
	while (count>0){
		CLEAR(inp);
		CLEAR(left);
		CLEAR(right);
		CLEAR(leftt);
		CLEAR(rightt);
		CLEAR(bufferr);
		CLEAR(bufferl);
		CLEAR(leftf);
		CLEAR(rightf);
		scanf("%d %s %d",&baseinp,&inp,&baseout);
		if(baseinp<2 ||baseinp>36){
			printf("Base origen invalida\n");
	
		}
		else if(!checkbase(baseinp)){
			printf("Numero invalido\n");
	
			
		}
		else if(baseout<2 ||baseout>36){
			printf("Base destino invalida\n");
	
		}
		else if(baseinp==baseout){
			printf("%s\n",inp);
	
		}
		else{
		
			out=fullconversion(baseinp,baseout);
		}
		count--;
	}
	return 0;
}
