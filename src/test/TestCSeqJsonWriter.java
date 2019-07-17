//package test;
//
//import java.io.BufferedWriter;
//import java.io.FileWriter;
//import java.io.IOException;
//
//import beans.CSeqBean;
//import dataWorkers.CSeqJsonWriter;
//
//public class TestCSeqJsonWriter {
//
//	public static void main(String[] args) {
//		
//		//programmi/mutex.c, [92mSAFE[0m, 2.88, 36.55MB
//		CSeqBean bean1 = new CSeqBean("mutex", "2.88", "36.55", "log-result1");
//		CSeqBean bean2 = new CSeqBean("mutex", "3.04", "38.24", "log-result2");
//		BufferedWriter buff = null;
//		try {
//			buff = new BufferedWriter(new FileWriter("Mutexresult.json",true));
//			CSeqJsonWriter jsonw= new CSeqJsonWriter(buff);
//			String json1 = jsonw.createCSeqJsonWriter(bean1);
//			String json2 = jsonw.createCSeqJsonWriter(bean2);
//			jsonw.createTableJSonCseq(json1);
//			jsonw.createTableJSonCseq(json2);
//			System.out.println(json1+"\n"+json2);
//			buff.close();
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
//		
//	}
//
//}
