#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

// Espacio para las variables globales de la ventana
float gl_ancho = 2.0, gl_alto = 2.0, gl_cerca = 2.0, gl_lejos = 4.0;
int w_ancho = 500, w_alto = 500;


// Espacio para otras variables globales


// Espacio para la declaración de funciones
void InitGlew();
void InitGL();
void Display();
void ReshapeAspect(int ancho, int alto);

//main
int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w_ancho, w_alto);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);

	glutCreateWindow("OpenGL Practica ");
	InitGlew(); // despues de crear la primera ventana
	InitGL();
	glutDisplayFunc(Display); // registra la funcion de rendering
	glutReshapeFunc(ReshapeAspect);

	glutMainLoop(); // bucle principal

	return 0;
}

void InitGlew(){

	// para poder utilizar trasnparentemente todas las extensiones de OpenGL

	GLenum glew_init = glewInit();
	if (glew_init != GLEW_OK)
	{
		// Problem: glewInit failed, something is seriously wrong.
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_init));
	}
	else
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
}

void InitGL(){

	if (gl_ancho / w_ancho != gl_alto / w_alto){
		fprintf(stderr, "La relación de aspecto no es correcta\n");
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	// TO DO

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-gl_ancho / 2.0, gl_ancho / 2.0, -gl_alto / 2.0, gl_alto / 2.0, gl_cerca, gl_lejos); // espacio de trabajo
}

// cambio de dimensiones de la ventana, manteniendo la relaci�n de aspecto
void ReshapeAspect(int ancho, int alto){

    float dx = gl_ancho;
    float dy = gl_alto;

    if (ancho > alto){
        dx = dy*(float)ancho / (float)alto;
    }
    if (alto > ancho){
        dy = dx*(float)alto / (float)ancho;
    }

    glViewport(0, 0, ancho, alto); // utiliza la totalidad de la ventana
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_cerca, gl_lejos); // espacio de trabajo
    glutPostRedisplay();
}

// función de gestion de ventana
void Display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra todo lo existente en el framebuffer
	// TO DO

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.2f, 0.2f, -2.5f);
		glVertex3f(0.2f, 0.2f, -3.5f);
		glVertex3f(0.8f, 0.2f, -2.5f);
		glVertex3f(0.8f, 0.2f, -3.5f);

	}
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.8f, 0.2f, -2.5f);
		glVertex3f(0.8f, 0.2f, -3.5f);
		glVertex3f(0.8f, 0.8f, -2.5f);
		glVertex3f(0.8f, 0.8f, -3.5f);

	}
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.2f, 0.8f, -2.5f);
		glVertex3f(0.2f, 0.8f, -3.5f);
		glVertex3f(0.8f, 0.8f, -2.5f);
		glVertex3f(0.8f, 0.8f, -3.5f);
	}
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(0.2f, 0.2f, -2.5f);
		glVertex3f(0.2f, 0.2f, -3.5f);
		glVertex3f(0.2f, 0.8f, -2.5f);
		glVertex3f(0.2f, 0.8f, -3.5f);
	}
	glEnd();

	glFlush(); // actualiza el framebuffer
}