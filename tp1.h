#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED
#include <locale.h>
#include <ctype.h>
//2 ver projet1 sans fichier
//projet 2 avec 200 tel7
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct adr
{
    char rue[15];
    char ville[15];
    char code_postale[15];
};
 struct date
{
    char annee[15];
    char mois[15];
    char jour[15];
};
typedef struct rep
{
    char tel[15];
    char nom[15];
    char prenom[15];
    struct adr adresse;
    struct date date_naiss;
    char email[15];
};
struct cellule
{
    struct rep info;
    struct cellule *suiv;
};
typedef struct cellule* LISTE_P;

LISTE_P insere_tete_tel(LISTE_P L, struct rep x)
{
    LISTE_P p;
    p=(struct cellule*)malloc(sizeof(struct cellule));
    p->suiv=L;
    p->info=x;
    L=p;//lezem L pointe sur 1ere pos
    return L;
}
int test(LISTE_P LP , int num)
{
    LISTE_P p=LP;
    while(p!=NULL)
    {
        if (p->info.tel==num)
            return 1;
        p=p->suiv;
    }
    return 0;
}
LISTE_P insere_queue_tel(LISTE_P L, struct rep x)
{
    LISTE_P p1,p2;
    p1=(struct cellule*)malloc(sizeof(struct cellule));
    p1->info=x;
    p1->suiv=NULL;
    if(L==NULL)
        L=p1;
    else
    {
        p2=L;
        while(p2->suiv!=NULL)
            p2=p2->suiv;
        p2->suiv=p1;
    }
    return L;
}

LISTE_P recuperation(){
    FILE * f;
    f = fopen("file2.txt","r");
    struct rep R;
    LISTE_P LP=NULL;
    while(!feof(f)){
        fscanf(f,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s\n",R.tel,R.nom,R.prenom,R.adresse.rue,R.adresse.ville,R.adresse.code_postale,
               R.date_naiss.annee,R.date_naiss.mois,R.date_naiss.jour,R.email);
        LP=insere_queue_tel(LP,R);
    }
    fclose(f);
    return LP;
}
void ecrire(LISTE_P L,char* nomfichier){
    FILE *h;
    h=fopen(nomfichier,"w");
    while(L!=NULL){
    fprintf(h,"%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",L->info.tel,L->info.nom,L->info.prenom,L->info.adresse.rue,L->info.adresse.ville,L->info.adresse.code_postale,
            L->info.date_naiss.annee,L->info.date_naiss.mois,L->info.date_naiss.jour,L->info.email);
    L=L->suiv;
    }
    fclose(h);
}
LISTE_P insere_pos_tel(LISTE_P L, int pos,struct rep x)
{
    LISTE_P p2,p1=L;
    int i=1;
    while(i<pos-1)
    {
      p1=p1->suiv;
      i++;
    }
    p2=(struct cellule*)malloc(sizeof(struct cellule));
    p2->info=x;
    p2->suiv=p1->suiv;
    p1->suiv=p2;
}
int taille_liste_rep(LISTE_P L )
{
    LISTE_P p=L;
    int t=0;
    while(p!=NULL)
    {
        t++;
        p=p->suiv;
    }
    return  t;
}/*
int recherche_tel(LISTE_P L,int tele)
{
    int result,i=0;
    if(L==NULL)
        printf("La liste est vide");
    else{
        do{
                result=strcmp(L->info.tel,tele);
        if(result==1)
        return i;
        else{
            L=L->suiv;
            i++;
        }
    }while(L->suiv!=NULL);
    }
    printf("num tel n existe pas");
}*/
struct rep saisie_tel(LISTE_P L)
{
struct rep R;
int x ,test,existe,r,z=0,pos,t;
char post[15];
do{
        r=0;
        printf("tel :");
        gets(R.tel);
        for(int i=0;i<strlen(R.tel);i++){
        if (isalpha(R.tel[i]) != 0)
        r++;
        }
        LISTE_P p1=L;
        existe=0;
            while(existe==0 && p1!=NULL){
                if(strcmp(p1->info.tel,R.tel)==0){
                existe=1;
                }
                p1=p1->suiv;
                }
}while(strlen(R.tel)!=8 || existe==1|| r!=0);
do{
        existe=0;r=0;
        printf("Donner nom :");
        gets(R.nom);
        for(int i=0;i<strlen(R.nom);i++)
            existe += isspace(R.nom[i]);
            for(int i=0;i<strlen(R.nom);i++){
                if (isdigit(R.nom[i]) != 0)
                    r++;
                    }
}while((r!=0)||(existe!=0));
do{
    printf("Donner prenom :");
    gets(R.prenom);
    existe=0;
    for(int i=0;i<strlen(R.prenom);i++){
            existe += isspace(R.prenom[i]);
    }
}while(existe>8);
printf("Donner rue :");
gets(R.adresse.rue);
do{
printf("Donner ville :");
gets(R.adresse.ville);
existe=0;
for(int i=0;i<strlen(R.adresse.ville);i++){
        if (isdigit(R.adresse.ville[i]) != 0)
            existe++;
        }
}while((existe!=0));
do{
    printf("Donner le codepostal :");
    gets(R.adresse.code_postale);
    r=0;
    for(int i=0;i<strlen(R.adresse.code_postale);i++){
    if (isalpha(R.adresse.code_postale[i]) != 0)
            r++;
    }
    }while(r!=0||strlen(R.adresse.code_postale)!=4);
   do{
    z=0;
    printf("Donner la date de naissance :\n");
   do{
    printf("     Donner le jour: ");
   gets(R.date_naiss.jour);
   }while(strlen(R.date_naiss.jour)!=2);
    do{
    printf("     Donner le mois: ");
   gets(R.date_naiss.mois);}while(strlen(R.date_naiss.mois)!=2);
   do{
   printf("     Donner l annee: ");
   gets(R.date_naiss.annee);}while(strlen(R.date_naiss.annee)!=4);
    int nbJoursMois;
   int jour1,mois1, annee1;
   switch(atoi(R.date_naiss.mois))
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:nbJoursMois = 31;
                break;
        case 4:
        case 6:
        case 9:
        case 11:nbJoursMois = 30;
                break;
        case 2:
                if ((atoi(R.date_naiss.annee)%4==0) && (atoi(R.date_naiss.annee)%100 !=0)||(atoi(R.date_naiss.annee)%400) == 0)
                    nbJoursMois = 29;
                else
                    nbJoursMois = 28;
                break;
        default: printf("mois non valide\n");z=1;
    }
    if ((atoi(R.date_naiss.jour)>0) && (atoi(R.date_naiss.jour) <= nbJoursMois)  && (atoi(R.date_naiss.mois)>0)  && (atoi(R.date_naiss.mois) <= 12) && (atoi(R.date_naiss.annee) >0))
    {
              printf("date valide\n");

    }
    else{
        printf("date invalide\n");
        z=1;}
   }while(z==1);

char symb[20] ={'!','#','$','%','&','*','+','-','/','=','?','^','`','{','|','}','~','@','.','_','\0'};
char att = '@';
char pt = '.';
int occAtt=0;
int occPt=0;
existe=0;
int posAtt =0;
int posPt =0;
int occSymb=0;
                   do{
                        printf("Donner email :");
                        scanf("%s",R.email);int l=strlen(R.email);
                        if(!isalpha(R.email[0]))
                        existe=1;
                        for(int i=0;i<l;i++){
                                if(att==R.email[i]){
                                    occAtt++;
                                    posAtt=i;
                        }
                        if(pt==R.email[i])
                            occPt++;
                        if(i>0){
                                if(isalpha(R.email[i])==0&&isdigit(R.email[i]&&i>1)==0){
                                    int k=0;
                        for(int j=0;j<strlen(symb);j++){
                        if(R.email[i]==symb[j]){
                            k=1;
                        }
                        if(R.email[i]==R.email[i-1])
                            existe=1;
                        if(i>posAtt&&R.email[i]==symb[j])
                            occSymb++;
                    }
            if(k==0||occSymb>1)
                existe=1;
    }
        }
    }
    if(occAtt!=1||occPt==0){
    existe=1;
}
if(existe==0){
occPt=0;
for(int i=l-1;i>0;i--){
        if(att== R.email[i]){
            posAtt=i;
            break;
        }
        if(pt==R.email[i]){
            posPt=i;
        occPt++;
        }
}
int posLeng=l-posAtt;
    if(posPt<posAtt||posLeng<6||occPt!=1||posPt==l||posPt==l-1||posPt-posAtt<2||posAtt<=2)
    existe=1;
}
                   }while(existe);
return R;
}
LISTE_P creation(LISTE_P L,char* nomFichier)//ccccccreation
{
    FILE* h;
    h= fopen(nomFichier, "a");
    int pos , x , test,t,existe,r,z=0;
    struct rep R;
    char post[15];
    if(h==NULL)
        printf("impossible d'ouvrir le fichier");
else
{
    do
    {
        t=taille_liste_rep(L);
        do
        {
            printf("Donner la position entre 1 et %d d objet a ajouter: ",t+1);
            scanf("%d",&pos);
        }while(!(pos>=1 && pos<=t+1));
       do{
                r=0;
                printf("Donner tel:");
                gets(R.tel);
                for(int i=0;i<strlen(R.tel);i++){
                if (isalpha(R.tel[i]) != 0){//it doesnt check 2->7
                        r++;
                }
                }
                LISTE_P p1=L;
                 existe=0;
                    while(existe==0 && p1!=NULL){
                        if(strcmp(p1->info.tel,R.tel)==0){
                        existe=1;
                }
                        p1=p1->suiv;
                 }
            }while(strlen(R.tel)!=8 || existe==1 || r!=0);
            do{
                    existe=0;r=0;
                    printf("Donner nom :");
                    gets(R.nom);
                    for(int i=0;i<strlen(R.nom);i++)
                        existe += isspace(R.nom[i]);
                        for(int i=0;i<strlen(R.nom);i++){
                                if (isdigit(R.nom[i]) != 0)
                                    r++;
                        }
            }while((r!=0)||(existe!=0));
             do{
    printf("Donner prenom :");
            gets(R.prenom);
    existe=0;
    for(int i=0;i<strlen(R.prenom);i++){
      existe += isspace(R.prenom[i]);
    }
            }while(existe>8);
           printf("Donner rue :");
            gets(R.adresse.rue);
             do{
            printf("Donner ville :");
            gets(R.adresse.ville);
            existe=0;
            for(int i=0;i<strlen(R.adresse.ville);i++){
                    if (isdigit(R.adresse.ville[i]) != 0)
                    existe++;
                    }
    }while((existe!=0));
    do{
    printf("Donner le codepostal :");
    gets(R.adresse.code_postale);
    r=0;
    for(int i=0;i<strlen(R.adresse.code_postale);i++){
    if (isalpha(R.adresse.code_postale[i]) != 0)
            r++;
    }
    }while(r!=0||strlen(R.adresse.code_postale)!=4);

    do{
    z=0;
    printf("Donner la date de naissance :\n");
   do{
    printf("     Donner le jour: ");
   gets(R.date_naiss.jour);
   }while(strlen(R.date_naiss.jour)!=2);
    do{
    printf("     Donner le mois: ");
   gets(R.date_naiss.mois);}while(strlen(R.date_naiss.mois)!=2);
   do{
   printf("     Donner l annee: ");
   gets(R.date_naiss.annee);}while(strlen(R.date_naiss.annee)!=4);
    int nbJoursMois;
   int jour1,mois1, annee1;
   switch(atoi(R.date_naiss.mois))
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:nbJoursMois = 31;
                break;
        case 4:
        case 6:
        case 9:
        case 11:nbJoursMois = 30;
                break;
        case 2:
                if ((atoi(R.date_naiss.annee)%4==0) && (atoi(R.date_naiss.annee)%100 !=0)||(atoi(R.date_naiss.annee)%400) == 0)
                    nbJoursMois = 29;
                else
                    nbJoursMois = 28;
                break;
        default: printf("mois non valide\n");z=1;
    }
    if ((atoi(R.date_naiss.jour)>0) && (atoi(R.date_naiss.jour) <= nbJoursMois)  && (atoi(R.date_naiss.mois)>0)  && (atoi(R.date_naiss.mois) <= 12) && (atoi(R.date_naiss.annee) >0))
    {
              printf("date valide\n");

    }
    else{
        printf("date invalide\n");
        z=1;}
   }while(z==1);

char symb[20] ={'!','#','$','%','&','*','+','-','/','=','?','^','`','{','|','}','~','@','.','_','\0'};
char att = '@';
char pt = '.';
int occAtt=0;
int occPt=0;
existe=0;
int posAtt =0;
int posPt =0;
int occSymb=0;
                   do{
                        printf("Donner email :");
                        scanf("%s",R.email);int l=strlen(R.email);
                        if(!isalpha(R.email[0]))
                        existe=1;
                        for(int i=0;i<l;i++){
                                if(att==R.email[i]){
                                    occAtt++;
                                    posAtt=i;
                        }
                        if(pt==R.email[i])
                            occPt++;
                        if(i>0){
                                if(isalpha(R.email[i])==0&&isdigit(R.email[i]&&i>1)==0){
                                    int k=0;
                        for(int j=0;j<strlen(symb);j++){
                        if(R.email[i]==symb[j]){
                            k=1;
                        }
                        if(R.email[i]==R.email[i-1])
                            existe=1;
                        if(i>posAtt&&R.email[i]==symb[j])
                            occSymb++;
                    }
            if(k==0||occSymb>1)
                existe=1;
    }
        }
    }
    if(occAtt!=1||occPt==0){
    existe=1;
}
if(existe==0){
occPt=0;
for(int i=l-1;i>0;i--){
        if(att== R.email[i]){
            posAtt=i;
            break;
        }
        if(pt==R.email[i]){
            posPt=i;
        occPt++;
        }
}
int posLeng=l-posAtt;
    if(posPt<posAtt||posLeng<6||occPt!=1||posPt==l||posPt==l-1||posPt-posAtt<2||posAtt<=2)
    existe=1;
}
                   }while(existe);
            fprintf(h,"%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",R.tel,R.nom,R.prenom,R.adresse.rue,R.adresse.ville,R.adresse.code_postale,R.date_naiss.annee,R.date_naiss.mois,R.date_naiss.jour,R.email);
        if(pos==1){
                    L=insere_tete_tel(L,R);
                    }
        else{
            if(pos==t+1){
                L=insere_queue_tel(L,R);
            }
            else{
                insere_pos_tel(L,pos,R);
            }
        }
        do
        {
            printf("Voulez vous ajouter une autre personne O/N (0:Non,1: Oui).");
            scanf("%d",&test);
        }while(!(test==1 || test==0));
    }while(test);
    fclose(h);
}

    return L;
}
LISTE_P supprimer_pos_tel(LISTE_P L, int x)
{
    LISTE_P p2,p1=L;
    int i=1;
    while(i<=x ||p1!=NULL)
    {printf("%d",i);
        if(x==1){
                LISTE_P p1=(struct cellule*)malloc(sizeof(struct cellule));
    p1=L;
        L=L->suiv;
    free(p1);
return L;

        }
        else{
            if(i==x-1){
            p2=p1->suiv;
            p1->suiv=p2->suiv;
            free(p2);
            return L;
        }
        p1=p1->suiv;
        i++;
        }
    }
    return L;
}
LISTE_P affiche_personne(LISTE_P L,struct rep R){
    LISTE_P p1=L;
    int result1,result2,result3,result4,result5,result6,result7,result8,result9,result0;
    if(L==NULL){
        printf("Liste Vide");
    }
    else{
        while(p1!=NULL){
        result1=strcmp(p1->info.tel,R.tel);
        result2=strcmp(p1->info.nom,R.nom);
        result3=strcmp(p1->info.prenom,R.prenom);
        result4=strcmp(p1->info.email,R.email);
        result5=strcmp(p1->info.adresse.rue,R.adresse.rue);
        result6=strcmp(p1->info.adresse.ville,R.adresse.ville);

        result7=strcmp(p1->info.adresse.code_postale,R.adresse.code_postale);
        result8=strcmp(p1->info.date_naiss.jour,R.date_naiss.jour);
        result9=strcmp(p1->info.date_naiss.mois,R.date_naiss.mois);
        result0=strcmp(p1->info.date_naiss.annee,R.date_naiss.annee);
        if(!result1 && !result2 && !result3 && !result4 && !result5 && !result6 &&!result0  &&!result7
            &&!result8 &&!result9)
        {
             printf("tel :");
            printf("%s",p1->info.tel);
            printf("nom :");
            printf("%s",p1->info.nom);
            printf("rue :");
            printf("%s",p1->info.adresse.rue);
            printf("ville :");
            printf("%s",p1->info.adresse.ville);
            printf("code_postale :");
            printf("%s",p1->info.adresse.code_postale);
            printf("annee :");
            printf("%s",p1->info.date_naiss.annee);
            printf("mois :");
            printf("%s",p1->info.date_naiss.mois);
            printf("jour :");
            printf("%s",p1->info.date_naiss.jour);
            printf("email :");
            printf("%s",p1->info.email);
        }
            p1=p1->suiv;
    }
    }
    return L;
}
LISTE_P affiche_liste(LISTE_P L){
    if (L == NULL)
        printf("Liste Vide");
    else{
            LISTE_P p1=(struct cellule*)malloc(sizeof(struct cellule));
    p1=L;
        while(p1!=NULL)
        {
            printf("\n tel :");
            printf("%s",p1->info.tel);
            printf("\n nom :");
            printf("%s",p1->info.nom);
            printf("\n rue :");
            printf("%s",p1->info.adresse.rue);
            printf("\n ville :");
            printf("%s",p1->info.adresse.ville);
            printf("\n code_postale :");
            printf("%s",p1->info.adresse.code_postale);
            printf("\n annee :");
            printf("%s",p1->info.date_naiss.annee);
            printf("\n mois :");
            printf("%s",p1->info.date_naiss.mois);
            printf("\n jour :");
            printf("%s",p1->info.date_naiss.jour);
            printf("\n email :");
            printf("%s",p1->info.email);
            p1=p1->suiv;
        }}
        return L;
}
LISTE_P ajout_tete(LISTE_P L){
LISTE_P p;
struct rep R;
R=saisie_tel(L);
    p=(struct cellule*)malloc(sizeof(struct cellule));
    p->suiv=L;
    p->info=R;
    L=p;
    return L;
}
LISTE_P ajout_queue(LISTE_P L){
LISTE_P p1,p2;
struct rep R;
R=saisie_tel(L);
    p1=(struct cellule*)malloc(sizeof(struct cellule));
    p1->info=R;
    p1->suiv=NULL;
    if(L==NULL)
        L=p1;
    else
    {
        p2=L;
        while(p2->suiv!=NULL)
            p2=p2->suiv;
        p2->suiv=p1;
    }
    return L;
}
LISTE_P ajout_pos(LISTE_P L, int pos){
LISTE_P p2,p1=L;
    int i=1;
struct rep R;
R=saisie_tel(L);
    while(i<pos-1)
    {
      p1=p1->suiv;
      i++;
    }
    p2=(struct cellule*)malloc(sizeof(struct cellule));
    p2->info=R;
    p2->suiv=p1->suiv;
    p1->suiv=p2;
}
LISTE_P supp_tete(LISTE_P L){
if(L==NULL){
    return L;
}
    LISTE_P p1=(struct cellule*)malloc(sizeof(struct cellule));
    p1=L;
        L=L->suiv;
    free(p1);
return L;
}
LISTE_P supp_queue(LISTE_P L){
if(L==NULL){return L;}
    LISTE_P p1;
    LISTE_P p2;
    p1=L;
    while(p1->suiv!=NULL){
            p2=p1;
        p1=p1->suiv;
    }
    p2->suiv=NULL;//lezem el case kbal el l ekhra tpointe aal null
return L;
}
LISTE_P supp_pos(LISTE_P L,int x){
LISTE_P p2;
LISTE_P p1;
p1=L;
    int i=0;
    while(i<=x)
    {
      p1=p1->suiv;
      i++;
    }
    p2=p1->suiv;
    p1->suiv=p2->suiv;
    free(p2);
    return L;
}
LISTE_P supp_by_tel(LISTE_P L,int v[]){
LISTE_P p=L,prec=NULL;
if(L==NULL){
    printf("La liste est vide");
}
else{
    while(p){
        if(strcmp(p->info.tel,v)==0)//strcmp
        {
            if(prec==NULL){//supp au debut
                L=L->suiv;
                free(p);
                p=L;
            }
            else{//supp !debut
                prec->suiv=p->suiv;
                free(p);
                p=prec->suiv;
            }
        }
        else{//ville !=v
            prec=p;
            p=p->suiv;
        }
    }
}
    return L;
}
LISTE_P supp_by_ind(LISTE_P L,int v[]){
LISTE_P p;
LISTE_P prec;
prec=NULL;int i=0;
p=L;
char c[1];
//if(L==NULL){
    //printf("La liste est vide");
//}
//else{
    while(p){
        strncpy(c,p->info.tel,2);
        if(strcmp(c,v)==0)//strcmp
        {
                prec->suiv=p->suiv;
                free(p);
                p=prec->suiv;
        }
        else{//ville !=v
            prec=p;
            p=p->suiv;
        }
    }
    //}
    return L;
}
LISTE_P supp_by_ville(LISTE_P L,char v[]){
LISTE_P p=L,prec=NULL;
    while(p){
        if(strcmp(p->info.adresse.ville,v)==0)//strcmp
        {
            if(prec==NULL){//supp au debut
                L=L->suiv;
                free(p);
                p=L;
            }
            else{//supp !debut
                prec->suiv=p->suiv;
                free(p);
                p=prec->suiv;
            }
        }
        else{//ville !=v
            prec=p;
            p=p->suiv;
        }
    }
    return L;
}

LISTE_P modif_adr(LISTE_P L){////////////////////////////////////
    char r[15],v[15],cp[15];
    int test;int i=0,existe;
    LISTE_P p1=L;
    if(L==NULL){
    printf("La liste est vide");
}
else{
    do{
        do
        {
            L=affiche_personne(L,p1->info);
            printf("Voulez vous modifier cette personne O/N (0:Non,1: Oui).");
            scanf("%d",&test);
            if(i!=0)
            p1=p1->suiv;
            i++;
        }while(!(test==1 || test==0));
    }while(!test);
        if(test==1){
    printf("Entrer rue :");
    scanf("%s",r);
    strcpy(p1->info.adresse.rue,r);//R or L->info?
    do{
    printf("Entrer ville :");
    scanf("%s",v);
    existe=0;
    for(int i=0;i<strlen(v);i++){
                    if (isdigit(v[i]) != 0)
                    existe++;
                    }
    }while((existe!=0));
    strcpy(p1->info.adresse.ville,v);
    do{
    printf("Entrer code_postale :");
    scanf("%s",cp);
    existe=0;
    for(int i=0;i<strlen(cp);i++){
    if (isalpha(cp[i]) != 0)
            existe++;
    }
    }while(existe!=0||strlen(cp)!=4);
strcpy(p1->info.adresse.code_postale,cp);
        }
}

    return L;
}
LISTE_P modif_tel(LISTE_P L){
    int existe,test;
    char v[15];
    LISTE_P p2=L;
    if(L==NULL){
    printf("La liste est vide");
}
else{
        do{
    do
        {
            L=affiche_personne(L,p2->info);
            printf("Voulez vous modifier cette personne O/N (0:Non,1: Oui).");
            scanf("%d",&test);
            p2=p2->suiv;
        }while(!(test==1 || test==0));
        }while(!test);
        if(test==1){
            do{
                printf("nouveau tel :");
                scanf("%s",&v);
                LISTE_P p1=L;
                 existe=0;
                    while(existe==0 && p1!=NULL){
                        if(strcmp(p1->info.tel,v)==0){
                        existe=1;
                }
                        p1=p1->suiv;
                 }
            }while(strlen(v)!=8 || existe==1);
            if(existe==0){
                strcpy(p2->info.tel,v);
            }
        }
}

            return L;
}
//partie 4
LISTE_P recherche_by_tel(LISTE_P L,char tell[15])
{
LISTE_P p1=L;
while(p1!=NULL)
{
    if(strcmp(p1->info.tel,tell)==0){
        affiche_personne(L,p1->info);
        return L;
    }
    p1=p1->suiv;
}
printf("tel n existe pas");
return L;
}

LISTE_P recherche_by_nom(LISTE_P L,char v[])
{
LISTE_P p1=L;
while(p1!=NULL)
{
    if(strcmp(p1->info.nom,v)==0){
        affiche_personne(L,p1->info);
        printf("\n");
    }
    p1=p1->suiv;
}
printf("nom n existe pas");
return L;

}
LISTE_P recherche_by_ind(LISTE_P L,int ind[])
{
char c[15];
LISTE_P p1=L;
while(p1!=NULL)
{
    strncpy(c,p1->info.tel,2);
    if(strcmp(c,ind)==0){
        affiche_personne(L,p1->info);
        printf("\n");
    }
    p1=p1->suiv;
}
printf("indeficatif n existe pas");
return L;
}
LISTE_P recherche_by_ville(LISTE_P L,char v[])
{
LISTE_P p1=L;
while(p1!=NULL)
{
    if(strcmp(p1->info.adresse.ville,v)==0){
        affiche_personne(L,p1->info);
        printf("\n");
    }
    p1=p1->suiv;
}
printf("ville n existe pas");
return L;
}/*
LISTE_P copyObj(LISTE_P L,struct rep R,struct rep T){
    strcpy(R.adresse.rue,T.adresse.rue);
    strcpy(R.adresse.ville,T.adresse.ville);
    R.adresse.code_postale=T.adresse.code_postale;
    R.date_naiss.annee=T.date_naiss.annee;
    R.date_naiss.mois=T.date_naiss.mois;
    R.date_naiss.jour=T.date_naiss.jour;
    strcpy(R.tel,T.tel);
    strcpy(R.nom,T.nom);
    strcpy(R.prenom,T.prenom);
    strcpy(R.email,T.email);
    return L;
}*/
//MessageBox(hwnd,"Le champ E-mail est vide","",MB_OK|MB_ICONERROR);
LISTE_P tri(LISTE_P L)//ml kbir l sghir
{
    struct rep R;
    LISTE_P p1=L;
    LISTE_P p2=L;
    while(p1->suiv!=NULL){
        p2=p1->suiv;
        do{
        if(strcmp(p1->info.tel,p2->info.tel)<0){//permutaion
    strcpy(R.adresse.rue,p1->info.adresse.rue);
    strcpy(R.adresse.ville,p1->info.adresse.ville);
    strcpy(R.adresse.code_postale,p1->info.adresse.code_postale);
    strcpy(R.date_naiss.annee,p1->info.date_naiss.annee);
    strcpy(R.date_naiss.mois,p1->info.date_naiss.mois);
    strcpy(R.date_naiss.jour,p1->info.date_naiss.jour);
    strcpy(R.tel,p1->info.tel);
    strcpy(R.nom,p1->info.nom);
    strcpy(R.prenom,p1->info.prenom);
    strcpy(R.email,p1->info.email);


    strcpy(p1->info.adresse.rue,p2->info.adresse.rue);
    strcpy(p1->info.adresse.ville,p2->info.adresse.ville);

    strcpy(p1->info.adresse.code_postale,p2->info.adresse.code_postale);
    strcpy(p1->info.date_naiss.annee,p2->info.date_naiss.annee);
    strcpy(p1->info.date_naiss.mois,p2->info.date_naiss.mois);
    strcpy(p1->info.date_naiss.jour,p2->info.date_naiss.jour);
    strcpy(p1->info.tel,p2->info.tel);
    strcpy(p1->info.nom,p2->info.nom);
    strcpy(p1->info.prenom,p2->info.prenom);
    strcpy(p1->info.email,p2->info.email);

    strcpy(p2->info.adresse.rue,R.adresse.rue);
    strcpy(p2->info.adresse.ville,R.adresse.ville);

    strcpy(p2->info.adresse.code_postale,R.adresse.code_postale);
    strcpy(p2->info.date_naiss.annee,R.date_naiss.annee);
    strcpy(p2->info.date_naiss.mois,R.date_naiss.mois);
    strcpy(p2->info.date_naiss.jour,R.date_naiss.jour);
    strcpy(p2->info.tel,R.tel);
    strcpy(p2->info.nom,R.nom);
    strcpy(p2->info.prenom,R.prenom);
    strcpy(p2->info.email,R.email);
        }
        p2=p2->suiv;
    }while(p2!=NULL);
    p1=p1->suiv;
    }
return L;
}
LISTE_P aff(LISTE_P L){
            LISTE_P p1=(struct cellule*)malloc(sizeof(struct cellule));
    p1=L;
        while(p1!=NULL)
        {
            printf("                        ");

            printf("%s",p1->info.tel);
            printf("           |            ");
            printf("%s",p1->info.nom);
            printf("    |     ");
            printf("%s",p1->info.prenom);
            printf("    |     ");
            printf("%s",p1->info.adresse.rue);
            printf("    |     ");
            printf("%s",p1->info.adresse.ville);
            printf("    |     ");
            printf("%s",p1->info.adresse.code_postale);
            printf("    |     ");
            printf("%s",p1->info.date_naiss.jour);
            printf("  |  ");
            printf("%s",p1->info.date_naiss.mois);
            printf("  |  ");
            printf("%s",p1->info.date_naiss.annee);
            printf("  |  ");
            printf("%s",p1->info.email);
            printf("\n");
            p1=p1->suiv;
        }
        return L;
}
