#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<X11/Xlib.h>
#include<X11/extensions/XTest.h>

int Dt(int delta){
	delta = (delta + 1) % 3;
	return(delta);
}
void Click(Display *screen){
	int delta=0;

	XTestFakeButtonEvent(screen,Button1,True,0);
	XFlush(screen);
	usleep(10000 * delta);
	delta = Dt(delta);
	XTestFakeButtonEvent(screen,Button1,False,0);
	XFlush(screen);
}
void FindUI(Display* screen,Window targetWindow){	//najde levý horní roh UI, pro automatizaci UI manipulace vztaženo o oknu (multibox?)
//	Window window; //najít target window pomocí Xlib funkcí...
	XWindowAttributes targetWindowAttr;
	XGetWindowAttributes(screen,targetWindow,&targetWindowAttr);

	printf("window.attr.id=%lu\nwindow.attr.width=%i\nwindow.attr.height=%i\n",targetWindow,targetWindowAttr.width,targetWindowAttr.height);

}

void DropBag(Display* screen,Window targetWindow){
	int delta=0;
	int i=0;
	int j=0;
	while(i<4){
		while(j<6){
			XWarpPointer(screen,None,targetWindow,0,0,0,0,587+i*43,277+j*29);
			j++;
			usleep(100000 * delta);
			delta = Dt(delta);
			printf("dropping slot %ix%i\n",i,j);
			XFlush(screen);
			Click(screen);
		}
		j=0;
		i++;
	}
}// NEXT UP : XWarpPointer for cursor placement



int main(){
	printf("Click the target Runelite window...\n");
	Display *screen = XOpenDisplay(NULL);
	if(screen == NULL){
		printf("Unable to open display.\n");
		return(1);
	}
	Window rootWindow = DefaultRootWindow(screen);
	Window targetWindow;
	XEvent event;
	printf("load screen var, rootWindow var, proceeding to grabbing a pointer and waiting for event"\n);
//	find the RL window by CLICKING IT
	XGrabPointer(screen,rootWindow,False,ButtonPressMask,GrabModeAsync,GrabModeAsync,None,None,CurrentTime);
	XNextEvent(screen,&event);

	targetWindow = event.xbutton.subwindow;
	if(targetWindow == None){
		targetWindow = event.xbutton.window;
		printf("targetWindow set to %lu\n",targetWindow);
	}
	XUngrabPointer(screen,CurrentTime);
	printf("ungrabbing pointer\n");
//	prints window attributes and id for checks, 
	FindUI(screen,targetWindow);
	printf("sleeping for a second, then bagdropping\n");
	sleep(1);

	DropBag(screen,targetWindow);

	XCloseDisplay(screen);
	return(0);
}






