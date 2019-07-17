package dataWorkers;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Set;

import org.json.simple.JSONObject;

import net.sf.json.JSONArray;

public class StoreTempJSON {


	//	private BufferedWriter bw_spin_temp_mem;
	//	private BufferedWriter bw_spin_coverage_hasharray;
	//	private BufferedWriter bw_cseq_temp_mem;
	//	private BufferedWriter bw_cseq_mem_unwind;
	//	
	//	
	//	
	//	public StoreTempJSON(BufferedWriter bw_spin_temp_mem, BufferedWriter bw_spin_coverage_hasharray,
	//			BufferedWriter bw_cseq_temp_mem, BufferedWriter bw_cseq_mem_unwind) {
	//		
	//		
	//		this.bw_spin_temp_mem = bw_spin_temp_mem;
	//		this.bw_spin_coverage_hasharray = bw_spin_coverage_hasharray;
	//		this.bw_cseq_temp_mem = bw_cseq_temp_mem;
	//		this.bw_cseq_mem_unwind = bw_cseq_mem_unwind;
	//	}


	public File createCSeq_temp_mem(ArrayList<JSONObject> jsonsCseq) throws IOException{
		File f = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/results/cseq_temp_mem.json");
		BufferedWriter bw = new BufferedWriter(new FileWriter(f));

		float interval = 0;
		String toret ="{\"name\":\"temp_mem_"+jsonsCseq.get(0).get("nomeProgramma")+"\", \"data\": [";
		if(!f.exists())
			f.createNewFile();

		for(JSONObject j : jsonsCseq){

			toret = toret+"["+j.get("time")+","+j.get("memoryUsage")+"],";

		}

		toret = toret.substring(0, toret.lastIndexOf(","));



		toret = toret+"]}\n";

		bw.write(toret);
		bw.close();

		return f;
	}


	public File createCSeq_mem_unwind(ArrayList<JSONObject> jsonsCseq) throws IOException{
		File f = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/results/cseq_mem_unwind.json");
		BufferedWriter bw = new BufferedWriter(new FileWriter(f));

		String toret ="\"name\":\"mem_unwind_"+jsonsCseq.get(0).get("nomeProgramma")+"\", \"data\": [";
		if(!f.exists())
			f.createNewFile();

		for(JSONObject j : jsonsCseq){

			toret = toret+"["+j.get("memoryUsage")+","+j.get("unwind")+"],";

		}

		toret = toret.substring(0, toret.lastIndexOf(","));



		toret = toret+"]}\n";

		bw.write(toret);
		bw.close();

		return f;
	}



	/*series: [{
        name: 'Temperature1',
        data: [[0, 15], [10, -50], [20, -56.5], [30, -46.5], [40, -22.1],
            [50, -2.5], [60, -27.7], [70, -55.7], [80, -76.5]]
    },{
        name: 'Temperature2',
        data: [[0, 1], [10, -30], [10, -56.5], [30, -46.5], [40, -22.1],
            [50, -2.5], [60, -27.7], [70, -55.7], [80, -76.5]]
    }]
	 * */


	public File createSpin_tot_mem_time(ArrayList<JSONObject> jsonsSpin) throws IOException{

		File f = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/results/spin_tot_mem_time.json");
		BufferedWriter bw = new BufferedWriter(new FileWriter(f));
		String toret ="{\"name\": \"tot_mem_time_"+jsonsSpin.get(0).get("nomeProgramma")+"\", \"data\": [";
		
		
		ArrayList<Float> totmem = new ArrayList<>();
		ArrayList<Float> tottime = new ArrayList<>();
		
		for(JSONObject j : jsonsSpin){
			JSONArray array = (JSONArray)j.get("memTimeRes");
			float summem =0;
			float sumtime =0;
			for(int i =0; i<array.size(); i++){
				JSONObject temp = (JSONObject)array.get(i);
				summem = summem+Float.parseFloat(temp.get("memoryUsage")+"");
				sumtime = sumtime+Float.parseFloat(temp.get("timeUsage")+"");
			}
			
			
			totmem.add(summem);
			tottime.add(sumtime);
			
		}
		
		for(int i =0; i<totmem.size(); i++){
			toret=toret+"["+tottime.get(i)+","+totmem.get(i)+"],";
		}
		
		toret = toret.substring(0, toret.lastIndexOf(","));
		
		toret = toret+"]}\n";
		
		
		for(JSONObject j : jsonsSpin){
			
			
			
		}
		
		
		
		bw.write(toret);
		bw.close();

		return f;
	}

	public File createSpin_temp_mem(ArrayList<JSONObject> jsonsSpin) throws IOException{
		
		
		File f = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/results/spin_mem_time.json");
		BufferedWriter bw = new BufferedWriter(new FileWriter(f));

		String toret ="{\"name\":\"temp_mem_"+jsonsSpin.get(0).get("nomeProgramma")+"\", \"data\": [";
		if(!f.exists())
			f.createNewFile();

		for(JSONObject j : jsonsSpin){

			toret = toret+"["+j.get("time")+","+j.get("memoryUsage")+"],";

		}

		toret = toret.substring(0, toret.lastIndexOf(","));



		toret = toret+"]}\n";

		bw.write(toret);
		bw.close();

		return f;

	}








}
