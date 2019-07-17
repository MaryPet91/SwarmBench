package dataWorkers;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class SpinReader {



	public SpinReader() {


	}


	public ArrayList<String> readSpinOut(ArrayList<File> scriptOut, File txt_out) throws IOException{


		ArrayList<String> sonoio = new ArrayList<>();
		BufferedReader br1 = null;

		String toret1 = "";
		for(File pathFile1: scriptOut){

			br1 = new BufferedReader(new FileReader(pathFile1.getPath()));

			//String toret = "";

			String read = "";
			while((read = br1.readLine())!= null){

				toret1 = toret1+read+"\n";

			}


		}

		BufferedReader br2 = null;

		String toret2 = "";


		br2 = new BufferedReader(new FileReader(txt_out.getPath()));

		//String toret = "";

		String read = "";
		while((read = br2.readLine())!= null){

			toret2 = toret2+read+"\n";

		}






		//questa parte legge il file ridirezionato del comando time sul server di spin

		sonoio.add(toret1);   //SCRIPTOUT
		sonoio.add(toret2);   //TXT_OUT



		br1.close();
		br2.close();


		return sonoio;


	}



}
