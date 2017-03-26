#include "stdafx.h"
#include "Char.h"
//==============================================================================
void getN(float x,float y,float x1,float y1,float offset){
	line(x, y, y1,offset);
	glBegin(GL_TRIANGLES);
		glVertex3f(x, y, 0.0f);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x + offset, y, 0.0f);
		glVertex3f(x + offset, y, 0.0f);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x1 + offset, y1, 0.0f);
	glEnd();
	line(x1, y, y1,offset);
}
//==============================================================================
void line(float x1, float y1, float y2,float offset){
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x1, y2, 0.0f);
		glVertex3f(x1 + offset, y2, 0.0f);
		glVertex3f(x1 + offset, y2, 0.0f);
		glVertex3f(x1 + offset, y1, 0.0f);
		glVertex3f(x1, y1, 0.0f);
	glEnd();
}
//==============================================================================
void geta(float x1,float y1,float x2,float y2,float offset){
	topa(x1, y1, x2, y2, offset);
	glBegin(GL_TRIANGLES);
		glVertex3f(x1+(x2-x1)*2.0f, y1, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f, y1+(y1-y2)*5.0f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f+offset, y1, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f + offset, y1, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f, y1 + (y1 - y2)*5.0f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f+offset, y1 + (y1 - y2)*5.0f, 0.0f);

		glVertex3f(x1 + (x2 - x1)*2.0f, y1+(y1-y2)*2.0f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2), 0.0f);
		glVertex3f(x2, y1 + (y1 - y2)-offset, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f+offset, y1 + (y1 - y2)*2.0f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2), 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f, y1 + (y1 - y2)*2.0f, 0.0f);

		glVertex3f(x2, y1 + (y1 - y2), 0.0f);
		glVertex3f(x1+offset, y1 + (y1 - y2)*3.0f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2) - offset, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2), 0.0f);
		glVertex3f(x1, y1 + (y1 - y2)*3.0f, 0.0f);
		glVertex3f(x1 + offset, y1 + (y1 - y2)*3.0f, 0.0f);

		glVertex3f(x1 + offset, y1 + (y1 - y2)*3.0f, 0.0f);
		glVertex3f(x1, y1 + (y1 - y2)*3.0f, 0.0f);
		glVertex3f(x1 + offset, y1 + (y1 - y2)*4.0f, 0.0f);
		glVertex3f(x1, y1 + (y1 - y2)*3.0f, 0.0f);
		glVertex3f(x1, y1 + (y1 - y2)*4.0f, 0.0f);
		glVertex3f(x1 + offset, y1 + (y1 - y2)*4.0f, 0.0f);

		glVertex3f(x1, y1 + (y1 - y2)*4.0f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2)*4.5f, 0.0f);
		glVertex3f(x1 + offset, y1 + (y1 - y2)*4.0f, 0.0f);
		glVertex3f(x1, y1 + (y1 - y2)*4.0f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2)*5.5f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2)*4.5f, 0.0f);

		glVertex3f(x1 + (x2 - x1)*2.0f, y1 + (y1 - y2)*3.0f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2)*4.5f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2)*5.5f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f, y1 + (y1 - y2)*3.0f, 0.0f);
		glVertex3f(x2, y1 + (y1 - y2)*5.5f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f+offset, y1 + (y1 - y2)*3.0f, 0.0f);
	glEnd();
}
//==============================================================================
void gett(float x1, float y1, float x2, float y2, float offset,float offset2){
	line(x1, y1, y1 - offset2, (x2 - x1)*2.0f + offset);
	line(x2, y1 + 2.0f*offset2, y2, offset);
	glBegin(GL_TRIANGLES);
		glVertex3f(x2,y2,0.0f);
		glVertex3f(x2+offset*2.0f, y2+(y2-y1)*0.3f, 0.0f);
		glVertex3f(x2 + offset*2.0f, y2 , 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x2 + offset, y2 + (y2 - y1)*0.2f,0.0f);
		glVertex3f(x2 + offset*2.0f, y2 + (y2 - y1)*0.3f, 0.0f);
	glEnd();
}
//==============================================================================
void geti(float x1, float y1, float y2, float y3, float offset, float offset2){
	line(x1,y1,y1-offset2,offset);
	line(x1, y2, y3, offset);
}
//==============================================================================
void geto(float x1, float y1, float x2, float y2, float offset, float offset2){
	cycle(x1,y1,x2,y2);
	glColor3f(0.0f, 0.0f, 0.0f);
	cycle(x1+offset, y1, x2, y2-offset2);
	glColor3f(1.0f, 1.0f, 1.0f);
}
//==============================================================================
void cycle(float x1, float y1, float x2, float y2){
	glBegin(GL_TRIANGLES);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2, y2, 0.0f);//up
		glVertex3f(x1 + (x2 - x1)*0.5f, y2 - (y2 - y1)*0.134f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x1 + (x2 - x1)*0.5f, y2 - (y2 - y1)*0.134f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.3f, y1 + (y2 - y1)*0.7f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x1 + (x2 - x1)*0.3f, y1 + (y2 - y1)*0.7f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.134f, y1 + (y2 - y1)*0.5f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x1 + (x2 - x1)*0.134f, y1 + (y2 - y1)*0.5f, 0.0f);
		glVertex3f(x1, y1, 0.0f);//left
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x1, y1, 0.0f);//left
		glVertex3f(x1 + (x2 - x1)*0.134f, y1 - (y2 - y1)*0.5f, 0.0f);		
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x1 + (x2 - x1)*0.134f, y1 - (y2 - y1)*0.5f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.3f, y1 - (y2 - y1)*0.7f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x1 + (x2 - x1)*0.3f, y1 - (y2 - y1)*0.7f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.5f, y1 - (y2 - y1)*0.866f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x1 + (x2 - x1)*0.5f, y1 - (y2 - y1)*0.866f, 0.0f);
		glVertex3f(x2, y1 + y1 - y2, 0.0f);//down		
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2, y1 + y1 - y2, 0.0f);//down
		glVertex3f(x2 + (x2 - x1)*0.5f, y1 - (y2 - y1)*0.866f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2 + (x2 - x1)*0.5f, y1 - (y2 - y1)*0.866f, 0.0f);
		glVertex3f(x2 + (x2 - x1)*0.7f, y1 - (y2 - y1)*0.7f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2 + (x2 - x1)*0.7f, y1 - (y2 - y1)*0.7f, 0.0f);
		glVertex3f(x2 + (x2 - x1)*0.866f, y1 - (y2 - y1)*0.5f, 0.0f);		
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2 + (x2 - x1)*0.866f, y1 - (y2 - y1)*0.5f, 0.0f);
		glVertex3f(x2 + x2 - x1, y1, 0.0f);//right		
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2 + x2 - x1, y1, 0.0f);//right
		glVertex3f(x2 + (x2 - x1)*0.866f, y1 + (y2 - y1)*0.5f, 0.0f);		
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2 + (x2 - x1)*0.866f, y1 + (y2 - y1)*0.5f, 0.0f);
		glVertex3f(x2 + (x2 - x1)*0.7f, y1 + (y2 - y1)*0.7f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2 + (x2 - x1)*0.7f, y1 + (y2 - y1)*0.7f, 0.0f);
		glVertex3f(x2 + (x2 - x1)*0.5f, y2 - (y2 - y1)*0.134f, 0.0f);
		glVertex3f(x2, y1, 0.0f);//mid
		glVertex3f(x2 + (x2 - x1)*0.5f, y2 - (y2 - y1)*0.134f, 0.0f);
		glVertex3f(x2, y2, 0.0f);
	glEnd();
}
//==============================================================================
void topa(float x1, float y1, float x2, float y2, float offset){
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x1 + offset, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x2, y2 + offset, 0.0f);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(offset + (x1 + x2) / 2.0f, (y1 + y2) / 2.0f + 0.2f* offset, 0.0f);
		glVertex3f(x1, y1, 0.0f);

		glVertex3f(x2 + x2 - x1, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x2 + x2 - x1 - offset, y1, 0.0f);
		glVertex3f(x2, y2 + offset, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x2 + x2 - x1 + offset, y1, 0.0f);
		glVertex3f(x2 + x2 - x1 + offset, y1, 0.0f);
		glVertex3f((x2 + (x1 + x2) / 2.0f + offset) / 2.0f - offset, (y1 + y2) / 2.0f + 0.2f* offset, 0.0f);
		glVertex3f(x2, y2 + offset, 0.0f);
	glEnd();
}
//==============================================================================
void getnh(float x1, float y1, float y2, float y3, float x2, float yy, float offset){
	line(x1, y1, y3, offset);
	topa(x1, y2, x2, yy, offset);
	line(x2 + x2 - x1, y2, y3, offset);
}
//==============================================================================
void getl(float x1, float y1, float y2, float offset){
	line(x1, y1, y2, offset);
}
//==============================================================================
void getC(float x1, float y1, float x2, float y2, float offset, float offset2){
	geto(x1, y1, x2, y2, offset, offset2);
	glColor3f(0.0f, 0.0f, 0.0f);
	line(x2, y1 + offset2*2.0f, y1 - offset2*2.0f, x2 + x2 - x1);
	glColor3f(1.0f, 1.0f, 1.0f);
}
//==============================================================================
void getu(float x1, float y1, float y2, float x2, float yy, float offset, float offset2){
	line(x1, y1, y2, offset);
	buttonU(x1, y2, x2, yy, offset, offset2);
	line(x2 + x2 - x1, y1, yy, offset);
}
//==============================================================================
void buttonU(float x1, float y2, float x2, float yy, float offset, float offset2){
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, y2, 0.0f);
		glVertex3f(x2, yy + offset2, 0.0f);
		glVertex3f(x1 + offset, y2, 0.0f);
		glVertex3f(x2, yy, 0.0f);
		glVertex3f(x2, yy + offset2, 0.0f);
		glVertex3f(x1, y2, 0.0f);

		glVertex3f(x2 + x2 - x1, y2, 0.0f);
		glVertex3f(x2, yy + offset2, 0.0f);
		glVertex3f(x2 + x2 - x1, y2, 0.0f);
		glVertex3f(x2 + x2 - x1 + offset, y2, 0.0f);
		glVertex3f(x2, yy + offset2, 0.0f);
		glVertex3f(x2, yy, 0.0f);
	glEnd();
}
//==============================================================================
void getg(float x1, float y1, float x2, float y2, float x3, float y4, float y5, float offset, float offset2){
	geto(x1, y1, x2, y2, offset, offset2);
	line(x3 - offset, y2, y4 - offset2*0.9f, offset);
	buttonU(x1, y4, x2 - offset*0.3f, y5, offset, offset2);
}
//==============================================================================
void getH(float x1, float y1, float y2, float y3, float x2, float offset, float offset2){
	line(x1, y1, y3, offset);
	line(x1, y2, y2 + offset2, x2 - x1);
	line(x2, y1, y3, offset);
}
//==============================================================================
void getS(float x1, float y1, float x2, float y2, float y3, float y4, float offset, float offset2){
	topa(x1, y1, x2, y2, offset);
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x2 + x2 - x1, y3, 0.0f);
		glVertex3f(x1 + offset, y1, 0.0f);

		glVertex3f(x2 + x2 - x1, y3, 0.0f);
		glVertex3f(x2 + x2 - x1 + offset, y3, 0.0f);
		glVertex3f(x1 + offset, y1, 0.0f);
	glEnd();
	buttonU(x1, y3, x2, y4, offset, offset2);
}
//==============================================================================
void getU(float x1, float y1, float y2, float x3, float y3, float offset, float offset2){
	line(x1, y1, y2, offset);
	buttonU(x1, y2, x3, y3, offset, offset2);
	line(x3 + x3 - x1 - offset, y1, y2 - offset2, offset);
}
//==============================================================================
void getv(float x1, float y1, float x2, float y2, float offset, float offset2){
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x1 + offset, y1, 0.0f);
		glVertex3f(x1 + offset, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x2, y2 + offset2, 0.0f);

		glVertex3f(x2 + (x2 - x1), y1, 0.0f);
		glVertex3f(x2 + (x2 - x1) - offset, y1, 0.0f);
		glVertex3f(x2, y2 + offset2, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x2 + (x2 - x1), y1, 0.0f);
		glVertex3f(x2, y2 + offset2, 0.0f);
	glEnd();
}
//==============================================================================
void gete(float x1, float y1, float x2, float y2, float offset, float offset2){
	geto(x1, y1, x2, y2, offset*0.9f, offset2*0.9f);
	glColor3f(0.0f, 0.0f, 0.0f);
	line(x2, y1 + offset2*0.3f, y1 - offset2*1.5f, x2 + x2 - x1);
	glColor3f(1.0f, 1.0f, 1.0f);
	line(x1, y1 + offset2*0.3f, y1-offset2*0.2f, (x2 - x1)*2.0f);
}
//==============================================================================
void getr(float x1, float y1, float y2, float y3, float x2, float yy, float offset){
	line(x1, y1, y3, offset);
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, y2, 0.0f);
		glVertex3f(x1 + offset, y2, 0.0f);
		glVertex3f(x2, yy, 0.0f);
		glVertex3f(x2, yy, 0.0f);
		glVertex3f(x2, yy + offset, 0.0f);
		glVertex3f(x1, y2, 0.0f);
		glVertex3f(x2, yy, 0.0f);
		glVertex3f(offset + (x1 + x2) / 2.0f, (y2 + yy) / 2.0f + 0.2f* offset, 0.0f);
		glVertex3f(x1, y2, 0.0f);
	glEnd();
}
//==============================================================================
void gety(float x1, float y1, float x2, float y2, float offset, float offset2){
	getv(x1, y1, x2, y2, offset, offset2);
	glBegin(GL_TRIANGLES);
		glVertex3f(x2-(x2-x1)*0.5f-offset*0.8f,y2+(y2-y1)*0.5f,0.0);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x2 + (x2 - x1) - offset, y1, 0.0f);
		glVertex3f(x2 - (x2 - x1)*0.5f - offset*0.8f, y2 + (y2 - y1)*0.5f, 0.0);
		glVertex3f(x2 - (x2 - x1)*0.5f, y2 + (y2 - y1)*0.5f, 0.0);
		glVertex3f(x2, y2, 0.0f);
	glEnd();
}
//==============================================================================