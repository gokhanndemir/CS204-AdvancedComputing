// Gökhan Demir 26562 CS204 HW7 for Spring 2020
#include <iostream>
#include <cmath> // For pow(power) function.
#include <string> // For strings and getline.
using namespace std;

void P(string AlteringOne, string KEY, int i1, bool TrueOrFalse) // The permutation function P.
{
	string lastone="        ";
	lastone[0]=AlteringOne[1];
	lastone[1]=AlteringOne[3];
	lastone[2]=AlteringOne[0];
	lastone[3]=AlteringOne[2];
	lastone[4]=AlteringOne[5];
	lastone[5]=AlteringOne[7];
	lastone[6]=AlteringOne[4];
	lastone[7]=AlteringOne[6];
	int binarystringtodecimal=0;
	for (int i=0;i<8;i++) // Thanks to this loop, I am able to calculate the value of binary string.
    {
		if(lastone[i]=='1')
        {
			binarystringtodecimal+=pow(2,7-i); 
        }
     }
	unsigned char a=binarystringtodecimal, b=KEY[i1], c=b^a; // XOR
    cout << hex << (int) c; // TAKEN FROM THE HOMEWORK'S PDF.
    if (TrueOrFalse==true)
    {
		cout << endl << endl;
    }
}

void StringToBinary(string s,string KEY)
{
	cout << "Ciphertext: ";
	bool TrueOrFalse=false;
    int i;
    for (i = 0; i<s.length(); i++)
    {
      	int number=128;
        int value = int(s[i]);
        string binary = "";
        while (number>=1)
		{
			if(value>=number)
			{
				binary+="1";
				value-=number;
			}
			else
			{
				binary+="0";
			}
			number/=2;
		}
		if (s.length()-i==1)
		{
			TrueOrFalse=true; // This will be helpful when printing 2 new (blank) lines.
        }
		if (i>=KEY.length())
		{
			P(binary,KEY,i%KEY.length(),TrueOrFalse);
		}
		else
		{
			P(binary,KEY,i,TrueOrFalse);
		}
    }
}

int main()
{
	string EncKey, plaintext;
	bool checker=true;
	cout << "*** Welcome to the Simple Data Encryption Application ***" << endl;
	cout << "Please enter the encryption key: ";
	getline(cin,EncKey);
	while (checker)
	{
		cout << "Please enter the plaintext to be encrypted: ";
		getline(cin,plaintext);
		if (plaintext=="^Z")
		{
			checker=false;
		}
		else
		{
			StringToBinary(plaintext,EncKey);
		}
	}
	return 0;
}