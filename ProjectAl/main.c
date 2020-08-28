#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
int main()
{
    //Variaveis do Game;
    const int largura = 500;
    const int altura = 350;
    //Start Allegro5
    //This command create a screen
    ALLEGRO_DISPLAY* display=NULL;

    //Allegro Setup Error Message
    if(!al_init())
        al_show_native_message_box(NULL,NULL,NULL,"Allegro nao foi inicializado com sucesso",NULL,NULL);

    //Screen Resolution
    display = al_create_display(largura,altura);

    //Allegro Screen Creating Error
    if(!display)
        al_show_native_message_box(NULL,NULL,NULL,"Erro ao criar o display",NULL,NULL);

    //Start ADDONS
    //Screen Rest Time
    al_init_primitives_addon();//Start formas primitivas
    /*
    al_draw_pixel(300,250,al_map_rgb(200,255,255));
    al_draw_line(100,100,largura - 100, 100, al_map_rgb(255,0,0),2);
    al_draw_line(50,200,largura - 50, 200, al_map_rgb(0,255,0),2);
    */
    al_draw_triangle(10,200,100,10,190,200,al_map_rgb(255,0,255),3);
    al_draw_filled_triangle(200,300,400,100,400,300,al_map_rgb(155,0,0));
    al_draw_circle(200,250,100,al_map_rgb(0,0,255),2);
    al_flip_display();
    al_rest(5.0);
    al_destroy_display(display);
    return 0;
}
