//
//  main.m
//  tutorial1_makingDisplay
//
//  Created by Derrick Ho on 4/10/13.
//
//




//=============================
//api tutorial 1: creating the display
//-----------------------------
#include <allegro5/allegro.h>
int main(int argc, char **argv) {
	/*The minimal start up code for allegro (taken from an old outdated site somewhere
	//	al_init();
	//	al_create_display(640, 480);
	//	al_clear_to_color(al_map_rgb_f(1, 1, 0));
	//	al_flip_display();
	//	al_rest(5.0);
	*/
	
	/*api tutorial*/
	ALLEGRO_DISPLAY *display = NULL;
	
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	
	display = al_create_display(640, 480);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	/*This draws to a screen thats invisable to the user.  We draw all the stuff
	we want here prior to showing it to the user.  Its kind of like in the instinct
	engine where you stacked images in the buffer prior to pushing it on to the
	screen.  This function lets stack that buffer
	
	al_map_rgb fills the buffer with one solid color.
	al_clear_to_color clears the screen before adding that solid color
	*/
	al_clear_to_color(al_map_rgb(1,0,0));
	
	/*Allegro, by default, creates two image buffers -- the one being displayed
	on the screen, and the one being drawn on in the code. When you have
	finished drawing to one of the image buffers for one loop, then you are
	ready to display its result to the screen for the user. al_flip_display is
	called to swap the two image buffers around so that the first image buffer
	is now displayed to the user while the second image buffer becomes the one
	you will draw on. Failing to call this function will result in only the single,
	blank image buffer being shown on the screen.
	*/
	al_flip_display();
	
	/*Here we rest the program for 10 seconds. al_rest takes a floating point
	integer specifying how many seconds to sleep. Using any valid floating point
	number is valid, including numbers less than 1.0. Allegro will attempt to sleep
	for the amount of time specified, but it does not have perfect accuracy.
	*/
	al_rest(10.0);
	
	/*This function destroys our display and frees the memory and should be
	called when you are about to shut down the program.	 And that concludes our
	basic introduction to Allegro 5 displays.
	*/
	al_destroy_display(display);
	return 0;
}


