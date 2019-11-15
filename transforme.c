
  /*!***************************************************************************************************
 * \file transforme.c
 * \author
 * \date
 * \brief ensemble de fonctions relatives à la transformation d'un fichier BMP
 *         Etat : WORK IS IN PROGRESS
 * \version 1.0
 ********************************************************************************************************/
/*************************************/
/****  fichiers inclus **************/
/*************************************/
 #include <stdlib.h>
 #include <stdio.h>
 #include "enTeteBMP.h"
 #include "transforme.h"
 


/*!******************************************************************************************************
*  \fn   bleuitImageBMP (char nomFichEntree[], char nomFichTransf[])
*  \brief   Fonction permettant de transformer un fichier BMP en entree
*    en un fichier BMP où on n'a gardé que les intensités de bleu pour chaque pixel.
*    Les intensites de rouge et de vert sont mises à zéro
*  \param [in] nomFichEntree   chaine de caractères ontenant le nom du fichier à modifier.
*  \param [in ] nomFichTransf  chaine de caractères contenant le nom du fichier qui contiendra l'image bleuie
**************************************************************************************************************/
int bleuitImageBMP (char nomFichEntree[], char nomFichTransf[])
{
    /*
      FILE *fichBleu;
	  char *ptEnt, *ptIm;
      EnTeteBMP enTete;

      free(ptEnt);
      free(ptIm);
*/
}


/*!******************************************************************************************************
*  \fn   chargeImageEnMemoire ( char *nomDeFichierBMP, char **ptEntete, char **ptImage, EnTeteBMP *enTete)
*  \brief  charge en mémoire une image BMP en séparant l'en-tête de la zone bit map. L'allocation des deux
*          emplacements mémoire est faite par deux malloc
*          Effectue au préalable
*          une lecture de l'en-tête grâce à la fonction litEnTete et retourne l'en-tête lue en paramètre résultat
*  \param [in]  nomDeFichierBMP   le fichier bmp à charger en mémoire. Aucune vérification du type n'est faite
*  \param [out ] ptEntete  retourne un pointeur sur la zone mémoire contenant une copie de l'image disque de l'en-tête
*  \param [out ] ptImage   retourne un pointeur sur la zone mémoire contenant une copie de l'image disque de la zone bit map

*  \return  retourne OK  ou ERREUR si l'ouverture du fichier pose probleme
**************************************************************************************************************/
int chargeImageEnMemoire ( char *nomDeFichierBMP, char **ptEnTete, char **ptImage, EnTeteBMP *enTeteBMP)
{
     FILE *f;
     if (litEnteteBMP (nomDeFichierBMP,enTeteBMP) == ERREUR)
        return ERREUR;

     f=fopen(nomDeFichierBMP,"rb");  

     *ptEnTete = malloc(enTeteBMP->tailleEntete);
     *ptImage = malloc(enTeteBMP->tailleImage);
    
     fread(*ptEnTete,enTeteBMP->tailleEntete, 1, f); 
     fread(*ptImage,enTeteBMP->tailleImage, 1, f); 

     return OK;
}

/*!******************************************************************************************************
*  \fn   getPixel(int  ligne, int colonne, char * ptImageBitMap,EnTeteBMP enTete )
*  \brief   Fonction retournant une structure contenant les intensités de bleu vert et rouge d'un pixel
*           repéré par sa ligne et sa colonne
*           (0,0) est le coin inférieur gauche.
*           Pour simplifier, aucune vérification de non dépassement des dimensions de l'image n'est faite.
*            A l'utilisateur d'être prudent!
*  \param [in] ligne   numéro de ligne à partir du bas de l'image. la numérotation des lignes commence à 0
*  \param [in] colonne  numéro de colonne à partir de la gauche de l'image. la numérotation des colonnes commence à 0
*  \param [in ] ptImageBitMap  pointeur sur la zone bit map en mémoire
*  \param [in ] enTete structure de type EnTeteBMP pour avoir accès à la géométrie de l'image
* \return une structure de type Pixel_T contenant les intensités de B V R du pixel
**************************************************************************************************************/
Pixel_T getPixel(int  ligne, int colonne, char * ptImageBitMap,EnTeteBMP enTete )
{
    int nbBourrage;
    Pixel_T pix;
    /*  a compleer */
    int row = enTete.largeurImage - ligne;
    int col = enTete.hauteurImage - colonne;
    int offset = row * 8 * col;

    //handle offset to get the 3 differents values
    printf("%d", *(ptImageBitMap + offset));
    printf("%d", *(ptImageBitMap + offset + 8));
    printf("%d", *(ptImageBitMap + offset + 16));



    return pix;

}

/*!******************************************************************************************************
*  \fn   setPixel(int ligne, int colonne, Pixel_T intensitesPix, char *ptImageBitMap, EnTeteBMP enTete)
*  \brief   Fonction permettant de positionner un pixel repéré par sa ligne et sa colonne avec  des intensités
*           de bleu vert et rouge d'un pixel
*           (0,0) est le coin inférieur gauche.
*           Pour simplifier, aucune vérification de non dépassement des dimensions de l'image n'est faite.
*            A l'utilisateur d'être prudent!
*  \param [in] ligne   numéro de ligne à partir du bas de l'image. la numérotation des lignes commence à 0
*  \param [in] colonne  numéro de colonne à partir de la gauche de l'image. la numérotation des colonnes commence à 0
*  \param [in] intensitesPix  une structure de type Pixel_T contenant les intensités à placer de BVR à placer dans le pixel
*  \param [in ] ptImageBitMap  pointeur sur la zone bit map en mémoire
*  \param [in ] enTete structure de type EnTeteBMP pour avoir accès à la géométrie de l'image
*  \return  rien  car on suppose pour simplifier que le pixel sera forcément dans l'image.  Vous pourrez à la fin sécuriser un peu cette fonction
**************************************************************************************************************/
void setPixel(int ligne, int colonne, Pixel_T intensitesPix, char *ptImageBitMap, EnTeteBMP enTete)
{
      int nbBourrage = enTete.largeurImage % 4;
      register int offSetIndex =ligne*(enTete.largeurImage + nbBourrage) + colonne;
      *(ptImageBitMap + offSetIndex ) = intensitesPix.bleu;
      *(ptImageBitMap + offSetIndex+1 ) = intensitesPix.vert;
      *(ptImageBitMap + offSetIndex+2 ) = intensitesPix.rouge;

}
/*!*****************************************************************************************************************
*  \fn   void sauveImageSurDisque(char *ptEnTete, char *ptImage,char *nomFichSauv,EnTeteBMP enTete )
*  \brief  sauve sur disque l'image en mémoire ayant été chargée au préalable par la fonction chargeImageEnMemoire
*
*  \param [in ] ptEntete  pointeur sur la zone mémoire contenant l'en-tête  du fichier tel qu'il doit être écrit sur le disque
*  \param [in] ptImage    pointeur sur la zone mémoire contenant la zone bit map de l'image
*  \param [in]  nomDeFichierSauv   chaine de caractères contenant le nom du fichier bmp où sera sauvegardée l'image .
*  \param [in ] enTeteBMP   une structure de type EnTeteBMP pour documenter l'image en mémoire
*  \return  retourne OK  ou ERREUR si l'ouverture du fichier pose probleme
********************************************************************************************************************/
void sauveImageSurDisque(char *ptEnTete, char *ptImage,char *nomFichSauv,EnTeteBMP enTete )
{
    
     FILE *fichSauv;
     if((fichSauv = fopen(nomFichSauv,"wb"))== NULL)
             return;

     fwrite(ptEnTete, enTete.tailleEntete,1,fichSauv);
     fwrite(ptImage, enTete.tailleImage,1,fichSauv);
     fclose(fichSauv);

}
void rectangleRouge(int x, int y, int largCar,int hautCar,char *nomFichEntree,char *nomFichAvecCarre)
{
    /*
      EnTeteBMP enTete;
      int lig,col;
      char *ptEnt, *ptIm,*pt;
      free(ptEnt);
      free(ptIm);
      */
}
