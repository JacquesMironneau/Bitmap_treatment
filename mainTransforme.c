
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
void extern rotate90Degrees(char *inputFile, char* outputFile);
/******************************************/
/************ fonction principale  ********/
/******************************************/
int main(void)
{

    char  *ptTete, *ptImage;
    EnTeteBMP teteBmp;
    chargeImageEnMemoire (FICHIER1, &ptTete, &ptImage, &teteBmp);
    sauveImageSurDisque(ptTete,ptImage,"onzeSeptembre.bmp",teteBmp);


    /*Set green a 30*30 square*/
    Pixel_T green = {0,127,0};
    int row,col;

    for(row = 0; row < 30; row++)
	for(col = 0;col < 30; col++)
	    setPixel(row,col,green,ptImage,teteBmp); 


    /*Set anoter green  30*30 square*/
    for(row = teteBmp.hauteurImage; row > teteBmp.hauteurImage - 30; --row)
	for(col = teteBmp.largeurImage;col > teteBmp.largeurImage - 30; --col)
	    setPixel(row,col,green,ptImage,teteBmp); 


    //Question getPixel
    Pixel_T p = getPixel(0,0, ptImage,teteBmp);
    printf("Le pixel est : %d %d %d", p.bleu, p.vert, p.rouge);

    //Question bleu
    bleuitImageBMP(FICHIER2, "casimirbleu.bmp");

    //Question carré rouge
    rectangleRouge(10,10, 100, 100, FICHIER2, "casimirrouge.bmp");

    sauveImageSurDisque(ptTete,ptImage,NOM_FICHIER_COPIE,teteBmp);

    //Test rotation with 3 differents bmp files
    rotate90Degrees(FICHIER1, NOM_FICHIER_ROT90);
    //rotate90Degrees(FICHIER2, "902.bmp");
    //rotate90Degrees(FICHIER3, "903.bmp");
}

