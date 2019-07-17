package servlet;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import dataWorkers.StoreTempJSON;

/**
 * Servlet implementation class JSONCSeqTIME_MEM
 */
@WebServlet("/JSONtemp")
public class JSONtemp extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSONtemp() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String namefileJSON = (String) request.getParameter("plot"); 
		
		File cseq = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/Lazy-CSeq/"+namefileJSON);
		File spin = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/SPIN/"+namefileJSON);
		
		//creo il json tmp per memoria e tempo cseq
		
		BufferedReader br1 = new BufferedReader(new FileReader(cseq));
		String read1= "";
		ArrayList<JSONObject> jsonsCseq = new ArrayList<>();
		
		while((read1 = br1.readLine())!=null){
			if(read1.indexOf("}")==-1){
				read1 +=read1;
			}else{
				
				try {
					jsonsCseq.add((JSONObject)new JSONParser().parse(read1));
				} catch (ParseException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
			
			
		}

		BufferedReader br2 = new BufferedReader(new FileReader(spin));
		String read2= "";
		ArrayList<JSONObject> jsonsSpin = new ArrayList<>();
		
		while((read2 = br2.readLine())!=null){
			if(read2.indexOf("}")==-1){
				read2 +=read2;
			}else{
				
				try {
					jsonsSpin.add((JSONObject)new JSONParser().parse(read2));
				} catch (ParseException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
			
			
		}
		
		
		//chiamo storejsons temp;
		
		StoreTempJSON stj = new StoreTempJSON();
		
		stj.createCSeq_temp_mem(jsonsCseq);
		stj.createCSeq_mem_unwind(jsonsCseq);
		//stj.createSpin_tot_mem_time(jsonsSpin);
		stj.createSpin_temp_mem(jsonsSpin);
		
		
		br1.close();
		br2.close();
		RequestDispatcher  view = request.getRequestDispatcher("/Chart.jsp");
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
