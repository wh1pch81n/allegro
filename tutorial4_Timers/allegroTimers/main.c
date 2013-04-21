//
//  main.c
//  tutorial4_Timers
//
//  Created by Derrick Ho on 4/15/13.
//
//

/*
{ What are Timers }
Timers are event sources that will send regular timed events at a given interval

{ Why do I want timers }
Timers can be used to regulate your main updte loop, so you only run at a given
FPS, or they can be used to the know when an animation needs to update, etc.

**note
Building upon the previous example, we demonstate timers
*/

#include <stdio.h>
#include <allegro5/allegro.h>

const float FPS = 60;// The rate taht will limit our logic

int main(int argc, char **argv){
	
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool redraw = true;
	
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	
	timer = al_create_timer(1.0 / FPS);// initialize our timer tick 1/FPS seconds per time.  AKA period
	if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
	
	display = al_create_display(640, 480);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}
	
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	
	al_register_event_source(event_queue, al_get_display_event_source(display));
	
	/*Make the event queue sensitive to the timer
	It allows timer events to be captured into the queue
	*/
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	
	al_clear_to_color(al_map_rgb(0,0,0));
	
	al_flip_display();
	
	/*Starts the timer.  This is manditory or else the timer won't start*/
	al_start_timer(timer);
	
	while(1)
	{
		ALLEGRO_EVENT ev;
		/*
		 It will stay here if no events captured.
		*/
		al_wait_for_event(event_queue, &ev);
		
		/*If the event is the Timer, triger a redraw.
		
		**This is where game logic would be taken care of**
		*/
		if(ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		
		/*Want to redraw only when all events have been
		consumed
		*/
		if(redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));
			al_flip_display();
		}
	}
	
	//house keeping
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	
	return 0;
}
