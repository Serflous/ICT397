#include <stdio.h>
#include "Window\GlutWindow.h"

int main(int argc, char ** argv)
{
	GlutWindow * window = new GlutWindow();
	window->InitializeGlutWindow(&argc, argv);
	window->BeginMainGameLoop();

    return 0;
}

