#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/freeglut.h>
#include <iostream>

class Texture
{
public:
	Texture();
	Texture(int textureId);
	Texture(const Texture & other);
	~Texture();

	void BindTexture();
	void Unbind();

	void SetTextureId(int texId);
	int GetTextureId();
private:

private:
	int m_textureId;
};

#endif