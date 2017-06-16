//
//  main.cpp
//  Test
//
//  Created by friend0165 on 2017/3/22.
//  Copyright © 2017年 friend0165. All rights reserved.
//
//==============================================================================
#include "stdafx.h"
//==============================================================================
#define maxL 1000   //how many cube can have
#define maxC 5      //how many char can show
//==============================================================================
struct myCube {
    bool  f;        //falling
    float x;        //scale x
    float z;        //scale z
    float h;        //hight
    float angle;    //angle of rotate
    float mid_x;    //cube middle x
    float mid_z;    //cube middle z
    float fulc_x;   //Fulcrum's x
    float fulc_z;   //Fulcrum's z
};
//==============================================================================
bool    isEnd = false;            //game end, true means end
bool    turn = true;              //moving at x or z, true for z
bool    isBack = false;           //moving to postive or negative
char    str[maxC];                //the array of char to show
int     lenght = 1;               //the niumber of rhe cubes
int     count = 0;                //the point you get
float   place = -2.0f;            //tanslate to the place when moving
float   view_y = 3.0f;            //the view point's y
//==========================================
GLint buf[1], sbuf[1];            //smooth
//==========================================
GLfloat high_shininess[] = { 100.0f };            //Material
GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//==========================================
GLfloat ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };//light
GLfloat diffuse[] = { 0.5f, 1.0f, 1.0f, 1.0f };
GLfloat position[] = { 6.0f, 1.0f, 1.5f, 0.0f };
GLfloat lmodel_ambient[] = { 0.6f, 0.6f, 0.6f, 1.0f };
GLfloat local_view[] = { 0.0f };
//==========================================
struct myCube  list[maxL];
//==============================================================================
void init(void);                //init all things and open lighting
void valueInit(void);           //init all the value
void change(void);              //change the place of the moving cube
void display(void);             //the main display function
bool addCube(void);             //adding cube to array, return true if have cut cube
void CubeCut(void);             //the function when pause the space button
void endGame(void);             //when the game end
void checkEnd(void);            //check is the game or not
void drawList(void);            //draw the member of the array
void IntToChar(void);           //changing count(int) to str(char array)
bool checkStay(int i, int j);   //check is the cube shoukd stay
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
//==============================================================================
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(416 * 2, 416 * 2);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
//==============================================================================
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (isEnd)   endGame();
    else{
        drawList();

        glPushMatrix();
        gluLookAt(-5.0, view_y, 5.0, 0.0, view_y - 3.0f, 0.0, 0.0, 1.0, 0.0);
        glPushMatrix();
        glDisable(GL_LIGHTING);
        IntToChar();
        int n = (int)strlen(str);
        glRasterPos3f(-0.1f*(n - 1), view_y, 0.0f);
        glColor3f(0.4f, 0.0f, 0.9f);
        for (int i = 0; i < n;i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *(str+i));
        glEnable(GL_LIGHTING);
        glPopMatrix();
        if (turn)    glTranslatef(-list[lenght - 1].mid_x, view_y - 2.0f, place);
        else        glTranslatef(-place, view_y - 2.0f, list[lenght - 1].mid_z);
        glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
        glScalef(list[lenght - 1].x, 1.0f, list[lenght - 1].z);
        glutSolidCube(1.0);
        glPopMatrix();

        change();
    }
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
    case 27:    exit(0);    break;
    case ' ':   
        if (isEnd){     init();    glutPostRedisplay(); }
        else            CubeCut();  
        break;
    }
}
//==============================================================================
void CubeCut(void){
    if (addCube())   lenght = lenght + 2;
    else            lenght++;
    turn = !turn;
    place = -2.0f;
    view_y += 1.0f;
    count++;
}
//==============================================================================
bool addCube(void){
    //lenght is the first place you can put cube in
    //if have cut cube, put the cut cube in first, and put the top cube secand
    //the cut cube's f will be true, meens need to compute falling
    //the last top will be (lenght-1)
    float temp, err;
    if (turn)    temp = list[lenght - 1].mid_z;
    else        temp = list[lenght - 1].mid_x;
    checkEnd();
    err = place - temp;
    if (fabsf(err)>0.1f){
        list[lenght].f = true;
        list[lenght].h = view_y - 2.0f;
        list[lenght + 1].f = false;
        list[lenght + 1].h = view_y - 2.0f;
        if (turn){
            list[lenght].x = list[lenght - 1].x;
            list[lenght].z = fabsf(err);
            list[lenght].mid_x = list[lenght - 1].mid_x;
            list[lenght + 1].x = list[lenght - 1].x;
            list[lenght + 1].z = list[lenght - 1].z - fabsf(err);
            list[lenght + 1].mid_x = list[lenght - 1].mid_x;
            if (err>0.0f){
                list[lenght].mid_z = list[lenght - 1].mid_z + (list[lenght - 1].z + list[lenght].z) / 2.0f;
                list[lenght + 1].mid_z = list[lenght - 1].mid_z + (list[lenght - 1].z - list[lenght + 1].z) / 2.0f;
            }else{
                list[lenght].mid_z = list[lenght - 1].mid_z - (list[lenght - 1].z + list[lenght].z) / 2.0f;
                list[lenght + 1].mid_z = list[lenght - 1].mid_z - (list[lenght - 1].z - list[lenght + 1].z) / 2.0f;
            }
        }else{
            list[lenght].z = list[lenght - 1].z;
            list[lenght].x = fabsf(err);
            list[lenght].mid_z = list[lenght - 1].mid_z;
            list[lenght + 1].z = list[lenght - 1].z;
            list[lenght + 1].x = list[lenght - 1].x - fabsf(err);
            list[lenght + 1].mid_z = list[lenght - 1].mid_z;
            if (err>0.0f){
                list[lenght].mid_x = list[lenght - 1].mid_x + (list[lenght - 1].x + list[lenght].x) / 2.0f;
                list[lenght + 1].mid_x = list[lenght - 1].mid_x + (list[lenght - 1].x - list[lenght + 1].x) / 2.0f;
            }else{
                list[lenght].mid_x = list[lenght - 1].mid_x - (list[lenght - 1].x + list[lenght].x) / 2.0f;
                list[lenght + 1].mid_x = list[lenght - 1].mid_x - (list[lenght - 1].x - list[lenght + 1].x) / 2.0f;
            }
        }
        return true;
    }else{
        list[lenght].f = false;
        list[lenght].x = list[lenght - 1].x;
        list[lenght].z = list[lenght - 1].z;
        list[lenght].h = view_y - 2.0f;
        if (turn){
            list[lenght].mid_z = temp;
            list[lenght].mid_x = list[lenght - 1].mid_x;
        }else{
            list[lenght].mid_x = temp;
            list[lenght].mid_z = list[lenght - 1].mid_z;
        }
        return false;
    }
}
//==============================================================================
void IntToChar(void){
    for (int i = 0; i<maxC; i++)        str[i] = '\0';
    sprintf(str, "%d", count);
}
//==============================================================================
void change(void){
    if (isBack)   place -= 0.005f;
    else          place += 0.005f;
    if (fabsf(place) > 2.0f)    isBack = !isBack;
    glutPostRedisplay();
}
//==============================================================================
void drawList(void){
    for (int i = 0; i<lenght; i++){
        glPushMatrix();
        gluLookAt(-5.0, view_y, 5.0, 0.0, view_y - 3.0f, 0.0, 0.0, 1.0, 0.0);
        if (list[i].f){
            int j;
            float temp;
            if (fmod(list[i].h, 1.0f) < 0.1f){
                temp = (int)(list[i].h / 1.0f)-1.0f;
                for (j = i-1; j >-1; j--)
                    if (fabsf(list[j].h - temp*1.0f) < 0.1){  if(checkStay(i, j))  break; }
            }
            if (list[i].h < 0.0f){  list[i].h = -9.0f; list[i].f = false; }
            list[i].h -= 0.0078125f; 
        }
        glTranslatef(-list[i].mid_x, list[i].h, list[i].mid_z);
        glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

        //位置仍要調整
        glTranslatef(-list[i].fulc_x, 0.0f, list[i].fulc_z);
        glRotatef(list[i].angle, list[i].fulc_x, 0.0f, list[i].fulc_z);
        glTranslatef(list[i].fulc_x, 0.0f, -list[i].fulc_z);

        glScalef(list[i].x, 1.0f, list[i].z);
        glutSolidCube(1.0);
        glPopMatrix();
    }
}
//==============================================================================
void init(void)
{
    glClearColor(0.7f, 1.0f, 0.9f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
    glGetIntegerv(GL_SAMPLE_BUFFERS_ARB, buf);
    glGetIntegerv(GL_SAMPLES_ARB, sbuf);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE_ARB);
    valueInit();
    list[0].x = 2.0f;
    list[0].z = 2.0f;
}
//==============================================================================
void valueInit(void){
    for (int i = 0; i<maxL; i++){
        list[i].f = false;        list[i].x = 0.0f;
        list[i].z = 0.0f;         list[i].h = 0.0f;        list[i].angle = 0.0f;
        list[i].mid_z = 0.0f;     list[i].mid_x = 0.0f;
        list[i].fulc_x = 0.0f;    list[i].fulc_x = 0.0f;
    }
    isEnd = false;    turn = true;    isBack = false;
    lenght = 1;       count = 0;
    place = -2.0f;    view_y = 3.0f;
}
//==============================================================================
void endGame(void){
    char * over = "game over__";
    glPushMatrix();
    glLoadIdentity();
    count--;
    gluLookAt(-5.0, view_y, 5.0, 0.0, view_y - 3.0f, 0.0, 0.0, 1.0, 0.0);
    glDisable(GL_LIGHTING);
    glColor3f(0.4f, 0.0f, 0.9f);
    glRasterPos3f(-0.3f, view_y, 0.0f);
    for (int i = 0; i <11; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *(over + i));
    IntToChar();
    int n = (int)strlen(str);
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *(str + i));
    glEnable(GL_LIGHTING);
    glPopMatrix();
}
//==============================================================================
void checkEnd(void){
    if (turn){
        if (place>list[lenght - 1].mid_z){
            if (list[lenght - 1].mid_z + list[lenght - 1].z<place) isEnd = true;
        }
        else if (list[lenght - 1].mid_z - list[lenght - 1].z>place) isEnd = true;
    }else{
        if (place>list[lenght - 1].mid_x){
            if (list[lenght - 1].mid_x + list[lenght - 1].x<place) isEnd = true;
        }
        else if (list[lenght - 1].mid_x - list[lenght - 1].x>place) isEnd = true;
    }
}
//==============================================================================
bool checkStay(int i, int j){
    int state = 0;
    if (list[i].mid_x - list[i].x / 2.0f >= list[j].mid_x - list[j].x / 2.0f)        state += 1;
    if (list[i].mid_x + list[i].x / 2.0f <= list[j].mid_x + list[j].x / 2.0f)        state += 2;
    if (list[i].mid_z - list[i].z / 2.0f >= list[j].mid_z - list[j].z / 2.0f)        state += 4;
    if (list[i].mid_z + list[i].z / 2.0f <= list[j].mid_z + list[j].z / 2.0f)        state += 8; 
    switch (state){
        case 7:
            if (list[i].mid_z - list[i].z / 2.0f < list[j].mid_z + list[j].z / 2.0f){
                list[i].angle -= 4.0f;        list[i].fulc_x = list[j].mid_x - list[j].x / 2.0f - list[i].mid_x;
            }return true;
        case 11:
            if (list[i].mid_z + list[i].z / 2.0f < list[j].mid_z - list[j].z / 2.0f){
                list[i].angle += 4.0f;        list[i].fulc_x = list[j].mid_z - list[j].z / 2.0f - list[i].mid_z;
            }return true;
        case 13:
            if (list[i].mid_x - list[i].x / 2.0f < list[j].mid_x + list[j].x / 2.0f){
                list[i].angle -= 4.0f;        list[i].fulc_z = list[j].mid_x - list[j].x / 2.0f - list[i].mid_x;
            }return true;
        case 14:
            if (list[i].mid_x + list[i].x / 2.0f < list[j].mid_x - list[j].x / 2.0f){
                list[i].angle += 4.0f;        list[i].fulc_z = list[j].mid_x - list[j].x / 2.0f - list[i].mid_x;
            }return true;
        case 15:        list[i].f = false;        list[i].h = list[j].h + 1.0f;    return true;
        default:        return false;
    }
}
//==============================================================================
