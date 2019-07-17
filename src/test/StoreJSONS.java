//package test;
//
//import java.io.BufferedWriter;
//import java.io.File;
//import java.io.FileWriter;
//import java.io.IOException;
//import java.util.ArrayList;
//
//import javax.servlet.RequestDispatcher;
//import javax.servlet.ServletException;
//import javax.servlet.annotation.WebServlet;
//import javax.servlet.http.HttpServlet;
//import javax.servlet.http.HttpServletRequest;
//import javax.servlet.http.HttpServletResponse;
//
//import beans.CSeqBean;
//import beans.SpinBean;
//import dataWorkers.CSeqJsonWriter;
//import dataWorkers.CSeqReader;
//import dataWorkers.SpinJsonWriter;
//import dataWorkers.SpinReader;
//import factories.CSeqFactory;
//import factories.SpinFactory;
//
///**
// * Servlet implementation class StoreJSONS
// */
//@WebServlet("/StoreJSONS")
//public class StoreJSONS extends HttpServlet {
//	private static final long serialVersionUID = 1L;
//       
//    /**
//     * @see HttpServlet#HttpServlet()
//     */
//    public StoreJSONS() {
//
//        // TODO Auto-generated constructor stub
//    }
//
//	/**
//	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
//	 */
//	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//		// TODO Auto-generated method stub
//		
//		String paramSpin = request.getParameter("paramSpin");
//		String paramCseq = request.getParameter("paramCSeq");
//		
//		
//		//mi prendo i files dalla directory di SwarmBench
//		File directorySwarm = new File("/Users/claudiapipino/Desktop/swarmBenchWS");
//		
//		File[] files = directorySwarm.listFiles();
//		
//		for(File f : files){
//			if(!f.getName().equals("results")){
//				CSeqReader cseqReader = new CSeqReader();
//				SpinReader spinReader = new SpinReader();
//				CSeqFactory cseqFactory = new CSeqFactory();
//				SpinFactory spinFactory = new SpinFactory();
//				
//				
//				String nomeFile= f.getName();
//				
//				ArrayList<String> resCseqReader = cseqReader.readCSeqOut(f.getPath()+"/"+nomeFile+".log", f.getPath()+"/_cs_"+nomeFile+".c.cbmc.log");
//				ArrayList<String> resSpinReader = spinReader.readSpinOut(f.getPath()+"/script0.out", f.getPath()+"/script1.out", f.getPath()+"/"+nomeFile+".txt");
//				
//				CSeqBean cseqBean = cseqFactory.createCSeqBean(resCseqReader, paramCseq);
//				
//				SpinBean spinBean = spinFactory.create_SpinBean(resSpinReader, nomeFile, paramSpin);
//				
//				
//				
//				BufferedWriter buff = new BufferedWriter(new FileWriter("/Users/claudiapipino/Desktop/swarmBenchWS/results/Cseqjson/"+nomeFile+".json",true));
//				CSeqJsonWriter jsonw= new CSeqJsonWriter(buff);
//				String json1 = jsonw.createCSeqJsonWriter(cseqBean);
//				
//				jsonw.createTableJSonCseq(json1);
//				
//				buff.close();
//				
//				
//				BufferedWriter buff2 = new BufferedWriter(new FileWriter("/Users/claudiapipino/Desktop/swarmBenchWS/results/Spinjson/"+nomeFile+".json",true));
//				SpinJsonWriter jsonw2= new SpinJsonWriter(buff2);
//				String json2 = jsonw2.createSpinJsonWriter(spinBean);
//				
//				jsonw2.createTableJSonSpin(json2);
//				
//				buff2.close();
//
//				
//				System.out.println(cseqBean.toString());
//				System.out.println(spinBean.toString());
//
//			}
//		}
//		
//		RequestDispatcher  view = request.getRequestDispatcher("TablesResults.jsp");//chiama la servlet del plot 
//		view.forward(request, response);
//	}
//
//	/**
//	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
//	 */
//	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//		// TODO Auto-generated method stub
//		doGet(request, response);
//	}
//
//}
