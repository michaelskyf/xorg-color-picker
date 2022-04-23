#include <cstdio>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xfixes.h>
#include "x.h"


int main(int argc, char **argv)
{
	const char *xdisplay;
	const char *envdisplay = getenv("DISPLAY");
	if(envdisplay)
	{
		xdisplay = envdisplay;
	}
	else
	{
		xdisplay = ":0";
	}

	X11 *x11 = new X11(xdisplay);
	if(!x11)
	{
		fprintf(stderr, "Failed to open X11 Display '%s'. Exiting\n", xdisplay);
		exit(-1);
	}

	/* Get cursor position */
	XFixesCursorImage *xcursor = XFixesGetCursorImage(x11->display);
	if(!xcursor)
	{
		fprintf(stderr, "Failed to get cursor position. Exiting\n");
		exit(-1);
	}

	long pixel = x11->getPixel(xcursor->x, xcursor->y);
	printf("%lx\n", pixel);

	delete x11;

	return 0;
}
