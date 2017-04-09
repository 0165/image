/***************************
4103056005 林佑儒 第1次作業 4/11
***************************/
#include "stdafx.h"
#include <stdlib.h>
#include "Array.h"
//==============================================================================
int model = 1;
int turn = 0;
int lturn = 0;
static GLfloat spin = 0.0;
//==============================================================================
void init();
void display();
void spinDisplay();
void mouse(int, int, int, int);
void fun_1();
void fun_2();
void fun_3();
void fun_4();
void keyboard(unsigned char, int , int );
//==============================================================================
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(416*2,122*2);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glewInit();
	glutDisplayFunc(display);	
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
//==============================================================================
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.5, 0.5, -0.5, 0.5, -1.0, 1.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
}
//==============================================================================
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case '1':	model = 1;	break;
		case '2':	model = 2;	break;
		case '3':	model = 3;	break;
		case '4':	model = 4;	break;
		default:	model = 5;	break;
	}
	display();
}
//==============================================================================
void spinDisplay(void)
{
	spin = spin + 0.03f;
	if (spin > 360.0f)
		spin = spin - 360.0f;
	glutPostRedisplay();
}
//==============================================================================
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
		case GLUT_LEFT_BUTTON:		turn = 1;		break;
		case GLUT_MIDDLE_BUTTON:	turn = 2;		break;
		case GLUT_RIGHT_BUTTON:	turn = 3;		break;
		default:									turn = 4;		break;
	}
	if (lturn != turn)	spin = 0;
	lturn = turn;
}
//==============================================================================
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	switch (turn) {
		case 1:	glRotatef(spin, 0.0f, 0.0f, 1.0f);	break;
		case 2:	glRotatef(spin, 0.0f, 1.0f, 0.0f);	break;
		case 3:	glRotatef(spin, 1.0f, 0.0f, 0.0f);	break;
		default:	break;
	}
	glTranslatef(-0.5f, -0.5f, 0.0f);
	switch (model) {
		case 1:	fun_1();	break;
		case 2:	fun_2();	break;
		case 3:	fun_3();	break;
		case 4:	fun_4();	break;
		default:	break;
	}
	spinDisplay();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}
//==============================================================================
void fun_4(){
	glVertexPointer(3, GL_FLOAT, 0, eji);
	glColorPointer(3, GL_FLOAT, 0, ceji);
	glMultiDrawElements(GL_POLYGON, keji, GL_UNSIGNED_INT, ieji, 1);
	glMultiDrawElements(GL_TRIANGLES, keji+1, GL_UNSIGNED_INT, ieji+1, 1);
	glMultiDrawElements(GL_POLYGON, keji+2, GL_UNSIGNED_INT, ieji+2, 2);
	
	glVertexPointer(3, GL_FLOAT, 0, xu);
	glColorPointer(3, GL_FLOAT, 0, cxu);
	glMultiDrawElements(GL_POLYGON, kxu, GL_UNSIGNED_INT, ixu, 8);

	glVertexPointer(3, GL_FLOAT, 0, j5);
	glColorPointer(3, GL_FLOAT, 0, cj5);
	glMultiDrawElements(GL_POLYGON, kj5, GL_UNSIGNED_INT, ij5, 7);

	glVertexPointer(3, GL_FLOAT, 0, vu);
	glColorPointer(3, GL_FLOAT, 0, cvu);
	glMultiDrawElements(GL_POLYGON, kvu, GL_UNSIGNED_INT, ivu, 16);
	glMultiDrawElements(GL_TRIANGLES, kvu + 16, GL_UNSIGNED_INT, ivu + 16, 1);
	
	glVertexPointer(3, GL_FLOAT, 0, u2);
	glColorPointer(3, GL_FLOAT, 0, cu2);
	glMultiDrawElements(GL_POLYGON, ku2, GL_UNSIGNED_INT, iu2, 5);
	glMultiDrawElements(GL_TRIANGLES, ku2 + 5, GL_UNSIGNED_INT, iu2 + 5, 1);
	
	glVertexPointer(3, GL_FLOAT, 0, vm);
	glColorPointer(3, GL_FLOAT, 0, cvm);
	glMultiDrawElements(GL_POLYGON, kvm, GL_UNSIGNED_INT, ivm, 7);
	glMultiDrawElements(GL_TRIANGLES, kvm + 7, GL_UNSIGNED_INT, ivm + 7, 1);
	glMultiDrawElements(GL_POLYGON, kvm+8, GL_UNSIGNED_INT, ivm+8, 2);
	glMultiDrawElements(GL_TRIANGLES, kvm + 10, GL_UNSIGNED_INT, ivm + 10, 1);
	glMultiDrawElements(GL_POLYGON, kvm+10, GL_UNSIGNED_INT, ivm+10, 6);

	glVertexPointer(3, GL_FLOAT, 0, english);
	glColorPointer(3, GL_FLOAT, 0, cenglish);
	glMultiDrawElements(GL_TRIANGLES, kenglish, GL_UNSIGNED_INT, ienglish, 1);
	
	glVertexPointer(3, GL_FLOAT, 0, logo);
	glColorPointer(3, GL_FLOAT, 0, clogo);
	glMultiDrawElements(GL_TRIANGLES, klogo, GL_UNSIGNED_INT, ilogo, 1);
	glMultiDrawElements(GL_POLYGON, klogo + 1, GL_UNSIGNED_INT, ilogo + 1, 4);
	glMultiDrawElements(GL_TRIANGLES, klogo+5, GL_UNSIGNED_INT, ilogo+5, 1);
	glMultiDrawElements(GL_POLYGON, klogo + 6, GL_UNSIGNED_INT, ilogo + 6, 3);

}
//==============================================================================
void fun_3(){
	glVertexPointer(3, GL_FLOAT, 0, eji);
	glColorPointer(3, GL_FLOAT, 0, ceji);
	glMultiDrawArrays(GL_POLYGON, feji, keji, 1);
	glMultiDrawArrays(GL_TRIANGLES, feji+1, keji+1, 1);
	glMultiDrawArrays(GL_POLYGON, feji+2, keji+2, 2);
	
	glVertexPointer(3, GL_FLOAT, 0, xu);
	glColorPointer(3, GL_FLOAT, 0, cxu);
	glMultiDrawArrays(GL_POLYGON,fxu,kxu,8);

	glVertexPointer(3, GL_FLOAT, 0, j5);
	glColorPointer(3, GL_FLOAT, 0, cj5);
	glMultiDrawArrays(GL_POLYGON, fj5, kj5, 7);

	glVertexPointer(3, GL_FLOAT, 0, vu);
	glColorPointer(3, GL_FLOAT, 0, cvu);
	glMultiDrawArrays(GL_POLYGON, fvu, kvu,16);
	glMultiDrawArrays(GL_TRIANGLES, fvu+16, kvu+16, 1);

	glVertexPointer(3, GL_FLOAT, 0, u2);
	glColorPointer(3, GL_FLOAT, 0, cu2);
	glMultiDrawArrays(GL_POLYGON, fu2, ku2, 5);
	glMultiDrawArrays(GL_TRIANGLES, fu2 + 5, ku2 + 5, 1);

	glVertexPointer(3, GL_FLOAT, 0, vm);
	glColorPointer(3, GL_FLOAT, 0, cvm);
	glMultiDrawArrays(GL_POLYGON, fvm, kvm, 7);
	glMultiDrawArrays(GL_TRIANGLES, fvm + 7, kvm + 7, 1);
	glMultiDrawArrays(GL_POLYGON, fvm+8, kvm+8, 2);
	glMultiDrawArrays(GL_TRIANGLES, fvm + 10, kvm + 10, 1);
	glMultiDrawArrays(GL_POLYGON, fvm + 10, kvm + 10, 6);

	glVertexPointer(3, GL_FLOAT, 0, english);
	glColorPointer(3, GL_FLOAT, 0, cenglish);
	glMultiDrawArrays(GL_TRIANGLES, fenglish, kenglish, 1);

	glVertexPointer(3, GL_FLOAT, 0, logo);
	glColorPointer(3, GL_FLOAT, 0, clogo);
	glMultiDrawArrays(GL_TRIANGLES, flogo, klogo, 1);
	glMultiDrawArrays(GL_POLYGON, flogo+1, klogo+1, 4);
	glMultiDrawArrays(GL_TRIANGLES, flogo+5, klogo+5, 1);
	glMultiDrawArrays(GL_POLYGON, flogo+6, klogo+6, 3);
}
//==============================================================================
void fun_2(){
	int i = 0;
	glInterleavedArrays(GL_C3F_V3F, 0, inteji);
	glDrawElements(GL_POLYGON, keji[0], GL_UNSIGNED_INT, ieji[0]);
	glDrawElements(GL_TRIANGLES, keji[1], GL_UNSIGNED_INT, ieji[1]);
	glDrawElements(GL_POLYGON, keji[2], GL_UNSIGNED_INT, ieji[2]);
	glDrawElements(GL_POLYGON, keji[3], GL_UNSIGNED_INT, ieji[3]);

	glVertexPointer(3, GL_FLOAT, 0, xu);
	glColorPointer(3, GL_FLOAT, 0, cxu);
	for (i = 0; i < 8; i++)		glDrawElements(GL_POLYGON, kxu[i], GL_UNSIGNED_INT, ixu[i]);
	
	glVertexPointer(3, GL_FLOAT, 0, j5);
	glColorPointer(3, GL_FLOAT, 0, cj5);
	for (i = 0; i < 7; i++)		glDrawElements(GL_POLYGON, kj5[i], GL_UNSIGNED_INT, ij5[i]);
	
	glVertexPointer(3, GL_FLOAT, 0, vu);
	glColorPointer(3, GL_FLOAT, 0, cvu);
	for (i = 0; i < 16; i++)		glDrawElements(GL_POLYGON, kvu[i], GL_UNSIGNED_INT, ivu[i]);
	glDrawElements(GL_TRIANGLES, kvu[i], GL_UNSIGNED_INT, ivu[i]);

	glVertexPointer(3, GL_FLOAT, 0, u2);
	glColorPointer(3, GL_FLOAT, 0, cu2);
	for (i = 0; i < 5; i++)		glDrawElements(GL_POLYGON, ku2[i], GL_UNSIGNED_INT, iu2[i]);
	glDrawElements(GL_TRIANGLES, ku2[i], GL_UNSIGNED_INT, iu2[i]);
	
	glVertexPointer(3, GL_FLOAT, 0, vm);
	glColorPointer(3, GL_FLOAT, 0, cvm);
	for (i = 0; i < 7; i++)		glDrawElements(GL_POLYGON, kvm[i], GL_UNSIGNED_INT, ivm[i]);
	glDrawElements(GL_TRIANGLES, kvm[i], GL_UNSIGNED_INT, ivm[i]);
	for (i = 8; i < 10; i++)		glDrawElements(GL_POLYGON, kvm[i], GL_UNSIGNED_INT, ivm[i]);
	glDrawElements(GL_TRIANGLES, kvm[i], GL_UNSIGNED_INT, ivm[i]);
	for (i = 10; i < 16; i++)		glDrawElements(GL_POLYGON, kvm[i], GL_UNSIGNED_INT, ivm[i]);

	glVertexPointer(3, GL_FLOAT, 0, english);
	glColorPointer(3, GL_FLOAT, 0, cenglish);
	glDrawElements(GL_TRIANGLES, kenglish[0], GL_UNSIGNED_INT, ienglish[0]);

	glVertexPointer(3, GL_FLOAT, 0, logo);
	glColorPointer(3, GL_FLOAT, 0, clogo);
	glDrawElements(GL_TRIANGLES, klogo[0], GL_UNSIGNED_INT, ilogo[0]);
	for (i = 1; i < 5; i++)		glDrawElements(GL_POLYGON, klogo[i], GL_UNSIGNED_INT, ilogo[i]);
	glDrawElements(GL_TRIANGLES, klogo[i], GL_UNSIGNED_INT, ilogo[i]);
	for (i = 6; i < 9; i++)		glDrawElements(GL_POLYGON, klogo[i], GL_UNSIGNED_INT, ilogo[i]);
}
//==============================================================================
void fun_1(){
	int i = 0;

	glVertexPointer(3, GL_FLOAT, 0, eji); 
	glColorPointer(3, GL_FLOAT, 0, ceji);
	glDrawArrays(GL_POLYGON, feji[0], keji[0]);
	glDrawArrays(GL_TRIANGLES, feji[1], keji[1]);
	glDrawArrays(GL_POLYGON, feji[2], keji[2]);
	glDrawArrays(GL_POLYGON, feji[3], keji[3]);

	glVertexPointer(3, GL_FLOAT, 0, xu);
	glColorPointer(3, GL_FLOAT, 0, cxu);
	for (i = 0; i < 8;i++)		glDrawArrays(GL_POLYGON, fxu[i], kxu[i]);
	
	glVertexPointer(3, GL_FLOAT, 0, j5);
	glColorPointer(3, GL_FLOAT, 0, cj5);
	for (i = 0; i < 7; i++)		glDrawArrays(GL_POLYGON, fj5[i], kj5[i]);

	glVertexPointer(3, GL_FLOAT, 0, vu);
	glColorPointer(3, GL_FLOAT, 0, cvu);
	for (i = 0; i < 16; i++)		glDrawArrays(GL_POLYGON, fvu[i], kvu[i]);
	glDrawArrays(GL_TRIANGLES, fvu[i], kvu[i]);
	
	glVertexPointer(3, GL_FLOAT, 0, u2);
	glColorPointer(3, GL_FLOAT, 0, cu2);
	for (i = 0; i < 5; i++)		glDrawArrays(GL_POLYGON, fu2[i], ku2[i]);
	glDrawArrays(GL_TRIANGLES, fu2[i], ku2[i]);

	glVertexPointer(3, GL_FLOAT, 0, vm);
	glColorPointer(3, GL_FLOAT, 0, cvm);
	for (i = 0; i < 7; i++)		glDrawArrays(GL_POLYGON, fvm[i], kvm[i]);
	glDrawArrays(GL_TRIANGLES, fvm[i], kvm[i]);
	for (i=8; i < 10; i++)		glDrawArrays(GL_POLYGON, fvm[i], kvm[i]);
	glDrawArrays(GL_TRIANGLES, fvm[i], kvm[i]);
	for (i=10; i < 16; i++)		glDrawArrays(GL_POLYGON, fvm[i], kvm[i]);

	glVertexPointer(3, GL_FLOAT, 0, english);
	glColorPointer(3, GL_FLOAT, 0, cenglish);
	glDrawArrays(GL_TRIANGLES, 0, 1752);

	glVertexPointer(3, GL_FLOAT, 0, logo);
	glColorPointer(3, GL_FLOAT, 0, clogo);
	glDrawArrays(GL_TRIANGLES, flogo[0], klogo[0]);
	for (i = 1; i < 5; i++)		glDrawArrays(GL_POLYGON, flogo[i], klogo[i]);
	glDrawArrays(GL_TRIANGLES, flogo[i], klogo[i]);
	for (i = 6; i < 9; i++)		glDrawArrays(GL_POLYGON, flogo[i], klogo[i]);
}
//==============================================================================