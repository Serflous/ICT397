#ifndef OBJMODEL_H
#define OBJMODEL_H

#include <GL/freeglut.h>

class OBJModel
{
public:
	OBJModel();
	OBJModel(const OBJModel & other);
	~OBJModel();

	void SetListId(GLuint listId);
	GLuint GetListId();
private:

private:
	GLuint m_listId;
};

#endif