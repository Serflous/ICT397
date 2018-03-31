#ifndef LOADER_H
#define LOADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include "Texture.h"
#include "OBJModel.h"

class Loader
{
public:
	Loader();
	Loader(const Loader & other);
	~Loader();
	void LoadTexture(const char * filename, int x, int y, Texture & tex);
	void LoadOBJModel(const char * filename, OBJModel & model);
private:
private:
	std::vector<Texture*> m_textures;
};

#endif