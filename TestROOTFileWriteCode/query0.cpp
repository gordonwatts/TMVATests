///
/// Auto-generated template by the LINQToTTree utility. Do not modify. Anyway, it is
/// good only for one query, so no use in modifying it!!
///
/// Uses the Velociy template engine.
///
#include "scanner.h"

#include "TFile.h"
#include "TTree.h"

#include <TFile.h>
#include <TSystem.h>

#include <string>
#include <stdexcept>
#include <map>

using std::string;

#ifdef __MAKECINT__
#endif


class query0 : public scanner
{
public:
	/// So there is some init that CINT will know about
	/// (I don't know why this is required, but it is).
	query0()
	{
	}

	/// Called when we are starting a run
	void SlaveBegin(TTree *t)
	{
		scanner::SlaveBegin(t);

		/// Init the variables that we are going to be carrying along with us.
		aOutputTTreeFileType_2 = std::pair<TFile*, TTree*>(0, 0);

		aOutputTTreeFileType_2.first = new TFile("C:\\Users\\gordo\\Documents\\Code\\Root\\LINQtoROOT\\LINQToTTree\\LINQToTTreeLib.Tests\\bin\\x86\\Debug\\hi.root", "RECREATE");
		aOutputTTreeFileType_2.second = new TTree("mytree", "fork me");
	}

	/// Called when we are closign the file and shutting down on the slave
	void SlaveTerminate()
	{
		scanner::SlaveTerminate();

		aOutputTTreeFileType_2.first->Write();
		aOutputTTreeFileType_2.first->Close();
		TH1I *aOutputTTreeFileType_2_hist = new TH1I("aOutputTTreeFileType_2", "C:\\Users\\gordo\\Documents\\Code\\Root\\LINQtoROOT\\LINQToTTree\\LINQToTTreeLib.Tests\\bin\\x86\\Debug\\hi.root", 1, 0.0, 1.0);
		aOutputTTreeFileType_2_hist->SetDirectory(0);
		Book(aOutputTTreeFileType_2_hist);
		Long_t aOutputTTreeFileType_2_size;
		Long_t aOutputTTreeFileType_2_modification_time;
		gSystem->GetPathInfo("C:\\Users\\gordo\\Documents\\Code\\Root\\LINQtoROOT\\LINQToTTree\\LINQToTTreeLib.Tests\\bin\\x86\\Debug\\hi.root", 0, &aOutputTTreeFileType_2_size, 0, &aOutputTTreeFileType_2_modification_time);
		TH1I *aOutputTTreeFileType_2_size_hist = new TH1I("aOutputTTreeFileType_2_size", "var transport", 1, 0.0, 1.0);
		aOutputTTreeFileType_2_size_hist->SetBinContent(1, aOutputTTreeFileType_2_size);
		aOutputTTreeFileType_2_size_hist->SetDirectory(0);
		Book(aOutputTTreeFileType_2_size_hist);
	}

	/// Called with all plots at hand
	void Terminate()
	{
		scanner::Terminate();
	}

	/// Called to process an entry
	bool Process(Long64_t entry)
	{
		///
		/// Get to the proper entry, reset internal cache
		///

		fDirector.SetReadEntry(entry);
		ResetCache();

		///
		/// Run the processing code
		///

		ExecuteQueryBlock0();

		///
		/// Always return true - we want to go onto the next entry, afterall.
		///

		return true;
	}

private:

	///
	/// The query block functions
	///
	void ExecuteQueryBlock0()
	{
		{
			aOutputTTreeFileType_2.second->Fill();
		}
	}


	///
	/// The member functions that the query blocks will be calling
	///


	///
	/// Reset all cached items before we get going
	///

	void ResetCache()
	{
	}

	/// Here are the variables that hold things we need to keep around
	/// between entries of the ntuple. So things like the result that has
	/// to be filled on each entry.

	std::pair<TFile*, TTree*> aOutputTTreeFileType_2;

	/// Store an object to send back. We encase it in a FlowObject because the list
	/// of objects that goes back is "flat" and FlowObject holds onto
	/// a tag that tells us where this should be stored later. Helps!
	void Book(TObject *o)
	{
		string objName("");
		if (o->InheritsFrom("TNamed")) {
			TNamed *n = static_cast<TNamed*>(o);
			objName = n->GetName();
		}
		else {
			objName = o->ClassName();
		}

		///
		/// If this is a replacement, then boom!
		///

		if (dynamic_cast<TObject*> (GetOutputList()->FindObject(objName.c_str())) == 0) {
			GetOutputList()->Add(o->Clone());
		}
	}

	///
	/// Load from the input list a name of some item
	///
	template<class T>
	T LoadFromInputList(const std::string &name)
	{
		if (fInput == 0) {
			std::cout << "Unable to load (object '" << name << "') from the input list - the list is null!" << std::endl;
			throw std::runtime_error(("Unable to load from input list the object called '" + name + "'.").c_str());
		}

		T result = static_cast<T>(fInput->FindObject(name.c_str()));
		if (result == 0) {
			std::cout << "Unable to find object '" << name << "' in the input list!" << std::endl;
			throw std::runtime_error(("Unable to load object '" + name + "' from the input list - not found!").c_str());
		}

		return result;
	}
};
