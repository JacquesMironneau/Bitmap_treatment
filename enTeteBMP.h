
/*!***************************************************************************************************
 * \file enTeteBMP.h
 * \author A Lagreze
 * \date Septembre 2014
 * \brief constantes et déclaration diverses relatives à l'extration de l'en-tête d'un fichier image BMP
 * \version 1.0
 ********************************************************************************************************/

#ifndef ENTETE_H
#define ENTETE_H

 typedef struct { /*structure (globale) ou seront stockées les infos importantes  de l'entete */
  char signature[3];  /* devra être une chaine de caractères terminée par 0 */
  int tailleFichier;
  int offsetDebImage;
  int tailleEntete;
  int largeurImage;
  int hauteurImage;
  int profCodage;
  int tailleImage;

  }EnTeteBMP;
/*******************************************/
/************* definition constantes  ******/
/*******************************************/
#define ERREUR 0
#define OK 1

#define TAILLE_SIGNATURE 2

#define OFFSET_TAILLE_FICHIER 2  /* deplacement du champ taillefichier par rapport debut du fichier*/
#define TAILLE_TAILLE_FICHIER 4  /* nbre d octets codant la taille du fichier */

#define OFFSET_OFFSET_DEBUT_IMAGE 10
#define TAILLE_OFFSET_DEBUT_IMAGE 4

/*** completez la suite **/
#define OFFSET_TAILLE_ENTETE 14 
#define TAILLE_TAILLE_ENTETE 4

#define OFFSET_LARGEUR_IMAGE 18
#define TAILLE_LARGEUR_IMAGE 4

#define OFFSET_HAUTEUR_IMAGE 22
#define TAILLE_HAUTEUR_IMAGE 4

#define OFFSET_PROFOND_CODAGE 28
#define TAILLE_PROFOND_CODAGE 2

#define OFFSET_TAILLE_IMAGE 34
#define TAILLE_TAILLE_IMAGE 4


#endif
