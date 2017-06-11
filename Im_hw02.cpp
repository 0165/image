/***************************
4103056005 林佑儒 第1次作業 4/11
***************************/
#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
//==============================================================================
bool	isBack=false;
float	place = 0.0f;
//==============================================================================
void init(void);
void display(void);
void change(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
//==============================================================================
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(416 * 2, 122 * 2);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glewInit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
//==============================================================================
void change(void){
	if (isBack)		place -= 0.001f;
	else				place += 0.001f;
	if (abs(place) > 2.0f)	isBack = !isBack;
	glutPostRedisplay();
}
//==============================================================================
void display(void)
{
	static GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	static GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	static GLfloat mat_ambient_color[] = { 0.8f, 0.8f, 0.2f, 1.0f };
	static GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	static GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	static GLfloat no_shininess[] = { 0.0f };
	static GLfloat low_shininess[] = { 5.0f };
	static GLfloat high_shininess[] = { 100.0f };
	static GLfloat mat_emission[] = { 0.3f, 0.2f, 0.2f, 0.0f };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	gluLookAt(-5.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(place, 0.0f, place);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glScalef(2.0f, 0.7f, 2.0f);
	glutSolidCube(1.0);
	glPopMatrix();

	change();
	glutSwapBuffers();
}
//==============================================================================
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h / 2, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
//==============================================================================
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}
//==============================================================================
void init(void)
{
	GLfloat ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat diffuse[] = { 0.5f, 1.0f, 1.0f, 1.0f };
	GLfloat position[] = { 1.0f, 1.0f, 1.5f, 0.0f };			//to (0,0,0)
	GLfloat lmodel_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat local_view[] = { 0.0f };

	glClearColor(0.3f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
//==============================================================================