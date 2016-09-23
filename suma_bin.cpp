#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define BUFFtmpflagR_SIZtmpflag 20

using namespace std;
using std::cout;
using std::cin;
using std::endl;

int count_chars(char arr[]){
	int numberofcharacters = 0;
	while(arr[numberofcharacters] != '\0') 
		++numberofcharacters;
	return numberofcharacters;
}

void sum_binary(char majorbuffer[], char minorbuffer[], char result[]){
	bool tmpflag = false;

	int nmajor = count_chars(majorbuffer)-1,
		nminor = count_chars(minorbuffer)-1;
	
	result[nmajor+2] = '\0';
	result[0] = '0';
	
	while(nminor >= 0){
		if(majorbuffer[nmajor] == minorbuffer[nminor]){
			if(majorbuffer[nmajor] == '1'){
				if(tmpflag == true)
					result[nmajor+1] = '1';
				else{
					result[nmajor+1] = '0';
					tmpflag = !tmpflag;
				}

			}
			else{
				if(tmpflag == true){
					result[nmajor+1] = '1';
					tmpflag = !tmpflag;
				}
				else
					result[nmajor+1] = '0';
			}
	
		}
		else{
			if(tmpflag == true)
				result[nmajor+1] = '0';
			else
				result[nmajor+1] = '1';
		}

		--nmajor;
	 	--nminor;
	}

	

	while( nmajor >= 0 ){
		if(tmpflag == true)
			if( majorbuffer[nmajor] == '1')
				result[nmajor+1]  = '0';
			else{
				result[nmajor+1]  = '1';
				tmpflag = false;
			}
		else
			result[nmajor+1]  = majorbuffer[nmajor];

		nmajor--; nminor--;
	}

	if( tmpflag == true )
		result[0]  = '1';

}


void check_major(char binaryBufferA[], char binaryBufferB[],char result[]){
	
	if(count_chars(binaryBufferA) > count_chars(binaryBufferB) )
		sum_binary(binaryBufferA, binaryBufferB, result);
	else
		sum_binary(binaryBufferB, binaryBufferA, result);

}

void show(char arr[]){
	int numberofcharacters = count_chars(arr);

	for(int index = 0; index < numberofcharacters ; index++)
		cout<<arr[index];
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	char binaryBufferA[BUFFtmpflagR_SIZtmpflag],binaryBufferB[BUFFtmpflagR_SIZtmpflag], result[BUFFtmpflagR_SIZtmpflag];

	cout<<"Ingrese binaryBufferes de A: "; 
	cin>>binaryBufferA;
	
	cout<<"Ingrese binaryBufferes de B: "; 
	cin>>binaryBufferB;

	check_major(binaryBufferA,binaryBufferB, result);

	show(result);

	return 0x0;
}

