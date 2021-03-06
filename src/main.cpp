#include <stdio.h>
#include "Window\GlutWindow.h"
#include "Objects\Loader.h"

int main(int argc, char ** argv)
{
	GlutWindow * window = GlutWindow::GetInstance();
	Loader * loader = new Loader();
	window->InitializeGlutWindow(&argc, argv);
	Texture tex;
	loader->LoadTexture("res/textures/baloon.raw", 128, 128, tex);
	window->BeginMainGameLoop(tex);

	delete loader;
    return 0;
}

