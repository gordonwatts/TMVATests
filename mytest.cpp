#include "TMVA/Reader.h"
#include "TFile.h"

#include <iostream>
#include <vector>

using namespace std;

void mytest() {

	cout << "hi" << endl;

	auto f = TFile::Open("DotNetTMVASimpleStraightCut/junk.root", "READ");

	auto r = static_cast<TMVA::Reader*>(f->Get("myreader"));
	r->Print();

	vector<double> stuff;
	stuff.push_back(1.0);
	stuff.push_back(5);
	cout << "result=" << r->EvaluateMVA(stuff, "SimpleCuts", 0.22) << endl;
	stuff.clear();
	stuff.push_back(2.0);
	stuff.push_back(0);
	cout << "result=" << r->EvaluateMVA(stuff, "SimpleCuts", 0.22) << endl;

	f->Close();
}