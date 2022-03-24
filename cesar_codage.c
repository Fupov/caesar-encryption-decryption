#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){

    FILE *f=NULL;
    FILE *f2=NULL;

    char r;
    int e;

    f = fopen(argv[1], "r+");
    //si le fichier dentree n'exist pas
    if( f == NULL )
    {
		fprintf(stderr, "Erreur : fichier d'entree introuvable dans le repertoire courant\n");
        //Exit programme
        return EXIT_FAILURE;
    }

    f2 = fopen(argv[3], "r+");
    //si le fichier de sortie n'exist pas
    if( f2 == NULL )
    {
		fprintf(stderr, "Erreur : fichier de sortie introuvable dans le repertoire courant\n");
        //Exit programme
        return EXIT_FAILURE;
    }
    if(argv[4] == NULL){
   		//Codage
    	while(e!=EOF)
    	{
			e=fscanf(f, "%c", &r);
        	//si les caractere du text est une lettre alphabetique
        	if(r>='a' && r<= 'z')
        	{
        	    r = (r-'a'+atoi(argv[2])+26)%26 + 'a';
        	    fputc(r,f2);
        	}else if(r>='A' && r<= 'Z')
        	{
        	    r = (r-'A'+atoi(argv[2])+26)%26 + 'A';
        	    fputc(r,f2);
        	}else{
				// sinon si c'est un caractere special
				
	    		fputc(r,f2);
        	}
	
	    }
	}else{
    //Decodage
    // Pour le decodage il faut ajouter un argument 4
    	while(e!=EOF)
    	{
			e=fscanf(f, "%c", &r);
    	    //si les caractere du text est une lettre alphabetique
    	    if(r>='a' && r<= 'z')
    	    {
    	        r = (r-'a'-atoi(argv[2])+26)%26 + 'a';
    	        fputc(r,f2);
    	    }else if(r>='A' && r<= 'Z')
    	    {
    	        r = (r-'A'-atoi(argv[2])+26)%26 + 'A';
    	        fputc(r,f2);
    	    }else{
				// sinon si c'est un caractere special
				
		    	fputc(r,f2);
    	    }
	
    	}
    }

    fclose(f);
    fclose(f2);

    return EXIT_SUCCESS;

}

