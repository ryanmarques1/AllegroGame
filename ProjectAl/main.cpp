#include <iostream>
#include <windows.h>
#include <cmath>
//----------------------------
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

enum teclaS{up,down,rigth,left1};
using namespace std;


int main()
{

    //display
    const int largura = 640;
    const int altura = 480;

    //Variaveis do Game;
    bool END = false;
    int px = 100;
    int py = 100;
    int cont = 0;
    bool teclas[] = {false,false,false,false};
    bool drawn = false;
    bool drawn2 = false;
    bool drawn3 = false;
    bool drawn4 = false;
    float px_q = 0.0;
    float py_q = 0.0;
    float px_c = 0.0;
    float py_c = 0.0;
    float px_t=0.0,py_t=0.0,px_t2=0.0,py_t2=0.0,px_t3=0.0,py_t3=0.0;
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
    al_install_mouse();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_ttf_addon();
    al_init_font_addon();
    //importanado os atributos.

    ALLEGRO_EVENT_QUEUE *events = NULL;
    ALLEGRO_FONT *font20 = NULL;
    //Entrada de dados e eventos
    events = al_create_event_queue();

    //Sources e Registros
    al_register_event_source(events,al_get_keyboard_event_source());
    al_register_event_source(events,al_get_display_event_source(display));
    al_register_event_source(events,al_get_mouse_event_source());


    font20 = al_load_font("slkscr.ttf",20,NULL);
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
                teclas[left1] = true;
                break;
            case ALLEGRO_KEY_Z:
                al_clear_to_color(al_map_rgb(0,0,0));
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
                    teclas[left1] = false;
                    break;
                default:
                    break;
                }

          }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            END = true;
        }
        //Utilizando o cursor do mouse para movimentar algum objeto

        else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES){
            px = ev.mouse.x;
            py = ev.mouse.y;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
             if(ev.mouse.button & 1){
                drawn = !drawn;
             }

            else if(ev.mouse.button & 2){
               END = true;

          }
        }



        if(teclas[up])
         py-= teclas[up] * 15;
        else if(teclas[down])
         py+= teclas[down] * 15;
        else if(teclas[left1])
         px-= teclas[left1] * 15;
        else if(teclas[rigth])
         px+= teclas[rigth] * 15;



    al_draw_textf( font20,al_map_rgb(255,0,0),largura/2,altura/2, ALLEGRO_ALIGN_CENTRE,"Quadros: ",cont++);

    //Drawn in Display

    if(drawn)
        al_draw_filled_rectangle(px_q,py_q,px_q + 30,py_q + 30,al_map_rgb(255,0,0));

    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
}

    //-------------------------------------
    //END GAME
    al_destroy_display(display);
    al_destroy_event_queue(events);
    return 0;
  }

