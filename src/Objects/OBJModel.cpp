#include "OBJModel.h"

OBJModel::OBJModel()
{

}

OBJModel::OBJModel(const OBJModel & other)
{

}

OBJModel::~OBJModel()
{

}

void OBJModel::SetListId(GLuint listId)
{
	m_listId = listId;
}

GLuint OBJModel::GetListId()
{
	return m_listId;
}