#include <GL/glut.h>
#include <iostream>

using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

//globais
int tX = 0, tY = 0;    //translação
float sXY = 1.0;   //Escala
int rX = 0, rY = 0;    //Rotação

void desenha_Robo(void){
    //corpo
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(80,80);
        glVertex2i(180,80);
        glVertex2i(180,210);
        glVertex2i(80,210);
    glEnd();

    //cabeça
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(95,215);
        glVertex2i(165,215);
        glVertex2i(165,285);
        glVertex2i(95,285);
    glEnd();

    //braço
    glBegin(GL_QUADS);
        glColor3f(0.80, 0.36, 0.36);
        glVertex2i(181,210);
        glVertex2i(206,210);
        glVertex2i(206,155);
        glVertex2i(181,155);
    glEnd();

    //antebraço
    glBegin(GL_QUADS);
        glColor3f(0.74, 0.56, 0.56);
        glVertex2i(181,156);
        glVertex2i(206,156);
        glVertex2i(206,106);
        glVertex2i(181,106);
    glEnd();
}

void normalKey(unsigned char key, int x, int y){
    switch(key){
        //'a' para aumentar
        case 'a':
            sXY += 0.2;
            glutPostRedisplay();
            break;

        //'d' para diminuir
        case 'd':
            sXY -= 0.2;
            glutPostRedisplay();
            break;

        default:
            break;
    }
}

/*Função para gerenciar as setas*/
void specialKey(int key, int x, int y){
    switch (key){
        case GLUT_KEY_UP:
            tY++;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            break;
        case GLUT_KEY_DOWN:
            tY--;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            break;
        case GLUT_KEY_LEFT:
            tX--;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            break;
        case GLUT_KEY_RIGHT:
            tX++;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void){
	/* Especifica que as transformações irão alterar os desenhos (modelos) */
	glMatrixMode(GL_MODELVIEW);  
	/* Carrega na matriz corrente a matriz identidade */
	glLoadIdentity();

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);
    glTranslated(tX,tY,0);
    glScalef(sXY,sXY,1.0);
    desenha_Robo();

	/* Executa os comandos OpenGL */
	glFlush();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void){
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Transformacoes");
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(normalKey);
    glutSpecialFunc(specialKey);
    Inicializa();
	glutMainLoop();
}
