package factories;

import java.util.ArrayList;

import beans.CSeqBean;

public class CSeqFactory {
	
	
	/** 
	 * programmi/mutex.c, [92mSAFE[0m, 2.07, 36.49MB*/ //  posizione 2 array
	public CSeqBean createCSeqBean(ArrayList<String> block, String param){
		
		
		
		String sonoio = block.get(0);
		
	//	System.out.println(sonoio.split(",")[0].split("/")[1].spli);
		
		//String nomeProgramma= sonoio.split(",")[0].split("/")[1].split(".")[0]; //non so perchè da errore indexoutofbound 0
		String nomeProgramma= sonoio.split(",")[0].split("/")[1];
		String seconds = sonoio.split(",")[2];
		String memoryUsageMB = sonoio.split(",")[3].substring(0,sonoio.split(",")[3].indexOf("M") );

		
		return new CSeqBean(nomeProgramma, seconds, memoryUsageMB, block.get(1), param);
	}

}
