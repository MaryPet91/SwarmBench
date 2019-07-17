package test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;


import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class UploadServlet
 */
@WebServlet("/UploadServlet")
public class UploadFromSRVServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public UploadFromSRVServlet() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub



		//mi arriva il path della cartella dove sono salvati i files di swarm
		String filesSwarmRes = request.getParameter("filespath"); 
		// prendo il nome del file inserito in input sulla jsp

		String paramSpin = request.getParameter("parametersSpin");
		String paramCseq = request.getParameter("parametersLazyCSeq");
		
		request.setAttribute("paramSpin", paramSpin);
		request.setAttribute("paramCSeq", paramCseq);
		
		String fileName = request.getParameter("fileInputName");
		System.out.println("io sono il nome del file: "+ fileName);

		//mi prendo la lista di files nella cartella sul server

		File directoryFiles = new File(filesSwarmRes); 
		File [] serverFiles = directoryFiles.listFiles();


		//devo scorrere tutti i file vedere se già esistono e salvarli in locale
		for(File f: serverFiles){


			if(f.getName().equals("_cs_"+fileName+".c.cbmc.log") || f.getName().equals(fileName+"_cseq.log")||
					f.getName().equals(fileName+"_spin.log") || f.getName().equals("script0.out")|| f.getName().equals("script1.out")){
				String path = "/Users/claudiapipino/Desktop/swarmBenchWS/"+fileName+"/"+f.getName();

				File toStore = new File(path);
				if(!toStore.exists())
					toStore.createNewFile();

				URI uri = null;
				try {
					uri = new URI(f.getPath());
				} catch (URISyntaxException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				URL url = uri.toURL();



				System.out.println("mi connetto a "+ url.toString());

				HttpURLConnection conn = (HttpURLConnection) url.openConnection();
				conn.setRequestMethod("GET");
				conn.setDoOutput(false);
				conn.connect();

				BufferedReader in = new BufferedReader(new InputStreamReader(url.openStream()));


				BufferedWriter bw = new BufferedWriter(new FileWriter(toStore));		

				String read = "";


				while((read=in.readLine())!=null){
					bw.write(read+"\n");
				}



				bw.close();
				in.close();

			}	
		}

		

		RequestDispatcher  view = request.getRequestDispatcher("/StoreJSONS");//chiama la servlet del plot 
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
