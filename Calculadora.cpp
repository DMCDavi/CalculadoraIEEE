#include <bits/stdc++.h>
#include <cstring>
#include <locale>
#include <cmath>
#include <cstdlib>

using namespace std;

//Retorna o tamanho do expoente de acordo a quantidade de bits
int TamanhoExpoente(int bits)
{
	if (bits == 8)
		return 3;
	else if (bits == 32)
		return 8;
	else if (bits == 64)
		return 11;
	else if (bits == 128)
		return 15;
	else
		return 0;
}

//Retorna o tamanho da mantissa de acordo a quantidade de bits
int TamanhoMantissa(int bits)
{
	if (bits == 8)
		return 4;
	else if (bits == 32)
		return 23;
	else if (bits == 64)
		return 52;
	else if (bits == 128)
		return 112;
	else
		return 0;
}

//Converte um numero decimal para binario
string ConverterBinario(double numero, int bits)
{
	string binario = "";
	//O padrao da quantidade de caracteres ignorados eh um pois na conversao pro padrao IEEE isola-se 1 algarismo
	int exp_max, qntd_igr = 1;
	double somatorio = 0;

	//Acha o expoente de pontenciacao maximo para o numero decimal
	for (exp_max = 0; numero >= pow(2, exp_max + 1); exp_max++)
		;
	//Preenche a string com os valores 1 ou 0 de acordo a potenciacao de 2 ate que chegue ao limite da precisao
	for (int exp = exp_max; TamanhoMantissa(bits) > binario.length() - qntd_igr || binario.empty(); exp--)
	{
		//Caso o expoente vire negativo adiciona um ponto para separar o binario e passa a ignorar dois caracteres
		if (exp < 0 && qntd_igr == 1)
		{
			binario += ".";
			qntd_igr++;
		}
		if (numero - somatorio >= pow(2, exp))
		{
			somatorio += pow(2, exp);
			binario += "1";
		}
		else
			binario += "0";
		//Caso o numero ja tenha sido encontrado depois de preencher todo o expoente, sai do loop
		if (somatorio == numero && exp <= 0)
			break;
	}
	return binario;
}

//Retorna o binario referente ao sinal do numero
string ConverterSinal(double numero)
{
	if (numero < 0)
		return "1";
	else
		return "0";
}

//Retorna o binario referente ao expoente do numero
string ConverterExpoente(double numero, int bits)
{
	string binario, expoente_str;
	int expoente_int, casas_decimais;

	binario = ConverterBinario(numero, bits);
	//Caso o numero esteja entre 0 e 1 o ponto percorre a direita
	if (binario[0] == '0')
		for (casas_decimais = 0; binario[0] == '0'; casas_decimais--)
		{
			//Apaga o primeiro algarismo e o ponto
			binario.erase(0, 2);
			//Insere um ponto apos o primeiro alagarismo
			binario.insert(1, ".");
		}
	//Senao o ponto percorre a esquerda
	else
		casas_decimais = binario.substr(1, binario.find(".") - 1).length();
	//Soma a quantidade casas decimais que o ponto percorreu para isolar o primeiro algarismo com o BIAS
	expoente_int = casas_decimais + pow(2, TamanhoExpoente(bits) - 1) - 1;
	expoente_str = ConverterBinario(expoente_int, bits);
	//Preenchendo a string com 0
	for (int i = expoente_str.length(); i < TamanhoExpoente(bits); i++)
		expoente_str.insert(0, "0");

	return expoente_str;
}

//Retorna o binario referente a mantissa do numero
string ConverterMantissa(double numero, int bits)
{
	string binario, mantissa;
	int ponto_pos;

	binario = ConverterBinario(numero, bits);
	//Caso o numero esteja entre 0 e 1 o ponto percorre a direita
	if (binario[0] == '0')
		while (binario[0] == '0')
		{
			//Apaga o primeiro algarismo e o ponto
			binario.erase(0, 2);
			//Insere um ponto apos o primeiro alagarismo
			binario.insert(1, ".");
		}
	//Senao o ponto percorre a esquerda
	else if(binario.find(".") != -1)
		while (binario.substr(0, binario.find(".")).length() > 1)
		{
			ponto_pos = binario.find(".");
			//Apaga o ponto
			binario.erase(ponto_pos, 1);
			//Insere um ponto na posicao anterior ao que estava antes
			binario.insert(ponto_pos - 1, ".");
		}
	//Separando a mantissa
	mantissa = binario.substr(binario.find(".") + 1, binario.length());
	//Preenchendo a string com 0
	for (int i = mantissa.length(); i < TamanhoMantissa(bits); i++)
		mantissa += "0";

	return mantissa;
}

string excesso(int expoente)
{

	string resultado;

    if (expoente == -4) resultado = "000";
    else if (expoente == -3) resultado = "001";
    else if (expoente == -2) resultado = "010";
    else if (expoente == -1) resultado = "011";
    else if (expoente == 0) resultado = "100";
	else if (expoente == 1) resultado = "101";
    else if (expoente == 2) resultado = "110";
    else if (expoente == 3) resultado = "111";
    else if (expoente > 3) resultado = "Overflow";
    else if (expoente < -1) resultado = "Underflow";

    return resultado;
}

//Converte um numero decimal para o padrão IEEE de 8 bits
string Converter8Bits(double numero)
{
	string expoente, mantissa="", sinal;
	string bin = ConverterBinario(abs(numero), 8);
	sinal = ConverterSinal(numero);
	int exp = 0;
	int pos = bin.find(".");
	if(pos == -1){
		exp = bin.length();
		expoente = excesso(exp);
		while(bin.length() < 4){
			bin.append("0");
		}
		mantissa = bin;
	}
	else{
		bin.erase(pos, 1);
	
	
	
	
	if(abs(numero) >= 1)
		exp = pos;
	else{
		int i = 0;
		while(bin[pos++] != '1'){
			i--;
		}
		pos = i;
		
		
	}
	
	mantissa = bin;
	expoente = excesso(pos);
	
	while(mantissa[0]=='0'){
		mantissa.erase(0,1);
	}
	
	while(mantissa.length() < 4){
		mantissa.append("0");
	}
	
	while(mantissa.length() > 4){
		mantissa.erase(mantissa.length()-1);
	}
	}
	
	
	
	return sinal + " || " + expoente + " || " + mantissa;
}

//Converte um numero decimal para o padrão IEEE724 de acordo a quantidade de bits especificado
string ConverterIEEE(double numero, int bits)
{
	string sinal, expoente, mantissa;

	sinal = ConverterSinal(numero);
	expoente = ConverterExpoente(abs(numero), bits);
	mantissa = ConverterMantissa(abs(numero), bits);

	return sinal + " || " + expoente + " || " + mantissa;
}

//Converte 4 bin�rios em 1 hexadecimal
string Converter4Bin_1Hex(string binario)
{
	int decimal = 0;
	string hexa="0";
	for(int i=0; i<4;i++)
	{
		decimal += (binario[i]-'1'+1)*pow(2, 3-i);
	}
	if(decimal < 10)
		hexa[0] = decimal + '1' - 1;
	else
		hexa[0] = decimal-10 +'A';
	return hexa;
}

//Converte um numero em binario para hexadecimal
string ConverterBinHex(string binario)
{
	int i = binario.length()-1;
	string hexa = "0x";
	while(i>=0)
	{
		string aux = "0000";
		for(int j=3; j>=0 && i>=0; j--)
		{
			aux[j] = binario[i];
			i--;
		}
		hexa.insert(2, Converter4Bin_1Hex(aux));
	}
	return hexa;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	double numero;

	cout << "Calculadora de AOC iniciada!" << endl;
	while (true)
	{
		cout << "Digite um número decimal, separado por ponto, que deseja converter, ou 0 para sair: " << endl;
		cin >> numero;
		if (numero == 0)
			break;
		cout << "SINAL || EXPOENTE || MANTISSA" << endl;
		cout << "IEEE 8 BITS" << endl;
		cout << Converter8Bits(numero) << endl;
		cout << "IEEE 32 BITS" << endl;
		cout << ConverterIEEE(numero, 32) << endl;
		cout << "IEEE 64 BITS" << endl;
		cout << ConverterIEEE(numero, 64) << endl;
		cout << "Hexadecimal" << endl;
		cout << ConverterBinHex("000111101") << endl;
		system("pause");
		system("cls");
	}

	return 0;
}
