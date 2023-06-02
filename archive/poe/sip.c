#include<windows.h>
#include<stdio.h>
#include<math.h>


void rest(int c){	//arugment for additive constant, random waiting time between events
	int dt;
	dt = 10+c+rand()%10-rand()%10;	// (10+c) +- 10 [ms]
	Sleep(dt);
}

void ho(int c){	//argument for rest() additive constants (transitive), types "return /hideout return"
	keybd_event(VK_RETURN,0x000D,0,0);
	rest(c);
	keybd_event(VK_RETURN,0x000D,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event(VK_SHIFT,0x0010,0,0);
	rest(c);
	keybd_event(VK_OEM_4,0x00DB,0,0);
	rest(c);
	keybd_event(VK_OEM_4,0x00DB,KEYEVENTF_KEYUP,0);
	rest(c);	
	keybd_event(VK_SHIFT,0x0010,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('H',0x0048,0,0);
	rest(c);
	keybd_event('H',0x0048,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('I',0x0049,0,0);
	rest(c);
	keybd_event('I',0x0049,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('D',0x0044,0,0);
	rest(c);
	keybd_event('D',0x0044,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('E',0x0045,0,0);
	rest(c);
	keybd_event('E',0x0045,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('O',0x004F,0,0);
	rest(c);
	keybd_event('O',0x004F,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('U',0x0055,0,0);
	rest(c);
	keybd_event('U',0x0055,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('T',0x0054,0,0);
	rest(c);
	keybd_event('T',0x0054,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event(VK_RETURN,0x000D,0,0);
	rest(c);
	keybd_event(VK_RETURN,0x000D,KEYEVENTF_KEYUP,0);
}

void sip(int c){	//arguemnt for rest() additive constants (transitive), sips flasks

//	keybd_event(VK_2,0x32,0,0);
//	rest(c);
//	keybd_event(VK_2,0x32,KEYEVENTF_KEYUP,0);
//	rest(c);
	keybd_event('3',0x0033,0,0);
	rest(c);
	keybd_event('3',0x0033,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('4',0x0034,0,0);
	rest(c);
	keybd_event('4',0x0034,KEYEVENTF_KEYUP,0);
	rest(c);
	keybd_event('5',0x0035,0,0);
	rest(c);
	keybd_event('5',0x0035,KEYEVENTF_KEYUP,0);
//	rest(c);
//	keybd_event('6',0x0036,0,0);
//	rest(c);
//	keybd_event('6',0x0036,KEYEVENTF_KEYUP,0);
}


int main(){
	
	while(1){
		while(!GetAsyncKeyState(0x32) && !GetAsyncKeyState(0x04)){
			rest(28);
		}
		while(GetAsyncKeyState(0x32)){
			sip(5);
			break;
		}
		while(GetAsyncKeyState(0x04)){
			ho(3);
			break;
		}
	}
	return(0);
}












