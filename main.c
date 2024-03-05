#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*15. Aplicație pentru rețete culinare
Aplicația permite selectarea dintr-o listă a unui titlu de rețetă deja existentă,
moment în care aceasta este afișată utilizatorului. Este posibilă căutarea în funcție
de un cuvânt introdus a titlurilor de rețetă. Utilizatorul poate introduce noi rețete
(titlu, descriere și ingrediente), poate șterge sau poate edita rețete.*/
int k=1,i=1,j=1;
typedef struct reteta
{
    char titlu[70]; //scris cu majuscule
    char ingrediente[100][100];
    char descriere[255][255];
    int nr_ing,nr_d;
}reteta;
reteta v[100];

void afisare()
{
    for (int ct=1; ct<=k; ct++)
        printf("%d. %s",ct,v[ct].titlu);
    int aleg;
    printf("\nAlegeti o reteta: ");
    scanf("%d",&aleg);
    if (aleg<1 || aleg>k)
    {
        printf("Comanda incorecta. Apasati Enter pentru a incerca din nou.");
        char ws;
        fflush(stdin);
        scanf("%c",&ws);
        if (ws=='\n')
        {
            system("cls");
            afisare();
        }
    }
    else
    {
        printf("\n%s",v[aleg].titlu);
        printf("\nIngrediente\n");
        for (int i=1; i<=v[aleg].nr_ing; i++)
            printf(" %s",v[aleg].ingrediente[i]);
        printf("\nMod de preparare\n");
        for (int j=1; j<=v[aleg].nr_d; j++)
            printf(" %s",v[aleg].descriere[j]);
        printf("\nPofta buna!\n");
    }

    char ws;
    printf("\n\nApasati Enter pentru a reveni la meniu");
    fflush(stdin);
    scanf("%c",&ws);
    if (ws=='\n')
        system("cls");
}
void cautare()
{
    char str[20];
    printf("Introduceti cuvantul cheie din titlu: ");
    scanf("%s",&str);
    char cuv[20];
    strcpy(cuv,strupr(str));
    fflush(stdin);
    int ok=0;
    for (int ct=1; ct<=k; ct++)
        if (strstr(v[ct].titlu,cuv))
        {
            if (ok==0)
                printf("\nS-a gasit:\n");
            ok++;
            printf("\n%s",v[ct].titlu);
            printf("\nIngrediente\n");
            for (int i=1; i<=v[ct].nr_ing; i++)
                printf("   %s",v[ct].ingrediente[i]);
            printf("\nMod de preparare\n");
            for (int j=1; j<=v[ct].nr_d; j++)
                printf("   %s",v[ct].descriere[j]);
        }
    if (ok==0)
        printf("\nNu s-a gasit nicio reteta.\n");

    char ws;
    printf("\n\nApasati Enter pentru a reveni la meniu");
    fflush(stdin);
    scanf("%c",&ws);
    if (ws=='\n')
        system("cls");
}
void introducere ()
{
    char t[70],s[100],d[255];

    printf("Dati un titlu retetei dvs.: ");
    fflush(stdin);
    gets(t);
    strcpy(v[++k].titlu,strupr(t));
    strcat(v[k].titlu,"\n");

    printf("\nDati ingredientele si apasati Enter urmat de * pentru a finaliza lista:\n");
    fflush(stdin);
    gets(s);
    i=0;
    strcpy(v[k].ingrediente[++i],s);
    strcat(v[k].ingrediente[i],"\n");
    while (s[0]!='*')
    {
        gets(s);
        strcpy(v[k].ingrediente[++i],s);
        strcat(v[k].ingrediente[i],"\n");
    }
    v[k].nr_ing=i-1;

    printf("\nIntroduceti descrierea retetei si apasati Enter urmat de * pentru a finaliza:\n");
    gets(d);
    j=0;
    strcpy(v[k].descriere[++j],d);
    strcat(v[k].descriere[j],"\n");
    while (d[0]!='*')
    {
        gets(d);
        strcpy(v[k].descriere[++j],d);
        strcat(v[k].descriere[j],"\n");
    }
    v[k].nr_d=j-1;

    printf("\nReteta a fost introdusa.\n");

    char ws;
    printf("\nApasati Enter pentru a reveni la meniu");
    fflush(stdin);
    scanf("%c",&ws);
    if (ws=='\n')
        system("cls");
}
void stergere   ()
{
    for (int ct=1; ct<=k; ct++)
        printf("%d. %s",ct,v[ct].titlu);
    int aleg;
    printf("\n\nCe reteta doriti sa stergeti?\n");
    scanf("%d",&aleg);
    if (aleg<1 || aleg>k)
    {
        printf("\nComanda incorecta. Apasati Enter pentru a incerca din nou.");
        char ws;
        fflush(stdin);
        scanf("%c",&ws);
        if (ws=='\n')
        {
            system("cls");
            stergere();
        }
    }
    else
    {
        for (int ct=aleg; ct<k; ct++)
        {
            strcpy(v[ct].titlu,v[ct+1].titlu);

            for (int i=1; i<=v[ct+1].nr_ing; i++)
                strcpy(v[ct].ingrediente[i],v[ct+1].ingrediente[i]);
            v[ct].nr_ing=v[ct+1].nr_ing;

            for (int j=1; j<=v[ct+1].nr_d; j++)
                strcpy(v[ct].descriere[j],v[ct+1].descriere[j]);
            v[ct].nr_d=v[ct].nr_d;
        }
        k--;
        printf("\nReteta a fost stearsa cu succes.\n");
    }

    char ws;
    printf("\nApasati Enter pentru a reveni la meniu.");
    fflush(stdin);
    scanf("%c",&ws);
    if (ws=='\n')
        system("cls");
}
void editare()
{
    printf("! In orice moment puteti apasa tasta 0 pentru a intrerupe actiunea !\n\n");
    char aleg;
    for (int ct=1; ct<=k; ct++)
        printf("%d. %s",ct,v[ct].titlu);
    printf("\nCe reteta doriti sa editati?\n");
    scanf("%d",&aleg);
    if (aleg==0)
        system("cls");
    else if (aleg<1 || aleg>k)
    {
        printf("\nComanda incorecta. Apasati Enter pentru a incerca din nou.");
        char ws;
        fflush(stdin);
        scanf("%c",&ws);
        if (ws=='\n')
        {
            system("cls");
            editare();
        }
    }
    else
    {
        char a;
        printf("\nCe doriti sa editati?\n(t)itlul\ni(n)gredientele\n(d)escrierea\n");
        fflush(stdin);
        scanf("%c",&a);
        if (a=='0')
            system("cls");
        else if (a=='t')
        {
            printf("\nIntroduceti noul titlu: ");
            char t[30];
            fflush(stdin);
            gets(t);
            strcpy(v[aleg].titlu,strupr(t));
            strcat(v[aleg].titlu,"\n");
            printf("\nTitlul a fost editat.\n\n");
        }
        else if (a=='n')
        {
            printf("\nDoriti sa (s)tergeti, adau(g)ati sau (m)odificati un ingredient\nsau\ndoriti sa introduceti din nou intrega (l)ista cu ingrediente? ");
            fflush(stdin);
            char c;
            scanf("%c",&c);
            if (c=='0')
                system("cls");
            else if (c=='s')
            {
                int ch;
                for (int i=1; i<=v[aleg].nr_ing; i++)
                    printf("%d. %s",i,v[aleg].ingrediente[i]);
                printf("\nAlegeti ingredientul: ");
                fflush(stdin);

                scanf("%d",&ch);
                if (ch==v[aleg].nr_ing) //ultimul ingredient
                    v[aleg].nr_ing--;
                else if (ch>=1 && ch<v[aleg].nr_ing)
                {
                    for (int i=ch; i<=v[aleg].nr_ing-1; i++)
                        strcpy(v[aleg].ingrediente[i],v[aleg].ingrediente[i+1]);
                    v[aleg].nr_ing--;
                }
                else
                {
                    printf("\nComanda incorecta. Apasati Enter pentru a incerca din nou.");
                    fflush(stdin);
                    char ws;
                    scanf("%c",&ws);
                    if (ws=='\n')
                    {
                        system("cls");
                        editare();
                    }
                }

                printf("\nIngredientul a fost sters.\n\n");
            }
            else if (c=='g')
            {
                char ing[100];
                printf("\nIntroduceti noul ingredient: ");
                fflush(stdin);
                gets(ing);
                strcat(ing,"\n");
                v[aleg].nr_ing++;
                strcpy(v[aleg].ingrediente[v[aleg].nr_ing],ing);
                printf("\nIngredientul a fost adaugat.\n\n");
            }
            else if (c=='m')
            {
                int ch;
                char ing[100];
                for (int i=1; i<=v[aleg].nr_ing; i++)
                    printf("%d. %s",i,v[aleg].ingrediente[i]);
                printf("\nAlegeti ingredientul: ");
                fflush(stdin);
                scanf("%d",&ch);
                if (ch>=1 && ch<=v[aleg].nr_ing)
                {
                    printf("\nReintroduceti ingredientul: ");
                    fflush(stdin);
                    gets(ing);
                    strcat(ing,"\n");
                    strcpy(v[aleg].ingrediente[ch],ing);
                    printf("\nIngredientul a fost modificat.\n\n");
                }
                else
                {
                    char ws;
                    printf("\nComanda incorecta, apasati Enter pentru a incerca din nou.\n");
                    fflush(stdin);
                    scanf("%c",&ws);
                    if (ws=='\n')
                    {
                        system("cls");
                        editare();
                    }
                }
            }
            else if (c=='l')
            {
                char s[255];
                printf("\nDati ingredientele si apasati Enter urmat de * pentru a finaliza lista:\n");
                fflush(stdin);
                gets(s);
                i=0;
                strcpy(v[aleg].ingrediente[++i],s);
                strcat(v[aleg].ingrediente[i],"\n");
                while (s[0]!='*')
                {
                    gets(s);
                    strcpy(v[aleg].ingrediente[++i],s);
                    strcat(v[aleg].ingrediente[i],"\n");
                }
                v[aleg].nr_ing=i-1;
                printf("\nLista de ingrediente a fost actualizata.\n\n");
            }
            else
            {
                char ws;
                printf("\nComanda incorecta, apasati Enter pentru a incerca din nou.\n");
                fflush(stdin);
                scanf("%c",&ws);
                if (ws=='\n')
                {
                    system("cls");
                    editare();
                }
            }
        }
        else if (a=='d')
        {
            printf("\nDoriti sa (s)tergeti, adau(g)ati sau (m)odificati o instructiune\nsau\ndoriti sa introduceti din nou intrega (l)ista cu instructiuni?");
            char c;
            fflush(stdin);
            scanf("%c",&c);
            if (c=='0')
                system("cls");
            else if (c=='s')
            {
                int ch;
                for (int j=1; j<=v[aleg].nr_d; j++)
                    printf("%d. %s",j,v[aleg].descriere[j]);
                printf("\nAlegeti ingredientul: ");
                fflush(stdin);

                scanf("%d",&ch);
                if (ch==v[aleg].nr_d) //ultima instructiune
                {
                    v[aleg].nr_d--;
                    printf("\nIngredientul a fost sters.\n\n");
                }
                else if (ch>=1 && ch<v[aleg].nr_d)
                {
                    for (int j=ch; j<=v[aleg].nr_d-1; j++)
                        strcpy(v[aleg].ingrediente[j],v[aleg].ingrediente[j+1]);
                    v[aleg].nr_d--;
                    printf("\nIngredientul a fost sters.\n\n");
                }
                else
                {
                    printf("\nComanda incorecta. Apasati Enter pentru a incerca din nou.");
                    fflush(stdin);
                    char ws;
                    scanf("%c",&ws);
                    if (ws=='\n')
                    {
                        system("cls");
                        editare();
                    }
                }
            }
            else if (c=='g')
            {
                char ins[100];
                printf("\nIntroduceti noua instructiune: ");
                fflush(stdin);
                gets(ins);
                v[aleg].nr_d++;
                strcpy(v[aleg].descriere[v[aleg].nr_d],ins);
                printf("\nInstructiunea a fost adaugata.\n\n");
            }
            else if (c=='m')
            {
                int ch;
                char ins[100];
                for (int j=1; j<=v[aleg].nr_d; j++)
                    printf("%d. %s",j,v[aleg].descriere[j]);
                printf("\nAlegeti instructiunea: ");
                fflush(stdin);
                scanf("%d",&ch);
                if (ch>=1 && ch<=v[aleg].nr_d)
                {
                    printf("\nReintroduceti noua instructiune: ");
                    fflush(stdin);
                    gets(ins);
                    strcpy(v[aleg].descriere[ch],ins);
                    printf("\nInstructiunea a fost modificata.\n\n");
                }
                else
                {
                    printf("\nComanda incorecta. Apasati Enter pentru a incerca din nou.");
                    fflush(stdin);
                    char ws;
                    scanf("%c",&ws);
                    if (ws=='\n')
                    {
                        system("cls");
                        editare();
                    }
                }
            }
            else if (c=='l')
            {
                char s[255];
                printf("\nDati instructiunile si apasati Enter urmat de * pentru a finaliza lista:\n");
                fflush(stdin);
                gets(s);
                j=0;
                strcpy(v[aleg].descriere[++j],s);
                strcat(v[aleg].descriere[j],"\n");
                while (s[0]!='*')
                {
                    gets(s);
                    strcpy(v[aleg].descriere[++j],s);
                    strcat(v[aleg].descriere[j],"\n");
                }
                v[aleg].nr_d=j-1;
                printf("\nLista de instructiuni a fost actualizata.\n\n");
            }
            else
            {
                char ws;
                printf("\nComanda incorecta, apasati Enter pentru a incerca din nou.\n");
                fflush(stdin);
                scanf("%c",&ws);
                if (ws=='\n')
                {
                    system("cls");
                    editare();
                }
            }
        }
        else
        {
            printf("\nComanda incorecta. Apasati Enter pentru a incerca din nou.");
            char ws;
            fflush(stdin);
            scanf("%c",&ws);
            if (ws=='\n')
            {
                system("cls");
                editare();
            }
        }
    }

    char ws;
    printf("Apasati Enter pentru a reveni la meniu");
    fflush(stdin);
    scanf("%c",&ws);
    if (ws=='\n')
        system("cls");
}
int main()
{
    char s[255];
    FILE *fin;
    fin=fopen("date.txt","r");
    fgets(s,255,fin);
    strcpy(v[k].titlu,s);
    i=0;
    j=0;
    while (fgets(s,255,fin))
    {
        if (s[0]>='A' && s[0]<='Z' && s[1]>='A' && s[1]<='Z') //titlu (cu majuscule)
        {
            k++;
            strcpy(v[k].titlu,s);
            i=0;
            j=0;
            v[k].nr_ing=0;
            v[k].nr_d=0;
        }
        else if (s[0]>='0' && s[0]<='9') //ingredient
        {
            strcpy(v[k].ingrediente[++i],s);
            v[k].nr_ing++;
        }
        else //rand din descriere
        {
            strcpy(v[k].descriere[++j],s);
            v[k].nr_d++;
        }
    }

    while (1)
    {
        printf("-= MENIU =-\n");
        printf("1. Afisare reteta\n");
        printf("2. Cautare retete\n");
        printf("3. Introducere reteta\n");
        printf("4. Stergere reteta\n");
        printf("5. Editare reteta\n");
        printf("\nIntroduceti varianta dorita, sau apasati Enter pentru a termina: \n");
        char choice;
        scanf("%c",&choice);
        system("cls");
        if (choice=='1')
            afisare();
        else if (choice=='2')
            cautare();
        else if (choice=='3')
        {
            introducere();
            FILE *fout;
            fout=fopen("date.txt","w");
            for (int ct=1; ct<=k; ct++)
            {
                fprintf(fout,"%s",v[ct].titlu);
                for (int i=1; i<=v[ct].nr_ing; i++)
                    fprintf(fout,"%s",v[ct].ingrediente[i]);
                for (int j=1; j<=v[ct].nr_d; j++)
                    fprintf(fout,"%s",v[ct].descriere[j]);
            }
        }
        else if (choice=='4')
        {
            stergere();
            FILE *fout;
            fout=fopen("date.txt","w");
            for (int ct=1; ct<=k; ct++)
            {
                fprintf(fout,"%s",v[ct].titlu);
                for (int i=1; i<=v[ct].nr_ing; i++)
                    fprintf(fout,"%s",v[ct].ingrediente[i]);
                for (int j=1; j<=v[ct].nr_d; j++)
                    fprintf(fout,"%s",v[ct].descriere[j]);
            }
        }
        else if (choice=='5')
        {
            editare();
            FILE *fout;
            fout=fopen("date.txt","w");
            for (int ct=1; ct<=k; ct++)
            {
                fprintf(fout,"%s",v[ct].titlu);
                for (int i=1; i<=v[ct].nr_ing; i++)
                    fprintf(fout,"%s",v[ct].ingrediente[i]);
                for (int j=1; j<=v[ct].nr_d; j++)
                    fprintf(fout,"%s",v[ct].descriere[j]);
            }
        }
        else if (choice=='\n')
            break;
        else
        {
            printf("Varianta nu exista. Apasati Enter pentru a incerca din nou.");
            char ws;
            fflush(stdin);
            scanf("%c",&ws);
            if (ws=='\n')
                system("cls");
        }
    }
    return 0;
}
