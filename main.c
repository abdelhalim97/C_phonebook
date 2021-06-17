#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include "tp1.h"
#include "myconio.h"
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);//halim@ggg.ggg
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;
void loadImages();
LISTE_P L=NULL;

HWND hname ,hage,hout,hogo,Add,Finnish,hLogo;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage,hGenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("my project"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1250,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;


   /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/



    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {



        case 0:
                system("color F5");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(0,0);

                //L=creation(L);7
                L=creation(L,"file2.txt");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 1:
                system("color F5");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(0,0);
                L=ajout_tete(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 2:
                system("color F5");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(0,0);
                L=ajout_queue(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 3:
                system("color F5");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(0,0);
                int pos=0;
                printf("donner la pos");
                scanf("%d",&pos);
                L=ajout_pos(L,pos);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 4:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                L=supp_tete(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 5:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                L=supp_queue(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 33:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                int posSup;
                printf("donner la pos");
                scanf("%d",&posSup);
                L=supprimer_pos_tel(L,posSup);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 34:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                int v[7];
                printf("donner tel");
                gets(v);
                L=supp_by_tel(L,v);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 35:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                char vi[15];
                printf("donner une ville");
                gets(vi);
                L=supp_by_ville(L,vi);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 36:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                int indd[1];
                printf("donner ind");
                gets(indd);
                L=supp_by_ind(L,indd);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 15:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                L=affiche_liste(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 37:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                int tell[7];
                int r=0,existe;
                do{
                        r=0;
                printf("donner tel");
                gets(tell);
                for(int i=0;i<strlen(tell);i++){
                if (isalpha(tell[i]) != 0){
                        r++;
                }
                }
                }while(strlen(tell)!=8  || r!=0);
                L=recherche_by_tel(L,tell);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 38:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                char no[15];
                int q=0,e=0;
                do{
                    q=0;
                    e=0;
                printf("donner un nom");
                gets(no);
                for(int i=0;i<strlen(no);i++)
                        e += isspace(no[i]);
                        for(int i=0;i<strlen(no);i++){
                                if (isdigit(no[i]) != 0)
                                    q++;
                        }
                }while((q!=0)||(e!=0));
                L=recherche_by_nom(L,no);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 39:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                int indif[1];
                do{
                    printf("donner ind");
                    gets(indif);

                }while(strlen(indif)!=2);
                L=recherche_by_ind(L,indif);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

        case 40:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                char villee[15];
                int ff;
                do{
                printf("donner nom du ville");
                gets(villee);
                ff=0;
                for(int i=0;i<strlen(villee);i++){
                    if (isdigit(villee[i]) != 0)
                    ff++;
                    }
                    }while((ff!=0));
                L=recherche_by_ville(L,villee);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 41:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                L=tri(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 6:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                L=modif_adr(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 7:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                L=modif_tel(L);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 25:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                if(taille_liste_rep(L)<1){
                    MessageBox(hwnd,"Liste est vide",MB_OK,MB_ICONERROR);
                }else{
                ecrire(L,"file2.txt");/////////////////
                MessageBox(hwnd,"Liste a enregistre avec succes",MB_OK,MB_ICONINFORMATION);
                }
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 26:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                L=recuperation();
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 27:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                system("projet.pdf");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 28:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                system("file2.txt");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 29:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                if(taille_liste_rep(L)<1){
                    MessageBox(hwnd,"La liste est vide",MB_OK,MB_ICONERROR);
                }
                else{
                    printf("\e[1;31m"); //Set the text to the color red
                    printf("Numero telephone   |     nom    |     prenom    |     rue    |     ville    |code postal|jour/mois/annee|     email\n","");
                    printf("\e[1m"); //Resets the text to default color
                    printf("\e[1;30m");
                    printf("%4c                    --------------------------------------------------------------------------------------------------------------------------------------- \n","");
                    printf("\e[1m");
                    printf("\e[1;34m");
                    //recuperation();
                    L=aff(L);
                    printf("\e[1m");
                    printf("\n");
                }
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 30:
                if (MessageBox(hwnd,"Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;



        }
    case WM_CREATE :
        loadImages();
        addmenus(hwnd);
        AddControls(hwnd);
//         CreateBtt(hwnd) ;
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"pr.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {



         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    //hmenu1=CreateMenu();
    HMENU htp=CreateMenu();
    HMENU htp1=CreateMenu();
    HMENU htp2=CreateMenu();
    HMENU htp3=CreateMenu();
    HMENU htp4=CreateMenu();
    HMENU htp6=CreateMenu();
    HMENU htp5=CreateMenu();
    HMENU hex1=CreateMenu();
    HMENU hex3=CreateMenu();
    HMENU hex2=CreateMenu();
    HMENU hex4=CreateMenu();
    HMENU hex5=CreateMenu();
        HMENU hex6=CreateMenu();
    HMENU hex7=CreateMenu();


//creation menu creation mise a jour(ajouter un tel=>(ajouter tete ajouter pos ajouter queue)supprimer in tel=>(en tete en Q )modifier=>(adresse tele)
                                     // recherche affichage(tout contact re par num par indicatif par nom par ville tri 1)
                                     //4eeme(enregistrement  recuperation)plus(enoncer ouvrir la liste de tel)
//

       AppendMenu(hmenu,MF_STRING,0,"Creation");
/***************************************************************/
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp6,"Mise à jour des téléphones");
    AppendMenu(htp6,MF_POPUP,(UINT_PTR)hex5,"Menu ajouter un tel");
        AppendMenu(hex5,MF_STRING,1,"Ajout en tête");
        AppendMenu(hex5,MF_STRING,2,"Ajout en queue");
        AppendMenu(hex5,MF_STRING,3,"Ajout dans une position");
/***************************************************************/
    AppendMenu(htp6,MF_POPUP,(UINT_PTR)hex6,"Menu supprimer");
        AppendMenu(hex6,MF_STRING,4,"Suppression en tête");
        AppendMenu(hex6,MF_STRING,5,"Suppression en queue");
        AppendMenu(hex6,MF_STRING,33,"Suppression à partir d’une position");
        AppendMenu(hex6,MF_STRING,34,"Suppression  d’un téléphone donné");
        AppendMenu(hex6,MF_STRING,35,"Suppression des téléphones d ’ une ville donnée");
        AppendMenu(hex6,MF_STRING,36,"Suppression des téléphones d’un indicatif donné");
/***************************************************************/
    AppendMenu(htp6,MF_POPUP,(UINT_PTR)hex7,"Menu modifier");
        AppendMenu(hex7,MF_STRING,6,"adresse");
        AppendMenu(hex7,MF_STRING,7,"tele");
/***************************************************************/
/*    AppendMenu(htp5,MF_POPUP,(UINT_PTR)hex4,"Recherche et affichage");
        AppendMenu(hex4,MF_STRING,8,"tout");
        AppendMenu(hex4,MF_STRING,9,"contact");
        AppendMenu(hex4,MF_STRING,10,"par num");
        AppendMenu(hex4,MF_STRING,11,"par indicatif");
        AppendMenu(hex4,MF_STRING,12,"par nom");
        AppendMenu(hex4,MF_STRING,13,"par ville");
        AppendMenu(hex4,MF_STRING,14,"tri 1");
/***************************************************************/

     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"Menu Recherche et affichage");

      AppendMenu(htp1,MF_STRING,15,"Contenu de la liste des téléphones");
      AppendMenu(htp1,MF_STRING,37,"Recherche par numéro téléphone");
      AppendMenu(htp1,MF_STRING,38,"Recherche par nom");
      AppendMenu(htp1,MF_STRING,39,"Recherche par indicatif téléphone");
      AppendMenu(htp1,MF_STRING,40,"Recherche par ville");
      AppendMenu(htp1,MF_STRING,41,"Tri 1");

/***************************************************************/
 /*    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp2,"affichage");

      AppendMenu(htp2,MF_STRING,16,"tout");
      AppendMenu(htp2,MF_STRING,17,"contact");
      AppendMenu(htp2,MF_STRING,18,"par num");
      AppendMenu(htp2,MF_STRING,19,"par indicatif");
      AppendMenu(htp2,MF_STRING,20,"par nom");

/***************************************************************/
  AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp3,"Menu Enregistrementet chargement");

      AppendMenu(htp3,MF_STRING,25,"enregistrement");
      AppendMenu(htp3,MF_STRING,26,"Chargement");

/******************************************************************/
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp4,"plus");

      AppendMenu(htp4,MF_STRING,27,"enoncer");
      AppendMenu(htp4,MF_STRING,28,"ouvrir");
      AppendMenu(htp4,MF_STRING,29,"Afficher la liste de tel");
/******************************************************************/
    AppendMenu(hmenu,MF_STRING,30,"Quitter");
    SetMenu(hwnd,hmenu);
}
void AddControls(HWND hwnd){
    hLogo = CreateWindowW(L"Static",NULL,WS_VISIBLE|WS_CHILD|SS_BITMAP,0,0,1000,300,hwnd,NULL,NULL,NULL);
    SendMessageW(hLogo,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hlogoImage);
    CreateWindowW(L"static",L"Accueil:",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,20,40,100,30,hwnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Creation",WS_VISIBLE | WS_CHILD,125,100,200,50,hwnd,(HMENU)0,NULL,NULL);
    CreateWindowW(L"Button",L"Chargement",WS_VISIBLE | WS_CHILD,375,100,200,50,hwnd,(HMENU)26,NULL,NULL);
    CreateWindowW(L"Button",L"Afficher la liste de tel",WS_VISIBLE | WS_CHILD,625,100,200,50,hwnd,(HMENU)29,NULL,NULL);
    CreateWindowW(L"Button",L"Enregistrement",WS_VISIBLE | WS_CHILD,875,100,200,50,hwnd,(HMENU)25,NULL,NULL);

    CreateWindowW(L"static",L"Ajouter:",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,20,190,100,30,hwnd,NULL,NULL,NULL);
    //CreateWindowW(L"Button",L"en tête",WS_VISIBLE | WS_CHILD,125,250,200,50,hwnd,(HMENU)1,NULL,NULL);
    CreateWindowW(L"Button",L"en tete",WS_VISIBLE | WS_CHILD,125,250,200,50,hwnd,(HMENU)1,NULL,NULL);
    CreateWindowW(L"Button",L"en queue",WS_VISIBLE | WS_CHILD,375,250,200,50,hwnd,(HMENU)2,NULL,NULL);
    CreateWindowW(L"Button",L"dans une position",WS_VISIBLE | WS_CHILD,625,250,200,50,hwnd,(HMENU)3,NULL,NULL);

    CreateWindowW(L"static",L"Suppression:",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,20,340,100,30,hwnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"en tete",WS_VISIBLE | WS_CHILD,125,400,125,50,hwnd,(HMENU)4,NULL,NULL);
    CreateWindowW(L"Button",L"en queue",WS_VISIBLE | WS_CHILD,300,400,125,50,hwnd,(HMENU)5,NULL,NULL);
    CreateWindowW(L"Button",L"dans une position",WS_VISIBLE | WS_CHILD,485,400,125,50,hwnd,(HMENU)33,NULL,NULL);//140
    CreateWindowW(L"Button",L"d un telephone donne",WS_VISIBLE | WS_CHILD,670,400,125,50,hwnd,(HMENU)34,NULL,NULL);//215
    CreateWindowW(L"Button",L"d une ville donnee",WS_VISIBLE | WS_CHILD,855,400,125,50,hwnd,(HMENU)35,NULL,NULL);//290
    CreateWindowW(L"Button",L"un indicatif donne",WS_VISIBLE | WS_CHILD,1040,400,125,50,hwnd,(HMENU)36,NULL,NULL);//365

    CreateWindowW(L"static",L"Menu modifier:",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,20,490,100,30,hwnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"par adresse",WS_VISIBLE | WS_CHILD,350,550,225,50,hwnd,(HMENU)6,NULL,NULL);
    CreateWindowW(L"Button",L"par telephone",WS_VISIBLE | WS_CHILD,625,550,225,50,hwnd,(HMENU)7,NULL,NULL);

    CreateWindowW(L"Button",L"Quitter",WS_VISIBLE | WS_CHILD,1000,650,190,50,hwnd,(HMENU)30,NULL,NULL);
}
void loadImages(){
    hlogoImage=(HBITMAP)LoadImageW(NULL,L"11.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
}
