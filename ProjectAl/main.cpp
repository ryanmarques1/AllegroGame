#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


enum teclaS{up,down,rigth,left};
int main()
{


    //display
    const int largura = 640;
    const int altura = 480;

    //Variaveis do Game;
    bool END = false;
    int px = 100;
    int py = 100;
    bool teclas[] = {false,false,false,false};
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




    //Inicialização de addons e instalações.
    al_install_keyboard();
    al_init_primitives_addon();
    al_init_image_addon();
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
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                END = true;
            }
            switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                teclas[up] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                teclas[down] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                teclas[rigth] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                teclas[left] = true;
                break;
            }
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_UP){
                switch(ev.keyboard.keycode){
                case ALLEGRO_KEY_UP:
                    teclas[up] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    teclas[down] = false;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    teclas[rigth] = false;
                    break;
                case ALLEGRO_KEY_LEFT:
                    teclas[left] = false;
                    break;
                default:
                    break;
                }

          }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            END = true;
        }
        py-= teclas[up] * 10;
        py+= teclas[down] * 10;
        px-= teclas[left] * 10;
        px+= teclas[rigth] * 10;
    //Drawn

       al_draw_filled_rectangle(px,py, px + 20, py + 20, al_map_rgb(255,0,0));
       al_flip_display();
       al_clear_to_color(al_map_rgb(0,0,0));
    }

    //-------------------------------------
    //END GAME
    al_destroy_display(display);
    al_destroy_event_queue(events);
    return 0;
}
