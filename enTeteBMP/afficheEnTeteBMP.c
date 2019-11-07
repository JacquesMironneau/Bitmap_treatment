
 /*!***************************************************************************************************
 * \file afficheEnTeteBMP.c
 * \author A Lagreze
 * \date Septembre 2014
 * \brief programme permettant la lecture et l'affichage de l'en-tête d'un fichier BMP
 *        le nom du fichier est défini par un define place en debut de ce module
 *        Etat : en cours
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
 #define NOM_FICHIER "avion.bmp"

/***********************************************/
/************ prototype des fonctions  *********/
/***********************************************/
int extern litEnteteBMP (char nomDeFichierBMP[], EnTeteBMP *enTete);
void extern afficheEnTeteBMP (EnTeteBMP enTete);

/******************************************/
/************ fonction principale  ********/
/******************************************/
int main(void)
{
  EnTeteBMP enTeteFich;
  litEnteteBMP (NOM_FICHIER, &enTeteFich);
  afficheEnTeteBMP(enTeteFich);
}

