package servlet;


import java.io.IOException;


import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;



/**
 * Servlet implementation class SpinSwarm
 */
@WebServlet("/SpinSwarm")
public class SpinSwarm extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public SpinSwarm() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String  namefile = (String) request.getParameter("file");


		String param = (String) request.getParameter("parametersSpin");


		for(int i =1; i<=3; i++){
			ProcessBuilder process = new ProcessBuilder();


			//swarm -f ./spin/workspace/'.$nameFile.'/'.$nameFile.'.pml '.$params

			process.command("bash","-c","swarm -f /home/mary/tacs/Swarm-Project/script/spin/workspace/"+namefile+"/"+namefile+""+i+"/"+namefile+""+i+".pml "+param);
			Process p = process.start();
			try {
				p.waitFor();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			process2(namefile, i);

		}
		request.setAttribute("namefile", namefile);
		request.setAttribute("parameter", param);
		RequestDispatcher  view = request.getRequestDispatcher("/Continue_Spin.jsp");//chiama la servlet del plot 
		view.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}


	public void process2(String namefile, int i) throws IOException {
		//./spin/workspace/'.$nameFile.'/'.$nameFile.'.pml.swarm
		ProcessBuilder process2 = new ProcessBuilder();
		process2.command("bash","-c","cd /home/mary/tacs/Swarm-Project/script/spin/workspace/"+namefile+"/"+namefile+""+i+" ; /usr/bin/time -o "+namefile+""+i+".txt "+"./"+namefile+""+i+".pml.swarm");
		Process proc = process2.start();

		try {
			proc.waitFor();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
