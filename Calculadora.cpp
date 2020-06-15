#include <bits/stdc++.h>
#include <cstring>
#include <locale.h>

using namespace std;

//Converte um numero decimal para binario
string ConverterBinario(double decimal)
{
	return "101.01";
}

//Retorna o binario referente ao sinal do numero
string ConverterSinal(double decimal)
{
	if (decimal < 0)
		return "1";
	else if (decimal >= 0)
		return "0";
}

//Retorna o binario referente ao expoente do numero
string ConverterExpoente(double decimal)
{
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
	cout << "Digite um número decimal, separado por ponto, que deseja converter: " << endl;
	cin >> decimal;
	cout << "SINAL || EXPOENTE || MANTISSA" << endl;
	cout << "IEEE 8 BITS" << endl;
	cout << Converter8Bits(decimal) << endl;
	cout << "IEEE 32 BITS" << endl;
	cout << Converter32Bits(decimal) << endl;
	cout << "IEEE 64 BITS" << endl;
	cout << Converter64Bits(decimal) << endl;
	cout << "Hexadecimal" << endl;
	cout << ConverterHexadecimal(decimal) << endl;

	return 0;
}
