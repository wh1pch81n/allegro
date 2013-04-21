//
//  main.m
//  tutorial1_makingDisplay
//
//  Created by Derrick Ho on 4/10/13.
//
//




//=============================
//api tutorial 2: full screen display (node: seems buggy)
//-----------------------------
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"

int main(int argc, char **argv){

	ALLEGRO_DISPLAY       *display = NULL;
	ALLEGRO_DISPLAY_MODE   disp_data;

	al_init(); // I'm not checking the return value for simplicity.
	al_init_image_addon();
	al_init_primitives_addon();
	int num =al_get_num_display_modes();
//	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);// get minimum resolution
al_get_display_mode(1, &disp_data);//get max resolution.
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(disp_data.width, disp_data.height);

	al_rest(3);
	al_destroy_display(display);

	return 0;
}	



