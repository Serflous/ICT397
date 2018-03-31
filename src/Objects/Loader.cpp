#include "Loader.h"

Loader::Loader()
{

}

Loader::Loader(const Loader & other)
{

}

Loader::~Loader()
{
	std::vector<Texture*>::iterator texIter;
	for (texIter = m_textures.begin(); texIter != m_textures.end(); texIter++)
	{
		Texture * tex = *texIter;
		tex->Destroy();
	}

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

void Loader::LoadOBJModel(const char * filename, OBJModel & model)
{
	std::vector<glm::vec3> verts;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> norms;
	std::vector<int> indicies;

	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cout << "OBJ Failed to open." << std::endl;
		return;
	}

	std::stringstream ss;
	std::string line = "";
	while (std::getline(file, line))
	{
		ss.str(line);

		// Vertex
		if (line.compare(0, 2, "v ") == 0)
		{
			std::string prefix, x, y, z;
			glm::vec3 vert;
			ss >> prefix >> x >> y >> z;
			vert.x = strtof(x.c_str(), NULL);
			vert.y = strtof(y.c_str(), NULL);
			vert.z = strtof(z.c_str(), NULL);

			verts.push_back(vert);
		}

		// UV
		if (line.compare(0, 3, "vt ") == 0)
		{
			std::string prefix, u, v;
			glm::vec2 uv;
			ss >> prefix >> u >> v;
			uv.x = strtof(u.c_str(), NULL);
			uv.y = strtof(v.c_str(), NULL);

			uvs.push_back(uv);
		}

		// Norms
		if (line.compare(0, 3, "vn ") == 0)
		{
			std::string prefix, x, y, z;
			glm::vec3 norm;
			ss >> prefix >> x >> y >> z;
			norm.x = strtof(x.c_str(), NULL);
			norm.y = strtof(y.c_str(), NULL);
			norm.z = strtof(z.c_str(), NULL);

			norms.push_back(norm);
		}
	}
}