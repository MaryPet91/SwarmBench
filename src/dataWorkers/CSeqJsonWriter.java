package dataWorkers;

import java.io.BufferedWriter;

import java.io.IOException;

import beans.CSeqBean;

public class CSeqJsonWriter {

	BufferedWriter buff;

	public CSeqJsonWriter(BufferedWriter buff){
		this.buff = buff;
	}


	/*<%
														json.get("nomeProgramma");
													%>
												</td>
												<td>
													<%
														json.get("time");
													%>
												</td>
												<td>
													<%
														json.get("memeoryUsage");
													%>
												</td>
												<td>
													<%
														json.get("parameters");*/
	public String createCSeqJsonWriter(CSeqBean bean){
		System.out.println("Params :"+bean.getParam());
		return "{\"nomeProgramma\":\""+bean.getNomeProgramma()+"\", \"time\":"+bean.getSeconds()+", \"memoryUsage\":"+bean.getMemoryUsageMB()+", "
				+ "\"unwind\":\""+bean.getParam().substring(bean.getParam().indexOf("d")+2, bean.getParam().indexOf("d")+3)+"\"}\n";
	}

	public void createTableJSonCseq(String json) throws IOException{
		buff.write(json);
	}

}