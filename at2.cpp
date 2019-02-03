#include <GL/glut.h>
#include <iostream>

using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

//globais
int iX = 0, iY = 0;

void desenha_Robo(void){
    //pernas
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(100+iX,0+iY);
        glVertex2i(125+iX,0+iY);
        glVertex2i(125+iX,80+iY);
        glVertex2i(100+iX,80+iY);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(135+iX,0+iY);
        glVertex2i(160+iX,0+iY);
        glVertex2i(160+iX,80+iY);
        glVertex2i(135+iX,80+iY);
    glEnd();

    //corpo
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(80+iX,80+iY);
        glVertex2i(180+iX,80+iY);
        glVertex2i(180+iX,210+iY);
        glVertex2i(80+iX,210+iY);
    glEnd();

    //cabeça
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(95+iX,215+iY);
        glVertex2i(165+iX,215+iY);
        glVertex2i(165+iX,285+iY);
        glVertex2i(95+iX,285+iY);
    glEnd();

    //braço
    glBegin(GL_QUADS);
        glColor3f(0.80, 0.36, 0.36);
        glVertex2i(181+iX,210+iY);
        glVertex2i(206+iX,210+iY);
        glVertex2i(206+iX,155+iY);
        glVertex2i(181+iX,155+iY);
    glEnd();

    //antebraço
    glBegin(GL_QUADS);
        glColor3f(0.74, 0.56, 0.56);
        glVertex2i(181+iX,156+iY);
        glVertex2i(206+iX,156+iY);
        glVertex2i(206+iX,106+iY);
        glVertex2i(181+iX,106+iY);
    glEnd();
}

/*Função para gerenciar as setas*/
void specialKey(int tecla, int x, int y){
    switch (tecla){
        case GLUT_KEY_UP:
            iY++;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            break;
        case GLUT_KEY_DOWN:
            iY--;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            break;
        case GLUT_KEY_LEFT:
            iX--;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            break;
        case GLUT_KEY_RIGHT:
            iX++;
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
    glTranslated(iX,iY,0);
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
    glutSpecialFunc(specialKey);
    Inicializa();
	glutMainLoop();
}
