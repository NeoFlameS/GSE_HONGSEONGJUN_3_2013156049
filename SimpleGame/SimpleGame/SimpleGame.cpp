/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "Sound.h"
#include "SceneMgr.h"
#include "Renderer.h"
#include "Object.h"


Renderer *g_Renderer = NULL;
SceneMgr *main_ob=NULL;

//임시로 넣어 두겠습니다.


int mouse_state = 0;


void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	//g_Renderer->DrawSolidRect(-200, 200, 0, 4, 1, 0, 1, 1);
	// Renderer Test
	//
	main_ob->draw();
	

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mouse_state == 0) {
		main_ob->create_Object(x-250, 400-y, OBJECT_CHARACTER,-1,Team_2);
		mouse_state = 1;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mouse_state ==1) {
		
		mouse_state = 0;
	}
	
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 800);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 800);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}


	main_ob = new SceneMgr(g_Renderer);
	Sound* m_sound = new Sound();
	int soundBG = m_sound->CreateSound("./Dependencies/SoundSamples/ophelia.mp3");
	m_sound->PlaySound(soundBG, true, 0.2f);


	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

    return 0;
}

