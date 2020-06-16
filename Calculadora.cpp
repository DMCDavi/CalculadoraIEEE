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
	else
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

//Converte um numero decimal para o padrão IEEE de 8 bits
string Converter8Bits(double numero)
{
	return "0 || 101 || 0111";
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

//Converte um numero em binario para hexadecimal
string ConverterBinHex(string binario)
{
	return "0x41A2CCCD";
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
