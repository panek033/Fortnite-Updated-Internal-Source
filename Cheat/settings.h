#pragma once
#include "vector.h"

namespace settings {
	namespace bones
	{
		bool head = true;
		bool neck = false;
		bool torso = false;
		bool pelvis = false;
	}

	namespace aimbot {

		bool enable = true;
		bool bulletp = false;
		int aim_key = VK_MENU;
		bool memory = false;
		bool mouse = false;
		bool silent = false;
		bool sticky_silent = false;
		bool interpolate = false;
		bool constant = false;
		bool draw_fov = false;
		bool visible_only = false;
		bool target_line = false;
		float mouse_speed = 5;
		float interpolate_speed = 5;
		float field_of_view = 10;
	}

	namespace player {
		bool enable = true;
		bool skeleton = false;
		bool box = true;
		bool bbc = true;
		bool normal_box = false;
		bool cornered_box = false;
		bool snapline = false;
		bool player_name = false;
		bool active_weapon = false;
		bool display_distance = false;
		float max_distance = 300;
	}

	namespace pickups {
		bool enable = true;
		bool display_distance = true;
		bool lines = false;
		bool common = false;
		bool uncommon = false;
		bool rare = false;
		bool epic = false;
		bool legendary = false;
		bool mythic = false;
		float max_distance = 60;
		float line_offset = 20;
	}

	namespace radar {
		bool enable = false;
		bool show_line_of_sight = true;
		bool useless_circle = false;
		bool players = true;
		float range = 70;
		float positionx = 15;
		float positiony = 90;
		float size = 180;
	}

	namespace style {
		bool text_outlined = true;
		bool performance = false;
	}
}
