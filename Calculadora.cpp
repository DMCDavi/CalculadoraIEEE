#include<bits/stdc++.h>
#include<cstring>
using namespace std;

string ConversorBinario(int binario){
	string resultado, valorString;
	int aux=2;
	stringstream ss;  
	while(aux != 0){
		aux = binario%2;
		
		ss << aux;
		ss >> valorString;
		strcat(resultado, valorString);
		
	}
		
	return resultado;
}

string DecimalPF(double decimal){
	char sinal;
	string mantissa, expoente, resultado;
	
	
	if(decimal < 0){
		sinal = '0';
	}else if(decimal > 0){
		sinal = '1';
	}
	
	//binario = decimal;
	
	expoente = ConversorBinario(decimal);
	
	
	return resultado;
}

double PFDecimal(int sinal, long long int expoente, long long int mantissa){
	double Resultado;
	
	
	return Resultado;
}


main(){
	
	double Decimal;
	int OP, Sinal;
	long long int Expoente, Mantissa;
	cout<<"Calculadora de AOC iniciada!\n";

	while(OP != 0){
		
		cout<<"Opcoes:\n Ponto Flutuante para Decimal, Digite: 1\n Decimal para Ponto Flutuante, Digite: 2\n Digite 0 para sair da aplicação";
		cout<<"\n";
		cin>>OP;
		while(true){
		
			if(OP == 1){
				cout<<"Voce escolheu a opção de conversão Ponto Flutuante para Decimal\n";
				cout<<"Insira o sinal: ";
				cin>>Sinal;
				cout<<"Insira o expoente: ";
				cin>>Expoente;		
				cout<<"Insira a mantissa: ";
				cin>>Mantissa;
			
				cout<<"Representacao Decimal: "<<PFDecimal(Sinal, Expoente, Mantissa);
				cout<<"Valor em : "<<PFDecimal(Sinal, Expoente, Mantissa);
				cout<<"\n\n";
				system("PAUSE");
				
				break;
			}else if(OP == 2){
				cout<<"Voce escolheu a opção de conversão Hexadecimal para Ponto Flutuante \n";
				cout<<"Insira o valor: ";
				cin>>Decimal;
				cout<<"Valor em binario: "<<DecimalPF(Decimal);
				
			}else{
				cout<<"Opção não identificada, tente novamente!";
				break;
			}
		}
		if(OP == 0){
			cout<<"\nDesligando...";
			break;
		}
	}
	
	
	
	
	
	cout<<endl;
	system("PAUSE");
}
