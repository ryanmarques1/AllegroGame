#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
int main()
{
    //Variaveis do Game;

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
        al_show_native_message_box(NULL,NULL,NULL,"Erro ao criar o display,fechando",NULL,NULL);

    //Start ADDONS
    //Screen Rest Time

    al_init_primitives_addon();
    /*Utilização de imagesn */  al_init_image_addon();

    //-------------------------------------
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    al_rest(5.0);
    al_destroy_display(display);
    return 0;
}
