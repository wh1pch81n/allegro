//
//  main.c
//  allegro_test_take2
//
//  Created by Derrick Ho on 3/17/13.
//
//

////============================
////api tutorial 3: events
////----------------------------
//// [what are events]
//// They are an indicator that something has happened.  Like a mouse click or key press.
//// You may make your own events if needed
//
//// [why do i want events?]
//// It is more efficient.  events get placed in a queue and you deal with them
//// as needed.
//
//// { Event Sources }
//// examples include but not limited to Timers, Displays, and Inputs
//
//// { Event Queues }
//// This is the place Queues are pushed into.  You may pop them to handle each event.
////-----------------------------
//#include <stdio.h>
//#include <allegro5/allegro.h>
//
//int main(int argc, char **argv){
//	
//	ALLEGRO_DISPLAY *display = NULL; // create display pointer
//	ALLEGRO_EVENT_QUEUE *event_queue = NULL; //create event queue pointer
//	
//	//initialize allegro or die trying
//	if(!al_init()) {
//		fprintf(stderr, "failed to initialize allegro!\n");
//		return -1;
//	}
//	
//	//create a 640x 480 display or die trying
//	display = al_create_display(640, 480);
//	if(!display) {
//		fprintf(stderr, "failed to create display!\n");
//		return -1;
//	}
//	
//	//create event_queue or die trying
//	event_queue = al_create_event_queue();
//	if(!event_queue) {
//		fprintf(stderr, "failed to create event_queue!\n");
//		al_destroy_display(display);
//		return -1;
//	}
//	
//	// Allow event queue to consume events from the display.
//	// Without this function, the display events will be ignored
//	al_register_event_source(event_queue, al_get_display_event_source(display));
//	
//	al_clear_to_color(al_map_rgb(0,0,0)); //modity the bg color of the screen_buffer
//	
//	al_flip_display(); //show buffer.
//	
//	while(1)
//	{
//		ALLEGRO_EVENT ev;
//		ALLEGRO_TIMEOUT timeout;
//		
//		al_init_timeout(&timeout, 10); //initialize an ALLEGRO_TIMEOUT object to 60 ms aka 0.06 seconds
//		printf("blah3  ");
//		//It will rest here for the duration of the specified timeout and then continue to the next instruction
//		//If an event happens before that timeout happens, it will also go to the next instruction
//		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);
//		printf("blah3\n");
//		// goes in here if an event was recieved AND the event is a display closed
//		if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//			break;
//		}
//		
//		al_clear_to_color(al_map_rgb(0,0,0));
//		al_flip_display();
//	}
//	
//	al_destroy_display(display);
//	al_destroy_event_queue(event_queue);
//	
//	return 0;
//}



////=============================
////api tutorial 2: full screen display (node: seems buggy)
////-----------------------------
//#include "allegro5/allegro.h"
//#include "allegro5/allegro_image.h"
//#include "allegro5/allegro_primitives.h"
//
//int main(int argc, char **argv){
//	
//	ALLEGRO_DISPLAY       *display = NULL;
//	ALLEGRO_DISPLAY_MODE   disp_data;
//	
//	al_init(); // I'm not checking the return value for simplicity.
//	al_init_image_addon();
//	al_init_primitives_addon();
//	int num =al_get_num_display_modes();
////	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);// get minimum resolution
//al_get_display_mode(1, &disp_data);//get max resolution.
//	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
//	display = al_create_display(disp_data.width, disp_data.height);
//	
//	al_rest(3);
//	al_destroy_display(display);
//	
//	return 0;
//}


////=============================
////api tutorial 1: creating the display
////-----------------------------
//#include <allegro5/allegro.h>
//int main(int argc, char **argv) {
////The minimal start up code for allegro
////	al_init();
////	al_create_display(640, 480);
////	al_clear_to_color(al_map_rgb_f(1, 1, 0));
////	al_flip_display();
////	al_rest(5.0);
//
////api tutorial
//	ALLEGRO_DISPLAY *display = NULL;
//	
//	if(!al_init()) {
//		fprintf(stderr, "failed to initialize allegro!\n");
//		return -1;
//	}
//	
//	display = al_create_display(640, 480);
//	if(!display) {
//		fprintf(stderr, "failed to create display!\n");
//		return -1;
//	}
//	//This draws to a screen thats invisable to the user.  We draw all the stuff
//	//we want here prior to showing it to the user.  Its kind of like in the instinct
//	//engine where you stacked images in the buffer prior to pushing it on to the
//	//screen.  This function lets stack that buffer
//	//
//	//al_map_rgb fills the buffer with one solid color.
//	//al_clear_to_color clears the screen before adding that solid color
//	
//	al_clear_to_color(al_map_rgb(0,0,0));
//	
//	//Allegro, by default, creates two image buffers -- the one being displayed
//	//on the screen, and the one being drawn on in the code. When you have
//	//finished drawing to one of the image buffers for one loop, then you are
//	//ready to display its result to the screen for the user. al_flip_display is
//	//called to swap the two image buffers around so that the first image buffer
//	//is now displayed to the user while the second image buffer becomes the one
//	//you will draw on. Failing to call this function will result in only the single,
//	//blank image buffer being shown on the screen.
//	al_flip_display();
//	
//	//Here we rest the program for 10 seconds. al_rest takes a floating point
//	//integer specifying how many seconds to sleep. Using any valid floating point
//	//number is valid, including numbers less than 1.0. Allegro will attempt to sleep
//	//for the amount of time specified, but it does not have perfect accuracy.
//	al_rest(10.0);
//	
//	//This function destroys our display and frees the memory and should be
//	//called when you are about to shut down the program.	 And that concludes our
//	//basic introduction to Allegro 5 displays.
//	al_destroy_display(display);
//	return 0;
//}

