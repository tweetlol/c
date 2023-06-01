#include<windows.h>
#include<stdio.h>
#include<math.h>


void rest(int c){	//arugment for additive constant
	int dt;
	dt = c+rand()%10;
	Sleep(dt);
}

void sip(int c){	//arguemnt for rest() additive constants (transitive)
//	keybd_event(VK_2,0x32,0,0);
//	rest(c);
//	keybd_event(VK_2,0x32,KEYEVENTF_KEYUP,0);
	keybd_event('3',0x0033,0,0);
	rest(c);
	keybd_event('4',0x0034,0,0);
	rest(c);
	keybd_event('5',0x0035,0,0);
	rest(c);
	keybd_event('3',0x0033,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('4',0x0034,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('5',0x0035,KEYEVENTF_KEYUP,0);
}


int main(){
	
	while(1){
		while(!GetAsyncKeyState(0x32)){
			rest(18);
		}
		while(GetAsyncKeyState(0x32)){
		}
		sip(5);
	}
	return(0);
}












