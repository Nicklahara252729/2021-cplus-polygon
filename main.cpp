#include<windows.h>
#include<glut.h>
#include<math.h>
//=========== bintang ==========//
void drawStar(){
	glBegin(GL_POLYGON);
	glVertex2f(77.,70.);
	glVertex2f (80.,146.);
	glVertex2f(99.,90.);
	glVertex2f(157.,90.);
	glVertex2f (110.,55.);
	glVertex2f (128.,1.);
	glVertex2f (80.,34.);
	glVertex2f (32.,1.);
	glVertex2f (54.,55.);
	glVertex2f (3.,90.);
	glVertex2f (63.,90.);
	glVertex2f (80.,146.);
	glEnd();
	glFlush();
}
void starRender(void){
	glPushMatrix();
	glColor3f(0,1,0);//biru
	drawStar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-150,-150,0);
	glColor3f(1,0,0);//Merah
	glRotatef(30,0,0,1);
	drawStar();
	glPopMatrix();
	glFlush();
}
//=========== bintang ==========//

//=========== kotak ==========//
void renderKotak(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(-300, -300);
	glVertex2f(-300, 300);
	glVertex2f(300, 300);
	glVertex2f(300, -300);
	glEnd();
	glFlush();
}
//=========== kotak ==========//

//=========== segitiga ==========//
void renderSegitiga(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(0,0,1);
	glVertex2f(200, 300);
	glVertex2f(100, 100);
	glVertex2f(300, 100);
	glEnd();
	glFlush();
}
//=========== segitiga ==========//

//=========== lingkaran ==========//
const double PI = 3.14;
int i;
void back(){
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex2d(-150,150);
	glVertex2d(150,150);
	glVertex2d(150,-150);
	glVertex2d(-150,-150);
	glEnd();
}
void renderLingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah){
	glBegin(GL_POLYGON);
	for(i=0;i<=360;i++){
		float corner = i*(2*PI/jumlah_titik);
		float x = x_tengah + radius * cos(corner);
		float y = y_tengah + radius * sin(corner);
		glVertex2f(x,y);
	}
	glEnd();
}

void drawLingkaran(){
	glClear(GL_COLOR_BUFFER_BIT);
	back();
	glColor3f(0.0, 0.0, 1.0);
	renderLingkaran(60,90,-80,-80);
	glFlush();
}
//=========== lingkaran ==========//
int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitWindowPosition(400,200);
	glutInitWindowSize(480,480);
	glutCreateWindow("BINTANG , KOTAK, SEGITIGA, LINGKARAN");
	gluOrtho2D(-500.,500.,-500.,500.);
	glutDisplayFunc(drawLingkaran);
	glutMainLoop();
}
