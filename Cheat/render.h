#pragma once

namespace render {
	bool outline = false;
	float outlinethickness = 1.f;
	float linethickness = 2.f;
	int hovered_headers = 0;
	uworld* world;
	aplayercontroller* controller;
	ucanvas* canvas;
	uobject* font;
	fvector2d screen_center, screen_size;  

	bool in_circle(int cx, int cy, int r, int x, int y) {
		int dist = (x - cx) * (x - cx) + (y - cy) * (y - cy);
		if (dist <= r * r)
			return true;
		else
			return false;
	}

	void text(fstring content, fvector2d position, flinearcolor render_color, bool center_x, bool center_y, bool outlined) {
		canvas->k2_draw_text(font, content, position, fvector2d(1.0, 1.0), render_color, 1.0f, flinearcolor(), fvector2d(), center_x, center_y, outlined, flinearcolor(0, 0, 0, 1));
	}

	fvector2d text_size(fstring content) {
		return canvas->k2_text_size(font, content, fvector2d(1.0, 1.0));
	}

	void line(fvector2d a, fvector2d b, flinearcolor render_color, float thickness) {
		canvas->k2_draw_line(a, b, thickness, render_color);
	}

	void line_with_outline(fvector2d a, fvector2d b, flinearcolor render_color, float thickness)
	{
		if (outline) {
			canvas->k2_draw_line(a, b, outlinethickness, flinearcolor(0.f, 0.f, 0.f, 1.f));
		}
		canvas->k2_draw_line(a, b, linethickness, render_color);
	}

	void circle(fvector2d position, int radius, int segments, flinearcolor color) {
		float PI = 3.1415927f;

		float Step = PI * 2.0 / segments;
		int Count = 0;
		fvector2d V[128];
		for (float a = 0; a < PI * 2.0; a += Step) {
			float X1 = radius * defines::math->cos(a) + position.x;
			float Y1 = radius * defines::math->sin(a) + position.y;
			float X2 = radius * defines::math->cos(a + Step) + position.x;
			float Y2 = radius * defines::math->sin(a + Step) + position.y;
			V[Count].x = X1;
			V[Count].y = Y1;
			V[Count + 1].x = X2;
			V[Count + 1].y = Y2;
			line(fvector2d{ V[Count].x, V[Count].y }, fvector2d{ X2, Y2 }, color, 2.2f);
		}
	}

	void filled_box(fvector2d position, fvector2d size, flinearcolor render_color) {
		for (int i = 0; i < size.y; i++) {
			canvas->k2_draw_line(fvector2d(position.x, position.y + i), fvector2d(position.x + size.x, position.y + i), 1.f, render_color);
		}
	}
}




