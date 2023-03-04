#include <stdio.h>

int fun1 (char mas1[], char mas2[]){
	for (int a = 0; mas1[a] != '\0'; a++){
        	if (mas1[a] != mas2[a])
			return 0;
	}
    return 3;
}

int fun2 (char mas1[], char mas2[]){
	for (int a = 0; mas1[a] != '\0'; a++){
        	if (mas1[a] != mas2[a])
			return 1;
	}
    return 3;
}


int fun3 (char mas1[], char mas2[]){
	for (int i =1; i <= 10; i++) {
           for(int j= 1; j <= 10; j++){
           }
    }
    return 1;
}

void fun4 (char mas1[], char mas2[]){
	for (int a = 0, b = 0; mas1[a] != '\0'; a++){
        	if (mas1[a] != mas2[a])
                b++;
        
	}
}


int main()
{
	char key[] = "key";
	char vvod[1000];
	int control1, control2;
    
    printf("Print your pasword:\n");
    scanf("%s", vvod);
    
    control1 = fun1( key, vvod);
    control1 = fun3( key, vvod) + 2;
    fun4( key, vvod);
    
    if (0==0)
        goto M2;
    
    if(control1 == 3){ 
        control2 = 3;
	}
	
    if(control1 == 1){ 
        control2 = 1;
	}
    
	if(control1 == 1){
		printf("You entered the wrong password. This is a failure :(\n");		
		goto M1;
	}
		
	printf("You entered the correct password! It is success!!!\n");
    return 0;
    
	M1: return 0;
    
    M2: control1 = fun2( key, vvod);
    
    
}
