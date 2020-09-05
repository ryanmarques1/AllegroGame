#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
int main()
{
    //Variaveis do Game;
    const int largura = 640;
    const int altura = 480;
    const float x = 900;
    const float y = 264;
    const int x2 = 640;
    bool END = false;

    float pontos[] = {0,0,400,100,50,200,largura,altura};
    float pontos2[] = {0,0,largura,400,250,300,altura,largura};
    float pontos3[] = {0,altura,300,350,largura,altura,500,100};
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

    //Inicialização de addons
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    //importanado os atributos.
    /*Dando load na imagem ALLEGRO_BITMAP *piso = al_load_bitmap("teste.bmp");*/
    ALLEGRO_FONT *fonte = al_load_font("Alien_Strawberry.ttf",35,NULL);
    ALLEGRO_FONT *fonte2 = al_load_font("slkscr.ttf",20,NULL);
    ALLEGRO_EVENT_QUEUE *events = NULL;

    //Drawn
    /*
    al_draw_triangle(10,200,100,10,190,200,al_map_rgb(255,0,255),2);
    al_draw_pixel(300,250,al_map_rgb(200,255,255));
    al_draw_line(100,100,largura - 100, 100, al_map_rgb(255,0,0),2);
    al_draw_line(50,200,largura - 50, 200, al_map_rgb(0,255,0),2);
    al_draw_filled_triangle(100,250,150,10,190,200,al_map_rgb(155,0,0));
    al_draw_circle(250,200,50,al_map_rgb(0,0,255),2);
    al_draw_ellipse(100,100,100,200,al_map_rgb(0,255,0),2);
    al_draw_bitmap(piso,50,50,ALLEGRO_FLIP_HORIZONTAL);
    al_draw_spline(pontos,al_map_rgb(255,0,0),5);
    al_draw_spline(pontos2,al_map_rgb(0,255,0),5);
    al_draw_spline(pontos3,al_map_rgb(0,0,255),5);
    */
    al_draw_text(fonte,al_map_rgb(0,255,255),x2/2,190,ALLEGRO_ALIGN_CENTRE,"Arkanoid: The vengeance of Dio");
    al_draw_text(fonte2,al_map_rgb(0,255,0),100,250,NULL,"Play to Start");
    al_draw_text(fonte2,al_map_rgb(0,255,0),100,290,NULL,"Coop");
    al_draw_text(fonte2,al_map_rgb(0,255,0),100,330,NULL,"Options");
    al_draw_text(fonte2,al_map_rgb(0,255,0),100,370,NULL,"Extras");
    /*
    int pixelx = al_get_display_width(display);
    int pixely = al_get_display_height(display);
    al_draw_textf(fonte2,al_map_rgb(0,0,255),100,250,ALLEGRO_ALIGN_LEFT,"Possui as dimensoes:%d e %d",pixelx,pixely);
    */


    //Entrada de dados e eventos
    events = al_create_event_queue();
    al_register_event_source(events,al_get_keyboard_event_source());
    //-------------------------------------
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    al_rest(5.0);

    al_destroy_display(display);
    /*al_destroy_bitmap(piso);*/
    al_destroy_font(fonte);
    al_destroy_font(fonte2);
    return 0;
}
