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
string ConverterBinario(double decimal, int bits)
{
	string binario = "";
	//O padrao da quantidade de caracteres ignorados eh um pois na conversao pro padrao IEEE isola-se 1 algarismo
	int exp_max, qntd_igr = 1;
	double pnt_flut = 0;

	//Acha o expoente de pontenciacao maximo para o numero decimal
	for (exp_max = 0; decimal >= pow(2, exp_max + 1); exp_max++);
	//Preenche a string com os valores 1 ou 0 de acordo a potenciacao de 2 ate que chegue ao limite da precisao
	for (int exp = exp_max; TamanhoMantissa(bits) > binario.length() - qntd_igr || binario.empty(); exp--)
	{
		//Caso o expoente vire negativo adiciona um ponto para separar o binario e passa a ignorar dois caracteres
		if (exp < 0 && qntd_igr == 1)
		{
			binario += ".";
			qntd_igr++;
		}
		if (decimal - pnt_flut >= pow(2, exp))
		{
			pnt_flut += pow(2, exp);
			binario += "1";
		}
		else
			binario += "0";
	}
	return binario;
}

//Retorna o binario referente ao sinal do numero
string ConverterSinal(double decimal)
{
	if (decimal < 0)
		return "1";
	else
		return "0";
}

//Retorna o binario referente ao expoente do numero
string ConverterExpoente(double decimal)
{
	//ConverterBinario(decimal, 8);
	return "101";
}

//Retorna o binario referente a mantissa do numero
string ConverterMantissa(double decimal)
{
	return "1011";
}

//Converte um numero decimal para o padrão IEEE de 8 bits
string Converter8Bits(double decimal)
{
	string sinal, expoente, mantissa;

	sinal = ConverterSinal(decimal);
	expoente = ConverterExpoente(decimal);
	mantissa = ConverterMantissa(decimal);

	return sinal + " || " + expoente + " || " + mantissa;
}

//Converte um numero decimal para o padrão IEEE de 32 bits
string Converter32Bits(double decimal)
{
	return "0 || 10110010 || 01110010100101001011110";
}

//Converte um numero decimal para o padrão IEEE de 64 bits
string Converter64Bits(double decimal)
{
	return "0 || 10110010111 || 0111001010010100101111011101010001011010010111101000";
}

//Converte um ponto flutuante para hexadecimal
string ConverterHexadecimal(double decimal)
{
	return "0x41A2CCCD";
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	double decimal;

	cout << "Calculadora de AOC iniciada!" << endl;
	while (true)
	{
		cout << "Digite um número decimal, separado por ponto, que deseja converter, ou 0 para sair: " << endl;
		cin >> decimal;
		if (decimal == 0)
			break;
		cout << "SINAL || EXPOENTE || MANTISSA" << endl;
		cout << "IEEE 8 BITS" << endl;
		cout << Converter8Bits(decimal) << endl;
		cout << "IEEE 32 BITS" << endl;
		cout << Converter32Bits(decimal) << endl;
		cout << "IEEE 64 BITS" << endl;
		cout << Converter64Bits(decimal) << endl;
		cout << "Hexadecimal" << endl;
		cout << ConverterHexadecimal(decimal) << endl;
		system("pause");
		system("cls");
	}

	return 0;
}
