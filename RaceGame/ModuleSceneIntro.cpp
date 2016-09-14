#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "ModulePlayer.h"
#include "ImGui\imgui.h"
#include "ImGui\imgui_impl_sdl.h"
#include <ctime>

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	quit = false;
	show_test_window = false;

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	
	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{

	
	{
		ImGui::Text("Hello, world!");
		if (ImGui::Button("quit")) quit ^= 1;
		if (ImGui::Button("example")) show_test_window ^= 1;
	}

	if (quit) {
		return UPDATE_STOP;
	}
	if (show_test_window) {

		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}

	return UPDATE_CONTINUE;
}















