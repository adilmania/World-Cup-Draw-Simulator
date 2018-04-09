#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "draw.h"

void Remplissage_1(int s[])
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

int Remplissage_2(int l[], pays ** Groupes, pays ** Chapeaux)
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
                if ( r == l[j] || ( (*(*(Groupes+i))).cont == (*(*(Chapeaux+1)+r-1)).cont ) && ( (*(*(Chapeaux+1)+r-1)).cont == "conmebol" ) )
                {
                    r = 0;
                    cpt++;
                }
            }
        }
        while (r == 0 && cpt<1000000);
        l[i] = r;
        (*(*(Groupes+i)+1)) = (*(*(Chapeaux+1)+r-1));
        if (cpt>=1000000)
        {
            test2 = 1;
        }
    }
    return test2;
}

int Remplissage_3(int l[], pays ** Groupes, pays ** Chapeaux)
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

                ( ((*(*(Groupes+i))).cont == ((*(*(Groupes+i)+1)).cont)) && ((*(*(Groupes+i))).cont == ((*(*(Chapeaux+2)+r-1)).cont)) ) 

                || 
                
                ( ( (*(*(Groupes+i)+1)).cont == (*(*(Chapeaux+2)+r-1)).cont ) && ( (*(*(Chapeaux+2)+r-1)).cont == "concacaf" ) )

                )
                {
                    r = 0;
                    cpt2++;
                }
            }
        }
        while (r == 0 && cpt2<1000000);
        l[i] = r;
        (*(*(Groupes+i)+2)) = (*(*(Chapeaux+2)+r-1));
        if (cpt2>=1000000)
        {
            test3 = 1;
        }
    }
    return test3;
}


int Remplissage_4(int l[], pays ** Groupes, pays ** Chapeaux)
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
                            (   ( (*(*(Chapeaux+3)+r-1)).cont == "uefa" ) && 
                                (
                                    ( 
                                        ( (*(*(Groupes+i))).cont == (*(*(Groupes+i)+1)).cont ) 
                                        && 
                                        ( (*(*(Groupes+i)+1)).cont == "uefa" )     
                                    )
                                    ||
                                    (
                                        ( (*(*(Groupes+i))).cont == (*(*(Groupes+i)+2)).cont ) 
                                        && 
                                        ( (*(*(Groupes+i))).cont == "uefa" )  
                                    )
                                    ||
                                    (
                                        ( (*(*(Groupes+i)+1)).cont == (*(*(Groupes+i)+2)).cont ) 
                                        && 
                                        ( (*(*(Groupes+i)+1)).cont == "uefa" )  
                                    )
                                )
                            )
                            ||
                            (   ( (*(*(Chapeaux+3)+r-1)).cont != "uefa" ) && 
                                (
                                  ( ( (*(*(Chapeaux+3)+r-1)).cont == (*(*(Groupes+i)+1)).cont ) || ( (*(*(Chapeaux+3)+r-1)).cont == (*(*(Groupes+i)+2)).cont ) )  
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
        (*(*(Groupes+i)+3)) = (*(*(Chapeaux+3)+r-1));
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

        Remplissage_1(s);

        // Initialisation Pays

        pays Russie; Russie.nom = "Russie"; Russie.cont = "uefa";
        pays Allemagne; Allemagne.nom = "Allemagne"; Allemagne.cont = "uefa";
        pays Angleterre; Angleterre.nom = "Angleterre"; Angleterre.cont = "uefa";
        pays Espagne; Espagne.nom = "Espagne"; Espagne.cont = "uefa";
        pays France; France.nom = "France"; France.cont = "uefa";
        pays Belgique; Belgique.nom = "Belgique"; Belgique.cont = "uefa";
        pays Serbie; Serbie.nom = "Serbie"; Serbie.cont = "uefa";
        pays Suede; Suede.nom = "Suede"; Suede.cont = "uefa";
        pays Suisse; Suisse.nom = "Suisse"; Suisse.cont = "uefa";
        pays Pologne; Pologne.nom = "Pologne"; Pologne.cont = "uefa";
        pays Portugal; Portugal.nom = "Portugal"; Portugal.cont = "uefa";
        pays Danemark; Danemark.nom = "Danemark"; Danemark.cont = "uefa";
        pays Croatie; Croatie.nom = "Croatie"; Croatie.cont = "uefa";
        pays Islande; Islande.nom = "Islande"; Islande.cont = "uefa";

        pays Bresil; Bresil.nom = "Bresil"; Bresil.cont = "conmebol";
        pays Argentine; Argentine.nom = "Argentine"; Argentine.cont = "conmebol";
        pays Uruguay; Uruguay.nom = "Uruguay"; Uruguay.cont = "conmebol";
        pays Colombie; Colombie.nom = "Colombie"; Colombie.cont = "conmebol";
        pays Perou; Perou.nom = "Perou"; Perou.cont = "conmebol";

        pays Mexique; Mexique.nom = "Mexique"; Mexique.cont = "concacaf";
        pays Costa_Rica; Costa_Rica.nom = "Costa_Rica"; Costa_Rica.cont = "concacaf";
        pays Panama; Panama.nom = "Panama"; Panama.cont = "concacaf";

        pays Nigeria; Nigeria.nom = "Nigeria"; Nigeria.cont = "caf";
        pays Maroc; Maroc.nom = "Maroc"; Maroc.cont = "caf";
        pays Tunisie; Tunisie.nom = "Tunisie"; Tunisie.cont = "caf";
        pays Egypte; Egypte.nom = "Egypte"; Egypte.cont = "caf";
        pays Senegal; Senegal.nom = "Senegal"; Senegal.cont = "caf";

        pays Coree_du_Sud; Coree_du_Sud.nom = "Coree_du_Sud"; Coree_du_Sud.cont = "afc";
        pays Japon; Japon.nom = "Japon"; Japon.cont = "afc";
        pays Arabie_Saoudite; Arabie_Saoudite.nom = "Arabie_Saoudite"; Arabie_Saoudite.cont = "afc";
        pays Australie; Australie.nom = "Australie"; Australie.cont = "afc";
        pays Iran; Iran.nom = "Iran"; Iran.cont = "afc";

        // Initialisation Chapeau

        pays Chapeau_1[8] = {Russie,Allemagne,Bresil,Portugal,Argentine,Belgique,Pologne,France};
        pays Chapeau_2[8] = {Espagne,Perou,Suisse,Angleterre,Colombie,Mexique,Uruguay,Croatie};
        pays Chapeau_3[8] = {Danemark,Islande,Costa_Rica,Suede,Tunisie,Egypte,Senegal,Iran};
        pays Chapeau_4[8] = {Serbie,Nigeria,Australie,Japon,Maroc,Panama,Coree_du_Sud,Arabie_Saoudite};

        pays * Chapeaux[4] = {Chapeau_1,Chapeau_2,Chapeau_3,Chapeau_4};  

        // printf("2 Elements du chapeau 1: %s %s \n",(*(*(Chapeaux)+6)).nom,(*(*(Chapeaux)+1)).nom); /* Allemagne : Pologne */

        // Initialisation Groupe

        pays Groupe_1[4]; pays Groupe_2[4]; pays Groupe_3[4]; pays Groupe_4[4];
        pays Groupe_5[4]; pays Groupe_6[4]; pays Groupe_7[4]; pays Groupe_8[4];
        pays * Groupes[8] = {Groupe_1,Groupe_2,Groupe_3,Groupe_4,Groupe_5,Groupe_6,Groupe_7,Groupe_8};

        // Remplissage Groupes - 1er Chapeau
            
        Groupe_1[0] = Chapeau_1[0];
        Groupe_2[0] = Chapeau_1[(s[0])];
        Groupe_3[0] = Chapeau_1[(s[1])];
        Groupe_4[0] = Chapeau_1[(s[2])];
        Groupe_5[0] = Chapeau_1[(s[3])];
        Groupe_6[0] = Chapeau_1[(s[4])];
        Groupe_7[0] = Chapeau_1[(s[5])];
        Groupe_8[0] = Chapeau_1[(s[6])];

        // Remplissage Groupes - 2eme Chapeau

        refait = Remplissage_2(l,Groupes,Chapeaux);

        // Remplissage Groupes - 3eme Chapeau

        refait = Remplissage_3(l,Groupes,Chapeaux);

        // Remplissage Groupes - 4eme Chapeau

        refait = Remplissage_4(l,Groupes,Chapeaux);

        // Traitement d'un cas particulier

        if((Groupe_1[0]).nom=="Russie" && (Groupe_1[1]).nom=="Colombie" && (Groupe_1[2]).nom=="Tunisie" && (Groupe_1[3]).nom=="Maroc")
        {
            refait = 1;
        }

        // Affichage 1

        printf("\nTIRAGE AU SORT COUPE DU MONDE 2018 - RUSSIE \n\n");

        printf("LE GROUPE 1: %s , %s , %s , %s\n",(Groupe_1[0]).nom,(Groupe_1[1]).nom,(Groupe_1[2]).nom,(Groupe_1[3]).nom);
        printf("LE GROUPE 2: %s , %s , %s , %s\n",(Groupe_2[0]).nom,(Groupe_2[1]).nom,(Groupe_2[2]).nom,(Groupe_2[3]).nom);
        printf("LE GROUPE 3: %s , %s , %s , %s\n",(Groupe_3[0]).nom,(Groupe_3[1]).nom,(Groupe_3[2]).nom,(Groupe_3[3]).nom);
        printf("LE GROUPE 4: %s , %s , %s , %s\n",(Groupe_4[0]).nom,(Groupe_4[1]).nom,(Groupe_4[2]).nom,(Groupe_4[3]).nom);
        printf("LE GROUPE 5: %s , %s , %s , %s\n",(Groupe_5[0]).nom,(Groupe_5[1]).nom,(Groupe_5[2]).nom,(Groupe_5[3]).nom);
        printf("LE GROUPE 6: %s , %s , %s , %s\n",(Groupe_6[0]).nom,(Groupe_6[1]).nom,(Groupe_6[2]).nom,(Groupe_6[3]).nom);
        printf("LE GROUPE 7: %s , %s , %s , %s\n",(Groupe_7[0]).nom,(Groupe_7[1]).nom,(Groupe_7[2]).nom,(Groupe_7[3]).nom);
        printf("LE GROUPE 8: %s , %s , %s , %s\n",(Groupe_8[0]).nom,(Groupe_8[1]).nom,(Groupe_8[2]).nom,(Groupe_8[3]).nom);


    }
    
    return 0;
}

