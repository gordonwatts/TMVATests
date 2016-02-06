using ROOTNET;
using ROOTNET.Interface.NTMVA;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using static System.Console;

namespace DotNetTMVASimpleStraightCut
{
    /// <summary>
    /// Can ROOT.NET support TMVA?
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("Creating the factory");
            var outputFile = NTFile.Open("tmvaNetOutput.root", "RECREATE");

            var factory = new ROOTNET.NTMVA.NFactory(new NTString("testjob"), outputFile, new NTString("!V:!Silent:AnalysisType=Classification"));

            // Signal and background
            var signalFileInfo = new FileInfo("..\\signal.training.root");
            var backgroundFileInfo = new FileInfo("..\\background.training.root");
            var signalFile = NTFile.Open(signalFileInfo.FullName, "READ");
            var backgroundFile = NTFile.Open(backgroundFileInfo.FullName, "READ");

            var signalTree = signalFile.Get("mytree") as NTTree;
            var backgroundTree = backgroundFile.Get("mytree") as NTTree;

            factory.AddSignalTree(signalTree, 1.0);
            factory.AddBackgroundTree(backgroundTree, 1.0);

            // The variables
            factory.AddVariable(new NTString("nTracks"), new NTString("Number of Tracks"), new NTString(""));
            factory.AddVariable(new NTString("logR"),    new NTString("CalRatio"),         new NTString(""));

            var m = factory.BookMethod(NTypes.EMVA.kCuts, new NTString("Cuts"));

            // Given these particular test files, with Cuts, this causes a crash.
            factory.TrainAllMethods();

            factory.TestAllMethods();
            factory.EvaluateAllMethods();

            outputFile.Close();
        }
    }
}
