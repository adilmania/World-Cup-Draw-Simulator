#ifndef draw_h
#define draw_h

// Les Structures

typedef struct country{
    char* name;
    char* cont;
}country;

typedef struct pot{
    country p1;
    country p2;
    country p3;
    country p4;
    country p5;
    country p6;
    country p7;
    country p8;
}pot;

typedef struct group{
    char* country1;
    char* country2;
    char* country3;
    char* country4;
}group;

#endif
