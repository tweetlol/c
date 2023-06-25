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
void Click(Display *screen){
	XTestFakeButtonEvent(screen,Button1,True,0);
	XFlush(screen);
	usleep(30000);
	XTestFakeButtonEvent(screen,Button1,False,0);
	XFlush(screen);
}
void FindUI(Display* screen,Window targetWindow){
	XWindowAttributes targetWindowAttr;
	XGetWindowAttributes(screen,targetWindow,&targetWindowAttr);

	printf("window.attr.id=%lu\nwindow.attr.width=%i\nwindow.attr.height=%i\n",targetWindow,targetWindowAttr.width,targetWindowAttr.height);

}

void DropBag(Display* screen,Window targetWindow,KeyCode shift){
	int delta=0;
	int i=0;
	int j=0;

	XTestFakeKeyEvent(screen,shift,True,CurrentTime);
	XFlush(screen);
	while(i<4){
		while(j<6){
			XWarpPointer(screen,None,targetWindow,0,0,0,0,590+i*43,301+j*36);
			j++;
			usleep(170000 * (1+delta));
			delta = Dt(delta);
			printf("dropping slot %ix%i\n",i,j);
			XFlush(screen);
			Click(screen);
		}
		j=0;
		i++;
	}
	XTestFakeKeyEvent(screen,shift,False,CurrentTime);
}

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

//	THE INT MAIN
int main(){
	
	Display *screen = XOpenDisplay(NULL);
	if(screen == NULL){
		printf("Unable to open display.\n");
		return(1);
	}

	Window rootWindow = DefaultRootWindow(screen);
	Window targetWindow;
	XEvent event;
	KeyCode shift = XKeysymToKeycode(screen,XK_Shift_L);

	//	find the RL window by CLICKING IT
	printf("Click the target Runelite window...\n");
	XGrabPointer(screen,rootWindow,False,ButtonPressMask,GrabModeAsync,GrabModeAsync,None,None,CurrentTime);
	XNextEvent(screen,&event);

	targetWindow = event.xbutton.subwindow;
	if(targetWindow == None){
		targetWindow = event.xbutton.window;
	}
	XUngrabPointer(screen,CurrentTime);
	printf("targetWindow set to %lu\n",targetWindow);

//	prints window attributes and id for checks, 
	FindUI(screen,targetWindow);
	sleep(1);
	
	while(1){
		Mine(screen,targetWindow);
		DropBag(screen,targetWindow,shift);
	}

	XCloseDisplay(screen);
	return(0);
}






