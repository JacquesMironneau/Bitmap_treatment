
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
/***********************************************/
/************ definition des constantes ********/
/***********************************************/
 #define NOM_FICHIER_ENTREE "avion.bmp"
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
    chargeImageEnMemoire ("velo_de_cours.bmp", &ptTete, &ptImage, &teteBmp);
    puts("sauvez le");
    sauveImageSurDisque(ptTete,ptImage,NOM_FICHIER_COPIE,teteBmp);


    /*
    rajoutez ici le test de test de setPixel (8 instructions)
    sauveImageSurDisque(completer,completer,NOM_FICHIER_TEST_SET_PIXEL,completer );
    rajoutez ici le test de getPixel.
    rectangleRouge(completer, NOM_FICHIER_ENTREE,NOM_FICHIER_CARRE_ROUGE);
    rotation90Horaire(NOM_FICHIER_ENTREE, NOM_FICHIER_ROT90);
  */
}

