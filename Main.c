#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct regCab {
	char status;
	int topoLista;
	char tagCampo1;
	char desCampo1[40];
	char tagCampo2;
	char desCampo2[40];
	char tagCampo3;
	char desCampo3[40];
	char tagCampo4;
	char desCampo4[40];
	char tagCampo5;
	char desCampo5[40];
	//214 Bytes
}regCab;

typedef struct regDados {
	char removido;//inicio com -
	int tamanhoRegistro;
	double encadeamentoLista;//inicio com -1
	char idServidor[4];
	double salarioServidor;
	char telefoneServidor[14];
	int n;
	char tagCampo4;
	char *nomeServidor;
	int c;
	char tagCampo5;
	char *cargoServidor;
}regDados;

typedef struct pgDisco {
	char conteudo[32000];
}pgDisco;

void LerCSV(FILE *arquivo);

int main(int argc, char const *argv[]){
	int numArquivos;
	char nomeArquivo[100], linha[150];
	FILE *arquivo = NULL;

	scanf("%d", &numArquivos);
	
	for (int i = 0; i < numArquivos; ++i){
		scanf("%s", nomeArquivo);
		
		arquivo = fopen(nomeArquivo, "r+b");
		LerCSV(arquivo);
	}

	return 0;
}

void LerCSV(FILE *arquivo){
	char linha[150], *token;
  	const char s[2] = ",";
  	int i = 0, j = 0;
  	regCab regCab;
  	pgDisco *pg;

  	pg = (pgDisco*) malloc(sizeof(pgDisco));

    fgets(linha, 150, arquivo);
    token = strtok(linha, s);
    
    //lendo o Cabeçalho
    regCab.status = '1';
    regCab.topoLista = -1;
    regCab.tagCampo1 = 'i';
    regCab.tagCampo2 = 's';
    regCab.tagCampo3 = 't';
    regCab.tagCampo4 = 'n';
    regCab.tagCampo5 = 'c';
    while(token != NULL){
    		if(j == 0) strcpy(regCab.desCampo1, token);
    		if(j == 1) strcpy(regCab.desCampo2, token);
    		if(j == 2) strcpy(regCab.desCampo3, token);
    		if(j == 3) strcpy(regCab.desCampo4, token);
    		if(j == 4) strcpy(regCab.desCampo5, token);
	    	token = strtok(NULL, s);
	    	j++;
	}

	

 	fclose(arquivo);
	return;
}
//SCC0215012019trabalho1-BCC-A.csv