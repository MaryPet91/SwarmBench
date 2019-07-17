package dataWorkers;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class CSeqReader {

public ArrayList<String> readCSeqOut(String pathFile1, String pathFile2) throws IOException{



		ArrayList<String> end = new ArrayList<>();
		BufferedReader br1 = new BufferedReader(new FileReader(pathFile1));  //file lungo lo metto in un unico blocco 

		String toret1 = "";
		String read1 = "";
		while((read1 = br1.readLine())!= null){

			toret1 = toret1+read1+"\n";

		}

		br1.close();
		
		
		
		BufferedReader br2 = new BufferedReader(new FileReader(pathFile2));  //file da splittare

		String toret2 = "";
		String read2 = "";
		while((read2 = br2.readLine())!= null){

			toret2 = toret2+read2+"\n";

		}

		br2.close();

		
		end.add(toret1);
		end.add(toret2);
		
		return end;


	}

}
