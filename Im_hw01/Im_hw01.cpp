// Im_hw01.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "Char.h"
#include <stdlib.h>
//==============================================================================
void display();
void init();

//==============================================================================
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize/*(1248, 366); */(416,122);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glewInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
//==============================================================================
void display(void)
{
	/* clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 1.0, 1.0);
	/*glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	*/
	getN(0.0096f, 1 - 0.8032f, 0.0384f, 1 - 0.9426f,0.0048f);
	geta(0.0576f,1-0.8688f,0.0697f,1-0.8524f,0.0048f);
	gett(0.0937f,1-0.836f,0.0985f,1-0.9262f,0.0048f,0.0163f);
	geti(0.1177f,1-0.795f,1-0.836f,1-0.9426f,0.0048f,0.0163f);
	geto(0.1322f, 1 - 0.8852f, 0.1466f, 1 - 0.8360f, 0.0048f, 0.0163f);
	getnh(0.173f,1-0.836f,1-0.8606f,1-0.9344f,0.1826f,1-0.836f,0.0048f);
	geta(0.2115f,1-0.8688f,0.2235f,1-0.8524f,0.0048f);
	getl(0.25f,1-0.795f,1-0.9426f,0.0048f);
	getC(0.2812f,1-0.8688f,0.3004f,1-0.795f,0.0048f,0.0163f);
	getnh(0.3317f, 1 - 0.795f, 1 - 0.8606f, 1 - 0.9344f, 0.3413f, 1 - 0.836f, 0.0048f);
	getu(0.3701f,1-0.836f,1-0.918f,0.3798f,1-0.9426f,0.0048f,0.0163f);
	getnh(0.4086f, 1 - 0.836f, 1 - 0.8606f, 1 - 0.9344f, 0.4182f, 1 - 0.836f, 0.0048f);
	getg(0.4447f, 1 - 0.8852f, 0.4567f, 1 - 0.8360f, 0.4687f, 1 - 0.959f, 0.0f,0.0048f,0.0163f);
	getH(0.5f,1-0.795f,1-0.8688f,1-0.9426f,0.5288f,0.0048f,0.0163f);
	getS(0.548f,1-0.8606f,0.56f,1-0.8278f,1-0.9098f,1-0.9426f,0.0048f,0.0163f);
	geti(0.5841f, 1 - 0.795f, 1 - 0.836f, 1 - 0.9426f, 0.0048f, 0.0163f);
	getnh(0.6009f, 1 - 0.836f, 1 - 0.8606f, 1 - 0.9344f, 0.6105f, 1 - 0.836f, 0.0048f);
	getg(0.6394f, 1 - 0.8852f, 0.6514f, 1 - 0.8360f, 0.6634f, 1 - 0.959f, 0.0f, 0.0048f, 0.0163f);
	getU(0.6923f,1-0.795f,1-0.9016f,0.7067f,1-0.9426f,0.0048f,0.0163f);
	getnh(0.7427f, 1 - 0.836f, 1 - 0.8606f, 1 - 0.9344f, 0.7524f, 1 - 0.836f, 0.0048f);
	geti(0.7812f, 1 - 0.795f, 1 - 0.836f, 1 - 0.9426f, 0.0048f, 0.0163f);
	getv(0.7956f,1-0.836f,0.81f,1-0.9426f,0.0048f,0.0163f);

	gete(0.8317f, 1 - 0.8852f, 0.8413f, 1 - 0.8360f, 0.0048f, 0.0163f);

	glutSwapBuffers();
	/* don't wait!
	* start processing buffered OpenGL routines
	*/
	// glFlush ();
}
//==============================================================================
void init(void)
{
	/* select clearing color 	*/
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
//==============================================================================
