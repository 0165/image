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
	topa(x1, y1, x2, y2+offset*3.0f, offset);
	geto(x1,y1-offset*8.5f,x2+offset*0.5f,y2-offset*5.5f,offset,offset*1.5f);
	glBegin(GL_TRIANGLES);
		glVertex3f(x1+(x2-x1)*2.0f, y1, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f, y1+(y1-y2)*4.5f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f+offset, y1, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f + offset, y1, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f, y1 + (y1 - y2)*4.5f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*2.0f+offset, y1 + (y1 - y2)*4.5f, 0.0f);
	glEnd();
}
//==============================================================================
void gett(float x1, float y1, float x2, float y2, float offset,float offset2){
	line(x1, y1, y1 - offset2, (x2 - x1)*2.0f + offset);
	line(x2, y1 + 2.0f*offset2, y2, offset);
	buttonlefto(x2, y2, x2 + offset*2.0f, y2 - (y2 - y1)*0.3f);
	glColor3f(1.0f,1.0f, 1.0f);
	buttonlefto(x2 + offset*1.1f, y2, x2 + offset*2.0f, y2 - (y2 - y1)*0.1f);
	glColor3f(0.6f, 0.196f, 0.8f);
}
//==============================================================================
void geti(float x1, float y1, float y2, float y3, float offset, float offset2){
	line(x1,y1,y1-offset2,offset);
	line(x1, y2, y3, offset);
}
//==============================================================================
void geto(float x1, float y1, float x2, float y2, float offset, float offset2){
	cycle(x1,y1,x2,y2);
	glColor3f(1.0f,1.0f, 1.0f);
	cycle(x1+offset, y1, x2, y2-offset2);
	glColor3f(0.6f, 0.196f, 0.8f);
}
//==============================================================================
void cycle(float x1, float y1, float x2, float y2){
	topo(x1, y1, x2, y2);
	buttono(x1, y1, x2, y2);
}
//==============================================================================
void buttono(float x1, float y1, float x2, float y2){
	buttonlefto(x1, y1, x2, y2);
	buttonrighto(x1, y1, x2, y2);
}
//==============================================================================
void buttonrighto(float x1, float y1, float x2, float y2){
	glBegin(GL_TRIANGLES);
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
	glEnd();
}
//==============================================================================
void buttonlefto(float x1, float y1, float x2, float y2){
	glBegin(GL_TRIANGLES);
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
	glEnd();
}
//==============================================================================
void toplefto(float x1, float y1, float x2, float y2){
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
	glEnd();
}
//==============================================================================
void toprighto(float x1, float y1, float x2, float y2){
	glBegin(GL_TRIANGLES);
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
void topo(float x1, float y1, float x2, float y2){
	toplefto(x1, y1, x2, y2);
	toprighto(x1, y1, x2, y2);
}
//==============================================================================
void topa(float x1, float y1, float x2, float y2, float offset){
	topo(x1, y1, x2+offset*0.5f, y2);
	glColor3f(1.0f,1.0f, 1.0f);
	topo(x1+offset, y1, x2 + offset*0.5f, y2-offset);
	glColor3f(0.6f, 0.196f, 0.8f);
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
	glColor3f(1.0f,1.0f, 1.0f);
	line(x2, y1 + offset2*2.0f, y1 - offset2*2.0f, x2 + x2 - x1);
	glColor3f(0.6f, 0.196f, 0.8f);
}
//==============================================================================
void getu(float x1, float y1, float y2, float x2, float yy, float offset, float offset2){
	line(x1, y1, y2, offset);
	buttonU(x1, y2, x2, yy, offset);
	line(x2 + x2 - x1, y1, yy, offset);
}
//==============================================================================
void buttonU(float x1, float y1, float x2, float y2, float offset){
	buttono(x1, y1, x2 + offset*0.5f, y1-y2+y1);
	glColor3f(1.0f,1.0f, 1.0f);
	buttono(x1 + offset, y1, x2 + offset*0.5f, y1 - y2 + y1 - offset);
	glColor3f(0.6f, 0.196f, 0.8f);
}
//==============================================================================
void getg(float x1, float y1, float x2, float y2, float x3, float y4, float y5, float offset, float offset2){
	geto(x1, y1, x2, y2, offset, offset2);
	line(x3 - offset, y2, y4 - offset2*0.9f, offset);
	buttonU(x1, y4, x2 - offset*0.5f, y5, offset);
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
	buttonU(x1, y3, x2, y4, offset);
}
//==============================================================================
void getU(float x1, float y1, float y2, float x3, float y3, float offset, float offset2){
	line(x1, y1, y2, offset);
	buttonU(x1, y2, x3-offset*0.5f, y3, offset);
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
	glColor3f(1.0f,1.0f, 1.0f);
	line(x2, y1 + offset2*0.3f, y1 - offset2*1.5f, x2 + x2 - x1);
	glColor3f(0.6f, 0.196f, 0.8f);
	line(x1, y1 + offset2*0.3f, y1-offset2*0.2f, (x2 - x1)*2.0f);
}
//==============================================================================
void getr(float x1, float y1, float y2, float y3, float x2, float yy, float offset){
	line(x1, y1, y3, offset);
	toplefto(x1, y2, x2, yy);
	glColor3f(1.0f,1.0f, 1.0f);
	toplefto(x1+offset, y2, x2, yy-offset*2.0f);
	glColor3f(0.6f, 0.196f, 0.8f);
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
void getlogo(float x1, float y1, float x2, float y2){
	glColor3f(0.0f, 0.8666f, 0.8666f);
	line(x1,y1,y2,x2-x1);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
		glVertex3f(x1 , y1 , 0.0f);
		glVertex3f(x1 , y1 - (y1 - y2)*0.9354f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.0588f, y1 - (y1 - y2)*0.8225f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.0882f, y1 - (y1 - y2)*0.6774f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.1176f, y1 - (y1 - y2)*0.4838f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.1323f, y1 - (y1 - y2)*0.3709f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.1176f, y1 - (y1 - y2)*0.2096f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.0882f, y1 - (y1 - y2)*0.0806f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.0441f, y1 , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x1 , y1 - (y1 - y2)*0.9677f, 0.0f);
		glVertex3f(x1 , y2, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.9852f, y2, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.9705f, y1 - (y1 - y2)*0.9677f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.8382f, y1 - (y1 - y2)*0.9032f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.6911f, y1 - (y1 - y2)*0.8709f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.5147f, y1 - (y1 - y2)*0.8548f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.3382f, y1 - (y1 - y2)*0.8709f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.1764f, y1 - (y1 - y2)*0.9032f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.0441f, y1 - (y1 - y2)*0.9516f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x2, y1, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.9558f, y1 , 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.9411f, y1 - (y1 - y2)*0.0161f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.897f, y1 - (y1 - y2)*0.1129f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.8676f, y1 - (y1 - y2)*0.258f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.8529f, y1 - (y1 - y2)*0.4516f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.8676f, y1 - (y1 - y2)*0.5645f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.9117f, y1 - (y1 - y2)*0.7419f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.9558f, y1 - (y1 - y2)*0.8709f, 0.0f);
		glVertex3f(x2, y1 - (y1 - y2)*0.9677f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x1 + (x2 - x1)*0.0882f, y1 , 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.1764f, y1 - (y1 - y2)*0.0322f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.3676f, y1 - (y1 - y2)*0.0645f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.5f, y1 - (y1 - y2)*0.0806f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.6911f, y1 - (y1 - y2)*0.0645f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.8235f, y1 - (y1 - y2)*0.0322f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.9411f, y1 , 0.0f);
	glEnd();
	glColor3f(0.6666f, 0.0f, 0.0f);
	cycle(x1 + (x2 - x1)*0.2941f, y1 - (y1 - y2)*0.4516f, x1 + (x2 - x1)*0.5147f, y1 - (y1 - y2)* 0.2258f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
		glVertex3f(x1 + (x2 - x1)*0.0582f, y1 - (y1 - y2)*0.0483f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.0882f, y1 - (y1 - y2)*0.0967f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.1470f, y1 - (y1 - y2)*0.1129f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.2258f, y1 - (y1 - y2)*0.1451f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.2258f, y1 - (y1 - y2)*0.0967f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.1470f, y1 - (y1 - y2)*0.0645f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x1 + (x2 - x1)*0.2258f, y1 - (y1 - y2)*0.0967f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.2258f, y1 - (y1 - y2)*0.1451f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.2941f, y1 - (y1 - y2)*0.1935f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.4117f, y1 - (y1 - y2)*0.2741f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.4264f, y1 - (y1 - y2)*0.2580f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.3676f, y1 - (y1 - y2)*0.1935f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.2794f, y1 - (y1 - y2)*0.1290f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(x1 + (x2 - x1)*0.4264f, y1 - (y1 - y2)*0.2580f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.4117f, y1 - (y1 - y2)*0.2741f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.5294f, y1 - (y1 - y2)*0.3870f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.6911f, y1 - (y1 - y2)*0.6129f, 0.0f);
		glVertex3f(x1 + (x2 - x1)*0.5441f, y1 - (y1 - y2)*0.3709f, 0.0f);
	glEnd();
	glColor3f(0.6f, 0.192f, 0.8f);
}
//==============================================================================