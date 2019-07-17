package dataWorkers;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Set;

import beans.SpinBean;




public class SpinJsonWriter {

	
	
BufferedWriter buff;
	
	public SpinJsonWriter(BufferedWriter buff){
		this.buff = buff;
	}
	
	
	public void createTableJSonSpin(String json) throws IOException{
		buff.write(json);
	}
	
	
	
	
	public String createSpinJsonWriter(SpinBean bean){

		
		System.out.println("Params :"+bean.getParam());
		return "{\"nomeProgramma\":\""+bean.getNomeProgramma()+"\", \"time\":"+bean.getSeconds()+", \"memoryUsage\":"+bean.getMemoryUsageMB()+", "
				+ "\"params\":\""+bean.getParam()+"\"}\n";
	}

		

	
	
	
}







//---------------------------qui giu non si guarda!!!
















//	public String createSpinJsonWriter(SpinBean bean){
//String toret = "{\"nomeprogramma\":\""+bean.getNomeProgramma()+"\",\"memTimeRes\":"+createMemoryTimeUsageJSONObj(bean.getMemoryTimeUsage())+
//", \"hashArrayUsage\":"+getHashArrayTable(bean.getHashArray())+"\"param\":\""+bean.getParam()+"\"}\n";
//
//
////String toret = "{\"nomeprogramma\":\""+bean.getNomeProgramma()+"\",\"memTimeRes\":"+createMemoryTimeUsageJSONObj(bean.getMemoryTimeUsage())+
////", \"hashArrayUsage\":"+getHashArrayTable(bean.getHashArray())+",\"blocksRes\":\""+bean.getBlockResult()+"\","
////+"\"param\":\""+bean.getParam()+"\"}\n";
//
//return toret;
//}

/*private String createMemoryTimeUsageJSONObj(HashMap<String, String> hmBean){
		
		
		
		Set<String> key = hmBean.keySet();
		List<Float> toSort = new ArrayList<Float>();
		
		for(String k: key)
			toSort.add(Float.parseFloat(k));
		
		Collections.sort(toSort,new MyComparator());

		String toret = "";
		for(Float f: toSort) {
			toret = toret +"{\"timeUsage\":"+f+", \"memoryUsage\":"+hmBean.get(f+"")+"},"; 
			
		}
		
		
		
		return "["+toret.substring(0,toret.lastIndexOf(","))+"]";
		
		
	}
	
	private String getHashArrayTable(ArrayList<String> hashBean){
		
		
		String toret = "";
		
		for(String s : hashBean){
			
			toret = toret+s+",";
			
		}
		
		
		return "["+toret.substring(0, toret.lastIndexOf(","))+"]";
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

	}*/


