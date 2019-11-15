
  /*!***************************************************************************************************
 * \file transforme.c
 * \author
 * \date
 * \brief ensemble de fonctions relatives � la transformation d'un fichier BMP
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
*    en un fichier BMP o� on n'a gard� que les intensit�s de bleu pour chaque pixel.
*    Les intensites de rouge et de vert sont mises � z�ro
*  \param [in] nomFichEntree   chaine de caract�res ontenant le nom du fichier � modifier.
*  \param [in ] nomFichTransf  chaine de caract�res contenant le nom du fichier qui contiendra l'image bleuie
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
*  \brief  charge en m�moire une image BMP en s�parant l'en-t�te de la zone bit map. L'allocation des deux
*          emplacements m�moire est faite par deux malloc
*          Effectue au pr�alable
*          une lecture de l'en-t�te gr�ce � la fonction litEnTete et retourne l'en-t�te lue en param�tre r�sultat
*  \param [in]  nomDeFichierBMP   le fichier bmp � charger en m�moire. Aucune v�rification du type n'est faite
*  \param [out ] ptEntete  retourne un pointeur sur la zone m�moire contenant une copie de l'image disque de l'en-t�te
*  \param [out ] ptImage   retourne un pointeur sur la zone m�moire contenant une copie de l'image disque de la zone bit map

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
*  \brief   Fonction retournant une structure contenant les intensit�s de bleu vert et rouge d'un pixel
*           rep�r� par sa ligne et sa colonne
*           (0,0) est le coin inf�rieur gauche.
*           Pour simplifier, aucune v�rification de non d�passement des dimensions de l'image n'est faite.
*            A l'utilisateur d'�tre prudent!
*  \param [in] ligne   num�ro de ligne � partir du bas de l'image. la num�rotation des lignes commence � 0
*  \param [in] colonne  num�ro de colonne � partir de la gauche de l'image. la num�rotation des colonnes commence � 0
*  \param [in ] ptImageBitMap  pointeur sur la zone bit map en m�moire
*  \param [in ] enTete structure de type EnTeteBMP pour avoir acc�s � la g�om�trie de l'image
* \return une structure de type Pixel_T contenant les intensit�s de B V R du pixel
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
*  \brief   Fonction permettant de positionner un pixel rep�r� par sa ligne et sa colonne avec  des intensit�s
*           de bleu vert et rouge d'un pixel
*           (0,0) est le coin inf�rieur gauche.
*           Pour simplifier, aucune v�rification de non d�passement des dimensions de l'image n'est faite.
*            A l'utilisateur d'�tre prudent!
*  \param [in] ligne   num�ro de ligne � partir du bas de l'image. la num�rotation des lignes commence � 0
*  \param [in] colonne  num�ro de colonne � partir de la gauche de l'image. la num�rotation des colonnes commence � 0
*  \param [in] intensitesPix  une structure de type Pixel_T contenant les intensit�s � placer de BVR � placer dans le pixel
*  \param [in ] ptImageBitMap  pointeur sur la zone bit map en m�moire
*  \param [in ] enTete structure de type EnTeteBMP pour avoir acc�s � la g�om�trie de l'image
*  \return  rien  car on suppose pour simplifier que le pixel sera forc�ment dans l'image.  Vous pourrez � la fin s�curiser un peu cette fonction
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
*  \brief  sauve sur disque l'image en m�moire ayant �t� charg�e au pr�alable par la fonction chargeImageEnMemoire
*
*  \param [in ] ptEntete  pointeur sur la zone m�moire contenant l'en-t�te  du fichier tel qu'il doit �tre �crit sur le disque
*  \param [in] ptImage    pointeur sur la zone m�moire contenant la zone bit map de l'image
*  \param [in]  nomDeFichierSauv   chaine de caract�res contenant le nom du fichier bmp o� sera sauvegard�e l'image .
*  \param [in ] enTeteBMP   une structure de type EnTeteBMP pour documenter l'image en m�moire
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
