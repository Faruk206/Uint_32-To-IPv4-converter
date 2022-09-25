/* Take the following IPv4 address: 128.32.10.1 
 * This address has 4 octets where each octet is a single byte (or 8 bits). 
 *
 * 1st octet 128 has the binary representation: 10000000 2nd octet 32 has the binary representation: 00100000 3rd octet 10 has the binary representation: 00001010 4th octet 1 has the binary representation: 00000001 
 * So 128.32.10.1 == 10000000.00100000.00001010.00000001 Because the above IP address has 32 bits, we can represent 
it as the unsigned 32 bit number: 2149583361 Complete the function that takes an unsigned 32 bit number and returns a string representation of its IPv4 address. 

Examples 2149583361 ==>"128.32.10.1"
32 ==> "0.0.0.32"
0 ==> "0.0.0.0"
*/

#include <bits/stdc++.h>

int Decoder(std::string binarno);

std::string StandardniKonverter(int broj){
	int ostatak, sljedeciBroj;
	
	std::cout<<"Broj: "<<broj<<" u binarnom iznosi: "<<std::endl;
	
	std::vector<int>Binarno;
	
	std::stringstream BinarniBroj;	
	
	while(broj != 0){
		broj/2;
		ostatak = broj%2;
		Binarno.push_back(ostatak);
		broj= broj/2;	
	}	
	
	std::reverse(Binarno.begin(), Binarno.end());
	
	for(int i = 0; i < Binarno.size(); i++){BinarniBroj << Binarno[i];}
	
	std::string output = BinarniBroj.str();
	
	std::string nule((32-output.length()), '0');
	
	return nule + output;

}


void Encoder(std::string binarno){
	std::string broj1 = "", broj2 = "", broj3 = "", broj4 = "";

	for(int i = 0; i < 33; i++){
		if(i < 8){broj1 = broj1 + binarno[i];}
		else if(i < 16){broj2 = broj2 + binarno[i];}
		else if(i < 24){broj3 = broj3 + binarno[i];}
		else if(i < 32){broj4 = broj4 + binarno[i];}
	}
	std::cout<<"Brojevi: "<<std::endl;
	std::cout<<broj1<<std::endl;
	std::cout<<broj2<<std::endl;
	std::cout<<broj3<<std::endl;
	std::cout<<broj4<<std::endl;

	std::cout<<"IP adresa: ";
	std::cout<<Decoder(broj1)<<".";
	std::cout<<Decoder(broj2)<<".";
	std::cout<<Decoder(broj3)<<".";
	std::cout<<Decoder(broj4)<<std::endl;
}

int Decoder(std::string binarno){
	int broj = 0, n;
	std::reverse(binarno.begin(), binarno.end());

	for(int i = 7; i>=0; i--){
		n = binarno[i] - '0';
		broj = broj + (n * pow(2,i));
	}

	return broj;
}

int main(){
	int testni_broj;
	std::string funkcija1;

	std::cout<<"======Test Funkcije1======== "<<std::endl;
	
	std::cout<<"Unesi broj da se konvertuje u binaran: "<<std::endl;
	std::cin>>testni_broj;
	
	funkcija1 = StandardniKonverter(testni_broj);
	std::cout<<funkcija1;
	
	std::cout<<""<<std::endl;
	std::cout<<"=======Test Funkcije2======="<<std::endl;
	
	Encoder(funkcija1);	
	
	std::cout<<"=======Test Funkcije3======="<<std::endl;
	Decoder(funkcija1);
	
	return 0;
}


