package servlet;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import beans.CSeqBean;

import dataWorkers.CSeqJsonWriter;
import dataWorkers.CSeqReader;

import factories.CSeqFactory;


/**
 * Servlet implementation class StoreCseqJSON
 */
@WebServlet("/StoreCseqJSON")
public class StoreCseqJSON extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public StoreCseqJSON() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		String paramCseq = request.getParameter("param");
		String namefile = request.getParameter("namefile");
		
		
		//mi prendo i files dalla directory di SwarmBench
		File directorySwarm = new File("/home/mary/tacs/Swarm-Project/script/lazy-cseq/workspace/"+namefile);
		BufferedWriter buff = new BufferedWriter(new FileWriter("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/Lazy-CSeq/"+namefile+".json"));

		
		CSeqReader cseqReader = new CSeqReader();
		
		CSeqFactory cseqFactory = new CSeqFactory();
		
		for(int i =1; i<=3; i++){
			ArrayList<String> resCseqReader = cseqReader.readCSeqOut(directorySwarm.getPath()+"/"+namefile+""+i+".log",directorySwarm.getPath()+"/_cs_"+namefile+""+i+".c.cbmc.log");
			CSeqBean cseqBean = cseqFactory.createCSeqBean(resCseqReader, paramCseq);
			CSeqJsonWriter jsonw= new CSeqJsonWriter(buff);
			String json1 = jsonw.createCSeqJsonWriter(cseqBean);
			jsonw.createTableJSonCseq(json1);
			
		}

		
		buff.close();
		
		
		RequestDispatcher  view = request.getRequestDispatcher("/SeePlots.jsp");//chiama la servlet del plot 
		view.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
