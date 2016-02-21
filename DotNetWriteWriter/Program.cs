using ROOTNET;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DotNetWriteWriter
{
    class Program
    {
        static void Main(string[] args)
        {
            // Next, lets see if we can't createa  reader.
            var reader = new ROOTNET.NTMVA.NReader();

            // Declare the variables
            float[] nTracks = new float[1];
            float[] logR = new float[1];

            reader.AddVariable(new NTString("logR"), logR);
            reader.AddVariable(new NTString("nTracks"), nTracks);

            // Book it
            var s = "C:\\Users\\gordo\\Documents\\Code\\calratio2015\\JetCutStudies\\SimpleJetCutTraining\\bin\\x86\\Debug\\weights\\VerySimpleTraining_SimpleCuts.weights.xml";
            reader.BookMVA(new NTString("SimpleCuts"), new NTString(s));

            var f = NTFile.Open("junk.root", "RECREATE");
            reader.Write("myreader");
            f.Close();
#if false
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
#endif
        }
    }
}
