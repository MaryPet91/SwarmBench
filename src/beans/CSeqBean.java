package beans;



/**nomeprogramma , SAFE, secondi, memoria in mb
 * */
public class CSeqBean {
	
	private String nomeProgramma;
	private String seconds;
	private String memoryUsageMB;
	private String logResult;
	private String param;
	
	
	public CSeqBean(String nomeProgramma, String seconds, String memoryUsageMB, String logResult, String param) {
		
		this.nomeProgramma = nomeProgramma;
		this.seconds = seconds;
		this.memoryUsageMB = memoryUsageMB;
		this.logResult = logResult;
		this.param = param;
	}


	public String getNomeProgramma() {
		return nomeProgramma;
	}


	public void setNomeProgramma(String nomeProgramma) {
		this.nomeProgramma = nomeProgramma;
	}


	public String getSeconds() {
		return seconds;
	}


	public void setSeconds(String seconds) {
		this.seconds = seconds;
	}


	public String getMemoryUsageMB() {
		return memoryUsageMB;
	}


	public void setMemoryUsageMB(String memoryUsageMB) {
		this.memoryUsageMB = memoryUsageMB;
	}


	public String getLogResult() {
		return logResult;
	}


	public void setLogResult(String logResult) {
		this.logResult = logResult;
	}


	public String getParam() {
		return param;
	}


	public void setParam(String param) {
		this.param = param;
	}
	
	

	
	
	
	
	

}
