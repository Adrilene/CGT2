#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

void desenha_Robo(void){
    //pernas
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(100,0);
        glVertex2i(125,0);
        glVertex2i(125,80);
        glVertex2i(100,80);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.82, 0.70, 0.55);
        glVertex2i(135,0);
        glVertex2i(160,0);
        glVertex2i(160,80);
        glVertex2i(135,80);
    glEnd();

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

/* Função callback chamada para fazer o desenho */
void Desenha(void){
	/* Especifica que as transformações irão alterar os desenhos (modelos) */
	glMatrixMode(GL_MODELVIEW);  
	/* Carrega na matriz corrente a matriz identidade */
	glLoadIdentity();

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

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

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Transformacoes");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}
