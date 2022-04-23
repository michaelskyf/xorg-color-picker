#include "x.h"
#include <X11/X.h>
#include <cstdio>
#include <cstdlib>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

X11::X11(const char *display_name)
{
	display = XOpenDisplay(display_name);
	if(!display)
	{
		fprintf(stderr, "Failed to open display. Exiting\n");
		exit(-1);
	}

	root = DefaultRootWindow(display);
}

X11::~X11()
{
	XCloseDisplay(display);
}

long X11::getPixel(int x, int y)
{
	XImage *image = XGetImage(this->display, this->root, x, y, 1, 1, AllPlanes, ZPixmap);

	long ret = image->f.get_pixel(image, 0, 0);

	XDestroyImage(image);

	return ret;
}
