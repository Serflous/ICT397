#include "Texture.h"

Texture::Texture()
{

}

Texture::Texture(int textureId)
{
	m_textureId = textureId;
}

Texture::Texture(const Texture & other)
{
	m_textureId = other.m_textureId;
}

Texture::~Texture()
{

}

void Texture::BindTexture()
{
	glBindTexture(GL_TEXTURE_2D, m_textureId);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::SetTextureId(int texId)
{
	m_textureId = texId;
}

int Texture::GetTextureId()
{
	return m_textureId;
}

void Texture::Destroy()
{
	glDeleteTextures(1, &m_textureId);
}