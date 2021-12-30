#include <X11/Xlib.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	char name[20] = {0};
	Display *dpy = NULL;
	int screen = 0;
	Window root = { 0 };

	char days[][24] = {
		"VASÁRNAP", "HÉTFŐ", "KEDD", "SZERDA",
	       	"CSÜTÖRTÖK", "PÉNTEK", "SZOMBAT",
	};

	char months[][24] = {
		"JANUÁR", "FEBRUÁR", "MARCIUS",
		"APRILIS", "MÁJUS", "JŰNIUS",
		"JÚLIUS", "AUGUSZTUS", "SZEPTEMBER",
		"OKTÓBER", "NOVEMBER", "DECEMBER",
	};
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	
	while(1) {
		t = time(NULL);
		tm = localtime(&t);
		dpy = XOpenDisplay(NULL);
		if (!dpy) {
			fprintf(stderr, "%s:  unable to open display '%s'\n",
			argv[0], XDisplayName (NULL));
			exit (2);
		}
		screen = DefaultScreen(dpy);
		root = RootWindow(dpy, screen);
		sprintf(name, "%s %02d - %s - %02d:%02d:%02d",
				months[tm->tm_mon],
				tm->tm_mday,
				days[tm->tm_wday],
				tm->tm_hour,
				tm->tm_min,
				tm->tm_sec);
		XStoreName(dpy, root, name);
		XCloseDisplay(dpy);
		sleep(1);
	}
}
