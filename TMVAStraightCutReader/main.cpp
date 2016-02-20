///
/// Read in a TMVA weight file and do a few tests by hand.
///

#include "tmva/Reader.h"
#include <iostream>

using namespace std;

int main()
{
	// Load up the reader
	auto reader = new TMVA::Reader();

	// Declare the variables
	float lowestPtTrack = 0.0;
	float nTracks = 0.0;
	float logR = 0.0;

	reader->AddVariable("logR", &logR);
	reader->AddVariable("nTracks", &nTracks);

	// Book it
	auto s = "C:\\Users\\gordo\\Documents\\Code\\calratio2015\\JetCutStudies\\SimpleJetCutTraining\\bin\\x86\\Debug\\weights\\VerySimpleTraining_SimpleCuts.weights.xml";
	reader->BookMVA("SimpleCuts", s);

	// Now get some values
	logR = 1.0;
	nTracks = 5;
	cout << "LogR: " << logR << " nTracks: " << nTracks << ": result=" << reader->EvaluateMVA("SimpleCuts", 0.22) << endl;

	logR = 2.0;
	nTracks = 00;
	cout << "LogR: " << logR << " nTracks: " << nTracks << ": result=" << reader->EvaluateMVA("SimpleCuts", 0.22) << endl;

	vector<double> stuff;
	stuff.push_back(1.0);
	stuff.push_back(5);
	cout << "result=" << reader->EvaluateMVA(stuff, "SimpleCuts", 0.22) << endl;
	stuff.clear();
	stuff.push_back(2.0);
	stuff.push_back(0);
	cout << "result=" << reader->EvaluateMVA(stuff, "SimpleCuts", 0.22) << endl;


	return 0;
}