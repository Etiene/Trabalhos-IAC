//================================================================//
//=====================  DEC-BIN CONV v1.1  ======================//
//== Converte n�meros naturais decimais para bin�rios de 8 bits ==//
//================================================================//
// Por: Etiene da Cruz Dalcol. Mat 1211996. T 3WA. Junho de 2012  //
// Para: Disciplina de Introdu��o a Arquitetura de Computadores   //
//       ministrada por Luiz Fernando Seibel.                     //
//================================================================//
// Log de altera��es:                                             //
// 09/12/2012 - V1.0: Cria��o do programa.                        //
// 10/12/2012 - V1.1: Modificado para ler entradas tamb�m ao      //
//                    inv�s de s� usar as entradas de teste.      //
// 15/08/2012 - V1.1: Consertando erro boçal.                      //
//================================================================//

#include <stdio.h>

int validar_dec(int dec){
	if(dec<0){
		printf("Entrada: %d.\nERROR BRAIN 404!!! A entrada precisa ser um numero NATURAL.\n",dec);
		return 1;
	}
	else if(dec>255){
		printf("Entrada: %d.\nERROR OVERFLOW 666 FROM HELL!!! Impossivel armazenar um numero natural maior que 256 na base 10 dentro de 8 bits.\n",dec);
		return 1;
	}
	return 0;
}

void ler_dec(int * dec){
	printf("Entre com um numero decimal natural: \n");
	scanf("%d",dec);
	if(validar_dec(*dec))
		ler_dec(dec);
}

void dec_bin(int dec, int bin[]){
	int i;
	
	for(i=7;i>=0;i--){
		if((dec==0)||(dec%2==0))
			bin[i]=0;
		else 
			bin[i]=1;
		dec = dec/2;
	}
}

int main(void){
	FILE * fpB = fopen("res_dec-bin.txt","w");
	int i,j,bin[8],dec;
	char c;
	printf("Conversor decimal-binario v1.1\n");
	printf("i = Iniciar programa. t = Testar com varias entradas(output em .txt).\n");
	scanf(" %c",&c);
	if(c=='i')
		while(1){
			ler_dec(&dec);
			dec_bin(dec,bin);
			printf("Resultado: ");
			for(i=0;i<8;i++)
					printf("%d",bin[i]);
				printf("\n");
			printf("Ler outro numero? s = Sim. n = Nao\n");
			scanf(" %c",&c);
			if(c!='s')
				break;
		}
	else if(c=='t'){
		int decs[6]={0,-5,314,15,234,115};
	
		for(i=0;i<6;i++){
			if(validar_dec(decs[i]))
				fprintf(fpB,"%d: Entrada invalida.\n",decs[i]);
			else {
				fprintf(fpB,"%d: ",decs[i]);
				dec_bin(decs[i],bin);
				for(j=0;j<8;j++)
					fprintf(fpB,"%d",bin[j]);
				fprintf(fpB,"\n");
			}
		}
	} else
		printf("Opcao invalida");
	fclose(fpB);
	return 0;
}