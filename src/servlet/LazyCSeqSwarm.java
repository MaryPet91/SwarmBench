package servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class LazyCSeqSwarm
 */
@WebServlet("/LazyCSeqSwarm")
public class LazyCSeqSwarm extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public LazyCSeqSwarm() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String  namefile = (String) request.getParameter("file");
		request.setAttribute("namefile", namefile);
		String param = (String) request.getParameter("parametersCSeq");
		request.setAttribute("param", param);

		
		
		for(int i =1; i<=3; i++){
		ProcessBuilder process = new ProcessBuilder();
		
		
		//swarm -f ./spin/workspace/'.$nameFile.'/'.$nameFile.'.pml '.$params
		
		process.command("bash","-c","cd /home/mary/tacs/Swarm-Project/script/lazy-cseq ; ./cseq-feeder.py -i workspace/"+namefile+"/"+namefile+""+i+".c "+param+" > workspace/"+namefile+"/"+namefile+""+i+".log");
		Process p = process.start();
		
		
		try {
			p.waitFor();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		}

		
		RequestDispatcher  view = request.getRequestDispatcher("/Continue_CSeq.jsp");//chiama la servlet del plot 
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
