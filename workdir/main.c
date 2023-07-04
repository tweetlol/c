#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<X11/Xlib.h>
#include<X11/keysym.h>
#include<X11/extensions/XTest.h>

int Dt(int delta){
	delta = (delta + 1) % 3;
	return(delta);
}
//clicks the screen (and unclicks)
void Click(Display *screen){
	usleep(5000);
	XTestFakeButtonEvent(screen,Button1,True,0);
	XFlush(screen);
	usleep(10000);
	XTestFakeButtonEvent(screen,Button1,False,0);
	XFlush(screen);
	usleep(5000);
}
//window-size check
void FindUI(Display* screen,Window targetWindow){
	XWindowAttributes targetWindowAttr;
	XGetWindowAttributes(screen,targetWindow,&targetWindowAttr);
	printf("  window.attr.id=%lu\n  window.attr.width=%i\n  window.attr.height=%i\n",targetWindow,targetWindowAttr.width,targetWindowAttr.height);
	printf("expected: 821x558\n");

}
//empties line 2 and lower of inventory (keeps line 1)
void DropBag(Display* screen,Window targetWindow,KeyCode shift){
	int delta=0;
	int i=0;
	int j=0;

	XTestFakeKeyEvent(screen,shift,True,CurrentTime);
	XFlush(screen);
	while(i<4){
		while(j<6){
			XWarpPointer(screen,None,targetWindow,0,0,0,0,590+i*43,301+j*36);
			usleep(120000 * (1+delta));
			delta = Dt(delta);
			printf("dropping slot %ix%i\n",i,j);
			j++;
			XFlush(screen);
			Click(screen);
		}
		j=0;
		i++;
	}
	XTestFakeKeyEvent(screen,shift,False,CurrentTime);
}
//mining loop (2 targets N+W)
void Mine(Display *screen,Window targetWindow){
	int i=0;
	int j=0;
	int delta=0;

	while(i<10){
		XWarpPointer(screen,None,targetWindow,0,0,0,0,390,220);
		XFlush(screen);
		Click(screen);
		sleep(4);
		usleep(12345 * delta);
		XWarpPointer(screen,None,targetWindow,0,0,0,0,500,350);
		XFlush(screen);
		Click(screen);
		sleep(4);
		usleep(13254 * delta);
		delta = Dt(delta);
		i++;
	}
}
//woodcutting loop (1 target N)
void Woodcut(Display *screen,Window targetWindow){
	int i=0;
	int delta=0;
	
	while(i<20){
		XWarpPointer(screen,None,targetWindow,0,0,0,0,390,220);
		XFlush(screen);
		Click(screen);
		sleep(10+delta);
		delta = Dt(delta);
		i++;
	}
}
//edgeville smelting Bank
void Bank(Display *screen,Window targetWindow){
	int i = 0;
	int j = 0;
	int delta = 0;

	XFlush(screen);
	while(i<3){
		while(j<6){
			XWarpPointer(screen,None,targetWindow,0,0,0,0,595+i*40,270+j*41);
			usleep(112369 * (1+delta));
			delta = Dt(delta);
			printf("banking slot %ix%i\n",i,j);
			j++;
			XFlush(screen);
			Click(screen);
		}
		j=0;
		i++;
	}
	XWarpPointer(screen,None,targetWindow,0,0,0,0,93,133);	//slot at 0x0
	XFlush(screen);
	Click(screen);
	XFlush(screen);
	sleep(1);
	XWarpPointer(screen,None,targetWindow,0,0,0,0,139,133);	//slot at 0x1
	XFlush(screen);
	Click(screen);
	sleep(1);
	XWarpPointer(screen,None,targetWindow,0,0,0,0,490,55);
	XFlush(screen);
	Click(screen);	//this click closes bank interface
}
//edgeville smelting Smelt
void Smelt(Display *screen,Window targetWindow,KeyCode space){
	int i = 0;

	XWarpPointer(screen,None,targetWindow,0,0,0,0,117,369);
	XFlush(screen);
	Click(screen);
	sleep(10);	//walks to furnace for 10 sec
	XTestFakeKeyEvent(screen,space,True,0);
	XFlush(screen);
	usleep(117368);
	XTestFakeKeyEvent(screen,space,False,0);
	XFlush(screen);
	sleep(2);	//first spacebar smelt

	while(i<11){
		XWarpPointer(screen,None,targetWindow,0,0,0,0,363,281);
		XFlush(screen);
		Click(screen);
		sleep(0.2);
		XTestFakeKeyEvent(screen,space,True,0);
		XFlush(screen);
		usleep(137186);
		XTestFakeKeyEvent(screen,space,False,0);
		XFlush(screen);
		sleep(2);
	}	//repeatedly clicks furnace in case of levelup interruptions

	XWarpPointer(screen,None,targetWindow,0,0,0,0,582,188);
	XFlush(screen);
	Click(screen);
	sleep(10);	//walks back to bank for 10 sec and opens bank interface when there
}


//THE INT MAIN
int main(){
	int run;
	Display *screen = XOpenDisplay(NULL);
	if(screen == NULL){
		printf("Unable to open display.\n");
		return(1);
	}

	Window rootWindow = DefaultRootWindow(screen);
	Window targetWindow;
	XEvent event;
	KeyCode shift = XKeysymToKeycode(screen,XK_Shift_L);
	KeyCode space = XKeysymToKeycode(screen,XK_space);


//	find the RL window by CLICKING IT
	printf("Click the target Runelite window...\n");
	XGrabPointer(screen,rootWindow,False,ButtonPressMask,GrabModeAsync,GrabModeAsync,None,None,CurrentTime);
	XNextEvent(screen,&event);

	targetWindow = event.xbutton.subwindow;
	if(targetWindow == None){
		targetWindow = event.xbutton.window;
	}
	XUngrabPointer(screen,CurrentTime);

//	prints window attributes and id for checks, 
	FindUI(screen,targetWindow);
	printf("###############################\n");
	sleep(1);
	printf("1: mining (4sec, 20cycles, North+West)\n2: woodcutting(10+sec, 20cycles, North)\n");
	printf("3: edgeville smelting (leave only resources tab open, X = 14)\n");
	scanf("%i",&run);
	switch(run){
	case 1:
		while(1){
			Mine(screen,targetWindow);
			DropBag(screen,targetWindow,shift);
	 	}
	case 2:
		while(1){
			Woodcut(screen,targetWindow);
			DropBag(screen,targetWindow,shift);
		}
	case 3:
		while(1){
			Bank(screen,targetWindow);
			Smelt(screen,targetWindow,space);
		}
	}
	XCloseDisplay(screen);
	return(0);
}






