#ifndef LOADER_H
#define LOADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>

#include "Texture.h"

class Loader
{
public:
	Loader();
	Loader(const Loader & other);
	~Loader();
	void LoadTexture(const char * filename, int x, int y, Texture & tex);
private:
private:
	std::vector<Texture*> m_textures;
};

#endif