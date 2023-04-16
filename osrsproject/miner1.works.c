#include <windows.h>
#include <stdio.h>
#include <stdlib.h>



int main(){
	
	int n=0;
	int interval=0;
	int dt=0;
	int i,j=0;
	int bagline=2615;
	int bagcolumn=1903;
	
	
	printf("Hello world, im autominer.\nEnter interval between mining clicks in seconds:\n");
	scanf("%i",&interval);
	printf("\n------------------------------\nMining interval set to %i s.\n",interval);
	printf("Press (F6) to toggle autoMINER.\nPress (ESC) any time to stop autoMINER.\n");
	
	while(1){
		
		while(!GetAsyncKeyState(0x75)){
		}
		while(GetAsyncKeyState(0x75)){
		}
		printf("AutoMINER has been ENABLED. (interval = %i)\n",interval);
		while(!GetAsyncKeyState(0x75)){
			if(GetAsyncKeyState(0x1B)){
			break;
			}
			printf("commencing mining: ");
			for(n;n<36;n++){		//MINING FOR LOOP
				if(GetAsyncKeyState(0x1B)){
				break;
				break;
				}
			sleep(interval+(dt%3));
			mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,32767,60915,0,0);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			printf("%i, ",n);
			dt++;
			}
			dt=0;
			n=0;
			printf("~dropping load~\n");
			for(i;i<6;i++){
				if(GetAsyncKeyState(0x1B)){
					break;
				}
				keybd_event(VK_SHIFT,0x10,KEYEVENTF_EXTENDEDKEY,0);		//PRESS SHIFT
				for(j;j<4;j++){
					if(GetAsyncKeyState(0x1B)){
						break;
					}
					sleep(1);
					mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,56868+j*bagcolumn,46810+i*bagline,0,0);	//šoup
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);		//KLIK
				}
				j=0;
			}
			keybd_event(VK_SHIFT,0x10,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);		//RELEASE SHIFT
			i=0;
			
		}
		while(GetAsyncKeyState(0x75)){
		}	
		printf("AutoMINER has been DISABLED.\n");
		i,j,n=0;
	}
return(0);
}

















