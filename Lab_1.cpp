

#include <iostream>
#include <Windows.h>

using namespace std;

void IntegerAddition()
{
	int a = 20;
	int b = 30;
	int result;
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < 10000000; i++)
	{
		result = a + b;
	}
	
	stop = clock();
	cout << "INT" << endl;
	
	cout <<"Time that was required:"<< stop - start<<endl<<endl;


}

void FloatAddition()
{
	float a = 123.43;
	float b = 544.22;
	float result;
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < 10000000; i++)
	{
		result = a + b;
	}

	stop = clock();
	cout << "FLOAT" << endl;
	
	cout << "Time that was required:" << stop - start << endl<<endl;


}

void DoubleAddition()
{
	double a = 122.433434343434;
	double b = 333.3443321656876;
	double result;
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < 10000000; i++)
	{
		result = a + b;
	}

	stop = clock();
	cout << "DOUBLE" << endl;
	
	cout << "Time that was required:" << stop - start << endl<<endl;

}

void AssemblyIntAddition() 
{

	short a = 20;
	short b = 30;
	short result;
	clock_t  start, stop;
	start = clock();
	for (int i = 0; i < 10000000; i++)
	{
		_asm {
			mov ax, a
			mov bx, b
			add ax, bx
			mov result, ax
			
		}
	}
	
	stop = clock();
	cout << "\nINT" << endl<<endl;
	
	cout << "Time that was required : " << stop - start << endl;
	
}


void AssemblyFloatAddition()
{

	float a = 123.43;
	float b = 544.22;
	float result=0;
	clock_t  start, stop;
	start = clock();
	/**/
	
	for (int i = 0; i < 10000000; i++)
	{
		_asm {
			
			mov ax, word ptr a
			add ax, word ptr b

			mov bx, word ptr [a+2] // передняя часть
			adc bx, word ptr [b+2] // передняя часть
			
			mov word ptr[result + 2], bx
			mov word ptr[result], ax

		}
	}
	
	stop = clock();
	cout << "\nFLOAT" << endl<<endl;
	
	cout << "Time that was required : " << stop - start << endl;
	
}


void AssemblyDoubleAddition() 
{
	double a = 122.433434343434;
	double b = 333.3443321656876;
	double result;
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < 10000000; i++)
	{
		_asm {
			
			

			mov eax, dword ptr a
			add eax, dword ptr b

			mov ebx, dword ptr[a + 2] // передняя часть
			adc ebx, dword ptr[b + 2] // передняя часть

			mov dword ptr[result + 4], ebx
			mov dword ptr[result], eax
		}
	}

	stop = clock();
	
	cout << "\nDOUBLE" << endl<<endl;
	
	cout << "Time that was required:" << stop - start << endl << endl;
	
}

int main()
{
	cout << "High level language" << endl << endl;
	IntegerAddition();
	FloatAddition();
	DoubleAddition();

	cout << "Assembly" << endl << endl;
	AssemblyIntAddition();
	AssemblyFloatAddition();
	AssemblyDoubleAddition();
	
}


