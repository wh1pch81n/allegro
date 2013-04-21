//
//  main.m
//  tutorial3
//
//  Created by Derrick Ho on 4/10/13.
//
//




//============================
//api tutorial 3: events
//----------------------------
// [what are events]
// They are an indicator that something has happened.  Like a mouse click or key press.
// You may make your own events if needed

// [why do i want events?]
// It is more efficient.  events get placed in a queue and you deal with them
// as needed.

// { Event Sources }
// examples include but not limited to Timers, Displays, and Inputs

// { Event Queues }
// This is the place Queues are pushed into.  You may pop them to handle each event.
//-----------------------------
#include <stdio.h>
#include <allegro5/allegro.h>

int main(int argc, char **argv){

	ALLEGRO_DISPLAY *display = NULL; // create display pointer
	ALLEGRO_EVENT_QUEUE *event_queue = NULL; //create event queue pointer

	//initialize allegro or die trying
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	//create a 640x 480 display or die trying
	display = al_create_display(640, 480);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	//create event_queue or die trying
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}

	// Allow event queue to consume events from the display.
	// Without this function, the display events will be ignored
	al_register_event_source(event_queue, al_get_display_event_source(display));
	
	//Trying to make it accept mouse events ( this is off the book)
	if(!al_install_mouse()){ fprintf(stderr, "failed to init mouse\n"); return -1;}
	al_register_event_source(event_queue, al_get_mouse_event_source());
	
	//Trying to make it accpet keyboard events ( this is off the book)
	if(!al_install_keyboard()){ fprintf(stderr, "failed to init keyboard\n"); return -1;}
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0,0,0)); //modity the bg color of the screen_buffer

	al_flip_display(); //show buffer.

	while(1)
	{
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;

		al_init_timeout(&timeout, 10); //initialize an ALLEGRO_TIMEOUT object to 60 ms aka 0.06 seconds
		//printf("blah3  ");
		//It will rest here for the duration of the specified timeout and then continue to the next instruction
		//If an event happens before that timeout happens, it will also go to the next instruction
		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);
		//printf("blah3\n");
		// goes in here if an event was recieved AND the event is a display closed
		if(get_event){
			switch (ev.type) {
				case ALLEGRO_EVENT_DISPLAY_CLOSE: {
					printf("Display has been closed by the red x\n");
					goto CLEAN_UP_AND_EXIT;
					break;
				}case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
					printf("mouse button has been pressed down\n");
					break;
				}case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
					printf("mouse button has been released\n");
					break;
				}case ALLEGRO_EVENT_MOUSE_AXES:{
					printf("mouse move\n");
					break;
				} case ALLEGRO_EVENT_KEY_DOWN:{
					printf("a key is down\n");
					break;
				}case ALLEGRO_EVENT_KEY_UP:{ 
					printf("a key is up\n");
					break;
				} default:{
					printf("No event but timer has exired\n");
				}
			}
		}
		al_clear_to_color(al_map_rgb(0,0,0));
		al_flip_display();
	}
	CLEAN_UP_AND_EXIT:
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
