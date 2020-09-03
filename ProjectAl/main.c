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
    /*Utiliza��o de imagesn */  al_init_image_addon();

    /* Load fonts */ al_init_font_addon();
    al_init_ttf_addon();

    /*
    al_draw_triangle(10,200,100,10,190,200,al_map_rgb(255,0,255),2);
    al_draw_pixel(300,250,al_map_rgb(200,255,255));
    al_draw_line(100,100,largura - 100, 100, al_map_rgb(255,0,0),2);
    al_draw_line(50,200,largura - 50, 200, al_map_rgb(0,255,0),2);
    al_draw_filled_triangle(100,250,150,10,190,200,al_map_rgb(155,0,0));
    al_draw_circle(250,200,50,al_map_rgb(0,0,255),2);
    al_draw_ellipse(100,100,100,200,al_map_rgb(0,255,0),2);
    /*Dando load na imagem ALLEGRO_BITMAP *piso = al_load_bitmap("teste.bmp");*/
    /*
    al_draw_bitmap(piso,50,50,ALLEGRO_FLIP_HORIZONTAL);

    float pontos[] = {0,0,400,100,50,200,largura,altura};
    float pontos2[] = {0,0,largura,400,250,300,altura,largura};
    float pontos3[] = {0,altura,300,350,largura,altura,500,100};
    al_draw_spline(pontos,al_map_rgb(255,0,0),5);
    al_draw_spline(pontos2,al_map_rgb(0,255,0),5);
    al_draw_spline(pontos3,al_map_rgb(0,0,255),5);
    */
    ALLEGRO_FONT *fonte = al_load_font(("Alien_Strawberry.ttf",20,NULL);

    //Drawn
    al_draw_text(fonte,al_map_rgb(255,255,0),50,50,"Arkanoid: The vengeance of Dio");


    //-------------------------------------
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    al_rest(5.0);

    al_destroy_display(display);
    al_destroy_bitmap(piso);
    al_destroy_font(fonte);
    return 0;
}
