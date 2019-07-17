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

import beans.SpinBean;
import dataWorkers.SpinJsonWriter;
import dataWorkers.SpinReader;
import factories.SpinFactory;

/**
 * Servlet implementation class StoreJsonNew
 */
@WebServlet("/StoreSpinJSON")
public class StoreSpinJSON extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public StoreSpinJSON() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String paramSpin = request.getParameter("param");
		String namefile = request.getParameter("namefile"); //

		BufferedWriter buff2 = new BufferedWriter(new FileWriter("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/SPIN/"+namefile+".json"));
		SpinJsonWriter jsonw2= new SpinJsonWriter(buff2);

		SpinReader spinReader = new SpinReader();

		SpinFactory spinFactory = new SpinFactory();
		ArrayList<SpinBean> beansSpin = new ArrayList<>();

		//mi prendo i files dalla directory di SwarmBench


		// /swarmBenchWS/mutex/mutex.pml , script0,script0.out, eccc..... 

		// /swarmBenchWS/mutex

		for(int i =1; i<=3; i++){
			File directorySwarm = new File("/home/mary/tacs/Swarm-Project/script/spin/workspace/"+namefile+"/"+namefile+""+i);

			File[] files = directorySwarm.listFiles();

			ArrayList<File> scriptOut = new ArrayList<>();
			ArrayList<File> txt_out = new ArrayList<>();
			for(File f: files){


				if(f.getName().startsWith("script") && f.getName().endsWith(".out")) {				
					scriptOut.add(f);

				}

				if(f.getName().startsWith(namefile) && f.getName().endsWith(".txt")) {				
					txt_out.add(f);

				}


			}

			ArrayList<String> resSpinReader = spinReader.readSpinOut(scriptOut,txt_out.get(0));
			SpinBean spinBean = spinFactory.create_SpinBean(resSpinReader, namefile, paramSpin);
			beansSpin.add(spinBean);

			String json2 = jsonw2.createSpinJsonWriter(spinBean);
			jsonw2.createTableJSonSpin(json2);





		}

		buff2.close();













		request.setAttribute("namefile", namefile);
		RequestDispatcher  view = request.getRequestDispatcher("/LazyCSeqFiles.jsp");//chiama la servlet del plot 
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
