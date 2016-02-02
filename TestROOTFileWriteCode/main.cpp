#include <iostream>

#include "TFile.h"

using namespace std;

int main()
{
	cout << "hi" << endl;

	auto f = new TFile("hi.root", "RECREATE");
	f->Close();
}