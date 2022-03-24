//
// Created by tchic on 22/03/2022.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef DECODAGECESAR_REQUIREMENTS_H
#define DECODAGECESAR_REQUIREMENTS_H
char prochaineLettre(FILE* in)
{
    int e;
    char r;
    if(in==NULL){
        return EXIT_FAILURE;
    }
    do{
        e=fscanf(in,"%c",&r);
        if((r>='a' && r<='z')||(r>='A' && r<='Z')){
            return r;
        }
    }while(e!=EOF);
    return EOF;
}

char lettreLaPlusFrequente(FILE* in)
{
    int max=0;
    int T[26]={0};
    int i;
    char r;

    do{
        r=prochaineLettre(in);
        if(r>='a' && r<='z'){
            T[r-'a']++;
        }
        if(r>='A' && r<='Z'){
            T[r-'A']++;
        }
    }while(r!=EOF);

    for(i=0;i<26;i++){
        if(T[i]>T[max]){
            max=i;
        }
    }
    return 'a'+max;
}

void decodageCesar(FILE *in, FILE *out)
{

    char freq=lettreLaPlusFrequente(in);
    int deca=freq-'e';
    char r;
    int e;
    rewind(in);
    e=fscanf(in, "%c", &r);
    while(e!=EOF)
    {

        //si les caractere du text est une lettre alphabetique
        if(r>='a' && r<= 'z')
        {
            r = (r-'a'-deca+26)%26 + 'a';
            fputc(r,out);
        }else if(r>='A' && r<= 'Z')
        {
            r = (r-'A'-deca+26)%26 + 'A';
            fputc(r,out);
        }else{
            // sinon si c'est un caractere special

            fputc(r,out);
        }
        e=fscanf(in, "%c", &r);
    }
}
#endif //DECODAGECESAR_REQUIREMENTS_H
