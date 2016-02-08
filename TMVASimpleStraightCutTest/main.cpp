#include <iostream>

#include "TMVA/Factory.h"
#include "TFile.h"

using namespace std;

int main()
{
	cout << "Creating the factory" << endl;

	// Create the factory
	auto outputFile = TFile::Open("tmvaOutput.root", "RECREATE");
	auto factory = new TMVA::Factory("testjob", outputFile, "!V:DrawProgressBar=True:!Silent:AnalysisType=Classification");

	// Signal and background file.
	//auto signalFile = TFile::Open("signal.training.root", "READ");
	//auto backgroundFile = TFile::Open("background.training.root", "READ");
	auto signalFile = TFile::Open("HV600pi100.training.root", "READ");
	auto backgroundFile = TFile::Open("J2Z.training.root", "READ");
	auto signalTree = static_cast<TTree*>(signalFile->Get("mytree"));
	auto backgroundTree = static_cast<TTree*>(backgroundFile->Get("mytree"));

	factory->AddSignalTree(signalTree, 1.0);
	factory->AddBackgroundTree(backgroundTree, 1.0);

	// The variables
	factory->AddVariable("nTracks", "Number of Tracks", "", 'I');
	factory->AddVariable("logR", "CalRatio", "", 'F');

	// Book the straight cuts guy
	factory->BookMethod(TMVA::Types::kCuts, "SimpleCuts",
		"!H:V:FitMethod=MC:EffSel:SampleSize=2000:VarProp[0]=FSmart:VarProp[1]=FSmart:VarTransform=Decorrelate");
	//factory->BookMethod(
	//	TMVA::Types::kLikelihood, 
	//	"Likelihood",
	//	"H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmoothBkg[1]=10:NSmooth=1:NAvEvtPerBin=50"
	//	);

	// And do the training
	factory->TrainAllMethods();

	// And some dump output
	factory->TestAllMethods();
	factory->EvaluateAllMethods();

	// Clean up
	outputFile->Close();
	delete outputFile;
	delete factory;

	return 0;
}
