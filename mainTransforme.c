
 /*!***************************************************************************************************
 * \file mainTransforme.c fourni aux étudiant
 * \author A Lagreze
 * \date  Septembre 2014
 * \brief  Programme main permettant de lancer un certain nombre de transformations sur des fichiers BMP
 * \version 1.0
 ********************************************************************************************************/
/*************************************/
/****  fichiers inclus **************/
/*************************************/
 #include <stdlib.h>
 #include <stdio.h>
 #include "enTeteBMP.h"
#include "transforme.h"
/***********************************************/
/************ definition des constantes ********/
/***********************************************/
 #define FICHIER1 "avion.bmp"
 #define FICHIER2 "casimir.bmp"
 #define FICHIER3 "velo_de_cours.bmp"
 #define NOM_FICHIER_COPIE "avionCopie.bmp"
 #define NOM_FICHIER_TEST_SET_PIXEL "avionTestSetPixel.bmp"
 #define NOM_FICHIER_BLEU "avionBleu.bmp"
 #define NOM_FICHIER_CARRE_ROUGE "avionCarreRouge.bmp"
 #define NOM_FICHIER_ROT90 "avion90.bmp"
/***********************************************/
/************ prototype des fonctions  *********/
/***********************************************/
int extern bleuitImageBMP (char nomFichEntree[], char nomFichTransf[]);
void extern carreRouge(int largCar,int hautCar,char *nomFichEntree,char *nomFichAvecCarre);
void extern rotation90Horaire(char nomFichEntree[], char nomFichTransf[]);
int extern chargeImageEnMemoire ( char *nomDeFichierBMP, char **ptEnTete, char **ptImage, EnTeteBMP *enTeteBMP);
void extern rectangleRouge(int x, int y, int largCar,int hautCar,char *nomFichEntree,char *nomFichAvecCarre);

/******************************************/
/************ fonction principale  ********/
/******************************************/
int main(void)
{

    char  *ptTete, *ptImage;
    puts("sauvez moi");
    EnTeteBMP teteBmp;
    /*
    chargeImageEnMemoire ("avion.bmp", &ptTete, &ptImage, &teteBmp);
    puts("sauvez le");
    sauveImageSurDisque(ptTete,ptImage,NOM_FICHIER_COPIE,teteBmp);
*/
    chargeImageEnMemoire (FICHIER3, &ptTete, &ptImage, &teteBmp);
    

    /*Set green a 30*30 square*/
   Pixel_T green = {0,127,0};
    int row;
    int col;
    for(row = 0; row < 30; row++)
        for(col =0;col < 30; col++)
            setPixel(row,col,green,ptImage,teteBmp); 

    Pixel_T p = getPixel(0,0, ptImage,teteBmp);
    printf("Le pixel est : %d %d %d", p.bleu, p.vert, p.rouge);

    bleuitImageBMP(FICHIER1, "bleu.bmp");

    rectangleRouge(10,10, 100, 100, "avion.bmp", "rouge.bmp");

    sauveImageSurDisque(ptTete,ptImage,NOM_FICHIER_COPIE,teteBmp);
    /*
    rajoutez ici le test de getPixel.
    rectangleRouge(completer, NOM_FICHIER_ENTREE,NOM_FICHIER_CARRE_ROUGE);
    rotation90Horaire(NOM_FICHIER_ENTREE, NOM_FICHIER_ROT90);
  */
}

