//================================================================//
//=====================  BIN-DEC CONV v1.1  ======================//
//== Converte números binários de 8 bits para naturais decimais ==//
//================================================================//
// Por: Etiene da Cruz Dalcol. Mat 1211996. T 3WA. Junho de 2012  //
// Para: Disciplina de Introdução a Arquitetura de Computadores   //
//       ministrada por Luiz Fernando Seibel.                     //
//================================================================//
// Log de alterações:                                             //
// 10/12/2012 - V1.0: Criação do programa.                        //
// 10/12/2012 - V1.1: Adicionando opcao de escolher um nnumero e  //
//                    não só usar as entrads de teste             //
//================================================================//

#include <stdio.h>
#include <string.h>
#include <math.h>

int validar_bin(char bin[]){
	int i;
	if(strlen(bin)!=8){
		printf("ERROR ??? !!! A entrada precisa ter OITO bits. \n");
		return 1;
	}
	for(i=0;i<8;i++)
		if(bin[i]!='0' && bin[i]!='1'){
			printf("ERROR BRAIN 404!!! A entrada precisa ser BINARIA. \n");
			return 1;
		}
	return 0;
}

int ler_bin(char bin[]){
	printf("Digite um numero binario de 8 bits para converter para decimal natural: \n (Entradas maiores que 8 bits serao cortadas)\n");
	scanf(" %s",bin);
	if(validar_bin(bin))
		ler_bin(bin);
}

int bin_dec(char bin[]){
	int i,dec = 0;
	for(i=7;i>=0;i--){
		if(bin[i]=='1')
			dec += (int)pow(2.,7-i);
	}
	return dec;
}

int main(void){
	FILE * fpB = fopen("res_bin-dec.txt","w");
	int i,dec;
	char bin[9],c;
	printf("i = Iniciar programa. t = Testar com varias entradas(output em .txt).\n");
	scanf(" %c",&c);
	if(c=='i')
		while(1){
			ler_bin(bin);
			printf("Resultado: %d.\n",bin_dec(bin));
			printf("Ler outro numero? s = Sim. n = Nao\n");
			scanf(" %c",&c);
			if(c!='s')
				break;
		}
	else if(c=='t'){
		char bins[7][10]={"1010","101010101","2312","01010010","10100001","01100011","00000110"};
	
		for(i=0;i<7;i++){
			if(validar_bin(bins[i]))
				fprintf(fpB,"%s: Entrada invalida.\n",bins[i]);
			else
				fprintf(fpB,"%s: %d\n",bins[i],bin_dec(bins[i]));
		}
	} else
		printf("Opcao invalida.\n");
	fclose(fpB);
	system("pause");
	return 0;
}