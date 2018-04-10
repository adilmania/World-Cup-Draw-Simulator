#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "draw.h"

void filling_1(int s[])
{
    int i, j, r;
    srand(time(NULL));
    r = ((rand() % 7) + 1);
    for (i = 0; i < 7; i++)
    {
        do
        {
            r = ((rand() % 7) + 1);
            for (j = 0; j < i; j++)
            {
                if (r == s[j])
                {
                    r = 0;
                }
            }
        }
        while (r == 0);
        s[i] = r;
    }
}

int filling_2(int l[], country ** groups, country ** pots)
{
    int test2;
    int i, j, r;
    int cpt = 0;
    srand(time(NULL));
    r = ((rand() % 8) + 1);
    for (i = 0; i < 8; i++)
    {
        do
        {
            r = ((rand() % 8) + 1);
            for (j = 0; j < i; j++)
            {
                if ( r == l[j] || ( (*(*(groups+i))).cont == (*(*(pots+1)+r-1)).cont ) && ( (*(*(pots+1)+r-1)).cont == "conmebol" ) )
                {
                    r = 0;
                    cpt++;
                }
            }
        }
        while (r == 0 && cpt<1000000);
        l[i] = r;
        (*(*(groups+i)+1)) = (*(*(pots+1)+r-1));
        if (cpt>=1000000)
        {
            test2 = 1;
        }
    }
    return test2;
}

int filling_3(int l[], country ** groups, country ** pots)
{
    int test3;
    int i, j, r;
    int cpt2 = 0;
    srand(time(NULL));
    r = ((rand() % 8) + 1);
    for (i = 0; i < 8; i++)
    {
        do
        {
            r = ((rand() % 8) + 1);
            for (j = 0; j < i; j++)
            {
                if ( r == l[j] ||

                ( ((*(*(groups+i))).cont == ((*(*(groups+i)+1)).cont)) && ((*(*(groups+i))).cont == ((*(*(pots+2)+r-1)).cont)) ) 

                || 
                
                ( ( (*(*(groups+i)+1)).cont == (*(*(pots+2)+r-1)).cont ) && ( (*(*(pots+2)+r-1)).cont == "concacaf" ) )

                )
                {
                    r = 0;
                    cpt2++;
                }
            }
        }
        while (r == 0 && cpt2<1000000);
        l[i] = r;
        (*(*(groups+i)+2)) = (*(*(pots+2)+r-1));
        if (cpt2>=1000000)
        {
            test3 = 1;
        }
    }
    return test3;
}


int filling_4(int l[], country ** groups, country ** pots)
{
    int test4;
    int i, j, r;
    int cpt3 = 0;
    srand(time(NULL));
    r = ((rand() % 8) + 1);
    for (i = 0; i < 8; i++)
    {
        do
        {
            r = ((rand() % 8) + 1);
            for (j = 0; j < i; j++)
            {
                if ( r == l[j] ||
                            (   ( (*(*(pots+3)+r-1)).cont == "uefa" ) && 
                                (
                                    ( 
                                        ( (*(*(groups+i))).cont == (*(*(groups+i)+1)).cont ) 
                                        && 
                                        ( (*(*(groups+i)+1)).cont == "uefa" )     
                                    )
                                    ||
                                    (
                                        ( (*(*(groups+i))).cont == (*(*(groups+i)+2)).cont ) 
                                        && 
                                        ( (*(*(groups+i))).cont == "uefa" )  
                                    )
                                    ||
                                    (
                                        ( (*(*(groups+i)+1)).cont == (*(*(groups+i)+2)).cont ) 
                                        && 
                                        ( (*(*(groups+i)+1)).cont == "uefa" )  
                                    )
                                )
                            )
                            ||
                            (   ( (*(*(pots+3)+r-1)).cont != "uefa" ) && 
                                (
                                  ( ( (*(*(pots+3)+r-1)).cont == (*(*(groups+i)+1)).cont ) || ( (*(*(pots+3)+r-1)).cont == (*(*(groups+i)+2)).cont ) )  
                                )
                            )
                    )
                {
                    r = 0;
                    cpt3++;
                }
            }
        }
        while (r == 0 && cpt3<1000000);
        l[i] = r;
        (*(*(groups+i)+3)) = (*(*(pots+3)+r-1));
        if (cpt3>=1000000)
        {
            test4 = 1;
        }
    }
    return test4;
}

int main(){

    int refait = 0;

    while(refait == 0)
    {
        int s[8];
        int l[8];

        refait = 0;

        filling_1(s);

        // Initialisation country

        country Russie; Russie.name = "Russie"; Russie.cont = "uefa";
        country Allemagne; Allemagne.name = "Allemagne"; Allemagne.cont = "uefa";
        country Angleterre; Angleterre.name = "Angleterre"; Angleterre.cont = "uefa";
        country Espagne; Espagne.name = "Espagne"; Espagne.cont = "uefa";
        country France; France.name = "France"; France.cont = "uefa";
        country Belgique; Belgique.name = "Belgique"; Belgique.cont = "uefa";
        country Serbie; Serbie.name = "Serbie"; Serbie.cont = "uefa";
        country Suede; Suede.name = "Suede"; Suede.cont = "uefa";
        country Suisse; Suisse.name = "Suisse"; Suisse.cont = "uefa";
        country Pologne; Pologne.name = "Pologne"; Pologne.cont = "uefa";
        country Portugal; Portugal.name = "Portugal"; Portugal.cont = "uefa";
        country Danemark; Danemark.name = "Danemark"; Danemark.cont = "uefa";
        country Croatie; Croatie.name = "Croatie"; Croatie.cont = "uefa";
        country Islande; Islande.name = "Islande"; Islande.cont = "uefa";

        country Bresil; Bresil.name = "Bresil"; Bresil.cont = "conmebol";
        country Argentine; Argentine.name = "Argentine"; Argentine.cont = "conmebol";
        country Uruguay; Uruguay.name = "Uruguay"; Uruguay.cont = "conmebol";
        country Colombie; Colombie.name = "Colombie"; Colombie.cont = "conmebol";
        country Perou; Perou.name = "Perou"; Perou.cont = "conmebol";

        country Mexique; Mexique.name = "Mexique"; Mexique.cont = "concacaf";
        country Costa_Rica; Costa_Rica.name = "Costa_Rica"; Costa_Rica.cont = "concacaf";
        country Panama; Panama.name = "Panama"; Panama.cont = "concacaf";

        country Nigeria; Nigeria.name = "Nigeria"; Nigeria.cont = "caf";
        country Maroc; Maroc.name = "Maroc"; Maroc.cont = "caf";
        country Tunisie; Tunisie.name = "Tunisie"; Tunisie.cont = "caf";
        country Egypte; Egypte.name = "Egypte"; Egypte.cont = "caf";
        country Senegal; Senegal.name = "Senegal"; Senegal.cont = "caf";

        country Coree_du_Sud; Coree_du_Sud.name = "Coree_du_Sud"; Coree_du_Sud.cont = "afc";
        country Japon; Japon.name = "Japon"; Japon.cont = "afc";
        country Arabie_Saoudite; Arabie_Saoudite.name = "Arabie_Saoudite"; Arabie_Saoudite.cont = "afc";
        country Australie; Australie.name = "Australie"; Australie.cont = "afc";
        country Iran; Iran.name = "Iran"; Iran.cont = "afc";

        // Initialisation pot

        country pot_1[8] = {Russie,Allemagne,Bresil,Portugal,Argentine,Belgique,Pologne,France};
        country pot_2[8] = {Espagne,Perou,Suisse,Angleterre,Colombie,Mexique,Uruguay,Croatie};
        country pot_3[8] = {Danemark,Islande,Costa_Rica,Suede,Tunisie,Egypte,Senegal,Iran};
        country pot_4[8] = {Serbie,Nigeria,Australie,Japon,Maroc,Panama,Coree_du_Sud,Arabie_Saoudite};

        country * pots[4] = {pot_1,pot_2,pot_3,pot_4};  

        // printf("2 Elements du pot 1: %s %s \n",(*(*(pots)+6)).name,(*(*(pots)+1)).name); /* Allemagne : Pologne */

        // Initialisation Group

        country Group_1[4]; country Group_2[4]; country Group_3[4]; country Group_4[4];
        country Group_5[4]; country Group_6[4]; country Group_7[4]; country Group_8[4];
        country * groups[8] = {Group_1,Group_2,Group_3,Group_4,Group_5,Group_6,Group_7,Group_8};

        // filling groups - 1er pot
            
        Group_1[0] = pot_1[0];
        Group_2[0] = pot_1[(s[0])];
        Group_3[0] = pot_1[(s[1])];
        Group_4[0] = pot_1[(s[2])];
        Group_5[0] = pot_1[(s[3])];
        Group_6[0] = pot_1[(s[4])];
        Group_7[0] = pot_1[(s[5])];
        Group_8[0] = pot_1[(s[6])];

        // filling groups - 2eme pot

        refait = filling_2(l,groups,pots);

        // filling groups - 3eme pot

        refait = filling_3(l,groups,pots);

        // filling groups - 4eme pot

        refait = filling_4(l,groups,pots);

        // Particular Case

        if((Group_1[0]).name=="Russie" && (Group_1[1]).name=="Colombie" && (Group_1[2]).name=="Tunisie" && (Group_1[3]).name=="Maroc")
        {
            refait = 1;
        }

        // Print 1

        printf("\nWORLD CUP 2018 DRAW SIMULATOR - RUSSIA \n\n");

        printf("The Group 1: %s , %s , %s , %s\n",(Group_1[0]).name,(Group_1[1]).name,(Group_1[2]).name,(Group_1[3]).name);
        printf("The Group 2: %s , %s , %s , %s\n",(Group_2[0]).name,(Group_2[1]).name,(Group_2[2]).name,(Group_2[3]).name);
        printf("The Group 3: %s , %s , %s , %s\n",(Group_3[0]).name,(Group_3[1]).name,(Group_3[2]).name,(Group_3[3]).name);
        printf("The Group 4: %s , %s , %s , %s\n",(Group_4[0]).name,(Group_4[1]).name,(Group_4[2]).name,(Group_4[3]).name);
        printf("The Group 5: %s , %s , %s , %s\n",(Group_5[0]).name,(Group_5[1]).name,(Group_5[2]).name,(Group_5[3]).name);
        printf("The Group 6: %s , %s , %s , %s\n",(Group_6[0]).name,(Group_6[1]).name,(Group_6[2]).name,(Group_6[3]).name);
        printf("The Group 7: %s , %s , %s , %s\n",(Group_7[0]).name,(Group_7[1]).name,(Group_7[2]).name,(Group_7[3]).name);
        printf("The Group 8: %s , %s , %s , %s\n",(Group_8[0]).name,(Group_8[1]).name,(Group_8[2]).name,(Group_8[3]).name);


    }
    
    return 0;
}
