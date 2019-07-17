package factories;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Set;

import com.sun.javafx.css.StyleCache.Key;

import beans.CSeqBean;
import beans.SpinBean;

public class SpinFactory {



	public SpinBean create_SpinBean(ArrayList<String> blocks, String nomeProgramma, String param){


		String sonoio = blocks.get(1);
		
	//	System.out.println(sonoio.split(",")[0].split("/")[1].spli);
		
		//String nomeProgramma= sonoio.split(",")[0].split("/")[1].split(".")[0]; //non so perchè da errore indexoutofbound 0
		String[] t = sonoio.split("\n")[0].split(" ");
		for(String s : t)
			System.out.println("test: "+s);
		String temp =sonoio.split("\n")[0].split(" ")[2];
		String seconds = temp.substring(temp.indexOf(":")+1, temp.indexOf("e")-1);
		//String memoryUsageMB = sonoio.split(",")[3].substring(0,sonoio.split(",")[3].indexOf("M") );
		String memoryUsageMB = getTotMemUsage(blocks.get(0)); //bisogna prenderlo dagli  script out
		
		return new SpinBean(nomeProgramma, seconds, memoryUsageMB, blocks.get(0), param);

	}


	
	
	private String getTotMemUsage(String block1){

		String [] split1 = block1.split("\n");
		float tot1 = 0;

		for(int i =0; i< split1.length; i++){

			if(split1[i].startsWith("Stats on memory usage")){
				tot1 = tot1 + Float.parseFloat(split1[i+5].split("	")[0]);
			}

		}




		return tot1+"";
	}
}















//---------------------------------------qui giu non si guarda!




















/*	public ArrayList<String> getSizeHashArray(String block1){
		
		
		String[]split_block1 = block1.split("\n");
		
		
		ArrayList<String> toret = new ArrayList<>();
		
		//mi scorro il primo per salvare i risultati
		
		for(int i =0; i<split_block1.length; i++){
			if(split_block1[i].startsWith("Stats on memory usage")){
				toret.add(split_block1[i+2].split("	")[0]);
			}
			
		}
		
		
		
		return toret;
	}

	public ArrayList<String> getCoverage(String block1){
		
		String[]split_block1 = block1.split("\n");
		
		
		ArrayList<String> toret = new ArrayList<>();
		
		//mi scorro il primo per salvare i risultati
		
		for(int i =0; i<split_block1.length; i++){
			if(split_block1[i].startsWith("State-vector")){
				toret.add(split_block1[i].split(",")[1].split(" ")[2]);
			}
			
		}
		
		
		return toret;
		
	}
	
	
	//scorro il secondo blocco
	
	public HashMap<String, String> getMemoryTimeUsage(String block2){
		
		HashMap<String, String> tmp = new HashMap<>();
		HashMap<String, String> toret = new HashMap<>();
		
		String split[] = block2.split("\n");
		
		for(String s : split){
			if(s.startsWith("./")){ //seconds:memory
				String split2 = s.split("#")[1].split(" ")[1];  //tempo:memoria
				String split3 = s.split("#")[1].split(" ")[6];
				tmp.put(split2, split3);
				System.out.println("SpinFactory-line86: "+split2+","+split3);
				
			}
		}
		
		
		Set<String> key = tmp.keySet();
		List<Float> toSort = new ArrayList<Float>();
		
		for(String k: key)
			toSort.add(Float.parseFloat(k));
		
		Collections.sort(toSort,new MyComparator());

		for(Float f: toSort) {
			toret.put(f+"", tmp.get(f+""));
			System.out.println("SpinFactory-line102: "+f+","+tmp.get(f+""));
		}
		
		Set<String> k2 = toret.keySet();
		
		for(String s: k2)
			System.out.println(s+","+toret.get(s));
		System.out.println("Size hm 1 "+tmp.size());
		System.out.println("Size hm 2 "+toret.size());
		return toret;
	}
	
	
	class MyComparator implements Comparator<Float> {

		@Override
		public int compare(Float o1, Float o2) {
			int esito=0;
			if(o1<o2)
				esito=-1;
			else if(o1>o2)
				esito=1;
			else
				esito=0;
			return esito;
		}

	}
*/