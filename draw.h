#ifndef draw_h
#define draw_h

// Les Structures

typedef struct pays{
    char* nom;
    char* cont;
}pays;

typedef struct chapeau{
    pays p1;
    pays p2;
    pays p3;
    pays p4;
    pays p5;
    pays p6;
    pays p7;
    pays p8;
}Chapeau;

typedef struct groupe{
    char* pays1;
    char* pays2;
    char* pays3;
    char* pays4;
}Groupe;

#endif
