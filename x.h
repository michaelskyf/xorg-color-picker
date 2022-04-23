#pragma once

#include <X11/Xlib.h>

class X11
{
	public:

		X11(const char *display_name);
		~X11();

		long getPixel(int x, int y);

		Display *display;
		Window root;
	private:
};
