
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
#define FICHIER1 "ImgBitmap/avion.bmp"
#define FICHIER2 "ImgBitmap/casimir.bmp"
#define FICHIER3 "ImgBitmap/velo_de_cours.bmp"
#define NOM_FICHIER_COPIE "ImgBitmap/avionCopie.bmp"
#define NOM_FICHIER_TEST_SET_PIXEL "ImgBitmap/avionTestSetPixel.bmp"
#define NOM_FICHIER_BLEU "ImgBitmap/avionBleu.bmp"
#define NOM_FICHIER_CARRE_ROUGE "ImgBitmap/avionCarreRouge.bmp"
#define NOM_FICHIER_ROT90 "ImgBitmap/avion90.bmp"
/***********************************************/
/************ prototype des fonctions  *********/
/***********************************************/
extern int  bleuitImageBMP (char nomFichEntree[], char nomFichTransf[]);
extern void carreRouge(int largCar,int hautCar,char *nomFichEntree,char *nomFichAvecCarre);
extern void rotation90Horaire(char nomFichEntree[], char nomFichTransf[]);
extern int  chargeImageEnMemoire ( char *nomDeFichierBMP, char **ptEnTete, char **ptImage, EnTeteBMP *enTeteBMP);
extern void  rectangleRouge(int x, int y, int largCar,int hautCar,char *nomFichEntree,char *nomFichAvecCarre);
extern void rotate90Degrees(char *inputFile, char* outputFile);
/******************************************/
/************ fonction principale  ********/
/******************************************/
int main(void)
{
    char  *ptTete, *ptImage;
    EnTeteBMP teteBmp;
    int row,col;

    chargeImageEnMemoire (FICHIER1, &ptTete, &ptImage, &teteBmp);
    sauveImageSurDisque(ptTete,ptImage,NOM_FICHIER_COPIE,teteBmp);


    /*Set green a 30*30 square*/

    Pixel_T green = {0,127,0};
    for(row = 0; row < 30; row++)
	for(col = 0;col < 30; col++)
	    setPixel(row,col,green,ptImage,teteBmp); 


    /*Set anoter green  30*30 square*/
    for(row = teteBmp.hauteurImage; row > teteBmp.hauteurImage - 30; --row)
	for(col = teteBmp.largeurImage;col > teteBmp.largeurImage - 30; --col)
	    setPixel(row,col,green,ptImage,teteBmp); 


    /*Question getPixel*/
    Pixel_T p;

    p = getPixel(0,0, ptImage,teteBmp);
    printf("Le pixel est : %d %d %d", p.bleu, p.vert, p.rouge);

    /*Question bleu*/
    bleuitImageBMP(FICHIER2, "ImgBitmap/casimirbleu.bmp");

    /*Question carré rouge*/
    rectangleRouge(10,10, 100, 100, FICHIER2, "ImgBitmap/casimirrouge.bmp");

    sauveImageSurDisque(ptTete,ptImage,NOM_FICHIER_COPIE,teteBmp);

    rotate90Degrees(FICHIER1, NOM_FICHIER_ROT90);

    return EXIT_SUCCESS;
}

