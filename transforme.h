/*************************************************************
déclarations et définitions relatives au fichier transforme.c 
**************************************************************/


/****  types **************/
/********************************************/
 typedef struct { char bleu; char vert; char rouge ;}Pixel_T;
/*********************************************/
/****  prototypes des fonctions **************/
/********************************************/
 int chargeImageEnMemoire ( char *nomDeFichierBMP, char **ptEnTete, char **ptImage, EnTeteBMP *enTeteBMP);
 int litEnteteBMP (char *nomDeFichierBMP, EnTeteBMP *enTete);
 void afficheEnTeteBMP (EnTeteBMP enTete);
 void setPixel(int ligne, int colonne, Pixel_T intensitesPix, char *ptImageBitMap, EnTeteBMP enTete);
 Pixel_T getPixel(int  ligne, int colonne, char * ptImageBitMap,EnTeteBMP enTete );
 void sauveImageSurDisque(char *ptEntete, char *ptImage,char *nomFichSauv,EnTeteBMP entete);
 void carreRouge(int largCar,int hautCar,char *nomFich,char *nomFichAvecCarre);
 void rectangleRouge(int x, int y, int largCar,int hautCar,char *nomFichEntree,char *nomFichAvecCarre);
