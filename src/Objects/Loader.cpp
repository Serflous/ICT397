#include "Loader.h"

Loader::Loader()
{

}

Loader::Loader(const Loader & other)
{

}

Loader::~Loader()
{

}

void Loader::LoadTexture(const char * filename, int x, int y, Texture & tex)
{
	unsigned char * data;
	FILE * fp;

	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		return;
	}

	data = (unsigned char *)malloc(x * y * 4);

	fread(data, x * y * 4, 1, fp);
	fclose(fp);

	GLuint texId;

	glGenTextures(1, &texId);

	glBindTexture(GL_TEXTURE_2D, texId);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)data);

	free(data);

	tex.SetTextureId(texId);

	m_textures.push_back(&tex);

}