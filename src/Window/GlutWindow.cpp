#include "GlutWindow.h"

GlutWindow * GlutWindow::m_instance;

GlutWindow::GlutWindow()
{

}

GlutWindow::~GlutWindow()
{

}

GlutWindow::GlutWindow(const GlutWindow & other)
{

}

GlutWindow * GlutWindow::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new GlutWindow();
	}
	return m_instance;
}

int GlutWindow::InitializeGlutWindow(int * argc, char ** argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // Initialize display modes, with RGBA, double buffering, and a depth buffer.
	glutInitWindowPosition(INIT_WINDOW_POS_X, INIT_WINDOW_POS_Y);
	glutInitWindowSize(INIT_WINDOW_SIZE_X, INIT_WINDOW_SIZE_Y);
	glutCreateWindow(WINDOW_TITLE);
	glutDisplayFunc(StaticDrawCallback);
	glutIdleFunc(StaticDrawCallback);
	glutReshapeFunc(StaticReshapeCallback);
	glutKeyboardFunc(StaticKeyboardCallback);
	glutKeyboardUpFunc(StaticKeyboardUpCallback);
	glutSpecialFunc(StaticSpecialKeyboardCallback);
	glutSpecialUpFunc(StaticSpecialKeyboardUpCallback);
	glClearColor(0.3922f, 0.5843f, 0.9294f, 1.0f);
	return 0;
}

void GlutWindow::DrawCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_TRIANGLES);
		glColor3f(0.4039f, 0.7373f, 0.6314f);
		glVertex3f(0.0f, 0.5f, -5);
		glColor3f(0.5882f, 0.1294f, 0.2118f);
		glVertex3f(0.5f, -0.5f, -5);
		glColor3f(0.2235f, 0.302f, 0.5176f);
		glVertex3f(-0.5f, -0.5f, -5);
	glEnd();

	glutSwapBuffers();
}

void GlutWindow::ReshapeCallback(int w, int h)
{
	float aspectRatio = w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, aspectRatio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void GlutWindow::BeginMainGameLoop()
{
	glutMainLoop();
}

void GlutWindow::StaticDrawCallback()
{
	m_instance->DrawCallback();
}

void GlutWindow::StaticReshapeCallback(int w, int h)
{
	m_instance->ReshapeCallback(w, h);
}

void GlutWindow::StaticKeyboardCallback(unsigned char key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(key, true);
}

void GlutWindow::StaticKeyboardUpCallback(unsigned char key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(key, false);
}

void GlutWindow::StaticSpecialKeyboardCallback(int key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(127 + key, true);
}

void GlutWindow::StaticSpecialKeyboardUpCallback(int key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(127 + key, false);
}