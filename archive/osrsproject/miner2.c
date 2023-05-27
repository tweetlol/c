#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int mine(int interval, int dt){
	Sleep(1000*interval+200*(dt%3));
	printf("1");
	mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,32767,60915,0,0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	Sleep(1000*interval+200*(dt%3));
	printf("2");
	mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,29058,51363,0,0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	return(0);
}

int drop(){
	int i=0;
	int j=0;
	printf("~dropping load~\n");
	for(i;i<6;i++){
		keybd_event(VK_SHIFT,0x10,KEYEVENTF_EXTENDEDKEY,0);	//PRESS SHIFT
		for(j;j<4;j++){
			Sleep(250);
			mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,56868+j*1903,46810+i*2615,0,0);	//šoup
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);		//KLIK
		}
		j=0;
	}
	keybd_event(VK_SHIFT,0x10,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);		//RELEASE SHIFT
	i=0;
	return(0);
}			

int main(){
	
	int n=0;
	int dt=0;
	int interval=0;
	int count=0;

	printf("Hello world, im autominer.\nEnter interval between mining clicks in seconds and number of clicks in a mining loop (between bag-drops):\n");
	scanf("%i %i",&interval,&count);
	printf("\n------------------------------\nMining interval set to +-%is, click count between drops set to %i.\n",interval,count);
	printf("Press (F6) to toggle autoMINER.\n");
	
	while(1){
		
		while(!GetAsyncKeyState(0x75)){
		}
		while(GetAsyncKeyState(0x75)){	//F6 PRESSED
		}
		printf("AutoMINER has been ENABLED. (interval = %i)\n",interval);
		while(!GetAsyncKeyState(0x75)){	//F6 UNPRESSED
			printf("commencing mining: ");
			for(n;n<count;n++){		//MINING FOR LOOP
				mine(interval,dt);
				dt++;
			}
			drop();	//DROP IT (all inventory except first row)
			n=0;
			dt=0;	//reset variables
		}
		while(GetAsyncKeyState(0x75)){
		}	
		printf("AutoMINER has been DISABLED.\n");
		n=0;
		dt=0;
	}
return(0);
}

















