 /*!***************************************************************************************************
 * \file enteteBMP.c
 * \author a completer 
 * \date  a completer
 * \brief  ensemble de fonctions relatives à la lecture et à l'affichage
 *         de l'en-tête d'un fichier BMP
 *         Etat : en cours
 * \version 1.0
 ********************************************************************************************************/
/*************************************/
/****  fichiers inclus **************/
/*************************************/
 #include <stdlib.h>
 #include <stdio.h>
 #include "enTeteBMP.h"
/*  à vous de faire un commentaire le plus precis possible de la fonction qui suit */
/*!******************************************************************************************************
*  \fn   litEnteteBMP (char *nomDeFichierBMP, EnTeteBMP *enTete)
*  \brief   à compléter 
*  \param [in] nomDeFichierBMP   une structure de type EnTeteBMP 
*   \param [out] enTete
*  \return 
***************************************************************************/
int litEnteteBMP (char *nomDeFichierBMP, EnTeteBMP *enTete)
{
      FILE *f;
      if ((f = fopen(nomDeFichierBMP, "rb"))==NULL)
      {
         printf (" probleme ouverture fichier %s\n", nomDeFichierBMP);
         return ERREUR;
      }
      fread(&enTete->signature,1,TAILLE_SIGNATURE,f);
        enTete->signature[2] = '\0';
      fseek(f,OFFSET_TAILLE_FICHIER,SEEK_SET);
      fread(&enTete->tailleFichier,TAILLE_TAILLE_FICHIER,1,f);

      fseek(f,OFFSET_OFFSET_DEBUT_IMAGE,SEEK_SET);
      fread(&enTete->offsetDebImage,TAILLE_OFFSET_DEBUT_IMAGE,1,f);

      fseek(f,OFFSET_TAILLE_ENTETE,SEEK_SET);
      fread(&enTete->tailleEntete,TAILLE_TAILLE_ENTETE,1,f);

      fseek(f,OFFSET_LARGEUR_IMAGE,SEEK_SET);
      fread(&enTete->largeurImage,TAILLE_LARGEUR_IMAGE,1,f);

      fseek(f,OFFSET_HAUTEUR_IMAGE,SEEK_SET);
      fread(&enTete->hauteurImage,TAILLE_HAUTEUR_IMAGE,1,f);

      fseek(f,OFFSET_PROFOND_CODAGE,SEEK_SET);
      fread(&enTete->profCodage,TAILLE_PROFOND_CODAGE,1,f);

      fseek(f,OFFSET_TAILLE_IMAGE,SEEK_SET);
      fread(&enTete->tailleImage,TAILLE_TAILLE_IMAGE,1,f);

      fclose(f);
      return OK;
}


/*!******************************************************************************************************
*  \fn   afficheEnTeteBMP (EnTeteBMP enTete)
*  \brief Fonction d'affichage à l'écran d'une structure de type EnTeteBMP
*  \param [in] enTete   une structure de type EnTeteBMP 
*  \return rien
*
*********************************************************************************************************/
void afficheEnTeteBMP (EnTeteBMP enTete)
{
  printf(" *****En tete du fichier bit map *** \n");
  printf ("Signature : %s\n",enTete.signature);
  printf ("Taille du fichier : %d\n",enTete.tailleFichier);
  printf ("Offset de début de l'image : %d\n",enTete.offsetDebImage);
  printf ("Taille du Bitmap Info(En tete) : %d\n",enTete.tailleEntete);
  printf ("Largeur : %d\n",enTete.largeurImage);
  printf ("Hauteur : %d\n",enTete.hauteurImage);
  printf ("Bits par pixels : %d\n",enTete.profCodage);
  printf ("Taille de l'image : %d\n",enTete.tailleImage);

}
