#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
int main()
{
    //display
    const int largura = 640;
    const int altura = 480;
    //Variaveis do Game;
    bool END = false;
    //Start Allegro5
    //This command create a screen
    ALLEGRO_DISPLAY* display=NULL;

    //Allegro Setup Error Message
    if(!al_init())
        al_show_native_message_box(NULL,NULL,NULL,"Allegro nao foi inicializado com sucesso",NULL,NULL);


    display = al_create_display(largura,altura);
    //Allegro Screen Creating Error
    if(!display)
        al_show_native_message_box(NULL,NULL,NULL,"Erro ao criar o display,fechando",NULL,NULL);




    //Inicialização de addons
    al_install_keyboard();
    //importanado os atributos.

    ALLEGRO_EVENT_QUEUE *events = NULL;

    //Entrada de dados e eventos
    events = al_create_event_queue();

    //Sources
    al_register_event_source(events,al_get_keyboard_event_source());
    al_register_event_source(events,al_get_display_event_source(display));

    //Loop
    while(!END){
        ALLEGRO_EVENT ev;
        al_wait_for_event(events,&ev);
        if(ev.type == ALLEGRO_EVENT_KEY_UP){
            if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
                END = true;
            }
        }
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            END = true;
        }
        al_flip_display();
    }
    //-------------------------------------

    al_destroy_display(display);
    al_destroy_event_queue(events);
    return 0;
}
